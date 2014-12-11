// 7. Написать программу, в которой определить две параллельные области, каждая из которых содержит итерационную конструкцию for
// выполняющую инициализацию элементов одномерных массивов целых чисел a[12], b[12] и c[12].
// Число нитей перед первой областью задать равным 3, перед второй – равным 4.
// Первая параллельная область выполняет инициализацию элементов массивов a и b с использованием статического распределения итераций,
// размер порции итераций выбрать самостоятельно, вторая параллельная область выполняет инициализацию элементов массива c по следующему правилу
// c[i] = a[i] + b[i], с использованием динамического распределения итераций, размер порции итераций выбрать самостоятельно.
// В каждой области определить и выдать на экран количество нитей, номер нити и результат выполнения цикла.
// Убедиться в правильности работы программы.  (5 баллов)

#include <omp.h>
#include <stdio.h>

#define MAGIC 12

int main() {

	int a[MAGIC], b[MAGIC], c[MAGIC];

	//omp_set_dynamic(0);
	//omp_set_num_threads(3);
#pragma omp parallel num_threads(3)
	{
		#pragma omp for schedule(static)
		for (int i = 0; i < MAGIC; i++) {
			a[i] = i * 2;
			b[i] = i * 3;
			printf("working %d of %d threads\n", omp_get_thread_num(), omp_get_num_threads());
		}
	}

	for (int i = 0; i < MAGIC; i++) {
		printf("%d ", a[i]);
	} printf("\n");

	for (int i = 0; i < MAGIC; i++) {
		printf("%d ", b[i]);
	} printf("\n");


	omp_set_num_threads(1);

	#pragma parallel omp for schedule(dynamic, 2)
		for (int i = 0; i < MAGIC; i++) {
			c[i] = a[i] + b[i];
			printf("working %d of %d threads\n", omp_get_thread_num(), omp_get_num_threads());
		}

		for (int i = 0; i < MAGIC; i++) {
			printf("%d ", c[i]);
		} printf("\n");



}
