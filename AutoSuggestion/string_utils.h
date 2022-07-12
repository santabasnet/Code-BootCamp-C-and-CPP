/* ************************************************* */
/* This file is a part of WordSuggestion. */
/* Created by santa on 2022-03-26. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#include<vector>
#include <string>
#include <map>

using namespace std;

#ifndef WORDSUGGESTION_STRING_UTILS_H
#define WORDSUGGESTION_STRING_UTILS_H

bool comparator(pair<string, int>, pair<string, int>);

vector<string> grams_of(string);

vector<string> grams_of(string, int);

vector<string> grams_of(string, vector<int>);

vector<string> grams_of(string, int *);

vector<string> randomized_words(vector<string>, int);

unordered_map<string, vector<string>> accumulate_ngrams(const vector<string> &);

vector<pair<string, int>> frequency_table_of(const vector<string> &);

vector<pair<string, double>> normalized_frequency(const vector<pair<string, int>> &);

vector<pair<string, double>> weighted_grams(
        const vector<string> &, const unordered_map<string, vector<string>> &, unsigned long);

unordered_map<string, vector<pair<string, double>>> weighted_word_ngrams(
        const unordered_map<string, vector<string>> &, const unordered_map<string, vector<string>> &, unsigned long);

#endif //WORDSUGGESTION_STRING_UTILS_H
