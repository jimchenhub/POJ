#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main(void)
{
//    srand((unsigned int)time(NULL));
//    for (int i = 0; i < 20; i++) {
//        int N = rand() % 12 + 2;
//        cout << N << endl;
//        for (int j = 0; j < N; j++) {
//            cout << rand() % 3;
//        }
//        cout << endl;
//    }
    
    map <string, int> result;
    int length = 0;
    string ob_str = "2012";
    
    while(scanf("%d", &length) == 1)
    {
        result.clear();
        string input;
        cin >> input;
        
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;
        for (int i = 0; i < length; i++) {
            if (input[i] == '0') count_0++;
            if (input[i] == '1') count_1++;
            if (input[i] == '2') count_2++;
        }
        
        if (!(count_0 >= 1 && count_1 >= 1 && count_2 >= 2))
        {
            cout << "-1" << endl;
            continue;
        }
        
        if (input.find(ob_str) != input.npos)
        {
            cout << "0" << endl;
            continue;
        }
        
        result[input] = 0;
        bool flag = false;
        int count = 0;
        
        while (!flag)
        {
            vector <string> temp_list;
            temp_list.clear();
            map <string, int>::iterator it;
            for (it = result.begin(); it != result.end(); it++)
            {
                string key = it->first;
                int value = it->second;
                
                if (value == count)
                {
                    for (int i = 0; i < length - 1; i++)
                    {
                        string after = key;
                        char temp = after[i];
                        after[i] = after[i+1];
                        after[i+1] = temp;
                        
                        if (after.find(ob_str) != after.npos)
                        {
                            flag = true;
                            break;
                        }
                        
                        if (result.find(after) == result.end())
                        {
                            temp_list.push_back(after);
                        }
                    }
                }
            }
            count++;
            if (flag)
                break;
            
            for (int i = 0; i < temp_list.size(); i++)
            {
                result[temp_list[i]] = count;
            }
            
        }
        
        cout << count << endl;
    }
    
    return 0;
}

/*

5
01112
6
221000
11
21020220002
9
102001220
5
02010
3
011
7
1122110
3
011
2
01
3
100
8
21001200
8
20111001
2
00
11
02102010211
12
021100002012
12
110120100220
2
01
5
22122
5
20120
8
12002210


*/