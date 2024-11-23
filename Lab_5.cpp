#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


int main() {
	setlocale(LC_ALL, "Rus");
	int n = 5, count = 0, count_i = 0, sum = 0;
	int* deg = NULL, * loop = NULL, * deg_i = NULL, * loop_i = NULL;
	int** G = NULL, ** I = NULL;
	printf("Введите количество вершин: ");
	srand(time(NULL));

	//scanf("%d", &n);
	G = (int**)malloc(n * sizeof(int*));
	deg = (int*)malloc(n * sizeof(int));
	loop = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i) {
		deg[i] = 0;
		loop[i] = 0;
		G[i] = (int*)malloc(n * sizeof(int));
	}
	printf("\n");

	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
			count += G[i][j];

		}
	}
	
	printf("  ");
	for (int i = 0; i < n; ++i) printf("%d ", i);
	printf("\n");

	for (int i = 0; i < n; ++i) {
		printf("%d ", i);
		for (int j = 0; j < n; ++j) {

			deg[i] += i != j ? G[i][j] : 2 * G[i][j];
			loop[i] += i == j ? 2 * G[i][j] : 0;
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		if (deg[i] - loop[i] == 0) printf("Вершина %d - изолированная\n", i);
		if (deg[i] - loop[i] == 1) printf("Вершина %d - концевая\n", i);
		if (deg[i] - loop[i] == n -1) printf("Вершина %d - доминирующая\n", i);
		//printf("%d %d\n", deg[i], loop[i]);
	}

	printf("\nРазмерM = %d\n\n", count);

	I = (int**)malloc(n * sizeof(int*));
	deg_i = (int*)malloc(count * sizeof(int));
	loop_i = (int*)malloc(count * sizeof(int));

	for (int i = 0; i < n; i++) {
		I[i] = (int*)malloc(count * sizeof(int));
		for (int j = 0; j < count; j++) {
			I[i][j] = 0;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (G[i][j] == 1) {
				I[i][count_i] = 1;
				I[j][count_i] = 1;
				count_i++;
			}
		}
	}

	printf("  ");
	for (int i = 0; i < count; ++i) printf("%c ", i + 97);
	printf("\n");

	for (int i = 0; i < n; i++) {
		printf("%d ", i);
		for (int j = 0; j < count; j++) {
			printf("%d ", I[i][j]);
		}
		printf("\n");
	}



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < count; j++) {
			if (I[i][j] == 1) {
				deg_i[i] += I[i][j];
				for (int k = 0; k < n; k++) {
					sum += I[k][j];
				}
				if (sum == 1) {
					loop_i[i] += 1;
				}
				sum = 0;
			}
		}
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		if (deg_i[i] - loop_i[i] == 0) printf("Вершина %d - изолированная\n", i);
		if (deg_i[i] - loop_i[i] == 1) printf("Вершина %d - концевая\n", i);
		if (deg_i[i] - loop_i[i] == n - 1) printf("Вершина %d - доминирующая\n", i);
		//printf("%d %d\n", deg[i], loop[i]);
	}
	printf("\nРазмерI = %d\n", count_i);
	return 0;
}
