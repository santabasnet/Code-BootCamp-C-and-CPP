/* ************************************************* */
/* This file is a part of SpellError. */
/* Created by santa on 2022-03-26. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#include <malloc.h>
#include <string.h>
#include "word_operations.h"
#include "text_utility.h"


/**
 * Check if the given string is present in the array of strings or not.
 * (Membership check)
 */
int isPresent(WordContainer *wordContainer, char *word) {
    for (int count = 0; count < wordContainer->size; count++)
        if (strcmp(wordContainer->entries[count], word) == 0) return TRUE;
    return FALSE;
}

/**
 * Check if the given string is absent in the container array.
 */
int isAbsent(WordContainer *wordContainer, char *word) {
    return !isPresent(wordContainer, word);
}

/**
 * Find unique string elements from the array of string.
 */
WordContainer *uniqueElements(WordContainer *container) {
    if (container->size < 0) return container;
    WordContainer *wordContainer = (WordContainer *) malloc(sizeof(WordContainer));
    wordContainer->entries = (char **) malloc(sizeof(char) * MAX_SIZE);
    wordContainer->size = 0;
    for (int count = 0; count < container->size; count++) {
        if (isAbsent(wordContainer, container->entries[count])) {
            *(wordContainer->entries + wordContainer->size) = (char *) malloc(strlen(container->entries[count]));
            strcpy(*(wordContainer->entries + wordContainer->size), container->entries[count]);
            wordContainer->size++;
        }
    }
    return wordContainer;
}

/**
 * Find the set difference.
 */
WordContainer *differenceOf(WordContainer *from, WordContainer *to) {
    WordContainer *difference = (WordContainer *) malloc(sizeof(WordContainer));
    difference->entries = (char **) malloc(sizeof(char) * MAX_SIZE);
    difference->size = 0;

    for (int count = 0; count < from->size; count++) {
        if (isAbsent(to, from->entries[count])) {
            *(difference->entries + difference->size) = (char *) malloc(strlen(from->entries[count]));
            strcpy(*(difference->entries + difference->size), from->entries[count]);
            difference->size++;
        }
    }

    return difference;
}



