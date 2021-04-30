/*
 * task_02.c
 *
 * 2. Написать рекурсивную функцию обхода графа в глубину.
 */
#define maxWidth 25

int isChecked[maxWidth] = {0};

void solution02(){

}


int depthTravers(int start, int goal, int size) {
    printf("%c", 65 + start);
    if (start == goal || isChecked[start]) {
        return 1;
    } else {
        isChecked[start] = 1;
        int j;
        for (j = 0; j < size; j++)
            if (matrix[start][j] == 1 && isChecked[j] == 0)
                return depthTravers(j, goal, size);
    }
    return 0;
}
