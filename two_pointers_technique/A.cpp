//two pointers concept and it's various applications
//Finding a pair whose sum is equal to x in a sorted array
#include <bits/stdc++.h>
using namespace std;
int naiveSolution (int A[], int size, int x) 
{
    //in this method
    //we will blindly iterate through the array in 
    //time complexity O(n^2) to find the sum of two elements = x
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (A[i] + A[j] == x)
            return 1;
        }
    }
    return 0;
}
int betterSolution (int A[], int size, int x)
{
    for (int i = 0, j = size - 1; i <= j;)
    {
        if (A[i] + A[j] == x) return 1;
        else if (A[i] + A[j] < x) i++;
        else if (A[i] + A[j] > x) j--;
    }
    return 0;
}
int main ()
{
    int A[] = {2, 3, 5, 8, 9, 10, 11};
    //int A[] = {8, 3, 6, 8}; //unsorted array for naiveSolution
    int size = sizeof (A) / sizeof (A[0]);
    int x = 17;
    //int x = 9;
    cout << naiveSolution (A, size, x) << '\n';
    cout << betterSolution (A, size, x) << '\n';
    return 0;
}
