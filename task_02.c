/*
 * task_02.c
 *
 * 2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти.
 * 	  Если память не выделяется, то выводится соответствующее сообщение.
 */
#include <stdio.h>
#include <malloc.h>
#define T char

struct TNode{
	T value;
	struct TNode *next;
};
typedef struct TNode Node;

struct Stack{
	Node *head;
	int maxSize;
	int size;
};
struct Stack Stack;
void push(T value){
	if(Stack.size >= Stack.maxSize){
		printf("Stack is overflow");
		return;
	}
	Node *tmp = NULL;
	if(tmp = (Node*)malloc(sizeof(Node))){ //проверка на выделение памяти
		tmp->value = value;
		tmp->next = Stack.head;

		Stack.head = tmp;
		Stack.size++;
	}
	else
		printf("Memory exception");
}
T pop(){
	if(Stack.size == NULL){
		printf("Stack is empty");
		return;
	}
	Node *next = NULL;
	T value = Stack.head->value;
	 next = Stack.head;
	 Stack.head = Stack.head->next;

	 free(next);
	 Stack.size--;
	 return value;
}
void PrintS(struct Stack stack){
	Node *current = stack.head;
	while(current != NULL){
		printf("|%c| \n", current->value);
		current = current->next;
	}
}
void solution02(){
	Stack.maxSize = 100;
	Stack.head = NULL;
	push('a');
	push('b');
	push('c');
	push('d');
	push('e');
	push('f');
	push('g');

	PrintS(Stack);
}

