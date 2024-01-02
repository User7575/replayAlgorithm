#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 10

/* 数组做函数参数会自动弱化成指针 */
int printArray(int *array, int length)
{   
    int ret = 0;
    if (array == NULL)
    {
        return ret;
    }
    for (int idx = 0; idx < length; idx++)
    {
        printf("%d\t", array[idx]);
    }
    return ret;
}


/* 找到基准值的位置 */
static int findBaseValPos(int *array, int start, int end)
{
    int ret = 0;
    end--;
    /* 基准值 */
    int baseValPos = array[start];
    while (start < end)
    {
        while (start < end)
        {
            if (array[end] < baseValPos)
            {
                array[start++] = array[end];
                break;
            }
            else
            {
                end--;
            }
        }

        while (start < end)
        {
            if (array[start] > baseValPos)
            {
                array[end--] = array[start];
                break;
            }
            else
            {
                start++;
            }
        }    
    }   // 退出条件是：start = end.
    array[start] = baseValPos;
    return start;   
}   

/* 快速排序 */
int quickSort02(int *array, int start, int end)
{
    int ret = 0;
    if (array == NULL)
    {
        return ret;
    }
    /* 如果start == end 说明数组只有一个元素. 直接返回. */
    if (start >= end)
    {
        return ret;
    }
    int baseValPos = findBaseValPos(array, start, end);

    /* 对基准值左侧排序 */
    quickSort02(array, start, baseValPos);
    /* 对基准值右侧排序 */
    quickSort02(array, baseValPos + 1, end);

    return ret;
}

/* 返回值: 1表示存在。 0表示不存在. */
int binarySearchAppointValPos(int *array, int length, int val)
{
    if (array == NULL)
    {
        return 0;
    }

    /* */
    int start = 0;
    int end = length - 1;

    int mid = 0;
    while(start <= end)
    {
        #if 0
        mid = (end + start) / 2;
        #else
        mid = (end + start) >> 1;
        #endif

        /* 找到了 */
        if(array[mid] == val)
        {
            return mid;
        }
        else if(array[mid] < val)
        {
            start = mid + 1;
        }
        else if(array[mid] > val)
        {
            end = mid - 1;
        }
    }
    /* 没找到 */
    return -1;
}


int main()
{
    int buffer[BUFFER_SIZE] = { 0 };
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        buffer[idx] = rand() % 100 + 1;
    }
    int length = sizeof(buffer) / sizeof(buffer[0]);
    quickSort02(buffer, 0, length);
    printArray(buffer, length);
    printf("\n");

    int val = 78;
    int isExist = binarySearchAppointValPos(buffer, length, val);
    printf("isdExist:%d\n", isExist);
    return 0;
}