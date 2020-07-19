#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;
/*
    Basic Concept: Computer picks random word, user tries to guess that word
    Rules: 6 tries MAX (head, body, 2 arms, 2 legs)
*/

int main()
{
    cout << endl;
    cout << endl;
    cout << endl;
    string name = " ";
    cout << "Hello Sir/Madam! What is your first name?" << endl;
    cin >> name;

    cout << endl;
    cout << endl;
    cout << "Nice to meet you " << name << "!" << endl;
    
    cout << endl;
    cout << "This is a basic hangman game. A word will be generated that you have to guess." << endl
         << "You have 6 incorrect answer choices max to guess all the correct letters of the word." << endl;
    
    cout << endl;
    cout << endl;
    cout << "Pick your topic: " << endl
         << "- sports" << endl
         << "- cs (computer science)" << endl;
    cout << endl;

    string topic;
    cin >> topic;
    string fileName = " ";

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

    ifstream inFS;
    inFS.open(fileName);

    if (!inFS.is_open())
    {
        return 0;
    }

    int numberOfLines = 0;
    string word = "";
    vector<string> words;
    while (!inFS.eof())
    {
        inFS >> word;
        inFS.ignore();
        words.push_back(word);
        numberOfLines++;
    }

    inFS.close();

    //had to seed the random number to computer time using srand, rand() by itself was generating same number
    unsigned seed = time(0);
    srand(seed);
    int randomNumber = rand() % numberOfLines;
    //cout << randomNumber << endl;
    string randomWord = words.at(randomNumber);
    //cout << randomWord << endl;

    for (int unsigned i = 0; i < randomWord.size(); i++)
    {
        randomWord.at(i) = tolower(randomWord.at(i));
    }

    cout << "Okay so the random word from that genre of " << topic << " has " << randomWord.length() << " letters." << endl;
    cout << "You have 6 incorrect answer choices before you lose." << endl;

    int incorrectChoices = 0;
    char letterChoice = ' ';

    //newWord is the the word the user will eventually come up with.
    string newWord = "";

    //prepopulating newWord with dashes and the size of the randomWord
    for (int unsigned i = 0; i < randomWord.size(); i++)
    {
        newWord.push_back('-');
    }

    while (incorrectChoices <= 6 && newWord != randomWord)
    {
        cout << "Your word is this complete: " << newWord << endl;
        cout << endl;
        cout << "You have " << 6 - incorrectChoices << " incorrect answer choices remaining." << endl;

        cout << endl;
        cout << endl;

        cout << "Please guess a letter: " << endl;
        cin >> letterChoice;
        letterChoice = tolower(letterChoice);

        int index = randomWord.find(letterChoice);
        if (index != string::npos)
        {
            for (unsigned i = 0; i < randomWord.size(); ++i)
            {
                if (letterChoice == randomWord.at(i))
                {
                    newWord.at(i) = letterChoice;
                }
            }
            cout << endl;
            cout << "You have made a correct choice!" << endl;
            cout << endl;
        }
        else
        {
            cout << endl;
            cout << "Sorry, you selected an invalid letter." << endl;
            cout << endl;
            incorrectChoices++;
        }
    }

    if (incorrectChoices > 6)
    {
        cout << endl;
        cout << endl;
        cout << "Sorry you lost!" << endl;
        cout << "The correct word was " << randomWord << "!" << endl;
    }
    else
    {
        cout << endl;
        cout << endl;
        cout << "Congrats, you guessed the correct word, which was " << randomWord << ", and WON!" << endl;
    }

    return 0;
}