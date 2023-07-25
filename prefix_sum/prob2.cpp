// problem link: http://www.usaco.org/index.php?page=viewproblem2&cpid=595
#include <bits/stdc++.h>

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
#define check(a, i)  printf("a[%d]: %d\n", i, a[i])
#define ll long long int
const int nax = 1e9;
void test_case()
{
    int N; cin >> N;
    vector<ll> v(N);
    for (auto& i : v) {
        cin >> i;
    }
    vector<ll> pref(N);
    pref[0] = v[0] % 7;
    for (int i = 1; i < N; i++) {
        pref[i] = (pref[i - 1] + v[i]) % 7;
    }

    unordered_map<ll, int> mp; 
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (mp.find(pref[i]) != mp.end()) {
            ans = max(ans, i - mp[pref[i]]);
        }
        else {
            mp[pref[i]] = i;
        }    
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
