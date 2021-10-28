#include <stdio.h>
#include <locale>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int arr[100]{};
	int max, min, size, index_max = 0, index_min = 0, ch = 0, d = 0;
	printf("Введите количество элементов массива:");
	scanf_s("%d", &size);
	printf("Введите %d элементов массива: \n", size);
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	max = arr[0];
	min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			index_max = i;
		}
		if (arr[i] < min)
		{
			min = arr[i];
			index_min = i;
		}
	}
	printf("Массив с удаленными четными элементами между максимальным и минимальным:\n");
	switch (index_min > index_max)
	{
	case true:
		d = index_max + 1;
		while (d != size - 1) {
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
		for (int i = index_min + 1; i < size; i++) {
			arr[i - ch] = arr[i];
		}
		break;
	case false:
		d = index_min + 1;
		while (d != size - 1) {
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
		for (int i = index_max + 1; i < size; i++) {
			arr[i - ch] = arr[i];
		}
		break;
	}
	for (int i = 0; i < size - ch ; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

