/*
 * task_02.c
 *
 *  Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.
 */
#include <stdio.h>
#include <string.h>
#define N 20
#define M 20

void printN(int n, int m, char a[N][M]);

int i, j, m, n, c[20][20];
char x[20], y[20], b[20][20];

void printM(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 'c')
	{
		printM(i - 1, j - 1);
		printf("%c", x[i - 1]);
	}
	else if (b[i][j] == 'u')
		printM(i - 1, j);
	else
		printM(i, j - 1);
}

void printN(int n, int m, char arr[N][M]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void lcs()
{
	m = strlen(x);
	n = strlen(y);
	for (i = 0; i <= m; i++)
		c[i][0] = 0;
	for (i = 0; i <= n; i++)
		c[0][i] = 0;

	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 'c';
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 'u';
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 'l';
			}
		}
	printN(m, n, b);
}
void solution02(){
	printf("enter 1st sequence");
	scanf("%s", x);
	printf("enter 2nd sequence");
	scanf("%s", y);
	printf("\n the Longest Common Subsequence is \n");
	lcs();
	printM(m, n);
	printf("\n");


}

