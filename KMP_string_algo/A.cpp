//KMP algorithm - Knuth-Morris-Pratt algorithm.
//if we are given a string s, find out a particular pattern in that string and return the index, if it exists.
#include <bits/stdc++.h>
using namespace std;
void naiveSolution (string s, string pattern)
{
    int i = 0, j = 0, count = 0, original_pos = 0;
    bool flag = true;
    //aaabaaaa
    //aab
    while (i < s.length() && j < pattern.length()) {
        if (s[i] != pattern[j]) {
            i = original_pos + 1;
            j = 0;
            count = 0;
            flag = true;
        }
        else if (s[i] == pattern[j]) {
            if (flag == true)
            original_pos = i;
            count++;
            i++;
            j++;
            flag = false;
        }
        if (count == pattern.length()) break;
        i++;
    }
    if (count == pattern.length()) {
        //cout << "pattern found at index: " << i - pattern.size() << '\n';
        cout << "pattern found at index: " << i << '\n';

    }
    else cout << "pattern not found!" << '\n';
}
void kmpAlgorithm (string s, string pattern)
{

}
int main ()
{
    string s = "aaabaaaa";
    string pattern = "aab";
    naiveSolution (s, pattern);
    return 0;
}
