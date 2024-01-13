#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
    string Str;
    cout << "Enter a sentence: " << endl;
    getline(cin, Str);

    return Str;
}

char ReadChar()
{
    char charachter;
    cout << "Enter a char: " << endl;
    cin >> charachter;

    return charachter;
}

void LetterInStringCounter(string Sentence, char Charachter) {
    int Counter = 0;
    for (short i = 0; i < Sentence.length(); i++)
    {
        Sentence[i] == Charachter && Counter ++;
    }

    cout << "You letter has " << Counter << " occurences in the string.";
    
}


int main()
{
    string Sentence = ReadString();
    char Charachter = ReadChar();
 
    LetterInStringCounter(Sentence,Charachter);
    return 0;
}