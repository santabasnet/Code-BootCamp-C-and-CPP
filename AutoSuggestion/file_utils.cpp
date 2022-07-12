/* ************************************************* */
/* This file is a part of WordSuggestion. */
/* Created by santa on 2022-03-27. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#include<iostream>
#include <fstream>
#include <cstring>
#include <list>
#include <set>
#include <iomanip>
#include "file_utils.h"
#include "string_utils.h"

/**
 * Tokenize string with the given DELIMITERS.
 */
vector<string> all_tokens(string const &text, const char *delimiter) {
    vector<string> tokens;
    char *token = strtok(const_cast<char *>(text.c_str()), delimiter);
    while (token != nullptr) {
        tokens.push_back(token);
        token = strtok(NULL, delimiter);
    }
    return tokens;
}

/**
 * Read all words from file.
 */
vector<string> read_from_file(string file_name) {
    vector<string> words;
    string word;
    ifstream inFile(file_name);
    while (getline(inFile, word)) {
        if (!word.empty()) {
            words.emplace_back(word);
        }
    }
    inFile.close();
    //string text = textStream.str();
    //char *delim = const_cast<char *>(DELIMITERS.c_str());
    //return all_tokens(text, delim);
    return words;
}

/**
 * Display List of Words in Console.
 */
void display_in_console(const vector<string> &words, string message) {
    cout << endl << "****************************************************" << endl;
    cout << message;
    cout << endl << "****************************************************" << endl;
    cout << "{";
    for (int i = 0; i < words.size(); i++) cout << endl << "\t" << words[i];
    cout << endl << "}";
    cout << endl << "****************************************************" << endl;
}

/**
 * Display All Indices.
 */
void display_in_console(const set<int> &words, string message) {
    cout << endl << "****************************************************" << endl;
    cout << message;
    cout << endl << "****************************************************" << endl;
    cout << "{";
    for (auto i = words.begin(); i != words.end(); i++) cout << endl << "\t" << *i;
    cout << endl << "}";
    cout << endl << "****************************************************" << endl;
}

/**
 * Display List of Words in Console.
 */
void display_in_console(vector<pair<int, int>> coefficients, string message) {
    cout << endl << "****************************************************" << endl;
    cout << message;
    cout << endl << "****************************************************" << endl;
    cout << "{";
    for (int i = 0; i < coefficients.size(); i++)
        cout << endl << "\t" << coefficients[i].first << "->" << coefficients[i].second;
    cout << endl << "}";
    cout << endl << "****************************************************" << endl;
}

/**
 * Display List of Words in Console.
 */
void display_in_console(list<string> words, string message) {
    cout << endl << "****************************************************" << endl;
    cout << message;
    cout << endl << "****************************************************" << endl;
    list<string>::iterator words_iter = words.begin();
    for (; words_iter != words.end(); words_iter++) cout << *words_iter << "\t";
    cout << endl << "****************************************************" << endl;
}

/**
 * Display gram/word frequency in the console.
 */
void display_in_console(const vector<pair<string, int>> &word_frequency, string message) {
    cout << endl << "****************************************************" << endl;
    cout << message;
    cout << endl << "****************************************************" << endl;
    vector<pair<string, int>>::const_iterator frequency_iter = word_frequency.begin();
    for (; frequency_iter != word_frequency.end(); frequency_iter++) {
        cout << endl << "\t" << setw(16) << frequency_iter->first << " -> " << setw(4) << frequency_iter->second;
    }
    cout << endl << "****************************************************" << endl;
}

/**
 * Display gram/word frequency in the console.
 */
void display_in_console(const unordered_map<string, int> &word_frequency, string message) {
    cout << endl << "****************************************************" << endl;
    cout << message;
    cout << endl << "****************************************************" << endl;
    unordered_map<string, int>::const_iterator frequency_iter = word_frequency.begin();
    for (; frequency_iter != word_frequency.end(); frequency_iter++) {
        cout << endl << "\t" << setw(16) << frequency_iter->first << " -> " << setw(4) << frequency_iter->second;
    }
    cout << endl << "****************************************************" << endl;
}

/**
 * Displays calculated scores in the console.
 */
void display_in_console(const unordered_map<string, double> &word_scores, string message) {
    cout << endl << "****************************************************" << endl;
    cout << message;
    cout << endl << "****************************************************" << endl;
    unordered_map<string, double>::const_iterator score_iter = word_scores.begin();
    for (; score_iter != word_scores.end(); score_iter++) {
        cout << endl << "\t" << setw(16) << score_iter->first << " -> " << setw(4) << score_iter->second;
    }
    cout << endl << "****************************************************" << endl;
}

/**
 * Displays calculated scores in the console.
 */
void display_in_console(const vector<pair<string, double>> &word_scores, string message) {
    cout << endl << "****************************************************" << endl;
    cout << message;
    cout << endl << "****************************************************" << endl;
    auto score_iter = word_scores.begin();
    for (; score_iter != word_scores.end(); score_iter++) {
        cout << endl << "\t" << setw(16) << score_iter->first << " -> " << setw(4) << score_iter->second;
    }
    cout << endl << "****************************************************" << endl;
}

/**
 * Displays calculated scores in the console.
 */
void display_in_console(const vector<pair<int, double>> &word_scores, string message) {
    cout << endl << "****************************************************" << endl;
    cout << message;
    cout << endl << "****************************************************" << endl;
    auto score_iter = word_scores.begin();
    for (; score_iter != word_scores.end(); score_iter++) {
        cout << endl << "\t" << setw(10) << score_iter->first << " -> " << setw(4) << score_iter->second;
    }
    cout << endl << "****************************************************" << endl;
}



/**
 * Display Word NGrams in Console.
 */
void display_in_console(const unordered_map<string, vector<string>> &word_ngrams, string message) {
    cout << endl << "****************************************************" << endl;
    cout << message;
    cout << endl << "****************************************************" << endl;
    unordered_map<string, vector<string>>::const_iterator words_iter;
    for (words_iter = word_ngrams.begin(); words_iter != word_ngrams.end(); words_iter++) {
        cout << words_iter->first << ":" << endl << "\t{" << endl;
        vector<string>::const_iterator grams_iterator = words_iter->second.begin();
        for (; grams_iterator != words_iter->second.end(); grams_iterator++) {
            cout << endl << "\t\t" << *grams_iterator;
        }
        cout << endl << "\t}" << endl;
    }
    cout << endl << "****************************************************" << endl;
}

/**
 * Display all the vectors of dictionary words.
 */
void display_in_console(const unordered_map<string, vector<pair<string, double>>> &words_weights, string message) {
    cout << endl << "****************************************************" << endl;
    cout << message;
    cout << endl << "****************************************************" << endl;
    for (auto words_iter = words_weights.begin(); words_iter != words_weights.end(); words_iter++) {
        cout << words_iter->first << ":" << endl << "\t{" << endl;
        auto vector_iter = words_iter->second.begin();
        for (; vector_iter != words_iter->second.end(); vector_iter++) {
            cout << endl << "\t\t(" << vector_iter->first << "->" << vector_iter->second << ")";
        }
        cout << endl << "\t}" << endl;
    }
    cout << endl << "****************************************************" << endl;
}


/**
 * Display all the vectors of dictionary words.
 */
void display_in_console(const unordered_map<string, vector<pair<int, double>>> &words_vector, string message) {
    cout << endl << "****************************************************" << endl;
    cout << message;
    cout << endl << "****************************************************" << endl;
    for (auto words_iter = words_vector.begin(); words_iter != words_vector.end(); words_iter++) {
        cout << words_iter->first << ":" << endl << "\t{" << endl;
        auto vector_iter = words_iter->second.begin();
        for (; vector_iter != words_iter->second.end(); vector_iter++) {
            cout << endl << "\t\t(" << vector_iter->first << "->" << vector_iter->second << ")";
        }
        cout << endl << "\t}" << endl;
    }
    cout << endl << "****************************************************" << endl;
}
