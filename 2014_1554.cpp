#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int length = 0;
    int start_pos = 0, end_pos = 0;
    int input[10001] = {0};
    int k = 0;

    while(scanf("%d", &length) == 1)
    {
        for (int i = 0; i < length; i++)
        {
            scanf("%d", &input[i]);
        }
        scanf("%d", &k);

        bool flag = false;
        for (int i = 0; i < length; i++)
        {
            int sum = 0;
            start_pos = i + 1;
            for (int j = i; j < length; j++)
            {
                sum += input[j];
                if (sum == k)
                {
                    flag = true;
                    end_pos = j+1;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
        {
            cout << start_pos << " " << end_pos << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}

/*

* right answer

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

const int Max_N = 10008 ;
int x[Max_N] ;
int sum[Max_N] ;
int n  , k ;
map<int , vector<int> > st ;

void Ans(){
    int start , nowserch ;
    vector<int> now ;
    vector<int> ::iterator it ;
    for(start = 1 ; start <= n ; start++){
        nowserch = sum[start-1] + k ;
        if(st.find(nowserch) == st.end())
            continue ;
        now = st[nowserch] ;
        for(it = now.begin() ; it < now.end() ; it++){
            if((*it) >= start){
                printf("%d %d\n" , start , (*it)) ;
                return ;
            }
        }
    }
    puts("No") ;
    return ;
}

int  main(){
    int i ;
    while(scanf("%d" ,&n) != EOF){
        st.clear() ;
        sum[0] = 0 ;
        for(i = 1 ; i <= n ; i++){
            scanf("%d", &x[i]);
            sum[i] = sum[i-1] + x[i] ;
            st[sum[i]].push_back(i) ;
        }
        scanf("%d" ,&k) ;
        Ans() ;
    }
    return  0 ;
}

*/