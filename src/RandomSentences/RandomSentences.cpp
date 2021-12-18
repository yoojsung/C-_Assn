//  C++RandomSentences  ---   create a series of random sentences
//
//  Jaesung Yoo
// CIS54 C/C++ programming
// June 25th, 2021
#include <iostream>    // needed for cout
#include <cstdlib>     // needed for the random number generator
#include <ctime>       // needed to seed the random number generator
#include <cctype>      // needed for toupper()
#include <string>      // needed for C++ strings
using namespace std;

const char* noun[] =
{ "desk", "chair", "envelope", "car", "train", "bus", "boat",
  "elephant", "dog", "cat", "moose", "rabbit"
};
const char* article[] =
{
    "the", "a", "one", "some", "any"
};
const char* adjective[] =
{
    "brave", "orange", "fast", "slow", "smart", "blue", "cool", "big"
};
const char* verb[] =
{
    "drove", "jumped", "ran", "walked", "skipped", "hit", "punched", "moved", "thought"
};
const char* preposition[] =
{
    "to", "from", "over", "under", "on"
};
int nounCount = sizeof(noun) / sizeof(char*);
int articleCount = sizeof(article) / sizeof(char*);
int adjectiveCount = sizeof(adjective) / sizeof(char*);
int verbCount = sizeof(verb) / sizeof(char*);
int prepositionCount = sizeof(preposition) / sizeof(char*);

//article, adjective, noun, verb, preposition, article, adjective, noun
int main(int argc, const char* argv[])
{
    // declare the variables
    string sentence;        // C++ string object
    int selection;

    srand((unsigned int)time(0));    // seed the random number generator

    for (int i = 0; i < 20; i++)     // create and display 5 sentences
    {
        selection = rand() % articleCount;  // pick an article
        sentence = article[selection];    // use = to place the 1st word in the sentence
        sentence += " ";

        selection = rand() % adjectiveCount;  // pick an adjective
        sentence += adjective[selection];    // use += to add another word to sentence
        sentence += " ";

        selection = rand() % nounCount;  // pick a noun
        sentence += noun[selection];    // use += to add another word to sentence
        sentence += " ";               // use += to add a space after each word

        selection = rand() % verbCount;  // pick a verb
        sentence += verb[selection];    // use += to add another word to sentence
        sentence += " ";

        selection = rand() % prepositionCount;  // pick a preposition
        sentence += preposition[selection];    // use += to add another word to sentence
        sentence += " ";

        selection = rand() % articleCount;  // pick an article
        sentence += article[selection];    // use += to add another word to sentence
        sentence += " ";

        selection = rand() % adjectiveCount;  // pick an adjective
        sentence += adjective[selection];    // use += to add another word to sentence
        sentence += " ";

        selection = rand() % nounCount;  // pick a noun
        sentence += noun[selection];   // use += to add another word to sentence
        sentence += ".";               // use += to add a period after each word

        sentence[0] = toupper(sentence[0]);     // make 1st char capital letter
        cout << sentence << endl;               // display the sentence
    }

    return 0;
}
