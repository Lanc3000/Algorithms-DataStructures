/*
 * task_01.c
 *1. ����������� �������������� ����������� ����������.
 *1. �������� ���������� �������� ��������� ���������������� � �� ���������������� ���������.
 *1. �������� ������� ����������, ������� ���������� ���������� ��������.
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
