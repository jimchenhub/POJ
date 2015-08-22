#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

char * result[MAX_SIZE] = {};
int result_num[MAX_SIZE] = {0};

void init ()
{
    int i = 0;
    for (i = 0 ; i < MAX_SIZE; i++)
    {
        result[i] = NULL;
        result_num[i] = 0;
    }
}

int is_valid(char * str)
{
    int i = 0;
    
    if (strlen(str) != 8)
        return 0;

    for (i = 0; i < 8; i++)
    {
        if (i == 3)
        {
            if (str[i] != '-')
                return 0;
        }
        else
        {
            if (!( (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') ))
            {
                return 0;
            }
        }
    }
    return 1;
}

char change(ch)
{
    char res = 0;
    switch(ch)
    {
        case 'A': res = '2'; break;
        case 'B': res = '2'; break;
        case 'C': res = '2'; break;
        case 'D': res = '3'; break;
        case 'E': res = '3'; break;
        case 'F': res = '3'; break;
        case 'G': res = '4'; break;
        case 'H': res = '4'; break;
        case 'I': res = '4'; break;
        case 'J': res = '5'; break;
        case 'K': res = '5'; break;
        case 'L': res = '5'; break;
        case 'M': res = '6'; break;
        case 'N': res = '6'; break;
        case 'O': res = '6'; break;
        case 'P': res = '7'; break;
        case 'R': res = '7'; break;
        case 'S': res = '7'; break;
        case 'T': res = '8'; break;
        case 'U': res = '8'; break;
        case 'V': res = '8'; break;
        case 'W': res = '9'; break;
        case 'X': res = '9'; break;
        case 'Y': res = '9'; break;
    }
    return res;
}

void add_to_result(char * str)
{
    int flag = 0;
    int i = 0;
    
    while (result[i] != NULL)
    {
        if (strcmp(result[i], str) == 0)
        {
            result_num[i]++;
            flag = 1;
            break;
        }
        i++;
    }

    if (flag == 0)
    {
        strcpy(result[i], str);
        result_num[i] = 1;
    }
}

void output ()
{
    int i = 0;
    while (result[i] != NULL)
    {
        printf("%s %d\n", result[i], result_num[i]);
    }
}

int main (void) 
{
    int count = 0;
    int i = 0, j = 0;
    char * temp_str = NULL;

    init();

    scanf("%d", &count);

    for (i = 0 ; i < count ; i++)
    {
        j = 0;
        scanf("%s", temp_str);

        if (temp_str == NULL)
        {
            continue;
        }

        if (!is_valid(temp_str))
        {
            continue;
        }
        
        for (j = 0; i < 8; j++)
        {
            if (temp_str[j] >= 'A' && temp_str[j] <= 'Z')
            {
                temp_str[j] = change(temp_str[j]);
            }
        }

        add_to_result(temp_str);
    }
    
    output();

    return 0;
}