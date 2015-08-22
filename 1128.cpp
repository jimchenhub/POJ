#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAX_NUM_RECT 26
#define MAX_BLOCK_SIZE 30
#define max(a, b)  (((a) > (b)) ? (a) : (b))
#define min(a, b)  (((a) < (b)) ? (a) : (b))

char block[MAX_BLOCK_SIZE][MAX_BLOCK_SIZE] = {0}; //block
int edge[MAX_NUM_RECT][MAX_NUM_RECT] = {0}; //边
int in[MAX_NUM_RECT] = {0}; //入度

int ptop[MAX_NUM_RECT], pbottom[MAX_NUM_RECT], pleft[MAX_NUM_RECT], pright[MAX_NUM_RECT];


void init(int height, int width)
{
    //获取所有的节点和节点的上下左右角的位置
    memset(ptop, MAX_BLOCK_SIZE, sizeof(ptop));
    memset(pleft, MAX_BLOCK_SIZE, sizeof(pleft));
    memset(pbottom, -1, sizeof(pbottom));
    memset(pright, -1, sizeof(pright));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            char now = block[i][j];
            if (now != '.')
            {
                int index = now - 'A';
                ptop[index] = min(i, ptop[index]);
                pleft[index] = min(j, pleft[index]);
                pbottom[index] = max(i, pbottom[index]);
                pright[index] = max(j, pright[index]);
            }
        }
    }
    
    //构建edge
    for(int count = 0; count < MAX_NUM_RECT; count++)
    {
        if (pbottom[count] == -1)
            continue;
        
        in[count] = 0;
        
        int pos_left = pleft[count], pos_right = pright[count], pos_top = ptop[count], pos_bottom = pbottom[count];
        char this_letter = count + 'A';
        
        //上
        for (int i = pos_left; i <= pos_right; i++)
        {
            char new_letter = block[pos_top][i];
            if (new_letter != this_letter)
            {
                edge[count][new_letter-'A'] = 1;
            }
        }
        //下
        for (int i = pos_left; i <= pos_right; i++)
        {
            char new_letter = block[pos_bottom][i];
            if (new_letter != this_letter)
            {
                edge[count][new_letter-'A'] = 1;
            }
        }
        //左
        for (int i = pos_top; i <= pos_bottom; i++)
        {
            char new_letter = block[i][pos_left];
            if (new_letter != this_letter)
            {
                edge[count][new_letter-'A'] = 1;
            }
        }
        //右
        for (int i = pos_top; i <= pos_bottom; i++)
        {
            char new_letter = block[i][pos_right];
            if (new_letter != this_letter)
            {
                edge[count][new_letter-'A'] = 1;
            }
        }
    }
    
    //构建in
    for (int i = 0; i < MAX_NUM_RECT; i++)
    {
        for (int j = 0; j < MAX_NUM_RECT; j++)
        {
            if (edge[i][j] == 1)
            {
                in[j]++;
            }
        }
    }
}

bool is_finish(int temp_in[MAX_NUM_RECT])
{
    bool flag = true;
    for (int i = 0; i < MAX_NUM_RECT; i++)
    {
        if (temp_in[i] != -1)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

void dfs(int temp_in[MAX_NUM_RECT], vector<char> result)
{
    if (is_finish(temp_in))
    {
        //输出结果
        vector<char>::iterator it;
        for(it = result.begin(); it != result.end(); it++)
            cout << *it;
        cout << endl;
        return;
    }
    
    vector<char> temp_result;
    int inner_in[MAX_NUM_RECT] = {0};
    
    for(int i = 0; i < MAX_NUM_RECT; i++)
    {
        if (temp_in[i] == 0)
        {
            for (int count = 0; count < MAX_NUM_RECT; count++)
                inner_in[count] = temp_in[count];
            
            temp_result.assign(result.begin(), result.end());
            
            //改变入度
            for (int j = 0; j < MAX_NUM_RECT; j++)
            {
                inner_in[j] -= edge[i][j];
            }
            inner_in[i] = -1;
            //记录结果
            temp_result.push_back('A'+i);
            //进行下一次递归
            dfs(inner_in, temp_result);
        }
    }
}

int main(void)
{
    int height = 0, width = 0;
    
    while (scanf("%d%d", &height, &width) == 2)
    {
        //清空内存
        memset(block, 0, sizeof(block));
        memset(edge, 0, sizeof(edge));
        memset(in, -1, sizeof(in));
        
        //获取block
        for (int i = 0; i < height; i++)
        {
            cin >> block[i];
        }
        
        //填充edge矩阵和入度表
        init(height, width);
        
        //输出结果
        vector<char> result;
        result.clear();
        dfs(in, result);
    }
    
    return 0;
}