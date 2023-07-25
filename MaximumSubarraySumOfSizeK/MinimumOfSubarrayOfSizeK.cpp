#include<bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// #define check(a, i)  printf("a[%d]: %d\n", i, a[i])
#define ll long long int
const int nax = 1e9 + 7;
#define MAX_CHARS 256
void solve() {
    vector<int> A = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    vector<int> ans;
    int start = 0, end = 0;
    deque<int> q;
    while (end < A.size()) {
        while (!q.empty() && q.back() > A[end]) {
            q.pop_back();
        }
        q.push_back(A[end]);
        if (end - start + 1 < k) {
            end++;
        }
        else if (end - start + 1 == k) {
            ans.push_back(q.front());
            if (!q.empty() && q.front() == A[start]) {
                q.pop_front();
            }
            start++; end++;
        }
    }
    debug(ans);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}