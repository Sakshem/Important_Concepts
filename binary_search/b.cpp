#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long int
//leetcode question
//leetcode.com/problems/sqrtx/
int main()
{
    //square root of a number without the sqrt operator
    //using binary search
    int x;
    scanf("%d", &x);
    ll l, m, r;
    l = 1;
    r = x;
    ll second = 0,ans = 0;
    while(l <= r)
    {
        m = l + (r - l)/2;
        cout << "m = " << m << endl;
        if(m * m == x)
        {
            ans = m;
            second = m;
            break;
        }
        else if(m * m < x)
        {
            ans = m;
            l = m + 1;
        }
        else if(m * m > x)
        {
            second = m;
            r = m - 1;
        }
   }
    cout << min(ans, second) << endl;
    return 0;
}
