/* ************************************************* */
/* This file is a part of SpellError. */
/* Created by santa on 2022-03-26. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include "text_utility.h"
#include "word_operations.h"

/**
 * Implementation of text trim function, removes leading and trailing white spaces.
 */
char *trimText(char *text) {
    char *result;
    size_t sourceLength = strlen(text);
    if (sourceLength == 0) return text;
    int lPadding = 0;
    int rPadding = 0;
    while (isspace((unsigned char) text[lPadding])) ++lPadding;
    while (isspace((unsigned char) text[sourceLength - rPadding - 1])) ++rPadding;
    if (lPadding + rPadding != 0) {
        result = (char *) malloc(sizeof(char *) * (sourceLength - lPadding - rPadding));
        for (int i = lPadding; i < sourceLength - rPadding; ++i)
            result[i - lPadding] = text[i];
        result[sourceLength - lPadding - rPadding] = '\0';
    }
    return result;
}

/**
 * Tokenize the text string into array of strings by the given delimiter.
 */
WordContainer *tokenize(char *text, char *delimiter) {
    /*char **tokens = (char **) malloc(sizeof(char) * MAX_SIZE);
    char *token = strtok(text, delimiter);
    for (int count = 0; token != NULL; count++) {
        *(tokens + count) = (char *) malloc(strlen(token));
        strcpy(*(tokens + count), token);
        token = strtok(NULL, delimiter);
    }
    return tokens;*/
    WordContainer *wordContainer = (WordContainer *) malloc(sizeof(WordContainer));
    wordContainer->entries = (char **) malloc(sizeof(char) * MAX_SIZE);
    char *token = strtok(text, delimiter);
    int count = 0;
    for (; token != NULL; count++) {
        *(wordContainer->entries + count) = (char *) malloc(strlen(token));
        strcpy(*(wordContainer->entries + count), token);
        token = strtok(NULL, delimiter);
    }
    wordContainer->size = count;
    return wordContainer;
}

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
    char *content = (char *) malloc(sizeof(char*) * fileSize + 1);
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
 * Converts a string to the lowercase representation.
 */
void toLowerCase(char *text) {
    for (int i = 0; text[i] != '\0'; i++) text[i] = tolower(text[i]);
}

/**
 * Perform normalize operation of wordItems of text(string). In this case, make
 * all the lower case.
 */
char **normalizeText(char **wordItems, int size) {
    char **result = (char **) malloc(sizeof(char*) * size);
    for (int count = 0; count < size; count++) {
        char *holder = (char *) malloc(sizeof(char) * strlen(wordItems[count]));
        strcpy(holder, wordItems[count]);
        toLowerCase(holder);
        char *word = trimText(holder);
        *(result + count) = (char *) malloc(sizeof(char) * strlen(word));
        strcpy(*(result + count), word);
    }
    return result;
}

/**
 * Display array of strings in the Console.
 */
void displayWords(char **wordItems, long size, const char *message) {
    printf("\n********************************************");
    printf("\nTotal Words : %ld", size);
    printf("\n%s", message);
    for (int count = 0; count < size; count++)
        printf("\n\t%s", *(wordItems + count));
    printf("\n********************************************");
}

/**
 * Display word container.
 */
void displayWords(WordContainer *wordContainer, const char *message) {
    displayWords(wordContainer->entries, wordContainer->size, message);
}
