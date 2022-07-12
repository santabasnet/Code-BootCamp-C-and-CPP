/* ************************************************* */
/* This file is a part of WordSuggestion. */
/* Created by santa on 2022-03-26. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#include <vector>

using namespace std;

#ifndef WORDSUGGESTION_VECTOR_UTILS_H
#define WORDSUGGESTION_VECTOR_UTILS_H

const double THRESHOLD_SCORE = 0.0;
const int MAX_SUGGESTIONS = 10;

/**
 * Computes the magnitude of the vector.
 */
double magnitude(const vector<pair<int, double>> &);

/**
 * Extract value of the indexed score.
 */
double indexed_score(const vector<pair<int, double>> &, int);

/**
 * Computes dot product of two indexed vectors.
 */
double dot_product_of(const vector<pair<int, double>> &, const vector<pair<int, double>> &);

/**
 * Computes cosine value of the angle between two vectors.
 */
double cos_theta(const vector<pair<int, double>> &, const vector<pair<int, double>> &);

#endif //WORDSUGGESTION_VECTOR_UTILS_H
