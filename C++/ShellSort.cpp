#include <iostream>
using namespace std;

void ShellSort(int *A, int n)
{
    int gap, i , j, temp;

    for ( gap = n/2; gap >= 1; gap/=2) // this loop control the passes
    {
        for ( i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            // For shifting all the elements
            while (j >= 0 && A[j] > temp)
            {
                A[j+gap] = A[j];
                j = j - gap;
            }
            A[j+gap] = temp;
        }
    }
}

int main()
{
    int A[] = {3, 7, 3, 10, 6, 6, 12, 4, 11, 2}, n = 10;
    ShellSort(A, n);
    for (int i = 0; i < n - 1; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
