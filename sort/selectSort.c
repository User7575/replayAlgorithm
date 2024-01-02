#include <stdio.h>

/* 选择排序: 相较于冒泡排序, 减少了交换的次数 */
/* 时间复杂度也是O(n^2) */

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

/* 选择排序 */
int selectSort(int *array, int length)
{
    int ret = 0;
    int minValue = 0;
    int minIndex = 0;
    for (int pos = 0; pos < length; pos++)
    {
        minValue = array[pos];
        for (int begin = pos + 1; begin < length; begin++)
        {   
            /* 遍历到的元素比最小值要小, 就更新元素 */
            if (minValue > array[begin])
            {
                minValue = array[begin];
                minIndex = begin;
            }
        }

        if (array[pos] > minValue)
        {
            int temp = array[pos];
            array[pos] = minValue;
            array[minIndex] = temp;
        }
    }
    return ret;
}

int main()
{
    int array[] = {54, 78, 3, 89, 127, 128};
    int length = sizeof(array) / sizeof(array[0]);

    /* 选择排序 */
    selectSort(array, length);
    printArray(array, length);
    // printf("min:%d\n", min);

    return 0;
}