#include <iostream>
#include <cstdlib>

using namespace std;

// int ReadPositiveNumber(string Msg)
// {
//     int Number;
//     do
//     {
//         cout << Msg << endl;
//         cin >> Number;
//     } while (Number <= 0);

//     return Number;
// }

int RandomNumber (int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void CreateMatrix (int Matrix[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           Matrix[i][j] = RandomNumber(1,200);
        }
        
    }
    
}

void PrintMatrix (int Matrix[3][3]) {
    cout << "The 3x3 Matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           cout << Matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];
    CreateMatrix(Matrix);
    PrintMatrix(Matrix);
    return 0;
}