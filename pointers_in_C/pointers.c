/*#include<stdio.h>
int main()
{
    int a = 12, b = 2;
    int *p, *q, *r;
    p = &a;
    q = &b;
    *r = *p + *q;
    printf("*r = %d\n",*r);
    return 0;
}*/
/*#include<stdio.h>
#include<stdlib.h>
int main()
{
    //program to print factorial of a number using pointers
    int *f, num, i = 1, *n;
    n = &num;
    *f = 1;
    printf("Enter any number:\n");
    scanf("%d", n);
    while (i <= *n)
    {
        *f = *f * i;
        i++;
    }
    printf("The factorial of the number is %d\n", *f);
    return 0;
}*/
/*#include<stdio.h>
int main()
{
    //program to print sum of digits of a number using pointers
    int num, *n, *sum;
    n = &num;
    *sum = 0;
    printf("Enter any number:\n");
    scanf("%d", n);
    while (*n > 0)
    {
        *sum += *n % 10;
        *n /= 10; 
    }
    printf("The sum of digits of the number is %d\n", *sum);

    return 0;
}*/
/*#include<stdio.h>
int main()
{
    //program to print product of digits of a number using pointers
    int num, *n, *prod;
    n = &num;
    printf("Enter any number:\n");
    scanf("%d", n);
    while (*n > 0)
    {
        *prod = *prod * (*n % 10);
        *n /= 10;
    }
    printf("the product is %d\n", *prod);
    return 0;
}*/
/*#include<stdio.h>
int main()
{
    //program to reverse digits of a number using pointers
    int num, *n, *rev;
    n = &num;
    *rev = 0;
    printf("enter any number:\n");
    scanf("%d", n);
    while (*n > 0)
    {
        *rev = *rev * 10 + (*n % 10);
        *n /= 10;
    }
    printf("The reverse of the number is %d\n", *rev);

    return 0;
}*/
/*#include<stdio.h>
#include<stdbool.h>
int main()
{
 //program to calculate hcf and lcm of two nums using pointers 
    int num1, num2, *a, *b, hcf, lcm, temp;
    a = &num1;
    b = &num2;
    printf("Enter any two numbers:\n");
    scanf("%d %d", a, b);
    //hcf
    temp = (*a < *b) ? (*b) : (*a);
     for(int i = 1; i <= temp; i++)
     {
     	if(*a % i == 0 && *b % i == 0)
		hcf = i;
     }
     printf("The hcf is %d\n", hcf);
     //lcm
     lcm = (*a < *b) ? (*a) : (*b);
     while(true)
     {
     	if(lcm % *a == 0 && lcm % *b == 0) {
		printf("The lcm is %d\n", lcm);
		break;
	}
	lcm++;
     }
    return 0;
}*/
/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    //Program to print armstrong number using pointers
    int l, h, *a, *b, temp, sum, t, digit, rem;
    a = &l;
    b = &h;
    printf("Enter starting and ending value:\n");
    scanf("%d %d", a, b);
    for(int i = *a; i <= *b; i++)
    {
        temp = i;
        sum = 0;
        t = temp;
    	digit = 0;
        while (t > 0)
        {
            digit++;
            t /= 10;
        }
        //printf("digits are:%d\n", digit);
     	while(temp > 0)
        {
    	    rem = temp % 10;
            sum += pow(rem, digit);
            temp /= 10;        	
    	}
	    //printf("Sum = %d, i = %d\n", sum, i);
        if(sum == i)
                printf("%d is an armstrong number\n", i);
    }

}*/
/*#include<stdio.h>
#include<math.h>
int main()
{
    //program to calculate x^y
    int x, y, *a, *b, *result;
    a = &x;
    b = &y;
    printf("Enter any two values\n");
    scanf("%d %d", a, b);
    *result = pow(*a, *b);
    printf("The value of %d^%d is %d\n",*a, *b, *result);
    return 0;
}*/
/*#include<stdio.h>
int main()
{
    int a, *p, **q, ***r, ****s, *****t;
    int b, *u, **v, ***w, ****x, *****y, ******z;
    a = 10, p = &a, q = &p, r = &q, s = &r, t = &s;
    b = 20, u = &b, v = &u, w = &v, x = &w, y = &x, z = &y;
    ***y = &q;
    //printf("%u", ***y);
    ***z = **q + 3;        
    int xy  = 12;
    xy = &xy;
    printf("%d", xy);

}*/
#include<stdio.h>
int main()
{
    int n = 50;
    printf("%u\n", &n);
    return 0;
}



