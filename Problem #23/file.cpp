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
    cout << Sentence[0] << endl;

    for (short i = 0; i < Sentence.length(); i++)
    {
        if (Sentence[i] == ' ')
        {
            cout << Sentence[i + 1] << endl;
        }
    }
}

int main()
{
    string Sentence = ReadString();

    PrintFirstLetterOfWord(Sentence);
    return 0;
}