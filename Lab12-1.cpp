#include <stdio.h>
#include <conio.h>
#include <locale>

struct Circle
{
	int X;
	int Y;
	int R, G, B;
	int W;
	int RAD;
};

int main()
{
	// var 
	int count = 0; 
	FILE* bin; 
	Circle par; 
	// main 
	setlocale(LC_ALL, "ru");
	fopen_s(&bin, "D:\\Lab12.bin", "wb");
	printf("Введите количество фигур: "); 
	scanf_s("%d", &count);
	fwrite(&count, sizeof(int), 1, bin);

	for (int i = 0; i < count; i++)
	{
		printf("\nВведите координату X: ");
		scanf_s("%d", &par.X);
		printf("\nВведите координату Y: ");
		scanf_s("%d", &par.Y);
		printf("\nВведите радиус: ");
		scanf_s("%d", &par.RAD);
		printf("\nВведите насыщенность красного: ");
		scanf_s("%d", &par.R);
		printf("\nВведите насыщенность зеленого: ");
		scanf_s("%d", &par.G);
		printf("\nВведите насыщенность синего: ");
		scanf_s("%d", &par.B);
		printf("\nВведите толщину линий: ");
		scanf_s("%d", &par.W);
		fwrite(&par, sizeof(Circle), 1, bin);
	}
	fclose(bin);
	return 0;
}
