#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
题目：
替换空格
请实现一个函数，把字符串中的每个空格替换成“%20”，
例如，输入”We are happy.”,则输出”We%20are%20happy.”。
*/

char *replace_spaces(const char *src, size_t slen)
{
    char *desc = NULL;
    size_t count = 0;
    size_t j = 0;

    //malloc mem
    for (size_t i = 0; i < slen; i++)
    {
        if (src[i] == ' ')
        {
            count++;
        }
    }
    desc = (char *)malloc(slen + count * 2);

    //copy
    for (size_t i = 0; i < slen; i++)
    {
        if (src[i] == ' ')
        {
            desc[j++] = '%';
            desc[j++] = '2';
            desc[j++] = '0';
        }
        else
        {
            desc[j++] = src[i];
        }
    }

    desc[j++] = '\0';

    return desc;
}

int main(int argc, const char **argv)
{
    char *str = (char *)"We are happy.";
    size_t len = strlen(str);

    char *dest = replace_spaces(str, len);

    if (strcmp(dest, "We%20are%20happy.") == 0)
        cout << "dest replace sucess!" << endl;
    else
        cout << "Error: dest replace failed!" << endl;

    return 0;
}