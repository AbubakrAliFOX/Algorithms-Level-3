#include <iostream>
#include <cstdlib>

using namespace std;

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

bool IsPalindromeMatrix(int Matrix1[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Matrix1[i][0] != Matrix1[i][2])
            {
                return false;
            }
            
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = {{1, 2, 1}, {0, 9, 0}, {9, 0, 9}};
    // int Matrix2[3][3] = {{1,2,3,}, {4,5,6}, {7,8,9}};

    PrintMatrix(Matrix1);

    if (IsPalindromeMatrix(Matrix1))
    {
        cout << "Palindrome Matrix";
    }
    else
    {
        cout << "Not Palindrome Matrix";
    }
    return 0;
}