/**
 * Finding all the misspelled words against to dictionary lookup.
 */

#include <stdio.h>
#include "text_utility.h"
#include "word_operations.h"

/**
 * Program entry point, returns 0 after successful operation.
 * @return 0, for successful operation.
 */
int main() {
    /**
     * 1. Read File Content from input text and dictionary file.
     * Relative path for the file name may vary with the working
     * environment.
     */
    char inputFile[] = "../resources/input.txt";
    char dictionaryFile[] = "../resources/dictionary.txt";
    char *fileContent = fileContentOf(inputFile);
    char *dictContent = fileContentOf(dictionaryFile);

    /**
     * 2. Extract unique words from dictionary content as well as input content.
     */
    char delimiter[16] = " -.\"[]{}(),\n/\t";
    WordContainer *dictWords = uniqueElements(tokenize(dictContent, delimiter));
    displayWords(dictWords, "Dictionary Entries");
    WordContainer *uniqueContainer = uniqueElements(tokenize(fileContent, delimiter));
    displayWords(uniqueContainer, "Unique Words: ");

    /**
     * 3. Extract Unique wrong words by take difference from text to dictionary.
     */
    WordContainer *wrongWords = differenceOf(uniqueContainer, dictWords);

    /**
     * 4. Finally display the wrong words.
     */
    displayWords(wrongWords, "All Wrong Words");
    return 0;
}
