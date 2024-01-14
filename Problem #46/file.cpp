#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;
string ReadString(string Msg)
{
    string Str;
    cout << Msg << "\n";
    getline(cin, Str);
    return Str;
}

int ReadNumber(string Msg)
{
    int Number;
    cout << Msg << "\n";
    cin >> Number;
    return Number;
}

struct User
{
    string Name;
    string AccNumber;
    int PinCode, PhoneNumber;
    float AccBalance;
};

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

User CreateUser(User UserData)
{
    UserData.Name = ReadString("Please Enter Name");
    UserData.AccNumber = ReadString("Please Enter Account Number");
    UserData.PinCode = ReadNumber("Please Enter Pin Code");
    UserData.PhoneNumber = ReadNumber("Please Enter PhoneNumber");
    UserData.AccBalance = ReadNumber("Please Enter Account Balance");

    return UserData;
}

string ConvertRecordToLine(User UserData, string Seperator)
{
    string ClientRecord = "";
    ClientRecord += UserData.Name + Seperator;
    ClientRecord += UserData.AccNumber + Seperator;
    ClientRecord += to_string(UserData.PinCode) + Seperator;
    ClientRecord += to_string(UserData.PhoneNumber) + Seperator;
    ClientRecord += to_string(UserData.AccBalance);
    return ClientRecord;
}

User ConvertLineToRecord(string DataLine, string Seperator)
{
    User UserData;
    vector<string> vData = split(DataLine, Seperator);

    UserData.Name = vData[0];
    UserData.AccNumber = vData[1];
    UserData.PinCode = stoi(vData[2]);
    UserData.PhoneNumber = stoi(vData[3]);
    UserData.AccBalance = stof(vData[4]);

    return UserData;
}

void PrintClientRecord(User UserData)
{
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccout Number: " << UserData.AccNumber;
    cout << "\nPin Code     : " << UserData.PinCode;
    cout << "\nName         : " << UserData.Name;
    cout << "\nPhone        : " << UserData.PhoneNumber;
    cout << "\nAccount Balance: " << UserData.AccBalance;
}


int main()
{
    User User1;
    // cout << ConvertRecordToLine(CreateUser(User1), "--");
    PrintClientRecord(ConvertLineToRecord("abubakr--14523--33332--507215259--5000.000000","--"));
    return 0;
}