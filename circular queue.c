#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;
int isFull(){
    return (rear+1)%MAX == front;
}

int isEmpty(){
    return front == -1;
}

void enqueue(int data){
    if(isFull()){
        printf("Queue Overflow!!!\n");
        return;
    }
    else if(isEmpty()){
        front = rear = 0;
    }
    else if(rear == MAX-1)
        rear=0;
    else
        rear++;
    queue[rear] = data;
    printf("Element inserted !!\n");

}
int dequeue(){
    if(isEmpty()){
        printf("Queue Underflow!!\n");
        return -1;
    }
    int val = queue[front];
    if(front == rear)
        front = rear = -1;
    else if(front == MAX-1)
        front = 0;
    return val;

}

int peek(){
    if(isEmpty()){
        printf("Queue Underflow!!\n");
        return -1;
    }
    return queue[front];

}

void display(){
    if(isEmpty()){
        printf("Queue is Empty!!\n");
        return;
    }
    int i=front;
    while(1){
        printf("%d ", queue[i]);
        if(i == rear)
            break;
        i = (i+1)%MAX;
    }

}
int main(){
    int choice,value,res;
    while(1){
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data");
                scanf("%d\n", &value);
                enqueue(value);
                break;
            case 2:
                res = dequeue();
                if(res != -1)
                printf("%d\n", res);
                break;
            case 3:
                res = peek();
                if(res != -1)
                printf("%d\n", res);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
                default:
                printf("Invalid\n");
        }
        
    }
    return 0;
}
