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

char CapitilizeLetter(char Letter)
{
    return char(toupper(Letter));
}

void CapatilizeSentence(string Sentence)
{
    bool IsFirstLetter = true;

    for (short i = 0; i < Sentence.length(); i++)
    {
        if (Sentence[i] != ' ' && IsFirstLetter)
        {
            Sentence[i] = CapitilizeLetter(Sentence[i]);
        }


        IsFirstLetter = Sentence[i] == ' ';
    }

    cout << Sentence << endl;
}

int main()
{
    string Sentence = ReadString();

    CapatilizeSentence(Sentence);

    return 0;
}