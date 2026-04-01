#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
}; 
struct Node* head=NULL, tail=NULL;
struct Node* createNode(int data){
    struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->prev = temp->next = NULL;
    return temp;
}
void insertNodeInBeg(int data){
    struct Node* newNode = createNode(data);
    if(head==NULL && tail==NULL)
        head = tail= newNode;
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node inserted in beginning!!!\n");
}

void insertNodeAtEnd(int data){
    struct Node* newNode = createNode(data);
    if(head==NULL && tail==NULL)
        head = tail= newNode;
    else{
        tail->next=newNode;
        newNode->prev=tail;
        tail = newNode;
    }
    printf("Node inserted at end!!!\n");
}
void insertNodeAtAnyPos(int data, int pos){ // here position is 0-base
    if(head==NULL && tail==NULL && pos==0){
        struct Node* newNode = createNode(data);\
        head = tail= newNode;
        printf("Node inserted at position %d !!!\n", pos);
    }
    else{
        struct Node* temp=head;
        int i=0;
        while(temp!=NULL){
            if(i==pos)
                break;
            temp=temp->next;
            i++;
        }
        if(temp == NULL)
            printf("Invalid position !!!\n");
        else if(i == pos){
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            printf("Node inserted at position %d!!!\n",pos);

        }
        else{
            struct Node* newNode = createNode(data);
            temp->prev->next = newNode;
            newNode->prev=temp->prev;
            temp->rev=newNode;
            newNode->next=temp;
            printf("Node inserted at position %d!!!\n",pos);
        }
    }
}
void deleteNodeFromBeg(){
    if(head==NULL && tail==NULL)
        printf("List is empty !!!\n");
    else if(head == tail){
        head = tail= NULL;
        printf("Node deleted from beginning!!!\n");
    }
    else{
        //struct Node* delNode = head;
        head = head->next;
        //free(delNode);
        printf("Node deleted from beginning!!!\n");
    }

}
void deleteNodeFromEnd(){
    if(head==NULL && tail==NULL)
        printf("List is empty !!!\n");
    else if(head == tail){
        head = tail= NULL;
        printf("Node deleted from beginning!!!\n");
    }
    else{
        tail->prev->next=NULL;
        tail=tail->prev;
        printf("Node deleted from beginning!!!\n");
    }

} 
void deleteNodeFromAnyPos(int pos){
    if(head==NULL && tail==NULL)
        printf("List is empty !!!\n");
    else if(pos==0)
        deleteNodeFromBeg();
    else{
        struct Node* temp = head;
        int i=0;
        while(temp != NULL && i != pos){
            temp=temp->next;
            i++;
        }
        if(temp == NULL)
            printf("Invalid position !!!\n");
        else{
            temp->prev->next=temp->next;
            if(temp->next != NULL)
                temp->next->prev=temp->prev;
            else
                tail = temp->prev;
            printf("Node deleted from %d position !!!\n", pos);

        }
    }
}
void search(int value){
    if(head == NULL && tail == NULL)
        printf("List is empty !!!\n");
    else{
        struct Node* temp = head;
        while(temp != NULL){
            if(temp->data == value){
                printf("Found !!!\n");
                return;
            }
            temp = temp->next;
        }
    }
}
void displayList(){
    if(head == NULL && tail == NULL)
        printf("List is empty !!!\n");
    else{
        struct Node* temp = head;
        while(temp != NULL){
            if(temp->data == value){
                printf("%d ", temp->data);
                temp = temp->next;
            }
            temp = temp->next;
        }
    }
}

int main(){
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
    }
}
