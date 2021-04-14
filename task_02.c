/*
 * task_02.c
 *
 *  Реализовать шейкерную сортировку.
 */
#include <stdio.h>
void swap(int*a, int*b);
void print(int N, int *a);
int shakerSort(int N, int *a);
void solution02(){
	int arr[] = { 99, 88, 77, 66, 55, 44, 33, 22, 11, 8, 5, 3, 1 };
	printf("Array before sorting:\n");
		print(13, arr);

		printf("Array after sorting:\n");

		printf("Count operations - %d\n", shakerSort(13, arr));
		print(13, arr);
}
int shakerSort(int N, int *a){
	int left = 0;
	int right = N - 1;
	int count = 0;

	while(left < right){
		for(int i = left; i < right; i++){
			count++;
			if(a[i] > a[i + 1]){
				swap(&a[i], &a[i + 1]);
			}
		}
		right--;
		for(int i = right; i > left; i--){
			count++;
			if(a[i - 1] > a[i]){
				swap(&a[i - 1], &a[i]);
			}
		}
		left++;
	}
	return count;
}

