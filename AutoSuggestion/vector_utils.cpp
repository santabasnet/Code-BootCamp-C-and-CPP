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
#include "file_utils.h"

/**
 * Standard template libraries.
 */
using namespace std;

/**
 * Computes the magnitude of indexed vector.
 */
double magnitude(const vector<pair<int, double>> &candidate) {
    double sum = 0.0;
    for (const auto &iter: candidate) sum += iter.second;
    return sqrt(sum);
}

/**
 * Returns value associated with the vector index, 0 in default case.
 */
double indexed_score(const vector<pair<int, double>> &entries, int index) {
    double indexed_value = 0.0;
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
double dot_product_of(const vector<pair<int, double>> &candidate_word, const vector<pair<int, double>> &partial_word) {
    /**
     * 1. Accumulate indices.
     */
    set<int> all_indices;
    for (const auto &iter: candidate_word) all_indices.insert(iter.first);
    for (const auto &iter: partial_word) all_indices.insert(iter.first);
    //display_in_console(all_indices, "Indices: ");

    /**
     * 2. Expand the vectors with new indices.
     */
    vector<pair<int, double>> n_candidates, n_partials;
    for (auto iter = all_indices.begin(); iter != all_indices.end(); iter++) {
        n_candidates.emplace_back(make_pair(*iter, indexed_score(candidate_word, *iter)));
        n_partials.emplace_back(make_pair(*iter, indexed_score(partial_word, *iter)));
    }

    /**
     * 3. Compute dot product.
     */
    double dot_sum = 0.0;
    auto c_iter = n_candidates.begin(), p_iter = n_partials.begin();
    while (c_iter != n_candidates.end() || p_iter != n_partials.end()) {
        dot_sum += c_iter->second * p_iter->second;
        ++c_iter, ++p_iter;
    }

    return dot_sum;
}

/**
 * Calculate the cosine value of angle between two vectors.
 */
double cos_theta(const vector<pair<int, double>> &candidate_word, const vector<pair<int, double>> &partial_word) {
    //cout<<endl<< dot_product_of(candidate_word, partial_word)<<"\t"<< magnitude(candidate_word) << "\t" << magnitude(partial_word);
    return dot_product_of(candidate_word, partial_word) / (magnitude(candidate_word) * magnitude(partial_word));
}
