#include <iostream>
using namespace std;
int largestPowerOf2InRange(int n)
{
    int x = 0;
    while ((1 << x) <= n) x++;
    return x - 1;
}
int solution(int n)
{
    if (n == 0) return 0;
    int x = largestPowerOf2InRange(n);
    int bitsTill2ToThePowerOfX = x * (1 << (x - 1));
    int msb2xtoN = n - (1 << x) + 1;
    int rest = n - (1 << x);
    int ans = bitsTill2ToThePowerOfX + msb2xtoN + solution(rest);
    return ans;
}
int main()
{
    auto method1 = [&] (int n) -> int {
        // O(digits)
        int count = 0;
        while (n) {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    };
    auto method2 = [&] (int n) -> int {
        // O(setBitsInNum) //O(logn)
        int count = 0; 
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    };
    auto method3 = [&] (int n) -> int {
        // O(1)
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) count++;
        }
        return count;
    };
    cout << method1(6) << '\n';
    cout << method2(6) << '\n';
    cout << method3(6) << '\n';

    //counting total set bits from 1 to n.
    //https://www.youtube.com/watch?v=g6OxU-hRGtY
    int n;
    cout << "Enter a number to count set bits from 1 to n is: " << '\n';
    cin >> n;
    cout << solution(n) << '\n';
    return 0;
}