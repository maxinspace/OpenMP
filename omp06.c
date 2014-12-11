// 6. Написать программу, в которой объявить и присвоить начальные значения целочисленным массивам a[10] и b[10].
// Используя конструкцию parallel for и reduction вычислить средние арифметические значения элементов массивов a и b,
// сравнить полученные значения, результат выдать на экран. (2 балла)

#include <omp.h>
#include <stdio.h>

int main() {

	int a[10] = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2};
	int b[10] = {10, 2, 3, 4, 5, 1, 5, 4, 3, 2};

	int sum_a = 0, sum_b = 0;
	#pragma omp parallel for reduction(+: sum_a) reduction(+: sum_b)
	for (int i = 0; i < 10; i++) {
		sum_a += a[i];
		sum_b += b[i];
	}

	printf("%d %d\n", sum_a, sum_b);

}
