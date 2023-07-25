#include <bits/stdc++.h>
using namespace std;
int bad_solution (int A[], int size)
{
    //naive solution
    //O(n^3) solution
    int best = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                cout << "A[" << k << "] : " << A[k] << '\n';
                sum += A[k];
            }
            best = max (sum, best);
        }
    }
    return best;
}
int average_solution (int A[], int size)
{
    //moderate solution
    //O(n^2) solution
    int best = 0;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += A[j];
            best = max (best, sum);
        }
    }
    return best;
}
int best_solution (int A[], int size)
{
    //best solution
    //O(n) solution
    int best = 0, sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = max (A[i], sum + A[i]);
        best = max (best, sum);
    }
    return best;
}
int main ()
{
    int A[] = {-1, 2, 4, -3, 5, 2, -5, 2};
    int size = sizeof (A) / sizeof (A[0]);
    cout << bad_solution(A, size) << '\n';
    //cout << average_solution (A, size) << '\n';
    //cout << best_solution (A, size) << '\n';
    return 0;
}