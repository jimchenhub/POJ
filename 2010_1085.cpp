#include <iostream>
#include <cstdio>
using namespace std;

int get_sum(int temp, int k)
{
    int sum = 0;
    while(temp != 0)
    {
        sum += temp % k;
        temp /= k;
    }
    return sum;
}

int main(void)
{
    int x = 0, y = 0;
    int k = 0;
    
    while(scanf("%d%d%d", &x, &y, &k) == 3)
    {
        while (x >= k)
        {
            x = get_sum(x, k);
        }
        int temp = 1;
        while (y != 0)
        {
            if (y % 2 == 1)
                temp *= x;
            y /= 2;
            while (temp >= k)
            {
                temp = get_sum(temp, k);
            }
            x *= x;
            while (x >= k)
            {
                x = get_sum(x, k);
            }
        }
        cout << temp << endl;
    }
    return 0;
}


/*

1122068665 1554148348 2
305534960 492672743 13
1916943953 1527345777 10
507634278 4264462 9
398214480 1231721308 15
994558980 1687552259 6
1127136014 821737111 7
34564785 1109756805 2
1087758560 429831009 7
427790301 96338751 8

1
8
8
8
8
5
2
1
2
1


*/