#include<stdio.h>

#define MAX 21252

int main()
{
    int p, e, i, d, n, count = 0;
    
    while( scanf("%d%d%d%d", &p, &e, &i, &d) != EOF )
    {
        count++;
        if(p == -1 && e == -1 && i == -1 && d == -1)
        {
            break;
        }
        
        n = ( 5544 * p + 14421 * e + 1288 * i - d ) % MAX;
        
        if( n <= 0 )   // 范围限制
        {
            n += 21252;
        }
        
        printf("Case %d: the next triple peak occurs in %d days.\n", count, n );
    }
    return 0;
}