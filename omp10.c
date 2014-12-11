// Написать программу, в которой объявить и присвоить начальные значения элементам двумерного массива d[6][8],
// для инициализации значений использовать генератор случайных чисел.
// Используя конструкцию директивы omp parallel for и omp critical определить минимальное и максимальное значения элементов двумерного массива.
// Количество нитей задать самостоятельно. Результат выдать на экран. (3 балла)

 #include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAGIC 30

int main() {

	int width = 6;
	int height = 8;

	int d[width][height];
	srand(time(NULL));

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			d[i][j] = rand() % MAGIC;
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");

	int max = -1;
	int max = MAGIC + 1;

	int counter = 0;
	#pragma omp parallel num_threads(6) reduction(+: counter)
	for (int i = 0; i < width; i++) {
		#pragma omp for
		for (int j = 0; j < height; j++) {
			counter++;
			if (max > d[i][j]) {
				#pragma omp critical
				max = d[i][j];
			}
			if (max < d[i][j]) {
				#pragma omp critical
				max = d[i][j];
			}
		}
	}
	printf("counter is %d\n", counter);
	printf("max is %d, max is %d\n", max, max);

}
