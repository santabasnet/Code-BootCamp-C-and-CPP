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

const int MAX_RANDOM_WORDS = 5000;

const int TOTAL_WORDS = 10000;

const vector<int> DEFAULT_GRAM_SIZES = {2, 3, 5};

bool comparator(pair<string, int>, pair<string, int>);

vector<string> grams_of(string);

vector<string> grams_of(string, int);

vector<string> grams_of(string, vector<int>);

vector<string> grams_of(string, int *);

vector<string> randomized_words(vector<string>, int);

unordered_map<string, vector<string>> accumulate_ngrams(const vector<string> &);

unordered_map<string, int> accumulate_frequency(unordered_map<string, vector<string>>);

#endif //WORDSUGGESTION_STRING_UTILS_H
