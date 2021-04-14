/*
 * task_01.c
 *1. ����������� �������������� ����������� ����������.
 *1. �������� ���������� �������� ��������� ���������������� � �� ���������������� ���������.
 *1. �������� ������� ����������, ������� ���������� ���������� ��������.
 */
#include <stdio.h>
void swap(int*a, int*b);
void print(int N, int *a);

void solution01(){
	int arr[] = {4, 2, 6, 67, 4, 7, 234, 54, 2, 24, 1};
	int arr2[] = {4, 2, 6, 67, 4, 7, 234, 54, 2, 24, 1};
	printf("Array before sorting:\n");
	print(11, arr);

	printf("Array after sorting:\n");

	printf("Count operations - %d\n", simpleBubleSort(11, arr));
	print(11, arr);

	printf("Array after super Buble sorting:\n");

	printf("Count operations - %d\n", fastBubleSort(11, arr2));
	print(11, arr2);
}
void swap(int *a, int *b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
void print(int N, int *a){
	int i;
	for(i = 0; i < N; i++){
		printf("%6i", a[i]);
	}
	printf("\n");
}
int simpleBubleSort(int N, int *a){
	int count = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N - 1; j++){
			count++; // ������� ���������� ���������
			if(a[j] > a[j+1])
				swap(&a[j], &a[j + 1]);
		}
	}
	return count;
}
int fastBubleSort(int N, int *a){
	int count = 0;
	for(int i = N; i > 1; i--){ // ������� i ��������� ����� �� ����� ������� ����� ������� �������, ����� �� ����������� ��� ��������������� ��������
		for(int j = 0; j < N - 1; j++){
			count++;
			if(a[j] > a[j+1])
				swap(&a[j], &a[j + 1]);
		}
	}
	return count;
}
