/* ************************************************* */
/* This file is a part of WordSuggestion. */
/* Created by santa on 2022-03-26. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <algorithm>
#include "file_utils.h"

using namespace std;

/**
 * Computes the magnitude of the vector.
 */
double magnitude(const vector<int> &items) {
    double sum = 0.0;
    for (int iter: items) sum += (double) (iter * iter);
    return sqrt(sum);
}

/**
 * Computes the magnitude of indexed vector.
 */
double magnitude(const vector<pair<int, int>> &candidate) {
    double sum = 0.0;
    for (const auto &iter: candidate) sum += iter.second;
    return sqrt(sum);
}

/**
 * Calculates the dot product between two vectors.
 */
double dot_product(const vector<int> &v, const vector<int> &w) {
    double dot_sum = 0.0;
    auto v_iter = v.begin(), w_iter = w.begin();
    for (; v_iter != v.end() || w_iter != w.end(); v_iter++, w_iter++)
        dot_sum += (double) (*v_iter * *w_iter);
    return dot_sum;
}

/**
 * Calculates the cosine value between two vectors u and w.
 */
double cos_theta(const vector<int> &v, const vector<int> &w) {
    return dot_product(v, w) / (magnitude(v) * magnitude(w));
}

/**
 * Selects all the unique words only.
 */
vector<string> unique_words(vector<string> all_words) {
    vector<string> unique;
    vector<string>::iterator word_iterator;
    for (word_iterator = all_words.begin(); word_iterator != all_words.end(); word_iterator++) {
        int exists = count(unique.begin(), unique.end(), *word_iterator);
        if (!exists) unique.push_back(*word_iterator);
    }
    return unique;
}

/**
 * Returns value associated with the vector index, 0 in default case.
 */
int indexed_score(const vector<pair<int, int>> &entries, int index) {
    int indexed_value = 0;
    for (auto iter = entries.begin(); iter != entries.end(); iter++) {
        if (iter->first == index) {
            indexed_value = iter->second;
            break;
        }
    }
    return indexed_value;
}

/**
 * Computes dot product of two indexed vectors. Expand both vectors to a
 * uniform dimensions so that the computation can be done with iterators.
 */
double dot_product_of(const vector<pair<int, int>> &candidate_word, const vector<pair<int, int>> &partial_word) {
    /**
     * 1. Accumulate indices.
     */
    set<int> all_indices;
    for (const auto &iter: candidate_word) all_indices.insert(iter.first);
    for (const auto &iter: partial_word) all_indices.insert(iter.first);
    /**
     * 2. Expand the vectors with new indices.
     */
    vector<pair<int, int>> n_candidates, n_partials;
    for (auto iter = all_indices.begin(); iter != all_indices.end(); iter++) {
        n_candidates.emplace_back(make_pair(*iter, indexed_score(candidate_word, *iter)));
        n_partials.emplace_back(make_pair(*iter, indexed_score(partial_word, *iter)));
    }
    //display_in_console(n_candidates, "Coefficients of Candidate: ");
    //display_in_console(n_partials, "Coefficients of Partial:  ");

    /**
     * 3. Compute dot product.
     */
    double dot_sum = 0.0;
    auto c_iter = n_candidates.begin(), p_iter = n_partials.begin();
    while (c_iter != n_candidates.end() || p_iter != n_partials.end()) {
        dot_sum += (double) c_iter->second * (double) p_iter->second;
        ++c_iter, ++p_iter;
    }
    return dot_sum;
}

/**
 * Calculate the cosine value of angle between two vectors.
 */
double cos_theta(const vector<pair<int, int>> &candidate_word, const vector<pair<int, int>> &partial_word) {
    return dot_product_of(candidate_word, partial_word) / (magnitude(candidate_word) * magnitude(partial_word));
}
