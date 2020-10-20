#include <bits/stdc++.h>

using namespace std;

/*
找出数组中重复的数字
在一个长度为n的数组里的所有数字都在0~n-1范围内。数组中某些数字是重复的，
但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组{2，3，1，0，2，5，3}，那么对应的输出是重复的数字2或者3。
*/

//1. 排序算法时间复杂度 O(nlogn)

//哈希实现： 时间复杂度O(n)
bool duplicate(int *numbers, size_t len, int *dupnum)
{
    int *hashtable = new int[len]();

    //O(n)
    for (size_t i = 0; i < len; i++)
    {
        cout << "numbers[i]:" << numbers[i] << " hashtable[numbers[i]]" << hashtable[numbers[i]] << endl;
        if (hashtable[numbers[i]])
        {
            *dupnum = numbers[i];
            cout << "dup: " << *dupnum << endl;
            return true;
        }
        else
        {
            //因为数字都在0~n-1范围内
            hashtable[numbers[i]] = 1;
        }
    }

    return false;
}

int main(int argc, const char **argv)
{
    int number[] = {1, 2, 3, 2, 5, 3};
    int dumpnum = 0;

    for (auto var : number)
    {
        cout << "var:" << var << endl;
    }
    bool dup = duplicate(number, sizeof(number) / sizeof(int), &dumpnum);
    if (dup)
    {
        cout << "dup:" << dumpnum << endl;
    }

    return 0;
}