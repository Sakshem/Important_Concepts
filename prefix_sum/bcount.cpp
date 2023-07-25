//problem link : http://www.usaco.org/index.php?page=viewproblem2&cpid=572
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
    int N, Q; cin >> N >> Q;

    vector<int> cows(N);
    for (auto& i : cows) { cin >> i; }
   
    vector<int> first_breed(N, 0), second_breed(N, 0), third_breed(N, 0);
   
    first_breed[0] = (cows[0] == 1);
    second_breed[0] = (cows[0] == 2);
    third_breed[0] = (cows[0] == 3);
    for (int i = 1; i < N; i++) {
        first_breed[i] = first_breed[i - 1] + (cows[i] == 1);
        second_breed[i] = second_breed[i - 1] + (cows[i] == 2);
        third_breed[i] = third_breed[i - 1] + (cows[i] == 3);
    }
    /*for (int i = 0; i < N; i++) {
        debug(first_breed[i], second_breed[i], third_breed[i]);
    }*/
    while (Q--) {
        int L, R; cin >> L >> R;
        --L, --R;
        cout << first_breed[R] - first_breed[L - 1] << ' ';
        cout << second_breed[R] - second_breed[L - 1] << ' ';
        cout << third_breed[R] - third_breed[L - 1] << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    test_case();
    return 0;
}
