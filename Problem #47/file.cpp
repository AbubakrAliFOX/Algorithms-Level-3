#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>

using namespace std;
string ReadString(string Msg)
{
    string Str;
    cout << Msg << "\n";
    getline(cin >> ws, Str);
    return Str;
}

char ReadChar(string Msg)
{
    char charachter;
    cout << Msg << endl;
    cin >> charachter;

    return charachter;
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
    string AccountNumber, PinCode, Phone;
    float AccountBalance;
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

User CreateUser()
{
    User UserData;
    cout << "Enter Account Number? "; // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, UserData.AccountNumber);
    cout << "Enter PinCode? ";
    getline(cin, UserData.PinCode);
    cout << "Enter Name? ";
    getline(cin, UserData.Name);
    cout << "Enter Phone? ";
    getline(cin, UserData.Phone);
    cout << "Enter AccountBalance? ";
    cin >> UserData.AccountBalance;

    return UserData;
}

string ConvertRecordToLine(User UserData, string Seperator)
{
    string ClientRecord = "";
    ClientRecord += UserData.Name + Seperator;
    ClientRecord += UserData.AccountNumber + Seperator;
    ClientRecord += UserData.PinCode + Seperator;
    ClientRecord += UserData.Phone + Seperator;
    ClientRecord += to_string(UserData.AccountBalance);
    return ClientRecord;
}

User ConvertLineToRecord(string DataLine, string Seperator)
{
    User UserData;
    vector<string> vData = split(DataLine, Seperator);

    UserData.Name = vData[0];
    UserData.AccountNumber = vData[1];
    UserData.PinCode = stoi(vData[2]);
    UserData.Phone = stoi(vData[3]);
    UserData.AccountBalance = stof(vData[4]);

    return UserData;
}

void PrintClientRecord(User UserData)
{
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccout Number: " << UserData.AccountNumber;
    cout << "\nPin Code     : " << UserData.PinCode;
    cout << "\nName         : " << UserData.Name;
    cout << "\nPhone        : " << UserData.Phone;
    cout << "\nAccount Balance: " << UserData.AccountBalance;
}

void AddCustomersToFile(string LineData)
{
    fstream MyFile;

    MyFile.open("Bank.txt", ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << LineData << "\n";
        MyFile.close();
    }
}

void CreateCustomers()
{
    char Answer;
    short Counter = 0;
    do
    {
        User CurrentUser;
        ++Counter;
        cout << "\n\nAdding Customer " << Counter << " : \n\n";

        string CustomerLineData = ConvertRecordToLine(CreateUser(), "##");
        AddCustomersToFile(CustomerLineData);

        Answer = ReadChar("Do you want to add more users? (y / n)");

    } while (Answer == 'y' || Answer == 'Y');
}

int main()
{

    CreateCustomers();
    User User1;
    // cout << ConvertRecordToLine(CreateUser(User1), "--");
    // PrintClientRecord(ConvertLineToRecord("abubakr--14523--33332--507215259--5000.000000", "--"));
    return 0;
}