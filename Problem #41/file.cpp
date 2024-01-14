#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;
string ReadString()
{
    string Str;
    cout << "Please Enter Your String?\n";
    getline(cin, Str);
    return Str;
}

vector<string> split(string Str, string Delim)
{

    short pos = 0;
    string sWord; // define a string variable  // use find() function to get the position of the delimiters
    short Counter = 0;
    vector<string> vWords;
    while ((pos = Str.find(Delim)) != std::string::npos)
    {
        sWord = Str.substr(0, pos); // store the word
        if (sWord != "")
        {
            vWords.push_back(sWord);
            Counter++;
        }
        Str.erase(0, pos + Delim.length()); /* erase() until positon and move to next word. */
    }
    if (Str != "")
    {
        vWords.push_back(Str); // it print last word of the string.
        Counter++;
    }

    return vWords;
}

vector<string> Reverse(vector<string> vWords)
{
    vector<string> Reversed;
    for (short i = 0; i < vWords.size(); i++)
    {
        Reversed.push_back(vWords[vWords.size() - 1 - i]);
    }

    return Reversed;
}

void PrintVectorTokens(vector<string> vWords)
{
    for (string &item : vWords)
    {
        cout << item << endl;
    }
}

string join(vector<string> vWords, string Delim)
{
    string Str;
    for (short i = 0; i < vWords.size(); i++)
    {
        Str = Str + vWords[i] + Delim;
    }

    return Str.substr(0, Str.length() - Delim.length());
}

int main()
{
    // vector<string> vWords = {"Ahmad", "Khaled", "Menza"};
    string Str = "I|am|from|Sudan|Bro";
    cout << join(Reverse(split(Str, "|")),"|");

    return 0;
}