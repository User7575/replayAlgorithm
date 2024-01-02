#include <stdio.h>

/* 交换两个整数 */
int swap(int *val1, int *val2)
{
    int ret = 0;
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    return ret;
}


/* 数组做函数参数会自动弱化成指针 */
int printArray(int *array, int length)
{   
    int ret = 0;
    for (int idx = 0; idx < length; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
    return ret;
}


/* 时间复杂度: O(n^2) */
void bubbleSort01(int *array, int length)
{
    for (int end = length; end > 0; end--)
    {
        for (int begin = 1; begin < end; begin++)
        {
            /* 后面的数 比 前面的数要小 叫交换 */
            if (array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
            } 

        }
    }
}


/* 优化1 */
void bubbleSort02(int *array, int length)
{
    int sorted = 1;
    for (int end = length; end > 0; end--)
    {
        /* 已经排好序的标志 */
        sorted = 1;
        for (int begin = 1; begin < end; begin++)
        {
            /* 后面的数 比 前面的数要小 叫交换 */
            if (array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
                /* 数据是没有排好序的. */
                sorted = 0;
            } 
        }
        if (sorted == 1)
        {
            break;
        }
    }
}

/* 优化2 */
void bubbleSort03(int *array, int length)
{
    int sortedIndex = 0;
    for (int end = length; end > 0; end--)
    {
        /* 已经排好序的索引 */
        sortedIndex = 1;
        for (int begin = 1; begin < end; begin++)
        {
            /* 后面的数 比 前面的数要小 叫交换 */
            if (array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
                /* 更新排好序的索引 */
                sortedIndex = begin;
            }
        }
        /* 更新. */
        end = sortedIndex;
    }
}

int main()
{
    int array[] = {54, 78, 100, 89, 127, 128};
    int length = sizeof(array) / sizeof(array[0]);

#if 1
    // bubbleSort01(array, length);
    // bubbleSort02(array, length);
    bubbleSort03(array, length);

    printArray(array, length);
#endif 

    return 0;
}