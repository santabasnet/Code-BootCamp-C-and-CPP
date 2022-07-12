#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "vector_utils.h"
#include "string_utils.h"
#include "file_utils.h"
#include "dimension.h"
#include "constant_literals.h"

using namespace std;

/**
 * Main program starts from here.
 */
int main() {

    /* 1. Read all the words from the file. */
    cout << endl << "****************************************************";
    cout << endl << "Generating statistics ... ";
    string dictionary_file = "../resources/dictionary.txt";
    vector<string> wordList = read_from_file(dictionary_file);

    /* 2. Initialize sample words with sorted values. */
    vector<string> sampledWords = randomized_words(wordList, MAX_RANDOM_WORDS);

    /* 3. Initialize the word and their ngram dictionary. */
    unordered_map<string, vector<string>> word_ngrams = accumulate_ngrams(sampledWords);

    /**
     * 4. Initialize total dimensions and all the word vectors, I wrote this in the constructor.
     */
    dimension suggestion_system(word_ngrams);
    cout << "Completed !";
    cout << endl << "****************************************************";

    while (true) {

        /* 6. Define input vector for a word. */
        string partial_word;
        cout << endl << "Enter a partial word: ";
        cin >> partial_word;

        /* 7. Get ranked words. */
        vector<pair<string, double>> suggested_words = suggestion_system.suggest(partial_word);
        display_in_console(suggested_words, "Suggested words with scores: ");

        /**
         * 8. Take a chance to run another epoch.
         */
        string choice;
        cout << endl << "Do you want to try another (Y/N) ? ";
        cin >> choice;
        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
        if (choice == "y" || choice == "yes") continue;
        break;
    }

    return 0;
}
/*--- End of Main ---*/
