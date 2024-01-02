#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* 宏定义在预处理阶段 被替换. */
#define BUFFER_SIZE 10

/* 宏函数 -> 无法调试 */
// #define CHECK_PTR()

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


int findAppointValPos(int *array, int length, int val, int *pPos)
{   
    int ret = 0;
    if (array == NULL)
    {
        return -1;
    }

    /* 找到的标记 */
    int flag = 0;
    for (int idx = 0; idx < length; idx++)
    {
        if (array[idx] == val)
        {
            *pPos = idx;
            flag = 1;
        }
    }
    /* 没找到 */
    if (flag == 0)
    {
        *pPos = -1;
    }
    
    return ret;
}


int main()
{
    /* 随机数种子 */
    // srand(time(NULL));

    int buffer[BUFFER_SIZE] = { 0 };
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        buffer[idx] = rand() % 100 + 1;
    }
    
    int length = sizeof(buffer) / sizeof(buffer[0]);
    printArray(buffer, length);
    printf("\n");

    int findNum = 36;
    int pos = 0;
    findAppointValPos(buffer, length, findNum, &pos);
    printf("pos:%d\n", pos);
    return 0;
}