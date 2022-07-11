/* ************************************************* */
/* This file is a part of SpellError. */
/* Created by Santa on 2022-03-25. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#ifndef SPELLERROR_TEXT_UTILITY_H
#define SPELLERROR_TEXT_UTILITY_H

#include "word_operations.h"

const int MAX_SIZE = 10000;

/**
 * Prototype definitions.
 */

char *trimText(char *);

char **normalizeText(char **, int);

void toLowerCase(char *);

void displayWords(char **, long,  const char *);

WordContainer *tokenize(char *, char *);

long fileSizeOf(const char *);

char *fileContentOf(const char *);

void displayWords(WordContainer *,  const char *);

#endif //SPELLERROR_TEXT_UTILITY_H
