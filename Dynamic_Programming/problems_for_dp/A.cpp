//https://codeforces.com/gym/302977/problem/A
#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
void test_case ()
{
    //without dp
    /*int n;
    cin >> n;
    if (n % 2 == 1) { cout << 0 << '\n'; return; }
    cout << (ll) pow (2, n / 2) << '\n';
    */
   //with dp
   int n;
   cin >> n;
   ll f[n + 1];
   f[0] = 1; //if there are 0 columns then it's already filled
   f[1] = 0; //if there is only 1 column then we can't fill it in any way.
   for (ll i = 2; i <= n; i++) {
       f[i] = 2 * f[i - 2];
   }
   cout << f[n] << '\n';
}
int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);
    test_case ();
    return 0;
}
