/* ************************************************* */
/* This file is a part of ErrorWords. */
/* Created by santa on 2022-03-27. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#ifndef ERRORWORDS_TEXT_UTILS_H
#define ERRORWORDS_TEXT_UTILS_H

const int TRUE = 1;
const int FALSE = 0;

/**
 * Represents word count and their information.
 */
typedef struct {
    char **entries;
    long noOfWords;
} WordContainer;

/**
 * Converts text string to word container, list of words
 * and their count.
 */
WordContainer *listOfWord(char *, char *);

int displayContainer(WordContainer *, char *);

WordContainer *uniqueElements(WordContainer *);

int isPresent(WordContainer *, char *);

int isAbsent(WordContainer *, char *);

WordContainer *differenceOf(WordContainer *, WordContainer *);

#endif //ERRORWORDS_TEXT_UTILS_H
