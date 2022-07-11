/* ************************************************* */
/* This file is a part of AutoSuggestion. */
/* Created by santa on 2022-03-28. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#ifndef AUTOSUGGESTION_FILE_UTILS_H
#define AUTOSUGGESTION_FILE_UTILS_H

#include "text_utils.h"

/**
 * Default file delimiters.
 */
#define DEFAULT_DELIMITER "\n,{},[]"

/**
 * Calculates the file size.
 */
long fileSizeOf(const char *);

/**
 * Reads the file content and returns the char pointer.
 */
char *fileContentOf(const char *);

/**
 * Displays the tokens in the console file.
 */
void displayTokens(char **items, long, const char *);

/**
 * Displays the TokenContainer in the console file.
 */
void displayTokens(TokenContainer *, const char *);

/**
 * Displays the Word and their associated grams.
 */
void displayWordGrams(WordGrams *, const char *);

#endif //AUTOSUGGESTION_FILE_UTILS_H
