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

bool FindNumberInMatrix(short Matrix[3][3], short Number)
{
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            if (Matrix[i][j] == Number)
            {
                return true;
            }
        }
    }
    return false;
}

void PrintIntersectingNumbers(short Matrix1[3][3], short Matrix2[3][3])
{
    cout << "Intersecting numbers are: " << endl;
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            if (FindNumberInMatrix(Matrix2, Matrix1[i][j]))
            {
                cout << Matrix1[i][j] << "\t";
            }
        }
    }
}

short FindSmallestNumber(short Matrix1[3][3])
{
    short Number = Matrix1[0][0];
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            if (Matrix1[i][j] < Number)
            {
                Number = Matrix1[i][j];
            }
        }
    }

    return Number;
}

short FindLargestNumber(short Matrix1[3][3])
{
    short Number = Matrix1[0][0];
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            if (Matrix1[i][j] > Number)
            {
                Number = Matrix1[i][j];
            }
        }
    }

    return Number;
}

int main()
{
    srand((unsigned)time(NULL));

    short Matrix1[3][3] = {{9, 12, 2}, {31, 18, 100}, {131, 101, 33}};
    // short Matrix2[3][3] = {{12, 13, 2}, {0, 9, 0}, {0, 0, 9}};
    PrintMatrix(Matrix1);

    cout << "Smallest Number is " << FindSmallestNumber(Matrix1) << endl;
    cout << "Largest Number is " << FindLargestNumber(Matrix1) << endl;

    return 0;
}