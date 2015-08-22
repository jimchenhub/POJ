#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N = 0, M = 0, K = 0;

void output(int temp[1001], char op[1001], int point_to_bf[1001], int value, int count)
{
    if (point_to_bf[value] == -1)
    {
        count++;
        cout << count << endl;
        cout << op[value];
        return;
    }
    
    output(temp, op, point_to_bf, point_to_bf[value], count+1);
    cout << op[value];
}

int main(void)
{
    scanf("%d%d%d", &N, &K, &M);
    int value = 0;
    
    int temp[1001] = {0}; //记录模除K后的值
    char op[1001] = {0}; //记录操作的方式
    int num_of_n[1001] = {0}; //记录得到这个模除值的N
    int point_to_bf[1001] = {0}; //记录前一个模除值
    
    vector<int> route;
    vector<int> later;
    
    while(!(N == 0 && K == 0 && M == 0))
    {
        value = (N + 1) % K; // result want to get
        value = value < 0 ? value+K : value;
        
        memset(temp, 0, sizeof(temp));
        memset(op, 0, sizeof(op));
        memset(num_of_n, 0, sizeof(num_of_n));
        memset(point_to_bf, 0, sizeof(point_to_bf));
        
        route.clear();
        later.clear();
        
        int t = 0;
        // +
        t = (N+M)%K;
        t = t < 0 ? t+K : t;
        if (temp[t] == 0)
        {
            temp[t] = 1;
            op[t] = '+';
            num_of_n[t] = N+M;
            point_to_bf[t] = -1; // -1作为结尾的指向值
            route.push_back(t);
        }
        // -
        t = (N-M)%K;
        t = t < 0 ? t+K : t;
        if (temp[t] == 0)
        {
            temp[t] = 1;
            op[t] = '-';
            num_of_n[t] = N-M;
            point_to_bf[t] = -1;
            route.push_back(t);
        }
        // *
        t = (N*M)%K;
        t = t < 0 ? t+K : t;
        if (temp[t] == 0)
        {
            temp[t] = 1;
            op[t] = '*';
            num_of_n[t] = N*M;
            point_to_bf[t] = -1;
            route.push_back(t);
        }
        // %
        int sub = N % M;
        sub = sub < 0 ? sub+M : sub;
        t = (sub)%K;
        t = t < 0 ? t+K : t;
        if (temp[t] == 0)
        {
            temp[t] = 1;
            op[t] = '%';
            num_of_n[t] = sub;
            point_to_bf[t] = -1;
            route.push_back(t);
        }
        
        while(route.size() > 0)
        {
            later.assign(route.begin(), route.end());
            route.clear();
            for (int num = 0; num < later.size(); num++)
            {
                int i = later[num];
                int t = 0;
                // +
                t = (i+M)%K;
                t = t < 0 ? t+K : t;
                if (temp[t] == 0)
                {
//                    later_add_arr[t] = '+';
                    route.push_back(t);
                    temp[t] = 1;
                     op[t] = '+';
                    point_to_bf[t] = i;
                    if (temp[0] == 0)
                        num_of_n[t] = num_of_n[i] + M;
                }
                // -
                t = (i-M)%K;
                t = t < 0 ? t+K : t;
                if (temp[t] == 0)
                {
//                    later_add_arr[t] = '-';
                    route.push_back(t);
                    temp[t] = 1;
                     op[t] = '-';
                    point_to_bf[t] = i;
                    if (temp[0] == 0)
                        num_of_n[t] = num_of_n[i] - M;
                }
                // *
                t = (i*M)%K;
                t = t < 0 ? t+K : t;
                if (temp[t] == 0)
                {
//                    later_add_arr[t] = '*';
                    route.push_back(t);
                    temp[t] = 1;
                     op[t] = '*';
                    point_to_bf[t] = i;
                    if (temp[0] == 0)
                        num_of_n[t] = num_of_n[i] * M;
                }
                // %
                if (temp[0] == 0)
                {
                    int sub = num_of_n[i] % M;
                    sub = sub < 0 ? sub+M : sub;
                    t = (sub)%K;
                    t = t < 0 ? t+K : t;
                    if (temp[t] == 0)
                    {
//                        later_add_arr[t] = '%';
                        route.push_back(t);
                        temp[t] = 1;
                        op[t] = '%';
                        point_to_bf[t] = i;
                        num_of_n[t] = num_of_n[i] % M;
                        num_of_n[t] = num_of_n[t] < 0 ? num_of_n[t] + M : num_of_n[t];
                    }
                }
                if (temp[value] == 1)
                    break;
            }
            if (temp[value] == 1)
                break;
        }
        if (temp[value] == 1)
        {
            output(temp, op, point_to_bf, value, 0);
            cout << endl;
        }
        else
        {
            cout << "0" << endl;
        }
        
        scanf("%d%d%d", &N, &K, &M);
    }
    
    return 0;
}

/*

437 964 666
-106 17 643
-505 150 452
-654 618 570
-561 614 126
209 293 790
577 806 697
-428 320 979
293 742 721
117 265 767
-184 511 629
-347 995 830
-322 711 778
-90 727 827
-336 493 652
-167 761 876
-833 132 826
870 642 642
847 118 52
50 617 988
0 0 0

7
*%+++++
3
*%+
3
%**
0
7
*--**+*
5
---*-
5
--**+
5
+*+*-
6
*--*-*
6
-**++*
7
+*-**--
0
9
-*+*-**++
6
++***+
6
*--*-*
7
*+*++++
2
*+
0
4
-**-
7
+*--*-*


#include<iostream>
#include<string>
#include<queue>
#define MOD(x,y)   ((x)%(y)+(y))%(y)
using namespace std;

bool hashing[1000][2];
struct node
{
    int dist,modk,modm;
    char opt;
}father[1000][2];
int n,k,m,m_k,n_m;

void print(node cur,int cnt)
{
         if( 1==cnt )
             {
                     putchar(cur.opt);
                     return;
                 }
        print(father[cur.modk][cur.modm],cnt-1);
         putchar(cur.opt);
     }

 void bfs(void)
 {
         queue<node> Q;
         node sn;
    
         m_k=MOD(m,k);
         n_m=MOD(n,m);
         memset(hashing,false,sizeof(hashing));
         sn.modk=MOD(n,k);
         sn.modm=0!=n_m;
         hashing[sn.modk][sn.modm]=true;
         sn.dist=0;
         Q.push(sn);
         while( !Q.empty() )
             {
                     node cur=Q.front();
            
                     Q.pop();
                     for(int i=0;i<4;i++)
                         {
                                 node next;
                    
                                 switch( i )
                                {
                                       case 0:next.modk=MOD(cur.modk+m_k,k);next.opt='+';break;
                                         case 1:next.modk=MOD(cur.modk-m_k,k);next.opt='-';break;
                                         case 2:next.modk=MOD(cur.modk*m_k,k);next.modm=0;next.opt='*';break;
                                         case 3:next.modk=MOD(cur.modm?n_m:0,k);next.opt='%';break;
                                         default:break;
                                     }
                                 if( next.opt!='*' ) next.modm=cur.modm;
                                     next.dist=cur.dist+1;
                                     if( next.modk==MOD(n+1,k) )    {father[next.modk][next.modm]=cur;printf("%d\n",next.dist);print(next,next.dist);puts("");return;}
                                 if( hashing[next.modk][next.modm] )    continue;
                                 hashing[next.modk][next.modm]=true;
                                 father[next.modk][next.modm]=cur;
                                Q.push(next);
                            }
                 }
         puts("0");
         return;
     }

 int main()
 {
         while( scanf("%d%d%d",&n,&k,&m),n||k||m )
                 bfs();
             return 0;
     }

*/