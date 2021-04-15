/*
 * task_01.c
 * 1*���������� ��������� � �������������. ����������� ������ ������� � ������������ � ���������� ���������� ���������.
 */
#include <stdio.h>
#define N 3
#define M 3

void print(int n, int m, int a[N][M]);
void routeBuilding(int n, int m, int map[N][M]);

void solution01(){

	int Map[N][M] = { {1, 1, 1}, {0, 1, 1}, {0, 0, 1} };
	printf("the map:\n");
	print(N,M, Map);

	printf("the count of pathes:\n");
	routeBuilding(N, M, Map);
}
void print(int n, int m, int a[N][M]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void routeBuilding(int n, int m, int map[N][M]){
	int path[N][M];
	for(int i = 0; i < M; i++){
		path[0][i] = 1; //��� �� ���� ��������� ������� ��� � ����� ����, ���� ���� �� - � ����� � ������ ������ ����� ���� ����������
	}
	for(int j = 1; j < N; j++){
		if(map[j][0] != 0) //������ ��� � ������ � ������ ��� ���������� ������� ������� ��������� �� ���������
			path[j][0] = 1;
		else
			path[j][0] = 0; // � ������ ���� � ����� �������� �� ���� ����� ���� �����������

		for(int i = 1; i < M; i++){
			if(map[j][i] != 0)
				path[j][i] = path[j][i - 1] + path[j - 1][i];
			else
				path[j][i] = 0;
		}
	}
	print(N, M, path);
}
