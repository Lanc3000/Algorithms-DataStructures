/*
 * task_01.c
 *
 *  –еализовать функцию перевода из дес€тичной системы в двоичную, использу€ рекурсию.
 */
void translateDecInBin(int num);
void solution01(){

	int one = 10;
	int two = 45;


	printf("translate 10 in binar:\n");
	translateDecInBin(one);
	printf("\n");
	printf("translate 45 in binar:\n");
	translateDecInBin(two);
	printf("\n");

}
void translateDecInBin(int num){
	if(num == 0)
		printf("");
	else{
		translateDecInBin(num / 2);
		printf("%d", num % 2);
	}
}
