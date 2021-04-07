/*
 * task_02.c
 *
 *  –еализовать функцию возведени€ числа a в степень b:
 *		a. без рекурсии;
 *		b. рекурсивно;
 *		c. *рекурсивно, использу€ свойство четности степени.
 */
int powNonRec(int num, int exp);
int powRec(int num, int exp);
void solution02(){
	int a;
	int b;
	printf("Enter the number:");
	scanf("%d", &a);
	printf("Enter the exponent:");
	scanf("%d", &b);

	printf("Non-recuration method:\n");
	printf("%d\n", powNonRec(a, b));
	printf("Non-recurtion method:\n");
	printf("Recuration method:\n");
	printf("%d\n", powRec(a, b));
}
int powNonRec(int num, int exp){
	int i;
	int result = 1;
	for(i = 0; i < exp; i++){
		result *= num;
	}
	return result;
}
int powRec(int num, int exp){
	if(exp == 0)
		return 1;
	else
		return powRec(num, exp - 1) * num;
}
