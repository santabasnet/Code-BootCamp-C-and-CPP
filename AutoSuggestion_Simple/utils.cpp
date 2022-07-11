/* ************************************************* */
/* This file is a part of WordSuggestion. */
/* Created by santa on 2022-03-26. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

/*
set<int> items = {60, 70, 50, 21, 9};
printf("\nSet Entries: ");
set<int>::iterator setIterator;
for (setIterator = items.begin(); setIterator != items.end(); setIterator++) {
cout << *setIterator << " ";
}
cout << "\tItems: " << items.size();
const bool present = items.find(500) != items.end();
cout << "\tIsPresent : " << present;


map<string, int> word_frequency = {
        {"eat", 30},
        {"run", 40}
};
word_frequency["location"] = 39;
word_frequency["compose"] = 10;
word_frequency.insert(pair<string, int>("compass", 100));

map<string, int>::iterator traverse;
cout << endl << "Word entries: " << endl;
for (traverse = word_frequency.begin(); traverse != word_frequency.end(); traverse++) {
cout << "Word: " << "(" << traverse->first << ", " << traverse->second << ")" << endl;
}
cout << endl << "Size: " << word_frequency.size();
const bool m_present = word_frequency.find("compose") != word_frequency.end();
cout << endl << "Is word present: " << m_present << endl;


vector<int> v1 = {40, 0, 45, 30, 20, 89, 90, 100, 5, 0};
vector<int> v2 = {20, 100, 6, 89, 999, 9, 900, 89, 50, 21};
cout << "Magnitude of v1: " << magnitude(v1) << endl;
cout << "Magnitude of v2: " << magnitude(v2) << endl;
cout << "Dot Product : " << dot_product(v1, v2) << endl;
cout << "Cos Theta: " << cos_theta(v1, v2) << endl;

list<string> words;
string a = "hello";


 char text[] = "Nepal";
 string country(text);
 cout<<"Text: "<< country;
 string s = "Testing";
 char *a = &(s[0]);


 //vector<int> sizes = {2, 3};
    int sizes[] = {2, 3};
    string country = "Nepal";
    vector<string> grams = gramsOf(country, sizes);
    vector<string>::iterator gramIter;
    for (gramIter = grams.begin(); gramIter != grams.end(); gramIter++) {
        cout << *gramIter << " ";
    }


    vector<string> words = {"684", "test", "xxx", "55", "ram", "east", "east", "55"};
    vector<string> randomWords = randomizedWords(words, 5);
    display_in_console(randomWords, "Random words: ");

    display_in_console(unique_words(words), "Unique Words: ");


    /**
     * Tests code.
     */
/*vector<pair<int, int>> v1 = {make_pair(1, 4), make_pair(2, 6), make_pair(5, 1)};
vector<pair<int, int>> v2 = {make_pair(2, 3), make_pair(1, 1), make_pair(4, 3)};
cout << endl << cos_theta(v1, v2);*/




