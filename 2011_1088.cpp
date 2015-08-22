#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main(void)
{
    int L = 0;
    int M = 0;
    
    char tree[10002] = {0};
    int start_pos[101] = {0};
    int end_pos[101] = {0};
    
    while(scanf("%d%d", &L, &M) == 2)
    {
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d", &start_pos[i], &end_pos[i]);
        }
        memset(tree, '0', sizeof(tree));
        memset(tree, '1', sizeof(char) * (L+1));
//        memset(tree, '1', sizeof(tree));
        for (int i = 0; i < M; i++)
        {
            memset(tree + start_pos[i] * sizeof(char), '0', sizeof(char) * (end_pos[i] - start_pos[i] + 1));
        }
        
        int count = 0;
        for (int i = 0; i <= L; i++)
        {
            if (tree[i] == '1')
            {
                count++;
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}