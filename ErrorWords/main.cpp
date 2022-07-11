#include <cstdio>
#include "file_utils.h"
#include "text_utils.h"

/**
 * Main program starts here.
 * @return 0 with successful execution.
 */
int main() {
    /**
     * 1. Read operation from a text file.
     */
    char fileName[] = "../resources/dictionary.txt";
    char inputFile[] = "../resources/input.txt";
    char *text = readFromFile(fileName);
    char *input = readFromFile(inputFile);
    /**
     * 2. Convert text (string) to unique words i.e. array of string.
     */
    char delimiter[10] = " \n,{},[]";
    WordContainer *dictionaryContainer = listOfWord(text, delimiter);
    WordContainer *uniqueDictionary = uniqueElements(dictionaryContainer);
    displayContainer(uniqueDictionary, "Dictionary Words: ");

    WordContainer *inputContainer = listOfWord(input, delimiter);
    WordContainer *uniqueInput = uniqueElements(inputContainer);
    displayContainer(uniqueInput, "InputWords: ");
    /**
     * 3. Calculate set difference.
     * Ww = Wi - Wd
     */
    WordContainer *wrongWords = differenceOf(uniqueInput, uniqueDictionary);

    /**
     * 4. Display the mis-spelled words.
     */
    displayContainer(wrongWords, "Wrong Words: ");
    return 0;
}
