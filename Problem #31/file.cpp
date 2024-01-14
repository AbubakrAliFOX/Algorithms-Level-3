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

void LetterInStringCounter(string Sentence, char Charachter, bool MatchCase = true) {
    int Counter = 0;

    for (short i = 0; i < Sentence.length(); i++)
    {
        if(MatchCase) {
            (Sentence[i] == Charachter) && Counter++;
        } else {
            (tolower(Sentence[i]) == tolower(Charachter)) && Counter ++;
        }
    }

    cout << "You letter " << Charachter << ", " << char(toupper(Charachter)) <<" has " << Counter << " occurences in the string.";
    
}


int main()
{
    string Sentence = ReadString();
    char Charachter = ReadChar();
 
    LetterInStringCounter(Sentence,Charachter, false);
    return 0;
}