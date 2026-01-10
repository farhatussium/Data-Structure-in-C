#include<stdio.h>
#define n 3
int stack[n];
int top=-1;
void push(int x){
    if(top<n-1){
    top++;
    stack[top]=x;
    printf("pushed %d to stack\n",x);
    } 
    else {
        printf("Stack Overflow\n");
    }
}
void pop(){
    if(top>=0){
       int val=stack[top];
       top--;
       printf("popped %d from stack\n",val);
    }
    else{
        printf("Stack Underflow\n");
  }
}
void peek(){
    if(top>=0){
    printf("Top element is %d\n",stack[top]);
    }
    else{
    printf("Stack is empty\n");
    }
}
int main(){
printf("Stack Implementation\n");
peek();
push(10);
push(20);
push(30);
pop();
push(40);
peek();
}