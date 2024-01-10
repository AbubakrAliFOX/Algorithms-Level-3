#include <iostream>
#include <cstdlib>

using namespace std;


int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void CreateRandomMatrix(int Matrix[3][3])
{   
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Matrix[j][i] = RandomNumber(1, 15);
        }
    }
}

void PrintMatrix(int Matrix[3][3], string Msg)
{
    cout << "\n" << Msg << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << Matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void MultiplyTwoMatrices(int Matrix1[3][3], int Matrix2[3][3]) {
    int Result[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Result[i][j] = Matrix1[i][j] * Matrix2[i][j];
        }
    }

    PrintMatrix(Result, "The result is: ");
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    int Matrix2[3][3];
    CreateRandomMatrix(Matrix1);
    CreateRandomMatrix(Matrix2);
    PrintMatrix(Matrix1, "Matrix 1: ");
    PrintMatrix(Matrix2, "Matrix 2: ");

    MultiplyTwoMatrices(Matrix1, Matrix2);
    return 0;
}