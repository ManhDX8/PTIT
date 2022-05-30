#include<stdio.h>
#include<stdbool.h>
#include<math.h>

void swap(long long *a,long long *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

long long gcd_lcm(long long a,long long b)
{
    long long n=a*b;
    while (a*b!=0)
    {
        a%=b;
        swap(&a,&b);
    }
    printf("%lld\n%lld",a+b,n/(a+b));
}

int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    gcd_lcm(a,b);
}