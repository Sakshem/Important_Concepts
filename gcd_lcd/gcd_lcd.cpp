#include<bits/stdc++.h>
using namespace std;
// TC - O(log(min(a, b)))
int gcd(int a, int b) {
    // if b divides a completely then b is the gcd of a and b
    if (a % b == 0) return b;

    // else replace a with b and b with remainder of a and b
    return gcd(b, a % b);
}
// TC - O(max(a, b))
int lcd(int a, int b) {
    int c = a > b ? a : b;
    while (true) {
        if (c % a == 0 && c % b == 0) {
            return c;
        }
        c++;
    }
}
// TC - O(log(min(a, b)))
int _lcd(int a, int b) { //lcd or lcm with the help of gcd
    return (a * b) / gcd(a, b);

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << gcd(12, 8) << '\n';
    cout << lcd(12, 8) << '\n';
    cout << _lcd(12, 8) << '\n';
    return 0;
}
