/*
 * task_03.c
 *
 * 3. Написать функцию обхода графа в ширину.
 *
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define maxWidth 25

int used[maxWidth] = {0};

typedef struct GraphNode {
    int value;
    int index;
    int isChecked;
    struct GraphNode *qnext;
    struct GraphNode *qprev;
} GraphNode;

typedef struct Queue {
    GraphNode *head;
    GraphNode *tail;
    int size;
} Queue;

Queue q;

void solution03(){


}



int widthTravers(int start, int goal, int size) {
    qPush(&q, start);
    int steps = 0;
    while (q.size > 0) {
        int value = qPop(&q);
        if (used[value] == 1) continue;
        used[value] = 1;
        printf("%c", 65 + value);
        steps++;
        if (value == goal)
            return steps;

        int i;
        for (i = 0; i < size; i++) {
            if (matrix[value][i] == 1 && used[i] == 0)
                qPush(&q, i);

        }
    }
    return -1;
}
