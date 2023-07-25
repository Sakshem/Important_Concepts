#include<iostream>
#include<vector>
//leetcode question 
//https://leetcode.com/problems/find-smallest-letter-greater-than-target
using namespace std;
int main()
{
    vector<char> letters;
    char target = 'j';
    letters.push_back('c');
    letters.push_back('f');
    letters.push_back('j');
    int l = 0;
    int r = letters.size() - 1;
    int mid;
    char ans = letters[0];
    while(l <= r)
    {
        mid = l + (r - l)/2;
        if(letters[mid] > target)
        {
            ans = letters[mid];
            r = mid - 1;
            printf("letters[mid] >= target: ans = %c, letters[mid = %d] = %c, l = %d and r = %d\n", ans, mid, letters[mid], l, r);
        }
        else if(letters[mid] <= target)
        {
            l = mid + 1;
            printf("letters[mid] < target: ans = %c, letters[mid = %d] = %c, l = %d and r = %d\n", ans, mid, letters[mid], l, r);
        }

    }
    cout << ans << endl;
    return 0;
}
