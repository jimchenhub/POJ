#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define min(a, b) ((a) < (b)) ? (a) : (b)
using namespace std;

long L1 = 0, L2 = 0, L3 = 0;
long C1 = 0, C2 = 0, C3 = 0;
int A = 0, B = 0;
int N = 0;
long input_distance[1025] = {0};
long payment[1025] = {0};

long count_payment(long input_distance)
{
    long result = 0;
    if (input_distance <= L1)
    {
        result = C1;
    }
    else if (input_distance <= L2)
    {
        result = C2;
    }
    else if (input_distance <= L3)
    {
        result = C3;
    }
    
    return result;
}

int main(void)
{
    
    while (scanf("%ld%ld%ld%ld%ld%ld", &L1, &L2, &L3, &C1, &C2, &C3) == 6)
    {
        scanf("%d%d", &A, &B);
        scanf("%d", &N);
        memset(input_distance, 0, sizeof(input_distance));
        memset(payment, 0, sizeof(payment));
        for (int i = 2; i <= N; i++)
        {
            scanf("%ld", &input_distance[i]);
        }
        
        for (int i = A + 1; i <= B; i++)
        {
            int j = i - 1;
            long dis_sum = input_distance[i] - input_distance[j];
            while (j >= A && dis_sum <= L3)
            {
                if (payment[i] == 0)
                {
                    payment[i] = payment[j] + count_payment(dis_sum);
                }
                else
                {
                    payment[i] = min(payment[i], payment[j] + count_payment(dis_sum));
                }
                j--;
                dis_sum = input_distance[i] - input_distance[j];
            }
        }
        
        cout << payment[B] << endl;
    }
    
    return 0;
}

/*

5 10 15 5 10 15
3 9
10
1
2
3
4
5
6
3
4
5


*/