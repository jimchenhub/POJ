// #include <stdio.h>

// char card[4][13] = {0};
// char card_type[4][13] = {0};

// int transfer(char ch, int type)
// {
//     int res = 0;
//     if (type == 1)
//     {
//         switch(ch)
//         {
//             case 'C': res = 1;break;
//             case 'D': res = 2;break;
//             case 'S': res = 3;break;
//             case 'H': res = 4;break;
//         }
//     }
//     else if (type == 2)
//     {
//         switch(ch)
//         {
//             case 'T': res = 10;break;
//             case 'J': res = 11;break;
//             case 'Q': res = 12;break;
//             case 'K': res = 13;break;
//             case 'A': res = 14;break;
//             default: res = (int)(ch - '0');break;
//         }
//     }
//     return res;
// }

// int before(char type, char value, char type_bf, char value_bf)
// {
//     int type_int = 0, type_bf_int = 0, value_int = 0, value_bf_int = 0;

//     type_int = transfer(type, 1);
//     type_bf_int = transfer(type_bf, 1);
    
//     if (type_int < type_bf_int)
//         return 1;
    
//     if (type_int > type_bf_int)
//         return 0;
    
//     value_int = transfer(value, 2);
//     value_bf_int = transfer(value_bf, 2);

//     if (value_int < value_bf_int)
//         return 1;
    
//     return 0;
// }

// void insert_card(char type, char value, int count)
// {
//     int i = 0, last = 12, line = count % 4;
    
//     if (card[line][0] == 0)
//     {
//         card[line][0] = value;
//         card_type[line][0] = type;
//     }
//     else
//     {
//         while ( card[line][i] != 0 && !before(type, value, card_type[line][i], card[line][i]))
//         {
//             i++;
//         }
        
//         if (card[line][i] != 0)
//         {
//             last = count / 4 - 1;
//             while(last >= i)
//             {
//                 card[line][last+1] = card[line][last];
//                 card_type[line][last+1] = card_type[line][last];
//                 last--;
//             }
//         }
        
//         card[line][i] = value;
//         card_type[line][i] = type;
//     }
// }

// void output_line(int line)
// {
//     int i = 0;
//     if (line == 1)
//     {
//         for (i = 0; i < 13; i++)
//         {
//             printf("+---");
//         }
//         printf("+\n");
//     }
//     else
//     {
//         for (i = 0; i < 13; i++)
//         {
//             printf("|%c %c",card[line][i], card[line][i]);
//         }
//         printf("|\n");
//     }
// }

// void output(int line)
// {
//     int i = 0;
    
//     output_line(1);
//     output_line(2);
    
//     for (i = 0; i < 13; i++)
//     {
//         printf("| %c ",card_type[line][i]);
//     }
//     printf("|\n");

//     output_line(2);
//     output_line(1);
// }

// int main(void)
// {
//     char start = 0, type = 0, value = 0;
//     int count = 0,i = 0,start_place = 0;
//     char* str[4] = {"South","West","North","East"};
    
//     scanf("%c", &start);
//     getchar();
    
//     scanf("%c", &type);
//     while (type != '#')
//     {
//         scanf("%c", &value);
        
//         insert_card(type, value, count);
        
//         scanf("%c", &type);
//         if (type == '\n')
//         {
//             scanf("%c", &type);
//         }
//         count++;
//     }
    
//     switch(start)
//     {
//         case 'S': start_place = 3;break;
//         case 'W': start_place = 2;break;
//         case 'N': start_place = 1;break;
//         case 'E': start_place = 0;break;
//     }
    
//     for(i = 0; i < 4; i++)
//     {
//         printf("%s player:\n",str[i]);
        
//         output((i+start_place)%4);
//     }
    
// }

#include <iostream>  
#include <string>  
#include <vector>  
#include <cctype>  
#include <algorithm>  
#include <map>  
using namespace std;  
  
struct Info//扑克牌的牌面   
{  
    char num;  
    char color;  
}card;  
  
//各个选手的牌   
vector<Info> n;  
vector<Info> e;  
vector<Info> s;  
vector<Info> w;  
map<char, int> m;  
map<char, int> mm;  
  
bool cmp(Info a, Info b)//主要是这个比较函数，通过map函数，使其不同字母的比较变得简单了！   
{  
     if (a.color == b.color)  
     {  
         if ((isdigit(a.num) && isdigit(b.num)) || (isdigit(a.num) && isalpha(b.num)) || (isdigit(b.num) && isalpha(a.num)))  
            return a.num < b.num;  
         else if (isalpha(a.num) && isalpha(b.num))  
            return m[a.num] < m[b.num];  
     }  
     else   
     {  
          return mm[a.color] < mm[b.color];  
     }      
}  
  
int main()  
{  
    int i;  
    char direction;  
    string str1, str2, str;  
    m['T'] = 1, m['J'] = 2, m['Q'] = 3, m['K'] = 4, m['A'] = 5;  
    mm['C'] = 1, mm['D'] = 2, mm['S'] = 3, mm['H'] = 4;  
    while (cin >> direction)  
    {  
          if (direction == '#') break;  
          n.clear(), e.clear(), s.clear(), w.clear();  
          cin >> str1 >> str2;  
          str = str1 + str2;  
          if (direction == 'N')//如果是N派发，则派牌的顺序是eswn！下面的则照顺时针推出！   
          {  
              for (i = 0; i < 104; i += 2)  
              {  
                  card.color = str[i];  
                  card.num = str[i+1];  
                  if (i%8==0)  
                     e.push_back(card);  
                  else if (i%8==2)  
                     s.push_back(card);  
                  else if (i%8==4)  
                     w.push_back(card);  
                  else if (i%8==6)  
                     n.push_back(card);  
              }  
          }  
          else if (direction == 'E')  
          {  
              for (i = 0; i < 104; i += 2)  
              {  
                  card.color = str[i];  
                  card.num = str[i+1];  
                  if (i%8==0)  
                     s.push_back(card);  
                  else if (i%8==2)  
                     w.push_back(card);  
                  else if (i%8==4)  
                     n.push_back(card);  
                  else if (i%8==6)  
                     e.push_back(card);  
              }  
          }  
          else if (direction == 'S')  
          {  
               for (i = 0; i < 104; i += 2)  
              {  
                  card.color = str[i];  
                  card.num = str[i+1];  
                  if (i%8==0)  
                     w.push_back(card);  
                  else if (i%8==2)  
                     n.push_back(card);  
                  else if (i%8==4)  
                     e.push_back(card);  
                  else if (i%8==6)  
                     s.push_back(card);  
              }  
          }  
          else if (direction == 'W')  
          {  
               for (i = 0; i < 104; i += 2)  
              {  
                  card.color = str[i];  
                  card.num = str[i+1];  
                  if (i%8==0)  
                     n.push_back(card);  
                  else if (i%8==2)  
                     e.push_back(card);  
                  else if (i%8==4)  
                     s.push_back(card);  
                  else if (i%8==6)  
                     w.push_back(card);  
              }  
          }  
            
          sort(s.begin(), s.end(), cmp);  
          sort(w.begin(), w.end(), cmp);  
          sort(n.begin(), n.end(), cmp);  
          sort(e.begin(), e.end(), cmp);  
          cout << "South player:" << endl;  
          cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;  
          for (i = 0; i < 13; i++)  
              cout << "|" << s[i].num << " " << s[i].num;  
          cout << "|" << endl;  
          for (i = 0; i < 13; i++)  
              cout << "| " << s[i].color << " ";  
          cout << "|" << endl;  
           for (i = 0; i < 13; i++)  
              cout << "|" << s[i].num << " " << s[i].num;  
          cout << "|" << endl;  
          cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;  
          cout << "West player:" << endl;  
          cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;  
          for (i = 0; i < 13; i++)  
              cout << "|" << w[i].num << " " << w[i].num;  
          cout << "|" << endl;  
          for (i = 0; i < 13; i++)  
              cout << "| " << w[i].color << " ";  
          cout << "|" << endl;  
           for (i = 0; i < 13; i++)  
              cout << "|" << w[i].num << " " << w[i].num;  
          cout << "|" << endl;  
          cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;  
          cout << "North player:" << endl;  
          cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;  
          for (i = 0; i < 13; i++)  
              cout << "|" << n[i].num << " " << n[i].num;  
          cout << "|" << endl;  
          for (i = 0; i < 13; i++)  
              cout << "| " << n[i].color << " ";  
          cout << "|" << endl;  
           for (i = 0; i < 13; i++)  
              cout << "|" << n[i].num << " " << n[i].num;  
          cout << "|" << endl;  
          cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;  
          cout << "East player:" << endl;  
          cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;  
          for (i = 0; i < 13; i++)  
              cout << "|" << e[i].num << " " << e[i].num;  
          cout << "|" << endl;  
          for (i = 0; i < 13; i++)  
              cout << "| " << e[i].color << " ";  
          cout << "|" << endl;  
           for (i = 0; i < 13; i++)  
              cout << "|" << e[i].num << " " << e[i].num;  
          cout << "|" << endl;  
          cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;  
          cout << endl;  
    }  
      
    system("pause");  
} 