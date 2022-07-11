#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "vector_utils.h"
#include "string_utils.h"
#include "file_utils.h"
#include "dimension.h"

using namespace std;

/**
 * Main program starts from here.
 */
int main() {

    /*vector<string> words = {"changing", "discipline", "running", "t", "temperature", "initiated"};
    for (vector<string>::iterator a = words.begin(); a != words.end(); a++) {
        vector<string> grams(gramsOf(*a));
        display_in_console(grams, "Word Grams: ");
    }*/

    /* 1. Read all the words from the file. */
    cout << endl << "****************************************************";
    cout << endl << "Generating statistics ... ";
    string dictionary_file = "../resources/dictionary.txt";
    vector<string> wordList = read_from_file(dictionary_file);
    //display_in_console(wordList, "Dictionary Words: ");

    /* 2. Initialize sample words with sorted values. */
    vector<string> sampledWords = randomized_words(wordList, MAX_RANDOM_WORDS);
    //display_in_console(sampledWords, "Sampled Dictionary Words: ");

    /* 3. Initialize the word and their ngram dictionary. */
    unordered_map<string, vector<string>> word_ngrams = accumulate_ngrams(sampledWords);
    //display_in_console(word_ngrams, "Word and their associated grams: ");

    /* 4. Calculate ngram frequencies. */
    unordered_map<string, int> ngrams_frequency(accumulate_frequency(word_ngrams));
    //display_in_console(ngrams_frequency, "Gram Frequency Table : ");

    /**
     * 5. Initialize total dimensions and all the word vectors, I wrote this in the constructor.
     */
    dimension suggestion_system(word_ngrams, ngrams_frequency);
    cout << "Completed !";
    cout << endl << "****************************************************";
    //cout << endl << "Total Grams: " << suggestion_system.number_of_dimensions();
    //suggestion_system.display_gram_words();
    //suggestion_system.display_words_vector();

    while (true) {
        /* 6. Define input vector for a word. */
        string partial_word;
        cout << endl << "Enter a partial word: ";
        cin >> partial_word;

        /* 7. Get ranked words. */
        vector<pair<string, double>> suggested_words = suggestion_system.suggest(partial_word);
        display_in_console(suggested_words, "Suggested words with scores: ");

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
