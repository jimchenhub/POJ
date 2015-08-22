#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define min(a,b) ((a) < (b)) ? (a) : (b)
#define max(a,b) ((a) > (b)) ? (a) : (b)
using namespace std;

int main(void)
{
    int N;
    int input[10001] = {0};
    
    int min_value = 0, max_value = 0;
    
    while (scanf("%d", &N) == 1)
    {
        memset(input, 0, sizeof(input));
        min_value = 1000001;
        max_value = -1000001;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &input[i]);
        }
        
        for (int i = 0; i < N; i++)
        {
            min_value = min(min_value, input[i]);
            max_value = max(max_value, input[i]);
        }
        cout << max_value << " " << min_value << endl;
    }
    
    return 0;
}