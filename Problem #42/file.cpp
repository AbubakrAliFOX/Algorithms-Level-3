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

string ReplaceStringMethod1(string Str, string Item, string Replace)
{
    short pos = Str.find(Item);
    string Before, After;
    while (pos != std::string::npos)
    {
        Before = Str.substr(0, pos);
        After = Str.substr(pos + Item.length(), Str.length() - 1);
        Str =  Before + Replace + After;
        pos = Str.find(Item);
    }
    return Str;
}

char LowercaseLetter(char Letter)
{
    return char(tolower(Letter));
}

string LowercaseSentence(string Sentence)
{

    for (short i = 0; i < Sentence.length(); i++)
    {
        Sentence[i] = LowercaseLetter(Sentence[i]);
    }

    return Sentence;
}

vector<string> split(string Str, string Delim) {

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
            Counter ++;
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

string join(vector<string> vWords, string Delim)
{
    string Str;
    for (short i = 0; i < vWords.size(); i++)
    {
        Str = Str + vWords[i] + Delim;
    }

    return Str.substr(0, Str.length() - Delim.length());
}

string ReplaceStringMethod2(string Str, string Item, string Replace, bool MatchCase = true)
{
    vector<string> vWords = split(Str, " ");

    for (string &i : vWords)
    {
        if (MatchCase) 
        {
            if (i == Item) {
                i = Replace;
            }
        } else {
            if (LowercaseSentence(i) == LowercaseSentence(Item)) {
                i = Replace;
            }
        }
        
    }
    
    return join(vWords, " ");
}

int main()
{
    string Str = "I will go out there now out";
    string Item = "Out";
    string Replace = "yeee";
    cout << ReplaceStringMethod2(Str, Item, Replace, false);

    return 0;
}