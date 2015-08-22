#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(void)
{
    int N = 0;
    int input[1001] = {0};
    
    scanf("%d", &N);
    while(N != 0)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &input[i]);
        }
        
        for (int i = 0; i < N; i++)
        {
            int count = 0;
            int value = input[i];
            int temp = (int)sqrt(input[i]);
            for (int j = 1; j <= temp; j++)
            {
                if (value % j == 0)
                    count++;
            }
            count *= 2;
            if (temp * temp == value)
                count--;
            
            cout << count << endl;
        }
        
        scanf("%d", &N);
    }
    return 0;
}