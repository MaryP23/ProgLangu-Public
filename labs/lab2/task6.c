#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100 

typedef struct stack {
    int arr[N]; 
    int top;      
} stack;

void zad(stack* s) {
    s->top = -1; 
}

bool pust(stack* s) {
    return s->top == -1;
}

bool full(stack* s) {
    return s->top == N - 1;
}

bool push(stack* s, int sch) {
    if (full(s)) {
        printf("Error.the stack is full.\n");
        return false;
    }
    s->arr[++(s->top)] = sch;
    return true;
}

bool out(stack* s, int* sch) {
    if (pust(s)) {
        printf("Error.the stack is empty.\n");
        return false;
    }
    *sch = s->arr[(s->top)--];
    return true;
}

bool view(stack* s, int* sch) {
    if (pust(s)) {
        printf("Error.The stack is empty..\n");
        return false;
    }
    *sch = s->arr[s->top];
    return true;
}

int main() {
    stack s;
    zad(&s); 

    push(&s, 15);

    int sch;

    if (view(&s, &sch)) {
        printf("the top value of the stack. %d\n", sch);
    }

    while (out(&s, &sch)) {
        printf("Extracing from the stack: %d\n", sch);
    }

    for (int i = 0; i < 105; ++i) {
        if (!push(&s, i)) {
            break;
        }
    }

    return 0;
}
