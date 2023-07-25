#include <bits/stdc++.h>
using namespace std;
/*int *mergingArrays (int A[], int B[], n, m)
{
    static int C[m + n], k = 0;
    //here we merge two arrays
    for (int i = 0, j = 0; i < n || j < m;)
    {
        if (A[i] <= B[i]) { C[i] = A[i]; i++; }
        else if (A[j] > B[j]) { C[j] = B[j]; j++; }
    }
    return C;
}*/
int main ()
{
    int n, m;
    cout << "Enter the size of the first vector!" << '\n';
    cin >> n;
    cout << "Enter the size of the second vector!" << '\n';
    cin >> m;
    vector <int> A(n), B(m);

    cout << "Enter elements in sorted order inside the first vector" << '\n';
    for (auto& x : A) cin >> x;

    cout << "Enter elements in sorted order inside the second vector" << '\n';
    for (auto& x : B) cin >> x;

    auto merge = [&] (vector <int>& A, vector <int>& B, int n, int m) {
        //merging to sorted arrays
        vector <int> C;
        for (int i = 0, j = 0; i < n || j < m;) 
        {
            if (A[i] <= B[j]) 
            {
                C.push_back (A[i]);
                i++; 
            }
            else if (A[i] > B[j]) 
            { 
                C.push_back (B[j]);
                j++;
            }
        }
        return C;
    };
    vector <int> C = merge (A, B, n, m);
    cout << "The merged sorted array is: " << '\n';
    for (int i = 0; i < C.size (); i++) { cout << C[i] << ' '; }
    cout << '\n';
    return 0;
}
