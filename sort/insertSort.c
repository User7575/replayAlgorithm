#include <stdio.h>


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

int insertSort01(int *array, int length)
{
    int ret = 0;

    int num = 0;
    for (int pos = 1; pos < length; pos++)
    {
        num = array[pos];
        for (int idx = pos; idx >= 0; idx--)
        {
            if (array[idx - 1] > num)
            {
                array[idx] = array[idx - 1];
            }
            else
            {
                array[idx] = num;
                break;
            }
        }
    }
    return ret;
}


int insertSort02(int *array, int length)
{
    int ret = 0;

    int copyNum = 0;
    int cur = 0;
    for (int idx = 1; idx < length; idx++)
    {
        cur = idx;     
        copyNum = array[idx];
        while (cur > 0 && copyNum < array[cur - 1])
        {
            array[cur] = array[cur - 1];
            cur--;
        }   // 退出条件是: cur == 0 && copyNum >= array[cur - 1]
        array[cur] = copyNum;
    }

    return ret;
}



int main()
{
    int array[] = {24, 30, 10, 68, 12, 39};
    int length = sizeof(array) / sizeof(array[0]);

    // insertSort01(array, length);
    insertSort02(array, length);

    printArray(array, length);

    return 0;
}