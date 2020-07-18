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
    cout << "This is a basic hangman game. A word will be generated that you have to guess." << endl
         << "You have 6 incorrect answer choices max to guess all the correct letters of the word." << endl;
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

    int randomNumber = rand() % numberOfLines;
    string randomWord = words.at(randomNumber);

    //cout << randomWord << endl;
    cout << "Okay so the random word from that genre of " << topic << " has " << randomWord.length() << " letters." << endl;
    cout << "You have 6 incorrect answer choices before you lose." << endl;
    
    int incorrectChoices;
    string letterChoice;
    
    while (incorrectChoices < 6 && /* we need a condition for if the word fills up */) {
        cout << "Please enter a letter" << endl;
        cin >> letterChoice;
        
        for (unsigned i = 0; i < randomWord.size(); ++i) {
            if (letterChoice == randomWord.at(i)) {
                cout << "You have made a correct choice" << endl;
                break;
            }
            
            cout << "Sorry, you selected an invalid letter" << endl;
            ++incorrectChoices;
        }
    }        
    
    //create extra arrays to keep track of choices and letters filled up?
    
    return 0;
}
