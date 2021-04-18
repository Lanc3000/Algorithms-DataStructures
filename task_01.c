/*
 * task_01.c
 * 1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
 */
#include <stdio.h>
#include <malloc.h>

#define T int

struct TNode
{
	T value;
	struct TNode* next;
};
typedef struct TNode Node;

struct Stack{
	Node *head;
	int size;
	int maxSize;
};
struct Stack Stack;

void Push(T value){
	if(Stack.size >= Stack.maxSize){
		printf("Stack overflow");
		return;
	}
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = Stack.head; // записываем ссылку на предыдущий первый элемент как на следующий для нового первого элемента
	Stack.head = tmp; //новый элемент записывается как голова стека
	Stack.size++;
}

T Pop(){
	if(Stack.size == 0){
		printf("Stack is empty");
		return;
	}
	Node* next = NULL;

	T value;
	value = Stack.head->value;

	next = Stack.head;

	Stack.head = Stack.head->next;

	free(next);
	Stack.size--;
	return value;
}
void PrintStack(struct Stack stack){
	Node* current = Stack.head;
	while(current != NULL){
		printf("%d", current->value);
		current = current->next;
	}

}
void solution01(){

	Stack.head = NULL;
	Stack.maxSize = 1000;
	int num;

	printf("Enter the number:\n");
	scanf("%d", &num);

	while(num != 0){
		Push(num % 2);
		num = num / 2;
	}
	PrintStack(Stack);
}

