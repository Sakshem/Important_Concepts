#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void test_case()
{
    //Given are two matrices
    //checking if the matrix multiplication of two matrices is possible or not.
    int n, m;
    cout << "Enter number of rows and column in first matrix: " << '\n';
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    cout << "Enter data in first matrix: " << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    cout << '\n';
    int p, q;
    cout << "Enter number of rows and column in second matrix: " << '\n';
    cin >> p >> q;
    vector<vector<int>> B(p, vector<int>(q));
    cout << "Enter data in second matrix: " << '\n';
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> B[i][j];
        }
    }
    cout << '\n';
    auto multiplication = [&] (vector<vector<int>>& A, vector<vector<int>>& B) -> vector<vector<int>>{
        //reminder: check whether two matrix multiplication is valid or not
        int w, x, y, z;
        w = (int)A.size(); //row of 1st matrix
        x = (int)A[0].size(); //column of 1st matrix
        y = (int)B.size(); //row of 2nd matrix
        z = (int)B[0].size(); //column of 2nd matrix
        assert(x == y); // to check once again column and row of 1st and 2nd matrix are same respectively.
        vector<vector<int>> C(w, vector<int>(z));
        for (int i = 0; i < w; i++) { // row of 1st matrix
            for (int j = 0; j < z; j++) { // column of 2nd matrix
                C[i][j] = 0;
                for (int k = 0; k < x; k++) { // could also write k < y (same)
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    };
    if (m != p) {
        cout << "Number of columns of first matrix does not match with number of rows of second matrix!" << '\n';
        cout << "Therefore, matrix multiplication is not possible!" << '\n';
    }
    else {
        vector<vector<int>> C = multiplication(A, B);
        cout << "resultant matrix size: " << C.size() << '\n';
        cout << "resultant matrix total columns: " << C[0].size() << '\n';
        cout << "Resultant matrix after multiplication is: " << '\n';
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < C[0].size(); j++) {
                cout << C[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}
int main()
{
    test_case();
    return 0;
}