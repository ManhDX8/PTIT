#include<stdio.h>
#include<string.h>
#include<stdbool.h>



int main()
{
    int n;
    scanf("%d",&n);
    
    for ( int i=1 ; i<=n ; i++ )
    {
        for ( int k=1 ; k<=n-i ; k++ )
        {
            printf("~");
        }
        for ( int j=1 ; j<=n ; j++ )
        {
            printf("*");
        }
        printf("\n");
    }
}