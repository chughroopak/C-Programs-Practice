// Program3: Write a program to maintain a singly linked list having the following functions:
// a. Creation of the list
// b. Displaying the list.
// c. Traverse through the linked list and subtract two consecutive nodes.
// The result should be inserted just before the nodes subtracted.
#include<stdio.h>
#include<stdlib.h>
void display();
void create_list();
void sub_alternate();

struct node{
    int val;
    struct node *next;
}*start=NULL;

int main(){
    while(1){
        printf("Choose what you want to do:\n1. Create Linked List. \n\
2. Display Linked List.\n3. Subtract alternate.\n4. Quit.\n");
        int c;
        fflush(stdin);
        scanf("%d", &c);
        switch(c){
            case 1:
            create_list();
            break;
            case 2:
            display();
            break;
            case 3:
            sub_alternate();
            break;
            case 4:
            return 0;
            break;
            default:
            printf("Choose a correct option.\n");
        }
    }
    return 0;
}

void create_list(){
    fflush(stdin);
    if(start==NULL){
        printf("There are no elements in this linked list. Do you want to add elements?(Y or N)...  ");
        char c;
        scanf("%c", &c);
        if(c=='y' || c=='Y'){
            char flag='y';
            struct node *prev = NULL;
            while(flag=='y' || flag=='Y'){
                printf("Enter the element: ");
                int v;
                scanf("%d", &v);
                struct node* new = (struct node *)malloc(sizeof(struct node));
                new->val = v;
                new->next = NULL;
                if(start==NULL){
                    start=new;
                    prev=start;
                }
                else{
                    prev->next = new;
                    prev=new;
                }
                fflush(stdin);
                printf("Do you want to add another element?(y or n).. ");
                scanf("%c", &flag);
            }
        }
    }
    else{
        printf("The linked list already exists.\n");
        display();
    }
}

void display(){
    struct node *last = start;
    printf("The linked list is as follows:\n");
    while(last->next!=NULL){
        printf("[%d]->",last->val);
        last=last->next;
    }
    printf("[%d]\n",last->val);
}

void sub_alternate(){
    struct node* prev=(struct node*)malloc(sizeof(struct node));
    struct node* first = start;
    start=NULL;
    while(first!=NULL && first->next!=NULL){
        struct node* new = (struct node*)malloc(sizeof(struct node));
        new->val=(first->val)-(first->next->val);
        new->next=first;
        if(start==NULL){
            start=new;
        }
        else{
            prev->next=new;
        }
        prev=first->next;
        first=first->next->next;
    }
    display();
}
