#include <iostream>
#include <vector>
using namespace std;
//O(n^2) solution
void solve(int n) //naive solution to find the prime numbers between 1 to n
{
    bool flag = true;
    vector <int> isPrime;
    for (int i = 2; i <= n; i++) {
        flag = true;
        for (int j = 2; j < i; j++) { 
            if (i % j == 0) { flag = false; break; }
        }
        if (flag == true) 
            isPrime.push_back(i);
    }
    for (int i = 0; i < isPrime.size(); i++) cout << isPrime[i] << ' ';
    cout << '\n';
}
//O(n * (n)^1/2) or O(n * root of (n))
void solve2(int n)
{
    bool flag = true;
    vector <int> isPrime;
    for (int i = 2; i <= n; i++) {
        flag = true;
        for (int j = 2; (long long) j * j <= i; j++) { //(long long) to avoid overflows
            if (i % j == 0) { flag = false; break; }
        }
        if (flag == true) isPrime.push_back (i);
    }
    for (auto x : isPrime) { cout << x << " " ; }
    cout << '\n';
}
//sieve of eratosthenes method
//O(nlog(log n)) time complexity
auto sieve(int n)
{
    vector <bool> is_prime (n + 1, true);
    vector <int> primeArray;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
             for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 0; i < is_prime.size (); i++) {
        if (is_prime[i] == true)
            primeArray.push_back (i);
    }
    return primeArray;
}
int main()
{
    int n;
    cin >> n;
    //solve (n);
    //solve2 (n);
    vector <int> primeArray = sieve(n);
    for (int i = 0; i < primeArray.size(); i++) 
    cout << primeArray[i] << ' ';
    cout << '\n';
    return 0;
}
