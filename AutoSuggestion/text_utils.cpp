/* ************************************************* */
/* This file is a part of AutoSuggestion. */
/* Created by santa on 2022-03-28. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include "text_utils.h"
#include "file_utils.h"

/**
 * Converts a string to the lowercase representation.
 */
void toLowerCase(char *text) {
    for (int i = 0; text[i] != '\0'; i++) text[i] = tolower(text[i]);
}

/**
 * Calculates grams count for the given text and the gram size.
 * @return numberOfGrams.
 */
int gramsCount(char *text, int size) {
    return (int) strlen(text) - size + 1;
}

/**
 * Default Grams Size.
 */
int gramsSize() {
    return sizeof(GRAM_SIZES) / sizeof(GRAM_SIZES[0]);
}

/**
 * Substring implementation.
 */
char *subString(char *text, int begin, int size) {
    char *gram = (char *) malloc(sizeof(char) * size);
    strncpy(gram, text + begin, size);
    return gram;
}

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
    if ((lPadding + rPadding) != 0) {
        result = (char *) malloc(sizeof(char *) * (sourceLength - lPadding - rPadding));
        for (int i = lPadding; i < sourceLength - rPadding; ++i)
            result[i - lPadding] = text[i];
        result[sourceLength - lPadding - rPadding] = '\0';
    }
    return result;
}

/**
* Tokenizes String text to the list of words(character pointers of pointer)
*/
TokenContainer *tokenize(char *text, const char *delimiter) {
    TokenContainer *tokenContainer = (TokenContainer *) malloc(sizeof(TokenContainer));
    tokenContainer->entries = (char **) malloc(sizeof(char *) * MAX_SIZE);
    tokenContainer->size = 0L;
    char *token = strtok(text, delimiter);
    for (; token != NULL;) {
        *(tokenContainer->entries + tokenContainer->size) = (char *) malloc(strlen(token));
        strcpy(tokenContainer->entries[tokenContainer->size++], token);
        token = strtok(NULL, delimiter);
    }
    return tokenContainer;
}

/**
 * Tokenizes String text to the list of words with default delimiters.
 */
TokenContainer *tokenize(char *text) {
    return tokenize(text, DEFAULT_DELIMITER);
}

/**
 * Perform normalize operation of wordItems of text(string). In this case, make
 * all the lower case.
 */
char **normalizeText(char **wordItems, int size) {
    char **result = (char **) malloc(sizeof(char) * size);
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
 * Generate ngrams from a string token with the given size.
 */
TokenContainer *nGramsOf(char *word, int size) {
    if (strlen(word) < 1) return NULL;

    int grams = gramsCount(word, size);
    TokenContainer *ngramTokens = (TokenContainer *) malloc(sizeof(TokenContainer));
    ngramTokens->size = 0L;
    ngramTokens->entries = (char **) malloc(sizeof(char *) * grams);
    for (int index = 0; index < grams; index++) {
        char *gram = subString(word, index, size);
        *(ngramTokens->entries + ngramTokens->size) = (char *) malloc(sizeof(char) * size);
        strcpy(*(ngramTokens->entries + ngramTokens->size), gram);
        ngramTokens->size++;
    }

    return ngramTokens;
}

/**
 * Combines two array of strings and returns the combined array.
 */
char **combineStringArrays(char **firstArr, long firstCount, char **secondArr, long secondCount) {
    long totalItems = firstCount + secondCount;
    char **combined = (char **) malloc(sizeof(char *) * totalItems);
    for (int inner = 0; inner < firstCount; inner++) {
        *(combined + inner) = (char *) malloc(sizeof(char) * strlen(firstArr[inner]));
        strcpy(combined[inner], firstArr[inner]);
    }
    for (int inner = firstCount; inner < totalItems; inner++) {
        *(combined + inner) = (char *) malloc(sizeof(char) * strlen(secondArr[inner - firstCount]));
        strcpy(combined[inner], secondArr[inner - firstCount]);
    }
    return combined;
}

/**
 * Combine two token containers.
 */
TokenContainer *combineTokenContainers(TokenContainer *first, TokenContainer *second) {
    TokenContainer *resultTokens = (TokenContainer *) malloc(sizeof(TokenContainer));
    resultTokens->entries = combineStringArrays(first->entries, first->size, second->entries, second->size);
    resultTokens->size = first->size + second->size;
    return resultTokens;
}

/**
 * Generates all grams specified with sizes in default environment.
 */
TokenContainer *nGramsOf(char *word) {
    TokenContainer *ngramTokens = (TokenContainer *) malloc(sizeof(TokenContainer));
    ngramTokens->size = 0;
    ngramTokens->entries = NULL;
    if (strlen(word) > 0) {
        for (int index = 0; index < gramsSize(); index++) {
            TokenContainer *innerContainer = nGramsOf(word, GRAM_SIZES[index]);
            TokenContainer *combined = combineTokenContainers(ngramTokens, innerContainer);

            printf("\nWord: %s", word);
            displayTokens(combined, "Tokens  :");

            ngramTokens = (TokenContainer *) malloc(sizeof(TokenContainer));
            ngramTokens->entries = combined->entries;
            ngramTokens->size = combined->size;
        }
    }
    return ngramTokens;
}

/**
 * Generate array of unique random numbers with specified size.
 */
int *sampledNumbers(long size, int period) {
    int *numbers = (int *) malloc(sizeof(int) * size);
    srand(time(0));
    for (int count = 0; count < size; count++) {
        int flag = FALSE;
        long number;
        while (!flag) {
            flag = TRUE;
            number = rand() % period;
            for (int i = 0; i < count; i++) {
                if (numbers[i] == number) {
                    flag = FALSE;
                    break;
                }
            }
        }
        *(numbers + count) = (int) number;
    }
    return numbers;
}

/**
 * Samples and generates limited tokens.
 */
TokenContainer *sampledWords(TokenContainer *allWords, int numberOfWords) {
    int *sample = sampledNumbers(numberOfWords, MAX_SIZE);
    TokenContainer *resultWords = (TokenContainer *) malloc(sizeof(TokenContainer));
    resultWords->entries = (char **) malloc(sizeof(char *) * numberOfWords);
    for (int index = 0; index < numberOfWords; index++) {
        char *word = allWords->entries[sample[index]];
        *(resultWords->entries + index) = (char *) malloc(sizeof(char) * strlen(word));
        strcpy(resultWords->entries[index], word);
    }
    resultWords->size = numberOfWords;
    return resultWords;
}

/**
 * Generate word and their ngrams.
 */
WordGrams *accumulateWordGrams(TokenContainer *sampledWords) {
    WordGrams *allWordGrams = (WordGrams *) malloc(sizeof(WordGrams));
    allWordGrams->tokenContainer = (TokenContainer **) malloc(sizeof(TokenContainer *) * SAMPLE_SIZE);
    allWordGrams->words = (char **) malloc(sizeof(char *) * SAMPLE_SIZE);
    allWordGrams->count = 0L;
    for (int entry = 0; entry < sampledWords->size; entry++) {
        *(allWordGrams->words + entry) = (char *) malloc(sizeof(char) * strlen(sampledWords->entries[entry]));
        strcpy(allWordGrams->words[entry], sampledWords->entries[entry]);
        allWordGrams->tokenContainer[entry] = nGramsOf(sampledWords->entries[entry]);
    }
    allWordGrams->count = sampledWords->size;
    return allWordGrams;
}
