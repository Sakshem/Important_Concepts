//https://leetcode.com/problems/longest-substring-without-repeating-characters/
//given a string. Find the length of the longest substring without repeating characters.
#include <bits/stdc++.h>
using namespace std;
int firstSolution (string s)
{
    int n = s.length();
    int end = 0, answer = 0;
    set <int> inside;
    inside.insert (s[0]);
    for (int start = 0; start < n; start++)
    {
        while (end + 1 < n && !inside.count (s[end + 1])) 
        {
            end++;
            inside.insert (s[end]);
        }
        cout << "start is: " << start << " " << "end is: " << end << '\n';
        answer = max (answer, end - start + 1);
        inside.erase (s[start]);
    }
    return answer;
}
int secondSolution (string s)
{
    int characters [128] = {0};
    int start = 0, end = 0, answer = 0, n = s.length();
    while (end < n) {
        characters[s[end]]++;
        while (characters[s[end]] > 1) {
            characters[s[start]]--;
            start++;
        }
        answer = max (answer, end - start + 1);
        end++;
    }
    return answer;
}

int main ()
{
    string s;
    cin >> s;
    //sample inputs: abcabcbb, bbbbb, owwkew
    cout << firstSolution (s) << '\n';
    //cout << secondSolution (s) << '\n';
    return 0;
}