#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void Swap(int *num1, int *num2)
{
    int temp = *num1;
     *num1 = *num2;
     *num2 =  temp;
}
void Bubble(int A[], int length)
{
    for(int i = 0; i < length - 1; i++)
    {
        for(int j = 0; j < length - i - 1; j++)
        {
            if(A[j] > A[j + 1])
                    Swap(&A[j], &A[j + 1]);
        }
    }
}
int main()
{
    int arr[MAX], temp, flag = 0;
    printf("Enter the elements in the array\n");
    for(int i = 0; i < 5; i++)
            scanf("%d", &arr[i]);
    //Bubble sort
    printf("\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = i + 1; j < 5; j++)
        {
            if(arr[i] > arr[j]){	
                temp = arr[j]; 
                arr[j] = arr[i];
                arr[i]  = temp;
		flag = 1;
            }
        } 
    }
    printf("The elements after sorting are:\n");
    for(int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    if(flag == 1)
	    printf("Sorting was done that is swapping\n");
    else
	    printf("Swapping was not done\n");

   // Bubble(arr, 5);
    printf("The elements after sorting are:\n");
    for(int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
 	puts("");
    return 0;
}
