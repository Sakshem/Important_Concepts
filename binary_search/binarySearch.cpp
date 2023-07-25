#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &B, int n, int key)
{
    int L = 0;
    int R = n - 1;
    int mid;
    int count = 0;
    while(L <= R)
    {
        cout << "count : " << count << '\n';
        mid = L + (R - L)/2; //use this instead of (L + R)/2 (to avoid overflows)
        if(B[mid] == key)
            return mid;
        else if(key < B[mid]) //this means that key will be to the left of mid
            R = mid - 1; 
        else if(key > B[mid]) //this means that key will be to the right of mid
            L = mid + 1;
    }
    return -1;
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> A(n);
    //Remember the array needs to be sorted or binary search won't work.
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);
     
    int key; //The element you want to search.
    scanf("%d", &key);


    int index = binarySearch(A, n, key);//this will return index of the key
    //if value of index is -1 that means the key wasn't found.

    if(index == -1)
        cout << "Key was not found!\n";
    else
        cout << "Key was found in index: " << index << '\n';
    return 0;
}
//also we have some examples solved with questions linked as to know how and when to use binary search
