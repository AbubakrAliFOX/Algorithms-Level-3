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




int MatrixSum(int Matrix[3][3])
{
    int Sum = 0;
    cout << "The Matrix Sum:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Sum += Matrix[i][j];
        }
    }

    return Sum;
}


int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];
    CreateMatrix(Matrix);
    PrintMatrix(Matrix);

    cout << "The matrix sum is: " << MatrixSum(Matrix) << endl;
    return 0;
}