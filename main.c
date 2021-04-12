/*
 * main.c
 *
 *  Самигуллин Тимур
 *  Алгоритмы и структуры данных. Урок 3.
 */
#include <stdio.h>
void solution01();
void solution02();
void solution03();
void solution04();
void menu();

int main(){

	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

	int sel = 0;
	do{
		menu();
		scanf("%i", &sel);
		switch(sel){
			case 1:
				solution01();
				break;
			case 2:
				solution02();
				break;
			case 1:
				solution03();
				break;
			case 2:
				solution04();
				break;
			default:
				printf("Wrong selected \n");
		}
	}
	while(sel != 0);
	return 0;
}
void menu(){
	printf("1 - task\n");
	printf("2 - task\n");
	printf("3 - task\n");
	printf("4 - task\n");
}

