#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int comparator(const void *a, const void *b)
{
    //for array
    int l = *(const int *)a;
    int r = *(const int *)b;
    return l-r; 
}
int CharComparator(const void *a, const void *b)
{   
    //for single characters: 
    int l = *(char *)a;
    int r = *(char *)b;
    return l - r;
}
int StringComparator(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}
int main()
{
    //I have an array 
    int arr[] = {10, 12, 3, 5, 2, 22, 1};
    char *str[] = {"apple", "mango", "orange", "banana", "pears", "kiwi"};
    char s[] = {'b', 'a', 'c', 'd'}; 
    //sort the array using qsort(); 
    qsort((void *)arr, 7, sizeof(arr[0]), comparator);
    qsort((void *)str, 6, sizeof(char *), StringComparator);  
    qsort((void *)s, 4, sizeof(s[0]), CharComparator); 
    printf("now the elements of the array in sorted order are:\n");
    for(int i = 0; i < 7; i++)
        printf("%d ", arr[i]);
    printf("\nNow the string in increasing order are:\n");
    for(int i = 0; i < 6; i++)
        printf("%s ", str[i]);
    printf("\nNow the char printed in increasing order are:\n");
    for(int i = 0; i < 4; i++)
        printf("%c ", s[i]);
}
