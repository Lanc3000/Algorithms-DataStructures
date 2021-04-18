/*
 * task_03.c
 *
 * 3. Ќаписать программу, котора€ определ€ет, €вл€етс€ ли введенна€ скобочна€ последовательность правильной.
 * 	  ѕримеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных Ч )(, ())({), (, ])}), ([(]) дл€ скобок [,(,{.
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct Stack{
	int top;
	unsigned capacity;
	int *array;
};
struct Stack *createStack(unsigned capacity){
	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
	if(!stack)
		return NULL;
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	if(!stack-> array)
		return NULL;

	return stack;
}

int isEmpty(struct Stack *stack){
	return stack->top == -1;
}

char peek(struct Stack *stack){
	return stack->array[stack->top];
}
char pop1(struct Stack *stack){
	if(!isEmpty(stack))
		return stack->array[stack->top--];
	return '$';
}
void push1(struct Stack *stack, char op){
	stack->array[++stack->top] = op;
}
int evaluatePostfix(char *exp){
	struct Stack *stack = createStack(strlen(exp));
	int i;
	if(!stack)
		return -1;

	for(i = 0; exp[i]; ++i){
		if(isdigit(exp[i]))
			push1(stack, exp[i] - '0');
		else
		{
			int val1 = pop1(stack);
			int val2 = pop1(stack);
			switch(exp[i]){
				case '+': push1(stack, val2 + val1);
					break;
				case '-': push1(stack, val2 - val1);
					break;
				case '*': push1(stack, val2 * val1);
					break;
				case '/': push1(stack, val2 / val1);
					break;
			}
		}
	}
	return pop1(stack);
}
void solution03(){
	char exp[] = "231*+9-";
	printf("postfix evaluation: %d", evaluatePostfix(exp));
	getch();

}

