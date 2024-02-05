/*Creating a Binary Search Tree and Performing Operation on it*/
#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree;
void create_tree(struct node*);
struct node* insert_element(struct node*, int);
void preorder_traversal(struct node*);
void inorder_traversal(struct node*);
void postorder_traversal(struct node*);
int main(){
    int data, choice;
    struct node* ptr;
    create_tree(tree);
    while(1){
        printf("********MENU**********");
        printf("\n 1. Insert New Element");
        printf("\n 2. Preorder Traversal");
        printf("\n 3. Inorder Traversal");
        printf("\n 4. Postorder Traversal");
        printf("\n 5. Exit From Menu");
        printf("\n Enter Your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the value of the new node: ");
            scanf("%d",&data);
            tree = insert_element(tree, data);
            break;
        case 2:
            printf("The elements of the tree are: ");
            preorder_traversal(tree);
            break;
        case 3:
            printf("The elements of the tree are: ");
            inorder_traversal(tree);
            break;
        case 4:
            printf("The elements of the tree are: ");
            postorder_traversal(tree);
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("\n Invalid Choice Entered!");
            break;
        }
    }
}
void create_tree(struct node* tree){
    tree = NULL;
};
struct node* insert_element(struct node*tree, int data){
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
    if(tree==NULL){
        tree=ptr;
        tree->left=NULL;
        tree->right=NULL;
    }
    else{
        parentptr=NULL;
        nodeptr=tree;
        while (nodeptr!=NULL)
        {
            parentptr=nodeptr;
            if(data<nodeptr->data){
                nodeptr=nodeptr->left;
            }
            else{
                nodeptr=nodeptr->right;
            }
        }
        if(data<parentptr->data){
            parentptr->left=ptr;
        }
        else{
            parentptr->right=ptr;
        }
        
    }
    return tree;
};
void preorder_traversal(struct node*tree){
    if(tree!=NULL){
        printf("%d\t",tree->data);
        preorder_traversal(tree->left);
        preorder_traversal(tree->right);
    }
};
void inorder_traversal(struct node*tree){
    if(tree!=NULL){
        inorder_traversal(tree->left);
        printf("%d\t",tree->data);
        inorder_traversal(tree->right);
    }
};
void postorder_traversal(struct node*tree){
    if(tree!=NULL){
        postorder_traversal(tree->left);
        postorder_traversal(tree->right);
        printf("%d\t",tree->data);
    }
};