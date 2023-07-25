#include <bits/stdc++.h>
using namespace std;
void reverse_string_vector (vector<string>& s)
{
    stack<string> st;
    string temp = "";
    for (string sentence : s) {
        if (sentence == " ") {
            temp.push_back(' ');
            st.push(temp);
            temp = "";
        }
        else {
            temp += sentence;
        }
    }
    if (!temp.empty()) {
        temp.push_back(' ');
        st.push(temp);
        temp = "";
    }
    s.clear();
    while (!st.empty()) {
        s.push_back(st.top());
        st.pop();
    }
}
void test_case() 
{
    //you are given a string and a vector of string sentence you have to reverse the words without reversing the characters in a word 
    //string s = "Hello how are you";
    vector<string> str = {"Hello", " ", "how", " ", "are", " ", "you"};
    //reverse both the strings as asked above.
    auto reverse_string = [&] (string& s) -> string {
        stack<string> st;
        string temp = "";
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == ' ') {
                temp.push_back(' ');
                st.push(temp);
                temp = "";
            }
            else {
                temp.push_back(s[i]);
            }
        }
        if (!temp.empty()) {
            temp.push_back(' ');
            st.push(temp);
            temp = "";
        }
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        return s;
    };

    cout << "Reversed form of string:\n" << reverse_string(s) << '\n';
    reverse_string_vector(str);
    cout << "Reversed form of vector of string:\n";
    for (auto s : str) {
        cout << s;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
