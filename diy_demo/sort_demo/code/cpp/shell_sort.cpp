
#include "shell_sort.h"
#include <QDebug>

ShellSort::ShellSort()
{

}

ShellSort::~ShellSort()
{

}

void ShellSort::sort(double *arr, const int size)
{
    if (!arr)
        return;

    int increment = size;
    do {
        increment = increment / 3 + 1;
        shellPass(arr, size, increment);
    } while(increment > 1);

} //希尔排序（不稳定，时间复杂度(<O(n^2))）

void ShellSort::shellPass(double *arr, int size, int delta)
{
    for (int i = delta; i < size; i++) {
        int tmp = arr[i];
        int j = 0;
        for (j = i - delta; j >= 0 && tmp < arr[j]; j -=delta)
        {
            qDebug() << "i =" << i;
            qDebug() << "j =" << j;
            arr[j + delta] = arr[j];
        }
        arr[j + delta] = tmp;
    }
}

