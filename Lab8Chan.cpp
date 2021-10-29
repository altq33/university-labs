#include <stdio.h> 
#include <locale>
#include <stdlib.h>



int FindInmax(int len, int* arr)
{
    int max = arr[0];
    int inmax = 0;
    for (int i = 0; i < len; i++)
    {
        if (max < arr[i])
        {    
            max = arr[i];
            inmax = i;
        }
    }
    return inmax;
}
int FindInmin(int len, int* arr)
{
    int min = arr[0];
    int inmin = 0;
    for (int i = 0; i < len; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            inmin = i;
        }
    }
    return inmin;
}

void InputArray(int* len, int** arr) {
    FILE* FirstFile;
    fopen_s(&FirstFile, "D:\\lab.txt", "rt");
    fscanf_s(FirstFile, "%d", len);
    *arr = (int*)malloc(sizeof(int) * *len);
    for (int i = 0; i < *len; i++) {
        fscanf_s(FirstFile, "%d", &((*arr)[i]));
    }
    fclose(FirstFile);
}

void OutputArray(int len, int* arr)
{
    FILE* SecondFile;
    int inmax = FindInmax(len, arr), inmin = FindInmin(len, arr);;

    switch (inmax > inmin)
    {
    case true:
        fopen_s(&SecondFile, "D:\\Lab2.txt", "wt");
        fprintf(SecondFile, "Четные элементы между минимальным и максимальным:\n");
        for (int i = inmin + 1; i < inmax; i++)
        {
            if (arr[i] % 2 == 0)
                fprintf(SecondFile, "%d ", arr[i]);
        }
        fclose(SecondFile);
        break;
    case false:
        fopen_s(&SecondFile, "D:\\Lab2.txt", "wt");
        fprintf(SecondFile, "Четные элементы между минимальным и максимальным:\n");
        for (int i = inmax + 1; i < inmin; i++)
        {
            if (arr[i] % 2 == 0)
                fprintf(SecondFile, "%d ", arr[i]);
        }
        fclose(SecondFile);
        break;
    }
}



int main()
{
    setlocale(LC_ALL, "ru");
    int* arr;
    int len;  
    InputArray(&len, &arr);
    OutputArray(len, arr);
    printf("Ответ успешно записан в файл!");
    free(arr);
    return 0;
}