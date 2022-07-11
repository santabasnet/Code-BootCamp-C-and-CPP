/* ************************************************* */
/* This file is a part of AutoSuggestion. */
/* Created by santa on 2022-03-28. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#ifndef AUTOSUGGESTION_TEXT_UTILS_H
#define AUTOSUGGESTION_TEXT_UTILS_H

/**
 * Constant Literals.
 */
const int MAX_SIZE = 10000;

/**
 * Const Literal for Sample size.
 */
const int SAMPLE_SIZE = 50;

/**
 * Boolean Literals.
 */
const int FALSE = 0;
const int TRUE = 1;

/**
 * Default NGrams.
 */
const int GRAM_SIZES[2] = {2, 3};

/**
 * Linked List to Read Data.
 */
struct Words {
    char *entry;
    struct Words *next;
};

/**
 * Data type definition.
 */
typedef struct {
    char **entries;
    long size;
} TokenContainer;

/**
 * All Words and their generated tokens.
 */
typedef struct {
    char **words;
    TokenContainer **tokenContainer;
    long count;
} WordGrams;

/**
 * Calculates grams count for the given text and the gram size.
 * @return numberOfGrams.
 */
int gramsCount(char *, int);

/**
 * Implementation of text trim function, removes leading and trailing white spaces.
 */
char *trimText(char *);

/**
 * Returns the indices of grams size.
 */
int gramsSize();

/**
 * Converts a string to the lowercase representation with address
 * reference.
 */
void toLowerCase(char *);

/**
* Tokenizes String text to the list of words(character pointers of pointer)
*/
TokenContainer *tokenize(char *, const char *);

/**
 * Perform tokenization with default delimiters.
 */
TokenContainer *tokenize(char *);

/**
 * Perform normalize operation of wordItems of text(string). In this case, make
 * all the lower case.
 */
char **normalizeText(char **, int);

/**
 * Generate ngrams from a string token with the given size.
 */
TokenContainer *nGramsOf(char *, int);

/**
 * Generates all grams specified with sizes in default environment.
 */
TokenContainer *nGramsOf(char *);

/**
 * Merge two arrays of strings with given sizes.
 */
char **combineStringArrays(char **, long, char **, long);

/**
 * Join two token containers.
 */
TokenContainer *combineTokenContainers(TokenContainer *, TokenContainer *);

/**
 * Generate array of unique random numbers with specified size.
 */
int *sampledNumbers(long, int);

/**
 * Perform the random sampling to extract words of given size.
 */
TokenContainer *sampledWords(TokenContainer *, int);

/**
 * Generate word and their ngrams.
 */
WordGrams *accumulateWordGrams(TokenContainer *);

#endif //AUTOSUGGESTION_TEXT_UTILS_H
