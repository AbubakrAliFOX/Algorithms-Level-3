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





bool AreMatreciesIdentical(int Matrix1[3][3], int Matrix2[3][3]) {
   for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Matrix1[i][j] != Matrix2[i][j]) {
                return false;
            }
        }
    }
    return true;
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


    if (AreMatreciesIdentical(Matrix1, Matrix2)) {
        cout << "Identical";
    } else {
        cout << "Not Identical";
    }
    return 0;
}