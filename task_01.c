/*
 * task_01.c
 *1. Попробовать оптимизировать пузырьковую сортировку.
 *1. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
 *1. Написать функции сортировки, которые возвращают количество операций.
 */
void swap(int*a, int*b);
void print(int N, int *a);
}
void solution01(){



}
void swap(int *a, int *b){
	a ^= b;
	b ^= a;
	a ^= b;
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
			count++;
			if(a[j] > a[j+1]){
				count++;
				swap(&a[j], &a[j + 1]);
			}
		}
	}
	return count;
}
int fastBubleSort(int N, int *a){

}
