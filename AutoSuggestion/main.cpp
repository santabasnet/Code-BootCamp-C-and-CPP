#include <cstdio>
#include <cstring>
#include "text_utils.h"
#include "file_utils.h"

/**
 * Global variable for File Names.
 */
const char dictionaryFile[] = "../resources/dictionary.txt";

/**
 * Word Auto Suggestion Project Demo In C.
 * @return 0 with successful output.
 */
int main() {
    /* 1. Read all the words from the file. */
    char *dictionaryContent = fileContentOf(dictionaryFile);
    //printf("%s", dictionaryContent);

    /* 2. Initialize sample words with sorted values. */
    TokenContainer *wordList = tokenize(dictionaryContent);
    //displayTokens(wordList, "WordList : ");
    TokenContainer *sample = sampledWords(wordList, SAMPLE_SIZE);
    //displayTokens(sample, "Sampled Word List: ");

    /**
     * 3. Generate word and their ngrams of sample words.
     */
    WordGrams *wordGrams = accumulateWordGrams(sample);
    //displayWordGrams(wordGrams, "NGrams of Sampled Words: ");

    char text[] = "nonprofit";
    TokenContainer *token = nGramsOf(text);
    displayTokens(token, "Tokens : ");

    //int *numbers = sampledNumbers(50L, 1000);
    //printf("\n");
    //for (int i = 0; i < 50; i++) printf("\t%d", numbers[i]);

    return 0;
}
