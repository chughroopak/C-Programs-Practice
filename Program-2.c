// Program2: Write a program to maintain a singly linked list having the following functions:
// a) Creation of the list
// b) Displaying the list.
// c) Swap all nodes at consecutive even odd positions.
// E.g.: The nodes at position 1 should be swapped with node 2, node 3 with node 4 and so on.

#include<stdio.h>
#include<stdlib.h>
void display();
void create_list();
void swap_alternate();

struct node{
    int val;
    struct node *next;
}*start=NULL;

int main(){
    while(1){
        printf("Choose what you want to do:\n1. Create Linked List. \n\
2. Display Linked List.\n3. Swap Alternate\n4. Quit.\n");
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
            swap_alternate();
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

void swap_alternate(){
    struct node* prev;
    struct node* first = start;
    struct node* second = start->next;
    start=NULL;
    while(first->next!=NULL){
        struct node* temp;
        first->next=second->next;
        second->next=first;
        if(start==NULL){
            start=second;
            prev=first;
        }
        else{
            prev->next=second;
            prev=first;
        }
        if(first->next!=NULL){
            first=first->next;
            if(first->next!=NULL){
                second=first->next;
            }
        }

    }
}
