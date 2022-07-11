/* ************************************************* */
/* This file is a part of SpellError. */
/* Created by santa on 2022-03-26. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#ifndef SPELLERROR_WORD_OPERATIONS_H
#define SPELLERROR_WORD_OPERATIONS_H

/**
 * Constant literals.
 */
const int TRUE = 1;
const int FALSE = 0;

/**
 * Data type definition.
 */
typedef struct {
    char **entries;
    long size;
} WordContainer;

int isPresent(WordContainer *, char *);

int isAbsent(WordContainer *, char *);

WordContainer *uniqueElements(WordContainer *);

WordContainer *differenceOf(WordContainer *, WordContainer *);

#endif //SPELLERROR_WORD_OPERATIONS_H
