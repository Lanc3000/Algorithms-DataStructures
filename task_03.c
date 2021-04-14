/*
 * task_03.c
 *
 *  Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив.
 *  Функция возвращает индекс найденного элемента или -1, если элемент не найден.
 */
void print(int N, int *a);
int binarySearch(int N, int *arr, int key);
void solution03(){
	int arr[] = {1, 3, 3, 5, 32, 45, 66, 234, 256, 777, 1345, 34567};
	int one = 777;
	int two = 7;
	printf("Array:\n");
	print(12, arr);
	printf("Search number %d:\n", one);
	printf("Index - %d\n", binarySearch(12, arr, one));

	printf("Search number %d:\n", two);
	printf("Index - %d\n", binarySearch(12, arr, two));

}
int binarySearch(int N, int *arr, int key){
	int left = 0;
	int right = N - 1;
	int currInd;
	while(1){
		currInd = (left + right)/2;
		if(arr[currInd] == key)
			return currInd;
		else{
			if(left >= right) //ничего не нашли
				return -1;
			else{ //деление диапазона
				if(arr[currInd] > key)
					left = currInd + 1; //поиск в верхней половине
				else
					right = currInd - 1; // в нижней половине
			}
		}
	}
}
