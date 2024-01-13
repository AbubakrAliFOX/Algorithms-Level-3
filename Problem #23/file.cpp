#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
    string Str;
    cout << "Enter a sentence: " << endl;
    getline(cin, Str);

    return Str;
}

void PrintFirstLetterOfWord(string Sentence)
{
    bool FirstLetter = true;

    for (short i = 0; i < Sentence.length(); i++)
    {
        if (Sentence[i] != ' ' && FirstLetter)
        {
            cout << Sentence[i] << endl;
        }

        FirstLetter = Sentence[i] == ' ';
    }
}

int main()
{
    string Sentence = ReadString();

    PrintFirstLetterOfWord(Sentence);
    return 0;
}