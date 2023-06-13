/*Write a C program to create a Stack along with writing a code to create, insert, delete,
search, traverse and display all the nodes
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node* top = NULL;

void push(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (top == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = top;
    }
    top = newNode;
    printf("Node is Inserted\n\n");
}

int Delete() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        struct Node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
        return temp_data;
    }
}

void display() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        printf("The stack is \n");
        struct Node *temp = top;
        while (temp->next != NULL) {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL\n\n", temp->data);
    }
}
int Search(int value){
    struct Node *temp = top;
        while (temp->next != NULL) {
            if(temp->data==value){
                return 1;
            }
            temp = temp->next;
        }
    return 0;
}
void traverse(){
    struct Node *temp = top;
        while (temp->next != NULL) {
            temp = temp->next;
        }
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Search\n4. Traverse\n5. Display\n6. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Deleted element is :%d\n", Delete());
            break;
        case 3:
            printf("\nEnter the value to Search: ");
            scanf("%d", &value);
            if(Search(value))
                printf("Yes");
            else
                printf("No");
            printf("\n");
            break;
            break;
        case 4:
            traverse();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}
