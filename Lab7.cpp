#include <stdio.h>
#include <locale>
#include <conio.h>
int FindInmin(int arrlen, int* arr)
{
    int min = arr[0];
    int index_min = 0;
    for (int i = 0; i < arrlen; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            index_min = i;
        }
    }
    return index_min;
}

int FindInmax(int arrlen, int* arr)
{
    int max = arr[0];
    int index_max = 0;
    for (int i = 0; i < arrlen; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            index_max = i;
        }
    }
    return index_max;
}

int FindMin(int arrlen, int* arr)
{
    int  min = arr[0];
    for (int i = 0; i < arrlen; i++)
    {
        if (arr[i] < min)
        {
           min = arr[i];
        }     
    }
    return min;
}

int FindMax(int arrlen, int* arr)
{
    int  max = arr[0];
    for (int i = 0; i < arrlen; i++)
    {
        if (arr[i] > max)
        {
           max = arr[i];       
        }       
    }
    return max;
}

void InputArr(int* len, int* arr)
{
    printf("Введите количество элементов массива: ");
    scanf_s("%d", len);
    printf("Введите  элементы массива: ");
    for (int i = 0; i < *len; i++)
    {
        scanf_s("%d", &arr[i]);
    }
}

void PrintArr(int len, int* arr)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

void ChangeArr(int* len, int* arr)
{
    int max, min, d = 0, index_max = 0, index_min = 0;
    max = FindMax(*len, arr);
    min = FindMin(*len, arr);
    index_max = FindInmax(*len, arr);
    index_min = FindInmin(*len, arr);
    int ch = 0;
    switch (index_min > index_max)
    {
    case true:
        d = index_max + 1;
        while (d != *len - 1) {
            if (arr[d] % 2 != 0)
            {
                arr[d - ch] = arr[d];
            }
            else {
                ch++;               
            }
            d++;
            if (d == index_min) {
                arr[d - ch] = arr[d];
                break;
            }
        }
        for (int i = index_min + 1; i < *len; i++) {
            arr[i - ch] = arr[i];
        }
        break;
    case false:
        d = index_min + 1;
        while (d != *len - 1) {
            if (arr[d] % 2 != 0) {
                arr[d - ch] = arr[d];
            }
            else {
                ch++;
            }
            d++;
            if (d == index_max) {
                arr[d - ch] = arr[d];
                break;
            }
        }
        for (int i = index_max + 1; i < *len; i++) {
            arr[i - ch] = arr[i];
        }
        break;
    }
    *len -= ch;
}


int main()
{
    setlocale(LC_ALL, "ru");
    int len, arr[10]; 
    InputArr(&len, arr);
    ChangeArr(&len, arr);
    PrintArr(len, arr);
    return 0; 
}
