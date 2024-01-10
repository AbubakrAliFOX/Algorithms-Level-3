#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void CreateMatrix(int Matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Matrix[i][j] = RandomNumber(1, 200);
        }
    }
}

void PrintMatrix(int Matrix[3][3])
{
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

void PrintArray(int arr[3])
{
    cout << "The Result:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void PrintMiddleRow(int Matrix[3][3])
{
    int Result[3];
    cout << "\n\nMiddle Row:" << endl;
    for (int i = 0; i < 3; i++)
    {
        Result[i] = Matrix[1][i];
    }
    PrintArray(Result);
}

void PrintMiddleCol(int Matrix[3][3])
{
    int Result[3];
    cout << "\n\nMiddle Column:" << endl;
    for (int i = 0; i < 3; i++)
    {
        Result[i] = Matrix[i][1];
    }
    PrintArray(Result);
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];
    CreateMatrix(Matrix);
    PrintMatrix(Matrix);

    PrintMiddleRow(Matrix);
    PrintMiddleCol(Matrix);
    return 0;
}