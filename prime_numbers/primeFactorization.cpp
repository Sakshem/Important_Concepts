 <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> primes; // global vector consisting of all prime numbers upto a certain number(computed by sieve method)
auto sieve (ll n)
{
    vector <bool> is_prime (n + 1, true);
    vector <ll> primeArray;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
             for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 0; i < is_prime.size (); i++)
    {
        if (is_prime[i] == true)
        primeArray.push_back (i);
    }
    return primeArray;
}
vector<ll> factors(ll x) { // with precomputed list of primes.
    vector<ll> ret;
    for (ll p : primes) { // precompute list of primes.
        if (p * p > x) {
            // checked all primes below p, now x can't be a product of two unchecked primes since 
            // p^2 > x, so x must be prime.
            if (x > 1) {
                ret.push_back(x);
                x = 1;
                break;
            }
        }
        else {
            while (x % p == 0) { // take as much of this prime as we have.
                ret.push_back(p);
                x /= p; // make sure to divide x, that makes the p^2 > x case work.
            }
        }
    }
    return ret;
}
vector<ll> wheelFactorization(ll n) { // wheel factorization method.
    vector<ll> factorization;
    while (n % 2 == 0) {
        factorization.push_back(2);
        n /= 2;
    }
    // Once we check that number is now no longer divisible by 2.
    // We now no longer need to check all the alternate even numbers.
    for (ll d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1) { // The left over number will be prime if it's greater than 1.
        factorization.push_back(n);
    }
    return factorization;
}
int main() {

    // create a precomputed array of prime numbers using sieve method.
    // then use the factors function to get all the list of prime numbers that are factors of that number x.
    primes = sieve(100);
    ll n;
    cout << "Enter the number to calculate it's factors: " << '\n';
    cin >> n;
    vector<ll> all_factors = factors(n);
    cout << '\n';
    cout << "All the factors of the number " << n << " using precomputed primes: " << '\n';
    for (auto factor : all_factors) {
        cout << factor << ' ';
    }
    cout << '\n';
    cout << "All the factors of the number " << n << " using wheel factorization: " << '\n';
    all_factors.clear();
    all_factors = wheelFactorization(n);
    for (auto factor : all_factors) {
        cout << factor << ' ';
    }
    cout << '\n';
    return 0;
}
