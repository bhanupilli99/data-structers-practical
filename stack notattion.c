#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int data) {
   if(top == MAX-1) {
      printf("Stack Overflow!");
   } else {
      top++;
      stack[top] = data;
   }
}

int pop() {
   if(top == -1) {
      printf("Stack Underflow!");
      return -1;
   } else {
      int data = stack[top];
      top--;
      return data;
   }
}

int main() {
   push(10);
   push(20);
   push(30);
   printf("%d\n", pop());
   printf("%d\n", pop());
   printf("%d\n", pop());
   printf("%d\n", pop());
   return 0;
}
 
