/* ************************************************* */
/* This file is a part of AutoSuggestion. */
/* Created by santa on 2022-03-28. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */
#include <malloc.h>
#include <cstring>
#include "text_utils.h"

/**
 * Returns the file size of the given name.
 */
long fileSizeOf(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("\nUnable to open file !");
        return 0L;
    }
    fseek(file, 0L, SEEK_END);
    long size = ftell(file);
    fclose(file);
    return size;
}

/**
 * Read all the text from the given file name and return the array of text(string).
 */
char *fileContentOf(const char *fileName) {
    long fileSize = fileSizeOf(fileName);
    if (fileSize <= 0L) {
        printf("\nNo file contents !");
        return 0L;
    }
    char *content = (char *) malloc(sizeof(char) * fileSize + 1);
    FILE *file = fopen(fileName, "r");
    char input = fgetc(file);
    int count = 0;
    for (; input != EOF; count++) {
        content[count] = input;
        input = fgetc(file);
    }
    content[count] = '\0';
    return content;
}

/**
 * Display in Console.
 */
/**
* Display array of strings in the Console.
*/
void displayTokens(char **items, long size, const char *message) {
    fprintf(stdout, "\n********************************************");
    fprintf(stdout, "\nTotal Entries : %ld", size);
    fprintf(stdout, "\n%s", message);
    for (int count = 0; count < size; count++) fprintf(stdout, "\n\t%s", *(items + count));
    fprintf(stdout, "\n********************************************");
}

/**
 * Display token container in console.
 */
void displayTokens(TokenContainer *tokenContainer, const char *message) {
    displayTokens(tokenContainer->entries, tokenContainer->size, message);
}

/**
 * Displays the Word and their associated grams.
 */
void displayWordGrams(WordGrams *wordGrams, const char *message) {
    fprintf(stdout, "\n********************************************");
    fprintf(stdout, "\nTotal Entries : %ld", wordGrams->count);
    fprintf(stdout, "\n%s", message);
    for (int count = 0; count < wordGrams->count; count++) {
        printf("\nWord: %s -> ", wordGrams->words[count]);
        printf("\t1.");
        for (int i = 0; i < wordGrams->tokenContainer[count]->size; i++) {
            printf("\t%s", wordGrams->tokenContainer[count]->entries[i]);
        }
    }
    fprintf(stdout, "\n********************************************");
}


