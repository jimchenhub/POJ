#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

struct result
{
    int a1;
    int a0;
};

struct factor
{
    int first;
    int second;
    int third;
    int fourth;
};

int main(void)
{
    int p = 0, q = 0, k = 0;
    int a0 = 0, a1 = 0;
    struct result * res = (struct result *)malloc(sizeof(struct result));
    struct factor * fac = (struct factor *)malloc(sizeof(struct factor));
    struct factor * fac_res = (struct factor *)malloc(sizeof(struct factor));
    
    while(scanf("%d%d%d%d%d", &a0, &a1, &p, &q, &k) == 5)
    {
        a0 = a0 % 10000;
        a1 = a1 % 10000;
        p = p % 10000;
        q = q % 10000;
        
        if (k == 0)
        {
            cout << a0 << endl;
            continue;
        }

        res->a0 = a0;
        res->a1 = a1;
        fac->first = p;
        fac->second = q;
        fac->third = 1;
        fac->fourth = 0;
        
        k--;
        fac_res->first = 1;
        fac_res->second = 0;
        fac_res->third = 0;
        fac_res->fourth = 1;
        
        int temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
        while (k != 0)
        {
            if (k % 2 == 1)
            {
                temp1 = (fac->first * fac_res->first + fac->second * fac_res->third) % 10000;
                temp2 = (fac->first * fac_res->second + fac->second * fac_res->fourth) % 10000;
                temp3 = (fac->third * fac_res->first + fac->fourth * fac_res->third) % 10000;
                temp4 = (fac->third * fac_res->second + fac->fourth * fac_res->fourth) % 10000;
                fac_res->first = temp1;
                fac_res->second = temp2;
                fac_res->third = temp3;
                fac_res->fourth = temp4;

            }
            
            temp1 = (fac->first * fac->first + fac->second * fac->third) % 10000;
            temp2 = (fac->first * fac->second + fac->second * fac->fourth) % 10000;
            temp3 = (fac->third * fac->first + fac->fourth * fac->third) % 10000;
            temp4 = (fac->third * fac->second + fac->fourth * fac->fourth) % 10000;
            
            fac->first = temp1;
            fac->second = temp2;
            fac->third = temp3;
            fac->fourth = temp4;
            
            k /= 2;
        }
        
        temp1 = (fac_res->first * res->a1 + fac_res->second * res->a0) % 10000;
        temp2 = (fac_res->third * res->a1 + fac_res->fourth * res->a0) % 10000;
        res->a1 = temp1;
        res->a0 = temp2;
        
        cout << res->a1 << endl;
    }
    
    return 0;
}

/*

5229 3309 5758 6622 162728
122 6761 3786 6563 369491
3100 6568 5375 6021 222563
6034 2616 8039 1687 934033
3267 4103 4493 2689 691555
5591 207 6328 6193 991013
3607 5257 3699 7537 578005
9227 3532 7285 5916 128994
7548 7866 1443 4479 300234
3403 640 4646 9114 139935

2000
3547
2228
7256
7683
3087
17
752
8972
8672

*/