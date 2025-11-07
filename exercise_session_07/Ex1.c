#include <stdio.h>

int main() {
    int p[] = {10,20,30,40,50,60,70,80,90,100};

    printf("Type of p: int[10]\n");
    printf("Type of *p: int\n");
    printf("Type of &p: int (*)[10]\n");

    printf("*p = %d\n", *p);
    printf("p[0] = %d\n", p[0]);
    printf("p[3] = %d\n", p[3]);
    printf("*(p+5) = %d\n", *(p+5));
    printf("*p+5 = %d\n", *p+5);
    
    printf("p[-1] accesses memory before the array so it's undefined behaviour");

    int *q = p - 1;
    printf("q[0] = %d (same as *(p-1))\n", q[0]);
    printf("*(q+10) = %d\n", *(q+10));
    printf("*(q+11) = %d\n", *(q+11));

    return 0;
}

