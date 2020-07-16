#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <vector>
#include <ctime>
#include <random>
using namespace std;
/*
    Basic Concept: Computer picks random word, user tries to guess that word
    Rules: 6 tries MAX (head, body, 2 arms, 2 legs)

*/

int main()
{
    string name;
    cout << "Hello Sir/Madam! What is your first name?" << endl;
    cin >> name;
    cout << "Nice to meet you " << name << "!" << endl;
    cout << endl;
    cout << "This is a basic hangman game. A word will be generated that you have to guess."
         << "You have 6 incorrect answer choices max to guess all the correct letters for the word" << endl;
    cout << endl;
    cout << "Pick your topic: " << endl
         << "- sports" << endl
         << "- cs (computer science)" << endl;
    cout << endl;

    string topic;
    cin >> topic;
    string fileName = " ";

    ifstream inFS;

    cout << endl;
    cout << "Okay so you picked: " << topic << endl;
    cout << endl;

    if (topic == "sports")
    {
        fileName = "sports.txt";
    }
    else if (topic == "cs")
    {
        fileName = "cs.txt";
    }

    inFS.open(fileName);

    if (!inFS.is_open())
    {
        return 0;
    }

    string word = "";
    vector<string> words;
    while (!inFS.eof())
    {
        inFS >> word;
        inFS.ignore();
        words.push_back(word);
    }

    inFS.close();

    return 0;
}