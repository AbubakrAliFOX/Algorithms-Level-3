#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const string FileName = "Bank.txt";

char ReadChar(string Msg)
{
    char charachter;
    cout << Msg << endl;
    cin >> charachter;

    return charachter;
}

string ReadString(string Msg)
{
    string Str;
    cout << Msg << "\n";
    getline(cin, Str);
    return Str;
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
    UserData.PinCode = vData[2];
    UserData.Phone = vData[3];
    UserData.AccountBalance = stof(vData[4]);

    return UserData;
}

void AddCustomersToFile(string LineData)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);

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

vector<User> GetUsersFromFile()
{
    fstream MyFile;
    vector<User> vAllUsersRecords;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            User CurrentUser = ConvertLineToRecord(Line, "##");
            vAllUsersRecords.push_back(CurrentUser);
        }

        MyFile.close();
    }

    return vAllUsersRecords;
}

void PrintClientRecord(User UserData)
{
    cout << "| " << setw(15) << left << UserData.AccountNumber;
    cout << "| " << setw(10) << left << UserData.PinCode;
    cout << "| " << setw(40) << left << UserData.Name;
    cout << "| " << setw(12) << left << UserData.Phone;
    cout << "| " << setw(12) << left << UserData.AccountBalance;
}

void PrintAllCustomer()
{
    vector<User> vAllUsers = GetUsersFromFile();

    cout << "\n\t\t\t\t\tClient List (" << vAllUsers.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    for (User &User : vAllUsers)
    {
        PrintClientRecord(User);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}

bool FindCustomer(string AccountNumber, User &CurrentUser)
{
    vector<User> vAllUsers = GetUsersFromFile();

    for (User &u : vAllUsers)
    {
        if (AccountNumber == u.AccountNumber)
        {
            CurrentUser = u;
            return true;
        }
    }

    return false;
}

void PrintCustomerSearchResult(string AccountNumber)
{
    User CurrentUser;

    if (FindCustomer(AccountNumber, CurrentUser))
    {
        PrintClientRecord(CurrentUser);
    }
    else
    {
        cout << "\n Client Not Found" << endl;
    }
}

void OverrideCutomersToFile(vector<User> vUsers)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out);

    if (MyFile.is_open())
    {
        for (User &u : vUsers)
        {
            MyFile << ConvertRecordToLine(u, "##") << "\n";
        }

        MyFile.close();
    }
}

void RemoveCustomerFromFile(string AccountNumber)
{
    vector<User> vAllUsers = GetUsersFromFile();
    vector<User> vUpdatedUsers;

    for (User &u : vAllUsers)
    {
        if (u.AccountNumber != AccountNumber)
        {
            vUpdatedUsers.push_back(u);
        }
    }

    OverrideCutomersToFile(vUpdatedUsers);
}

void DeleteCustomer(string AccountNumber)
{
    User CurrentUser;
    char Answer;

    if (FindCustomer(AccountNumber, CurrentUser))
    {
        PrintClientRecord(CurrentUser);
        cout << "\n\nWould you like to delete this customer? (y / n)" << endl;
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            RemoveCustomerFromFile(AccountNumber);
            cout << "Deleted Successfully!" << endl;
        }
    }
    else
    {
        cout << "\n Client Not Found" << endl;
    }
}

int main()
{
    string AccountNumber = ReadString("Please Enter Account Number: ");
    // CreateCustomers();
    // PrintAllCustomer();
    // PrintCustomerSearchResult(AccountNumber);
    DeleteCustomer(AccountNumber);
}