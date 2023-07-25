#include<bits/stdc++.h>
using namespace std;
struct node {
    int val;
    struct node *next;
} *headFirst = NULL, *tailFirst = NULL, *headSecond = NULL, *tailSecond = NULL;
void createFirstList(vector<int>& first) {
    struct node *n;
    for (auto& i : first) {
        n = new node;
        n->val = i;
        n->next = NULL;
        if (!headFirst) {
            headFirst = tailFirst = n;
        }
        else {
            tailFirst->next = n;
            tailFirst = n;
        }
    }
}
void createSecondList(vector<int>& second) {
    struct node *n;
    for (auto& i : second) {
        n = new node;
        n->val = i;
        n->next = NULL;
        if (!headSecond) {
            headSecond = tailSecond = n;
        }
        else {
            tailSecond->next = n;
            tailSecond = n;
        }
    }
}
struct node *merge(struct node *first, struct node *second) {
    // consider creating a fake vertex
    struct node *fake = new node;
    fake->val = -1;
    fake->next = NULL;
    struct node *last = fake;
    while (first && second) {
        if (first->val < second->val) {
            last->next = first;
            last = first;
            first = first->next;
        } else {
            last->next = second;
            last = second;
            second = second->next;
        }
    }
    if (first) {
        last->next = first;
    }
    if (second) {
        last->next = second;
    }
    return fake->next;
}
void display(struct node *p) {
    cout << "Elements are: " << '\n';
    while (p) {
        cout << p->val << ' ';
        p = p->next;
    }
    cout << '\n';
}
int main() {
    vector<int> first = {2, 5, 7, 8};
    vector<int> second = {3, 4, 5, 9, 12};
    createFirstList(first);
    createSecondList(second);
    struct node *p = merge(headFirst, headSecond);
    display(p);
    return 0;
}
