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

short CountWords(string Str)
{
    string delim = " "; // delimiter
    cout << "\nYour string wrords are: \n\n";
    short pos = 0;
    string sWord; // define a string variable  // use find() function to get the position of the delimiters
    
    short Counter = 0;
    while ((pos = Str.find(delim)) != std::string::npos)
    {
        sWord = Str.substr(0, pos); // store the word
        if (sWord != "")
        {
            cout << sWord << endl;
            Counter ++;
        }
        Str.erase(0, pos + delim.length()); /* erase() until positon and move to next word. */
    }
    if (Str != "")
    {
        cout << Str << endl; // it print last word of the string.
        Counter++;
    }
 
    return Counter;
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

void PrintVectorTokens(vector<string> vWords) {
    for (string &item : vWords)
    {
        cout << item << endl;
    }
    
}

int main()
{
    PrintVectorTokens(split(ReadString(), "v"));
}