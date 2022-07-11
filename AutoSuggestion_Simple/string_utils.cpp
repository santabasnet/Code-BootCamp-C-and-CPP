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
    for (vector<int>::iterator s_iterator = eligible_sizes.begin(); s_iterator != eligible_sizes.end(); s_iterator++) {
        vector<string> k_grams(grams_of(text, *s_iterator));
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
* Accumulate NGram Frequencies.
*/
unordered_map<string, int> accumulate_frequency(unordered_map<string, vector<string>> word_ngrams) {
    unordered_map<string, int> gram_frequency;
    unordered_map<string, vector<string>>::iterator wg_iter;
    for (wg_iter = word_ngrams.begin(); wg_iter != word_ngrams.end(); wg_iter++) {
        vector<string> grams(wg_iter->second);
        for (int index = 0; index < grams.size(); index++) {
            if (gram_frequency.find(grams[index]) == gram_frequency.end())
                gram_frequency.insert(make_pair(grams[index], 1));
            else
                gram_frequency[grams[index]]++;
        }
    }
    return gram_frequency;
}