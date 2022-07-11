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

const double THRESHOLD_SCORE = 0.1;
const int MAX_SUGGESTIONS = 10;

/**
 * Computes the magnitude of the vector.
 */
double magnitude(const vector<int> &);

/**
 * Calculates the dot product between two vectors.
 */
double dot_product(const vector<int> &, const vector<int> &);

/**
 * Calculates the cosine value between two vectors u and w.
 */
double cos_theta(const vector<int> &, const vector<int> &);

/**
 * Computes dot product of two indexed vectors.
 */
double dot_product_of(const vector<pair<int, int>> &, const vector<pair<int, int>> &);

/**
 * Computes cosine value of the angle between two vectors.
 */
double cos_theta(const vector<pair<int, int>> &, const vector<pair<int, int>> &);

/**
 * Selects all the unique words only.
 */
vector<string> unique_words(vector<string>);

#endif //WORDSUGGESTION_VECTOR_UTILS_H
