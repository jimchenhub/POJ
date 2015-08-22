#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void)
{
    long a = 0, b = 0;
    while (scanf("%ld%ld", &a, &b) == 2)
    {
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;
        int sum = 0;
        long temp_a = a;

        while(temp_a != 0)
        {
            int a_add = temp_a % 10;
            long temp_b = b;
            while(temp_b != 0)
            {
                int b_add = temp_b % 10;
                sum += b_add * a_add;
                temp_b = temp_b / 10;
            }
            temp_a = temp_a / 10;
        }

        cout << sum << endl;
    }
    return 0;
}

/*
题目描述：
写个算法，对2个小于1000000000的输入，求结果。
特殊乘法举例：123 * 45 = 1*4 +1*5 +2*4 +2*5 +3*4+3*5
输入：
 两个小于1000000000的数
输出：
 输入可能有多组数据，对于每一组数据，输出Input中的两个数按照题目要求的方法进行运算后得到的结果。
样例输入：
123 45
样例输出：
54


*/