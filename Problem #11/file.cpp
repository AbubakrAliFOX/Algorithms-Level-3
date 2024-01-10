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

bool IsMatrixEqual(int Matrix1[3][3], int Matrix2[3][3]) {
    return MatrixSum(Matrix1) == MatrixSum(Matrix2);
}


int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = {{1,2,3,}, {4,5,6}, {7,8,9}};
    int Matrix2[3][3] = {{1,2,3,}, {4,5,6}, {7,8,9}};

    // CreateMatrix(Matrix1);
    PrintMatrix(Matrix1);

    // CreateMatrix(Matrix2);
    PrintMatrix(Matrix2);

    cout << "The 1st matrix sum is: " << MatrixSum(Matrix1) << endl;
    cout << "The 2nd matrix sum is: " << MatrixSum(Matrix2) << endl;

    if (IsMatrixEqual(Matrix1, Matrix2)) {
        cout << "Equal";
    } else {
        cout << "Not Equal";
    }
    return 0;
}