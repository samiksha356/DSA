#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL)
        printf("Queue overflow!!!\n");
    else{
        temp->data = data;
        temp->next = NULL;
        if(front == NULL && rear == NULL)
            front = rear= temp;
        else{
            rear->next=temp;
            rear=temp;
        }
        printf("%d push into the queue !!!\n", data);
    }
}
int dequeue(){
    if(front == NULL && rear == NULL){
        printf("Queue underflow!!!\n");
        return -1;

    }
    else{
        int val = front->data;
        front = front->next;
        if(front == NULL)
            rear = front;
        return val;
    }
}
int peek(){
    if(front == NULL && rear == NULL){
        printf("Queue underflow!!!\n");
        return -1;

    }
    else{
        return front->data;
        
    }
}
void display(){
    if(front == NULL && rear == NULL)
        printf("Queue is empty!!!\n");
    else{
        struct Node* temp = front;
        while(temp != NULL){
            printf("%d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(){
    int val, choice, res;
    while(1){
     
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                res = dequeue();
                if(res != -1)
                    printf("\n%d delete from the queue\n", res);
                break;
            case 3:
                res = peek();
                if(res != -1)
                    printf("\n%d is available at top of the queue.\n", res);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default: 
                printf("\nInvalid Choice...\n");
        }
        
    }
    return 0;
}
