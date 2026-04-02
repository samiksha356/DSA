#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp ->data = data;
    temp ->next = NULL;
    return temp;
}
void insertNodeInBeg(int data){
    struct Node* newNode =  createNode(data);
    if(head == NULL){
        head = newNode;
    }
    else{
        newNode->next=head;
        head = newNode;
    }
    printf("Node Inserted !!!\n");
}
void insertNodeAtEnd(int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;

    }
    else{
        struct Node* temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted !!!\n");
}
void insertNodeAtAnyPos(int data, int pos){
    if(head == NULL){
        printf("List is Empty!!!!\n");
    }
    else if(pos == 0){
        insertNodeInBeg(data);
    }
    else{
        struct Node* temp = head;
        int i=0;
        while(temp != NULL){
            if(i == pos-1)
                break;
            temp = temp->next;
            i++;
        }
        if(temp == NULL || temp->next==NULL){
            printf("Invalid position!!!\n");
        }
        else{
            struct Node* newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node Inserted !!!\n");
        }
    }
}
void deleteNodeFromBeg(){
    if(head == NULL)
        printf("List is empty !!!\n");
    else{
        head=head->next;
        printf("Node deleted !!!\n");
    }
}
void displayList(){
    if(head == NULL)
        printf("List is empty !!!\n");
    else{
        struct Node* temp = head;
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main(){
    int choice, data, pos;
    while(1){
        printf("1.Insert in Beginning\n");
        printf("2.Insert At End\n");
        printf("3.Insert At Specific Position\n");
        printf("4.Delete From Beginning\n");
        printf("5.Delete From End\n");
        printf("6.Delete From Specific Position\n");
        printf("7.Display Linked List\n");
        printf("8.Search Element In Linked List\n");
        printf("9.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertNodeInBeg(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertNodeAtEnd(data);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data: ");
                
                scanf("%d", &data);
                insertNodeAtAnyPos(data,pos);
                break;
            case 4:
                deleteNodeFromBeg();
                break;
            case 5:
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                break;
            case 7: 
                displayList();
                break;
            case 8:
                printf("Enter Searching Element: ");
                scanf("%d", &data);
                int index;
                if(index != -1)
                    printf("Element found at index %d\n", index);
                else
                    printf("Element not found!!!\n");
                break;
                case 9:
                    exit(0);
                    break;
                default:
                    printf("Invalid Choice!!!\n");

        }
    }
    return 0;
}
