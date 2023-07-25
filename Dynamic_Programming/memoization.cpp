#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
//we will use memoization dp for fibonacci series
//recursive dp
//top down apporach
ll N;
vector <ll> cached (20, -1);
ll f (ll n)
{
    if (n < 2)  return n;
    if (cached[n] != -1)
        return cached[n];
    cached[n] = f (n - 2) + f (n - 1);
    return cached[n];
}
int main()
{
    //suppose we have a fibonacci series function f(n) where n can be any number and we want to find f(n)
    //since we now for n >= 2, f(n) = f(n - 1) + f(n - 2)
    //and for n = 0 or 1, value of f(0) and f(1) is 0 and 1 respectively
    //so this a basic fibonacci series explanation
    //in general a fibonacci series looks like
    //{0, 1, 1, 2, 3, 5, 8, 13, 21, 34....}
    //so if we create a recursive function for finding f(n) value 
    //cout << f (3) << endl; here we will get 2 as answer cause if n = 3 that is element at 3rd index in the series is 2 (if index starts from 0)
    //but if we solve f (5) you can say that it will call the same function for f (3) and f (4) and in f (4) it will call f (3) AGAIN!
    //so in simple terms we are finding value of f (3) once again where we just found it 
    //so to prevent extra work we use a concept called memoization where we will store the value of f (n) if we don't know it yet 
    //so that in future if we need it again we can use it directly instead of recursively calling it.
    //fibonacci series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144....
    //N is the index here so if we write N = 6 it will return 8. As 8 is at index 6 here.
    //NOTE: again index here starts from 0.
    cin >> N;
    cout << f (N) << '\n';
    //time complexity before: O (2 ^ n)
    //time complexity after using memoization: O (n) (linear)
    //since we compute everything once.
    return 0;
}
