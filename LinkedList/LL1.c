/*Create a linked list*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *head = NULL;
struct node *create_ll(struct node*);
int main(){
    head = create_ll(head);
};
struct node *create_ll(struct node *head){
    struct node *temp, *ptr;
    int data;
    printf("Enter Data(-1 to end): ");
    scanf("%d",&data);
    while (data!=-1)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp -> data = data;
        if(head==NULL){
            temp->link=NULL;
            head=temp;
        }
        else{
            ptr=head;
            while (ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            ptr->link=temp;
            temp->link=NULL;
        }
        printf("Enter Data: ");
        scanf("%d",&data);
    }
    return head;
};