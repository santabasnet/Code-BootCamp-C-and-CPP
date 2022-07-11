/* ************************************************* */
/* This file is a part of WordSuggestion project. */
/* Created by santa on 2022-03-30. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#include <map>
#include <set>
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#include "dimension.h"
#include "file_utils.h"
#include "string_utils.h"
#include "vector_utils.h"

using namespace std;

/**
 * Default constructor with word grams initialization.
 * @param wordGrams
 */
dimension::dimension(unordered_map<string, vector<string>> word_ngrams, unordered_map<string, int> gram_frequency) {
    this->word_ngrams = move(word_ngrams);
    this->gram_score = move(gram_frequency);
    initialize_gram_indices();
}

/**
* Initialize all the gram and their indices.
*/
void dimension::initialize_gram_indices() {
    /**
     * 1. Build Gram Indices.
     */
    map<string, int> ordered_grams(this->gram_score.begin(), this->gram_score.end());
    int index = 0;
    for (auto iterator = ordered_grams.begin(); iterator != ordered_grams.end(); iterator++) {
        this->gram_index.insert(make_pair(iterator->first, index));
        this->index_gram.insert(make_pair(index, iterator->first));
        index++;
    }

    /**
     * 2. Generate the gram and their association to the words, this helps us to
     * find all the words to make vector comparisons with optimized way.
     */
    build_gram_words();

    /**
     * 3. Build the word and their associated vector.
     */
    build_word_vector();

}

/**
 * Gram and their associated words.
 */
void dimension::build_gram_words() {
    /**
     * 1. Convert all the entries in word-grams pair.
     * Example:
     *      Convert     player -> {pl, la, ay, ye, er, pla, lay, aye, yer}
     *              to,
     *                  {
     *                      (player -> pl), (player -> la), (player -> ay), (player -> ye), (player -> er),
     *                      (player -> pla), (player -> lay), (player -> aye), (player -> yer)
     *                  }
     */
    vector<pair<string, string>> word_gram_pair;
    for (auto wg_iter = this->word_ngrams.begin(); wg_iter != this->word_ngrams.end(); wg_iter++) {
        for (auto g_iter = wg_iter->second.begin(); g_iter != wg_iter->second.end(); g_iter++) {
            word_gram_pair.emplace_back(wg_iter->first, *g_iter);
        }
    }
    /**
     * 2. Make group of words they are associated with gram.
     */
    for (auto wgp_iter = word_gram_pair.begin(); wgp_iter != word_gram_pair.end(); wgp_iter++) {
        auto pair = *wgp_iter;
        if (this->gram_words.find(pair.second) != this->gram_words.end()) {
            this->gram_words[pair.second].emplace_back(pair.first);
        } else {
            vector<string> words = {pair.first};
            this->gram_words[pair.second] = words;
        }
    }
}

/**
 * Builds vectors of all words.
 */
void dimension::build_word_vector() {
    for (auto wng_iter = this->word_ngrams.begin(); wng_iter != this->word_ngrams.end(); wng_iter++) {
        this->words_vector[wng_iter->first] = generate_vector(wng_iter->second);
    }
}

/**
 * Make relevant suggestions for the partial word.
 */
vector<pair<string, double>> dimension::suggest(string partial_word) {
    /**
     * 1. Generate vector.
     */
    vector<string> grams = grams_of(move(partial_word));
    vector<pair<index, score>> grams_vector = generate_vector(grams);

    /**
     * 2. Get ranked words.
     */
    set<string> candidate_words = acquire_candidates(grams);
    unordered_map<string, vector<pair<index, score>>> candidate_vectors = acquire_vectors(candidate_words);
    //display_in_console(candidate_vectors, "Candidate Vectors: ");
    unordered_map<string, double> word_scores = compute_similarity(candidate_vectors, grams_vector);
    //display_in_console(word_scores, "Calculated scores of candidate words: ");

    /**
     * 3. Filter and sort map entries.
     */
    vector<pair<string, double>> ordered_scores = filter_sort_by_score(word_scores);
    //display_in_console(ordered_scores, "Sorted scores of candidate words: ");

    /**
     * 4. Take first k sorted elements.
     */
    vector<pair<string, double>> ranked_scores = top_scored_words(ordered_scores);

    /**
     * 5. Finally return the selected words.
     */
    return ranked_scores;
}

/**
 * Take first k sorted elements.
 */
vector<pair<string, double>> dimension::top_scored_words(const vector<pair<string, double>> &word_scores) {
    vector<pair<string, double>> ranked_scores;
    int counter = 0;
    for (auto iter = word_scores.begin(); iter != word_scores.end(); iter++, counter ++) {
        ranked_scores.emplace_back(iter->first, iter->second);
        if(counter > MAX_SUGGESTIONS) break;
    }
    return ranked_scores;
}

/**
 * Sort the calculated scores by the value.
 */
vector<pair<string, double>> dimension::filter_sort_by_score(const unordered_map<string, double> &word_scores) {
    vector<pair<string, double>> sorted_scores;
    for (auto &iter: word_scores) if (iter.second > THRESHOLD_SCORE) sorted_scores.emplace_back(iter);
    sort(sorted_scores.begin(), sorted_scores.end(), comparator);
    return sorted_scores;
}

/**
 * Generate vector for list of grams.
 */
vector<pair<int, int>> dimension::generate_vector(vector<string> grams) {
    vector<pair<index, score>> vector_entry;
    for (auto ng_iter = grams.begin(); ng_iter != grams.end(); ng_iter++) {
        if (this->gram_index.find(*ng_iter) != this->gram_index.end()) {
            vector_entry.emplace_back(make_pair(this->gram_index[*ng_iter], this->gram_score[*ng_iter]));
        }
    }
    return vector_entry;
}

/**
 * Acquire all the word candidates to be compared with partial word vector.
 */
set<string> dimension::acquire_candidates(const vector<string> &grams) {
    set<string> candidate_words;
    for (auto &gram: grams) {
        if (this->gram_words.find(gram) != this->gram_words.end()) {
            auto words_iter = this->gram_words[gram].begin();
            for (; words_iter != this->gram_words[gram].end(); words_iter++) candidate_words.insert(*words_iter);
        }
    }
    return candidate_words;
}

/**
 * Acquires all the candidate words with their vectors.
 */
unordered_map<string, vector<pair<int, int>>> dimension::acquire_vectors(const set<string> &candidate_words) {
    unordered_map<string, vector<pair<index, score>>> candidates;
    for (const auto &word: candidate_words) {
        candidates.insert(make_pair(word, this->words_vector[word]));
    }
    return candidates;
}

/**
 * Computes the similarity and sends the sorted output.
 */
unordered_map<string, double>
dimension::compute_similarity(const unordered_map<string, vector<pair<int, int>>> &candidates,
                              const vector<pair<index, score>> &partial_word) {
    unordered_map<string, double> vector_scores;
    for (auto candidate_iter = candidates.begin(); candidate_iter != candidates.end(); candidate_iter++) {
        double similarity = cos_theta(candidate_iter->second, partial_word);
        vector_scores.insert(make_pair(candidate_iter->first, similarity));
    }
    return vector_scores;
}

/**
 * Returns the count of all distinct grams.
 * @return number_of_dimensions
 */
unsigned long dimension::number_of_dimensions() {
    return this->gram_index.size();
}

/**
 * Displays all the entries of gram and their associated words in console.
 */
void dimension::display_gram_words() {
    display_in_console(this->gram_words, "Grams and their associated words: ");
}

/**
 * Display all the index based vectors.
 */
void dimension::display_words_vector() {
    display_in_console(this->words_vector, "Words and their associated vector: ");
}
