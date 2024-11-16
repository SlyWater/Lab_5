#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


int main() {
	setlocale(LC_ALL, "Rus");
	int n = 2;
	int c = 0, *deg, *loop;
	int** G = NULL;
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
			c += G[i][j];

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

	printf("\n");
	printf("%d", c);
	return 0;
}
