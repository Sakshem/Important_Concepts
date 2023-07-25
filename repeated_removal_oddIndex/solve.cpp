/*#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    struct node *next;
}*first = NULL, *last = NULL;
void insertLast(int val) {
    struct node *n;
    n = new node;
    n->data = val;
    n->next = NULL;
    if (!first) {
        first = last = n;
    }
    else {
        last->next = n;
        last = n;
    }
}
void deleteNode(struct node *p) {
    struct node *tail = p;
    // head node smaller
    while (first && first->next) {
        if (first->data < first->next->data) {
            first = first->next;
            tail = p = first;
        }
        else {
            break;
        }
    }
    cout << p->data << " " << tail->data << '\n';
    while (p) {
        if (p->next && p->data < p->next->data) {
            tail->next = p->next;
            p->next = NULL;
            p = tail->next;
        }
        else {
            tail = p;
            p = p->next;   
        }
    }
}
void printLL(struct node *p) {
    while (p->next) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << p->data << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    while (true) {
        int x; cin >> x;
        if (x < 0) {
            break;
        }
        insertLast(x);
    }

    deleteNode(first);
    printLL(first);
    return 0;
}*/

/*#include<bits/stdc++.h>
using namespace std;
void ReverseString(string& s) {
    string t;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            t.push_back(s[i]);
        }
    }
    reverse(t.begin(), t.end());
    int j = 0;
    for (int i = 0; i < n; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            s[i] = t[j];
            j++;
        }
    }
    cout << s << '\n';
}
int main() {
    string s; cin >> s;
    ReverseString(s);
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
    if (a.second.second != b.second.second) {
        return a.second.second > b.second.second;
    }
    else {
        return a.second.first < b.second.first;
    }
}
int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    unordered_map<int, pair<int, int>> hash;
    for (int i = 0; i < n; i++) {
        if (hash.find(v[i]) != hash.end()) {
            hash[v[i]].second++;
        } else {
            hash[v[i]] = make_pair(i, 1);
        }
    }
    vector<pair<int, pair<int, int>>> res;
    for (auto it = hash.begin(); it != hash.end(); it++) {
        res.push_back(make_pair(it->first, it->second));
    }
    sort(res.begin(), res.end(), comp);
    for (int i = 0; i < res.size(); i++) {
        int count = res[i].second.second;
        while(count--) {
            cout << res[i].first << ' ';
        }
    }
    cout << '\n';
    return 0;
}
