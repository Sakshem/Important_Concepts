#include<bits/stdc++.h>
using namespace std;
void Reversing(int *r, int low, int high)
{
    while(low < high)
    {
        swap(r[low], r[high]);
        low++;
        high--;
    }
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    //how many elements you want to rotate
    int d = 2;
    //left rotate
    Reversing(arr, 0, d - 1);
    Reversing(arr, d, n - 1);
    Reversing(arr, 0, n - 1);

    //right rotate
    Reversing(arr, n - d, n - 1);
    Reversing(arr, 0, n - d - 1);
    Reversing(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
