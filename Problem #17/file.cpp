#include <iostream>
#include <cstdlib>

using namespace std;

int ReadNumber(string Msg)
{
    int Number;
    cout << Msg << endl;
    cin >> Number;

    return Number;
}

void PrintMatrix(short Matrix[3][3])
{
    cout << "The 3x3 Matrix:" << endl;
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            cout << Matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

short FindNumberInMatrix(short Matrix1[3][3], short Number)
{
    short Counter = 0;
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                Counter++;
            }
        }
    }
    return Counter;
}

bool FindNumberInMatrixOPTIMIZED(short Matrix1[3][3], short Number)
{
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    srand((unsigned)time(NULL));

    short Matrix1[3][3] = {{9, 0, 2}, {0, 9, 0}, {0, 0, 9}};
    PrintMatrix(Matrix1);

    short Number = ReadNumber("Enter a number: ");

    if (FindNumberInMatrix(Matrix1, Number) > 0)
    {
        cout << "It is there" << endl;
    }
    else
    {
        cout << "NOT there" << endl;
    }

    if (FindNumberInMatrixOPTIMIZED(Matrix1, Number))
    {
        cout << "It is there OPTIMIZED" << endl;
    }
    else
    {
        cout << "NOT there OPTIMIZED" << endl;
    }
    return 0;
}