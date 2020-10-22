#include "bits/stdc++.h"

using namespace std;

//function： 在一维数组arr中查找num
bool find_sort_number_row(int *arr, int len, int num)
{
    cout << __func__ << endl;
    cout << "len:" << len << " arr[0]:" << *arr << endl;
    int mid;
    int p_mid, p_start, p_end;

    p_mid = len / 2;
    mid = *(arr + p_mid);
    cout << "mid:" << mid << endl;

    if (num > mid)
    {
        p_start = p_mid + 1;
        p_end = len;
        if (p_end - p_start < 0)
        {
            return false;
        }
        return find_sort_number_row(arr + p_start, p_end - p_start, num);
    }
    else if (num < mid)
    {
        p_start = 0;
        p_end = p_mid - 1;
        if (p_end - p_start < 0)
        {
            return false;
        }
        return find_sort_number_row(arr + p_start, p_end - p_start, num);
    }
    else
        return true;
}

/*
问题：
二维数组中的查找
在一个二维数组中，每一行都按照从左到右递增的顺序排序，
{0,2,4,6,8}
{1,3,5,7,9}
每一列都按照从上到下的递增的顺序排序，请完成一个函数，
输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。。
*/

//实现算法思想：
//1. 定位二分矩阵 row_mid, col_mid, 比较大小
//2.1.1 如果大，13, 14， 如果比本行最大元素大， 则查找row_mid+1 ~ row
//2.1.2 如果比本行最大元素小， 则二分查找[row_mid, col_mid+1]  ~ [row_mid+1, col]
//2.2.1 如果小,  10, 11, 如果比本行最小元素小， 则二分矩阵查找0 ~ row_mid-1
//2.2.2 如果比本行最小元素大， 则二分查找[row_mid,0] ~ [row_mid, col_mid-1]
bool find_sort_number_matrix(int arr[][5], int row, int num)
{
    size_t col = 5;
    int row_l, row_h;
    int col_l, col_h;
    int row_mid, col_mid;

    row_l = 0;
    row_h = row;
    col_l = 0;
    col_h = col;

    row_mid = (row_l + row_h) / 2;
    col_mid = (col_l + col_h) / 2;
    int mid = arr[row_mid][col_mid];
    cout << "[" << row_mid << "," << col_mid << "] : " << mid << endl;

    if (num == mid)
        return true;
    else if (num > mid)
    {
        int row_max = arr[row_mid][col - 1];
        cout << "num > mid " << endl;
        cout << "row_max:" << row_max << endl;
        cout << "row_max-1:" << arr[row_mid][col - 2] << endl;
        cout << "num:" << num << endl;
        //2.1.1 如果比本行最大元素大， 在下一行查找，则查找row_mid+1 ~ row
        if (num > row_max)
        {
            cout << "num > row_max" << endl;
            row_l = row_mid + 1;
            if (row_l > row)
                return false;
            int(*p)[5] = arr + row_l;
            return find_sort_number_matrix(p, row - row_l, num);
        }
        else if (num < row_max)
        {
            //2.1.2 如果比本行最大元素小， 则二分查找本行元素
            cout << "num < row_max" << endl;
            int *p_row_start = &arr[row_mid][col_mid + 1];
            int len = col - col_mid - 1;
            return find_sort_number_row(p_row_start, len, num);
        }
        else
            return true;
    }
    else
    {
        //2.2.1 如果小,  10, 11, 如果比本行最小元素小， 则二分矩阵查找0 ~ row_mid-1
        //2.2.2 如果比本行最小元素大， 则二分查找[row_mid,0] ~ [row_mid, col_mid-1]
        int row_min = arr[row_mid][0];
        if (num < row_min)
        {
            //在上一行查找
            row_h = row_mid - 1;
            if (row_h < 0)
            {
                return false;
            }
            int(*p)[5] = arr;
            return find_sort_number_matrix(p, row_h, num);
        }
        else if (num > row_min)
        {
            //find in this row
            int *p_row_start = &arr[row_mid][0];
            int len = col_mid - 1;
            return find_sort_number_row(p_row_start, len, num);
        }
        else
            return true;
    }

    return false;
}

int main(int argc, const char **argv)
{
    int row = 6;
    int arr[row][5] = {
        {0, 1, 2, 3, 4},       //0
        {5, 6, 7, 8, 9},       //1
        {10, 11, 12, 13, 14},  //2 2-Binary 12
        {15, 16, 17, 18, 19},  //3
        {20, 21, 22, 23, 24},  //4
        {25, 26, 27, 28, 30}}; //5

    //int num = 28;
    int num = 29;
    bool found = find_sort_number_matrix(arr, row, num);

    if (found)
    {
        cout << "found!" << endl;
    }
    else
    {
        cout << "not found!  num: " << num << endl;
    }

    return 0;
}