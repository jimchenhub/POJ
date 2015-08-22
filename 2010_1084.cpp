#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
    int N = 0;
    long result[1000002] = {0};
    result[1] = 1;
    while(scanf("%d", &N) == 1)
    {
        for(int i = 2; i <= N; i++)
        {
            if (result[i] > 0)
                continue;
            if (i % 2 == 1)
            {
                result[i] = result[i-1] ;
            }
            else
            {
                result[i] = (result[i-1] + result[i/2]) % 1000000000;
            }
        }
        
        cout << result[N] << endl;
    }
    return 0;
}


/*

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
a
1
2
2
4
4
6
6
10
10
14
14
20
20
26
26
36
36
46
46
60


*/