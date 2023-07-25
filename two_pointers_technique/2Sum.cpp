#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    vector<int> V(n);
    for (auto& x : V) {
        cin >> x;
    }
    //Question:
    /*find two elements in the array whose
    target sum is equal to x.*/

    auto findAns = [&] (int x, vector<int> V) {
        sort (V.begin(), V.end());
        int i = 0, j = V.size() - 1;
        while (i <= j) {
            int num = x - V[i];
            if (V[j] < num) {
                return -1;
            }
            else if (V[j] == num) {
                cout << V[i] << " " << V[j] << '\n';
                return 0;
            }
            else if (V[j] > num) {
                j--;
            }
        }
    };
    return 0;
}