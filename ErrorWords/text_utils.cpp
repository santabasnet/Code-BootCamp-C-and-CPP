/* ************************************************* */
/* This file is a part of ErrorWords. */
/* Created by santa on 2022-03-27. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#include <cstring>
#include <malloc.h>
#include "text_utils.h"
#include "file_utils.h"

/**
 * Converts text string to word container, list of words
 * and their count.
 */
WordContainer *listOfWord(char *text, char *delimiter) {
    WordContainer *wordContainer = (WordContainer *) malloc(sizeof(WordContainer));
    wordContainer->entries = (char **) malloc(sizeof(char*) * MAX_SIZE);
    char *token = strtok(text, delimiter);
    int count = 0;
    for (; token != NULL; count++) {
        *(wordContainer->entries + count) = (char *) malloc(strlen(token));
        strcpy(*(wordContainer->entries + count), token);
        token = strtok(NULL, delimiter);
    }
    wordContainer->noOfWords = count;
    return wordContainer;
}

/**
 * Check if the given string is present in the array of strings or not.
 * (Membership check)
 */
int isPresent(WordContainer *wordContainer, char *word) {
    for (int count = 0; count < wordContainer->noOfWords; count++)
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
    if (container->noOfWords < 0) return container;
    WordContainer *wordContainer = (WordContainer *) malloc(sizeof(WordContainer));
    wordContainer->entries = (char **) malloc(sizeof(char*) * MAX_SIZE);
    wordContainer->noOfWords = 0;
    for (int count = 0; count < container->noOfWords; count++) {
        if (isAbsent(wordContainer, container->entries[count])) {
            *(wordContainer->entries + wordContainer->noOfWords) = (char *) malloc(strlen(container->entries[count]));
            strcpy(*(wordContainer->entries + wordContainer->noOfWords), container->entries[count]);
            wordContainer->noOfWords++;
        }
    }
    return wordContainer;
}

/**
 * Displays the list of words.
 */
int displayContainer(WordContainer *container, char message[]) {
    printf("\n********************************************");
    printf("\n%s", message);
    printf("\n********************************************");
    printf("\nTotal Words : %ld", container->noOfWords);
    for (int count = 0; count < container->noOfWords; count++)
        printf("\n\t%s", *(container->entries + count));
    printf("\n********************************************");
}

WordContainer *differenceOf(WordContainer *from, WordContainer *to) {
    WordContainer *difference = (WordContainer *) malloc(sizeof(WordContainer));
    difference->entries = (char **) malloc(sizeof(char*) * MAX_SIZE);
    difference->noOfWords = 0;
    for (int count = 0; count < from->noOfWords; count++) {
        if (isAbsent(to, from->entries[count])) {
            *(difference->entries + difference->noOfWords) = (char *) malloc(strlen(from->entries[count]));
            strcpy(*(difference->entries + difference->noOfWords), from->entries[count]);
            difference->noOfWords++;
        }
    }
    return difference;
}

