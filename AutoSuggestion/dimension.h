/* ************************************************* */
/* This file is a part of WordSuggestion project. */
/* Created by santa on 2022-03-30. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */


#include <string>
#include <set>
#include <unordered_map>

#include "string_utils.h"

#ifndef WORDSUGGESTION_DIMENSION_H
#define WORDSUGGESTION_DIMENSION_H

using namespace std;

class dimension {
public:
    dimension(unordered_map<string, vector<string>>);

    /**
     * Returns the count of all distinct grams.
     * @return number_of_dimensions
     */
    unsigned long number_of_dimensions();

    /**
     * Returns the count of words.
     */
     unsigned long count_words();

    /**
     * Displays all the entries of gram and their associated words.
     */
    void display_gram_words();

    /**
     * Display all the index based vectors.
     */
    void display_words_vector();

    /**
     * Make relevant suggestions for the partial word.
     */
    vector<pair<string, double>> suggest(string);

private:
    typedef int index;
    typedef double score;

    unordered_map<string, vector<string>> word_ngrams;
    unordered_map<string, index> gram_index;
    unordered_map<index, string> index_gram;
    unordered_map<string, vector<string>> gram_words;
    unordered_map<string, vector<pair<index, score>>> words_vector;
    unordered_map<string, vector<pair<string, score>>> word_ngram_scores;

    /**
     * Method to initialize all the gram indices.
     */
    void initialize_gram_indices();

    /**
     * Builds gram and their associations to the words,
     * it is used by the initialize method.
     */
    void build_gram_words();

    /**
     * Build Gram Indices.
     */
    void build_gram_indices();

    /**
     * Builds vectors of all words.
     */
    void build_word_vector();

    /**
     * Builds weights for all the word grams.
     */
     void build_weighted_word_ngrams();

     /**
      * Generate Input Vector.
      */
     vector<pair<int, score>> generate_input_vector(const vector <string> &);

    /**
     * Generate vector for list of grams.
     */
    vector<pair<index, score>> generate_vector(const vector<pair<string, double>> &);

    /**
    * Acquire all the word candidates to be compared with partial word vector.
    */
    set<string> acquire_candidates(const vector<string> &);

    /**
    * Sort the calculated scores by the value.
    */
    vector<pair<string, score>> filter_sort_by_score(const unordered_map<string, score> &);

    /**
    * Acquires all the candidate words with their vectors.
    */
    unordered_map<string, vector<pair<int, score>>> acquire_vectors(const set<string> &);

    /**
     * Take first k sorted elements.
     */
    vector<pair<string, double>> top_scored_words(const vector<pair<string, double>> &);

    /**
     * Computes the similarity and sends the sorted output.
     */
    unordered_map<string, double>
    compute_similarity(const unordered_map<string, vector<pair<int, score>>> &, const vector<pair<index, score>> &);
};

#endif //WORDSUGGESTION_DIMENSION_H
