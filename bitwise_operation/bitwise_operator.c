#include<stdio.h>
#include<stdlib.h>
int main()
{
    char ch = 82;
    printf("%d\n", ch);
    //~(tilde) -> one's complement (negation) 
    printf("%d\n", ~ch);
    
    //bitwise and (&)
    int x = 11, y = 5, z;
    z = (x & y);
    //x = 00001011
    //y = 00000101
    //z = 00000001 which is 1 (in decimal)
    printf("z = %d\n", z);    
    
    //bitwise or (|)
    int a = 11, b = 7, c;
    c = a | b;
    //a = 00001011
    //b = 00000111
    //c = 00001111 which is 15 (in decimal)
    printf("%d\n", c);
    
    //bitwise xor (^)
    int p = 11, q = 7, r;
    r = p ^ q;
    //p = 00001011
    //q = 00000111
    //r = 00001100 which is 12 (in decimal)
    printf("r = %d\n", r);

    //Now trick to figure decimal value of a binary number
    //suppose we have a binary number 
    //00001011
    //here 0th index is 1, 1th index is 2, 2th index is 4, 3th index is 8
    //so number is in order 1, 2, 4, 8, 16, 32... and so on.
    //so if we have number say..
    //00001011
    //    8421
    // just add numbers where digit is 1
    // so we add 1 + 2 + 8 = we get 11 which is the decimal value of the binary code
    // another example.
    // suppose we have
    // 00000111
    //     8421
    // so we add 1 + 2 + 4 = 7, which is the decimal value of the binary code

    //left shift 
    int s = 5, d;
    d = s << 1;
    //here we have s = 5
    //s = 00000101
    //left shift by 1 means
    //s = 00001010
    //and this is 10
    //and if we left shift by 2
    //we get 20
    //so we can derive the formula as
    //s << i
    //s * 2^i
    printf("d = %d\n", d);
    
    //Right shift
    d = s >> i;
    //then we can say that
    //s / 2^i
    printf("d after right shift = %d\n", d);    
    return 0;
}
