#include <bits/stdc++.h>
using namespace std;
void solveO3() //solution with time complexity O(n^3)
{
    int n;
    //first method with time complexity O(n^3)
    cin >> n; 
    vector <int> a(n);
    //-1 2 -3 4 5 6 - 8 10    
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int best = 0, sum;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            sum = 0;
            for(int k = i; k <= j; k++) 
            { 
                sum += a[k];  
            }
            best = max(best, sum);
        }
    }
    cout << "Maximum sum is: " << best << '\n';
}
void solveO2() //solution with time complexiy O(n^2)
{
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    vector <int> arr(n);
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int best = 0;
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];
            best = max(best, sum); 
        }
    }
    printf("The maximum sum is: %d\n", best);
}
void solveO1() //solution with time complexity O(n)
{
    int n;
    printf("Enter size of the array:\n");
    scanf("%d", &n);
    vector <int> arr(n);
    printf("Enter elements inside the array:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int best = 0, sum = 0; 
    for(int i = 0; i < n; i++)
    {
        sum = max(arr[i], sum + arr[i]);
        best = max(best, sum);
    }
    printf("The maximum sum is: %d\n", best);
}
int main()
{
    //given any array of n elements we can find the max sum of the subsets of the array
    //there are 3 different types of solutions to solve this problem
    //with 3 different time complexities O(n^3) O(n^2) O(n)
    //solveO3();  
    //solveO2();
    //solveO1();
    return 0;
}
