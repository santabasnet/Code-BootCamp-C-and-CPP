/* ************************************************* */
/* This file is a part of WordSuggestion. */
/* Created by santa on 2022-03-27. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#include <string>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

#ifndef WORDSUGGESTION_FILE_UTILS_H
#define WORDSUGGESTION_FILE_UTILS_H

const string DELIMITERS(" |,: \n\r\t\f\v{}[]^%#!.*+=-/");

vector<string> read_from_file(string);

void display_in_console(const vector<pair<int, int>> &, string);

void display_in_console(const vector<string>&, string);

void display_in_console(const list<string>&, string);

void display_in_console(const vector<pair<string, double>> &, string);

void display_in_console(const unordered_map<string, int> &, string);

void display_in_console(const unordered_map<string, double>&, string);

void display_in_console(const unordered_map<string, vector<string>> &, string);

void display_in_console(const unordered_map<string, vector<pair<int, int>>> &, string);

vector<string> all_tokens(string const &, const char *);

#endif //WORDSUGGESTION_FILE_UTILS_H
