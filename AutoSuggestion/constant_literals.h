/* ************************************************* */
/* This file is a part of WordSuggestion project. */
/* Created by santa on 2022-04-02. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#include <string>
#include <vector>

using namespace std;

#ifndef WORDSUGGESTION_CONSTANT_LITERALS_H
#define WORDSUGGESTION_CONSTANT_LITERALS_H

const string DELIMITERS(" |,: \n\r\t\f\v{}[]^%#!.*+=-/");

const int MAX_RANDOM_WORDS = 2500;

const vector<int> DEFAULT_GRAM_SIZES = {2, 3};

#endif //WORDSUGGESTION_CONSTANT_LITERALS_H
