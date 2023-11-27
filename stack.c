
#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 5
#define EMPTY (-1)

char stack[STACK_SIZE];
int top = EMPTY;

void push(char value) {
    if (top > STACK_SIZE-1) {
        printf("ERROR: stack overflow\n");
        exit(1);
    }
    top++;
    stack[top] = value;
}

void pop() {
    if (top > -1) {
        top--;
    } else {
        printf("ERROR: stack is already empty\n");
        exit(1);
    }
}

int get() {
	if (top > -1 ) {
		return stack[top];
	} else {
		printf("ERROR: stack is empty");
		return 1;
	}
}

int main() {
    push(1);
    push(2);
    push(3);
    pop();
    pop();
    return 0;
}
