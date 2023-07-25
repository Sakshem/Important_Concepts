
#include<bits/stdc++.h>
using namespace std;
int binToDecimal(vector<int>& binary) {
    int multiplier = 1, ans = 0;
    int j = 0;
    for (int i = binary.size() - 1; i >= 0; i--) {
        ans += binary[i] * pow(2, j);
        j++;
    }
    return ans;
}
int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += (num & 1);
        num >>= 1;
    }
    return count;
}
int main() {
    int n, set; cin >> n >> set;
    vector<int> binary(n, 1);
    int high = binToDecimal(binary);
    cout << "high: " << high << '\n';
    int cnt = 0;
    for (int i = 0; i <= high; i++) {
        int check = countSetBits(i);
        if (check == set) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}
