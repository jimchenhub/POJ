/*
Accepted

But there is a problem that if input as below, the program would become non stop
50 10000
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
50 10000
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
50 10000
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
50 10000
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50

*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int n = 0, m = 0;
    int A[100] = {0};
    int C[100] = {0};
    
    int df[100001] = {0};
    int temp[100001] = {0};
    
    scanf("%d%d", &n, &m);
    while (!(n == 0 && m == 0))
    {
        memset(A, 0, sizeof(A));
        memset(C, 0, sizeof(C));
        
        // get An
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);
        }
        // get Cn
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &C[i]);
        }
        
        memset(df, 0, sizeof(df));
        memset(temp, 0, sizeof(temp));
        
        df[0] = 1;
        for (int i = 0; i < n; i++)
        {
            memset(temp, 0, sizeof(temp));
            for(int j = A[i];j <= m; j++)  
            {  
                if(!df[j] && df[j-A[i]] && temp[j-A[i]]<C[i])  
                {  
                    df[j] = 1;  
                    temp[j] = temp[j-A[i]]+1;
                }  
            }  
        }
        
        int count = 0;
        for (int i = 1; i <= m; i++)
            if (df[i] == 1)
                count++;
        
        cout << count << endl;
        
        //下一次循环
        scanf("%d%d", &n, &m);
    }

    return 0;
}

/*

50 10000
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
50 10000
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
3 10
1 2 4 2 1 1
2 5
1 4 2 1
0 0

42925

#include <stdio.h>  
#include <algorithm>  
#include <string.h>  
  
int dp[100005];  
int sum[100005];  
int v[105],c[105];  
  
int main()  
{  
    int i,j,n,m;
    scanf("%d%d",&n,&m);  
    while(n+m)  
    {  
        for(i = 1;i<=n;i++)  
        scanf("%d",&v[i]);  
        for(i = 1;i<=n;i++)  
        scanf("%d",&c[i]);  
        memset(dp,0,sizeof(dp));  
        dp[0] = 1;  
        int ans = 0;  
        for(i=1;i<=n;i++)  
        {  
            memset(sum,0,sizeof(sum));  
            for(j = v[i];j<=m;j++)  
            {  
                if(!dp[j] && dp[j-v[i]] && sum[j-v[i]]<c[i])  
                {  
                    dp[j] = 1;  
                    sum[j] = sum[j-v[i]]+1;  
                    ans++;  
                }  
            }  
        }  
        printf("%d\n",ans);  
        scanf("%d%d",&n,&m);
    }  
  
    return 0;  
}  

*/