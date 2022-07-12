/* ************************************************* */
/* This file is a part of WordSuggestion. */
/* Created by santa on 2022-03-26. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#include <string>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <unordered_map>
#include "string_utils.h"
#include "file_utils.h"
#include "constant_literals.h"

using namespace std;

/**
 * Compare the twin pairs by their second entry.
 */
bool comparator(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}

/**
 * Generates all the grams of the given string with the size.
 * Total Grams: (Length of Text - Gram Size + 1).
 */
vector<string> grams_of(string text, int size) {
    vector<string> grams;
    if (text.length() <= size) grams.push_back(text);
    else {
        for (int i = 0; i < text.length() - size + 1; i++)
            grams.push_back(text.substr(i, size));
    }
    return grams;
}

/**
 * Generates all the grams of the given string with the sizes.
 */
vector<string> grams_of(string text, vector<int> sizes) {
    /**
     * Extract eligible gram size.
     */
    vector<int> eligible_sizes;
    for (vector<int>::iterator sIter = sizes.begin(); sIter != sizes.end(); sIter++) {
        if (*sIter < text.length()) eligible_sizes.push_back(*sIter);
    }
    /**
     * Perform grams generations.
     */
    vector<string> grams;
    for (vector<int>::iterator s_iter = eligible_sizes.begin(); s_iter != eligible_sizes.end(); s_iter++) {
        vector<string> k_grams(grams_of(text, *s_iter));
        grams.insert(grams.end(), k_grams.begin(), k_grams.end());
    }
    grams.push_back(text);
    return grams;
}

/**
 * Generates all the grams of the given string with sizes specified in the array.
 */
vector<string> grams_of(string text, int *sizes) {
    int n = sizeof(sizes) / sizeof(sizes[0]);
    vector<int> v_sizes(n);
    copy(sizes, sizes + n, v_sizes.begin());
    return grams_of(text, v_sizes);
}

/**
 * Generates all the gram of the string with default gram sizes.
 */
vector<string> grams_of(string text) {
    return grams_of(text, DEFAULT_GRAM_SIZES);
}

/**
 * Selects all the randomized words of size k from the given vector.
 */
vector<string> randomized_words(vector<string> sourceData, int kSize) {
    /**
     * Generate all indices.
     */
    vector<int> all_numbers;
    all_numbers.reserve(sourceData.size());
    for (int index = 0; index < sourceData.size(); index++) all_numbers.push_back(index);

    /**
     * Randomize indices by shuffle.
     */
    unsigned random_seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(all_numbers.begin(), all_numbers.end(), default_random_engine(random_seed));

    /**
     * Truncate the sampled_words numbers and select random words.
     */
    vector<string> sampled_words;
    sampled_words.reserve(kSize);
    for (int index = 0; index < kSize; index++) sampled_words.push_back(sourceData.at(all_numbers.at(index)));
    return sampled_words;
}

string trim(string text) {
    const char *whiteSpaces = " \t\n\r\f\v";
    text.erase(text.find_last_not_of(whiteSpaces) + 1);
    text.erase(0, text.find_first_not_of(whiteSpaces));
    return text;
}


/**
 * Build word and their ngrams.
 */
unordered_map<string, vector<string>> accumulate_ngrams(const vector<string> &word_list) {
    unordered_map<string, vector<string>> word_grams;
    word_grams.reserve(word_list.size());
    for (auto word_iter = word_list.begin(); word_iter != word_list.end(); word_iter++) {
        string word = trim(*word_iter);
        vector<string> grams = grams_of(word);
        word_grams.insert(make_pair(word, grams));
    }
    return word_grams;
}

/**
 * Build Frequency Table.
 */
vector<pair<string, int>> frequency_table_of(const vector<string> &words) {
    vector<pair<string, int>> gram_frequency;
    int entries = 0;
    for (auto w_iter = words.begin(); w_iter != words.end(); w_iter++) {
        bool flag = false;
        int i = 0;
        for (; i < entries; i++) {
            if (gram_frequency[i].first == *w_iter) {
                flag = true;
                break;
            }
        }
        if (flag) gram_frequency[i].second++;
        else gram_frequency.emplace_back(make_pair(*w_iter, 1));
    }
    return gram_frequency;
}

/**
 * Normalized frequency table.
 * tf(t) = (Number of times term t appears in a document) / (Total number of terms in the document).
 */
vector<pair<string, double>> normalized_frequency(const vector<pair<string, int>> &gram_frequency) {
    double total_frequency = 0.0;
    for (const auto &g_iter: gram_frequency) total_frequency += (double) g_iter.second;

    vector<pair<string, double>> normalized_frequency;
    for (const auto &g_iter: gram_frequency)
        normalized_frequency.emplace_back(g_iter.first, ((double) g_iter.second / total_frequency));

    return normalized_frequency;
}

/**
* Accumulate NGram Inverse Document Frequencies for individual words.
 * idf(t) = log_e(Total docs / Number of docs with term t in it).
*/
vector<pair<string, double>>
grams_idf(const unordered_map<string, vector<string>> &gram_words, const vector<string> &grams,
          unsigned long total_docs) {
    vector<pair<string, double>> gram_idf;
    for (const auto &gram_word: gram_words) {
        auto docs_count = (double) gram_word.second.size();
        double idf = log((1.0 + docs_count) / (1.0 + (double) total_docs) + 1.0);
        gram_idf.emplace_back(gram_word.first, idf);
    }
    return gram_idf;
}

/**
 * Calculate weights for ngrams.
 */
vector<pair<string, double>> weighted_grams(
        const vector<string> &ngrams,
        const unordered_map<string, vector<string>> &gram_words,
        unsigned long total_docs
) {
    vector<pair<string, int>> g_frequency = frequency_table_of(ngrams);
    vector<pair<string, double>> norm_tf = normalized_frequency(g_frequency);
    vector<pair<string, double>> norm_idf = grams_idf(gram_words, ngrams, total_docs);
    vector<pair<string, double>> norm_tf_idf;
    for (int i = 0; i < norm_tf.size(); i++) {
        double score = norm_tf[i].second * norm_idf[i].second;
        norm_tf_idf.emplace_back(norm_tf[i].first, score);
    }
    return norm_tf_idf;
}

/**
* Accumulate tf-idf weights of word grams.
*/
unordered_map<string, vector<pair<string, double>>> weighted_word_ngrams(
        const unordered_map<string, vector<string>> &word_ngrams,
        const unordered_map<string, vector<string>> &gram_words,
        unsigned long total_docs
) {
    unordered_map<string, vector<pair<string, double>>> word_ngram_scores;

    for (const auto &word_ngram: word_ngrams) {
        vector<pair<string, double>> norm_tf_idf = weighted_grams(word_ngram.second, gram_words, total_docs);
        word_ngram_scores.insert(make_pair(word_ngram.first, norm_tf_idf));
    }

    return word_ngram_scores;
}