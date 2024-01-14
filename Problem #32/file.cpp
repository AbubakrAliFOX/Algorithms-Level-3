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

bool IsVowel (char Charachter) {
    string Vowels = "aeiou";
    for (short i = 0; i < Vowels.length(); i++)
    {
        if (tolower(Vowels[i]) == tolower(Charachter)) {
            return true;
        }
    }
    return false;
}


int main()
{
    // string Sentence = ReadString();
    char Charachter = ReadChar();
 
    if(IsVowel(Charachter)) {
        cout << "Vowel" << endl;
    } else {
        cout << "Not Vowel" << endl;

    }
    return 0;
}