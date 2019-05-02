#include <stdio.h>

#include <stdlib.h>



typedef struct node{

struct node* left;

struct node* right;

struct node* parent;

int value;

} node;



typedef struct tree

{

int size;

struct node* root;

} tree;



void insert(tree* t,int value);

int find(tree* t,int value,node* n);

void init(tree* t);

int _remove(tree* t,int value);

int removeMin(node* n);

int rotateLeft(node* n);

int root_rotateLeft(tree* t);

int rotateRight(node* n);

int root_rotateRight(tree* t);

void printTree(tree* t);

void clear_branch(node* n);

void clear(tree* t);



#define SIZE 128



void preorder_print_tree(tree* t){

node** nodes = malloc(sizeof(node)*SIZE);

int last_pos=SIZE-1;

printf("%d", t->root->value);

nodes[last_pos]=t->root->right;

last_pos--;

nodes[last_pos]=t->root->left;

last_pos--;

while(last_pos!=SIZE-1){

last_pos++;

node* tmp=nodes[last_pos];

printf(" %d", tmp->value);

if(tmp->right!=NULL){

nodes[last_pos]=tmp->right;

last_pos--;

}

if(tmp->left!=NULL){

nodes[last_pos]=tmp->left;

last_pos--;

}

}

printf("\n");

}



void postorder_print_node(node* n){

if (n!=NULL) {

int appended=0;

if(n->left!=NULL && n->right!=NULL){}

postorder_print_node(n->left);

postorder_print_node(n->right);

printf("%d ", n->value);

}

}



void postorder_print_tree(tree* t){

postorder_print_node(t->root->left);

postorder_print_node(t->root->right);

printf("%d\n", t->root->value);

}



int main(){

tree* root = malloc(sizeof(tree));

init(root);

int t;

for(int i=0;i<7;i++){

scanf("%d",&t);

insert(root,t);

}

printTree(root);

// preorder_print_tree(root);

// postorder_print_tree(root);

clear(root); 

return 0;

}



int rotateLeft(node* n){

if(n->right!=NULL){

node* tmp = n->right;

n->right=NULL;

n->parent=tmp;

tmp->parent=NULL;

tmp->left=n;

return 0;

}

else

return 1;

}



int root_rotateLeft(tree* t){

node* n = t->root;

if(rotateLeft(n)==0){

t->root=n->parent;

return 0;

}

else

return 1;

}



int rotateRight(node* n){

if(n->left!=NULL){

node* tmp = n->left;

n->left=NULL;

n->parent=tmp;

tmp->parent=NULL;

tmp->right=n; 

return 0;

}

else

return 1;

}



int root_rotateRight(tree* t){

node* n = t->root;

if(rotateRight(n)==0){

t->root=n->parent;

return 0;

}

else

return 1;

}



void insert(tree* t,int value){

if(t->root==NULL){

t->root=malloc(sizeof(node));

t->root->value=value;

t->root->left=t->root->right=t->root->parent=NULL;

t->size=1;

return;

}

node* tmp=t->root;

while(1){

if(tmp->value==value){

return;

}

if(value > tmp->value){

if(tmp->right==NULL){

tmp->right=malloc(sizeof(node));

tmp->right->value=value;

tmp->right->right=tmp->right->left=NULL;

tmp->right->parent=tmp;

t->size++;

return;

}

else

tmp=tmp->right;

}

else if(value < tmp->value){

if(tmp->left==NULL){

tmp->left=malloc(sizeof(node));

tmp->left->value=value;

tmp->left->left=tmp->left->left=NULL;

tmp->left->parent=tmp;

t->size++;

return;

}else

tmp=tmp->left;

}

}

}



int find(tree* t,int value,node* n){

if(t->root==NULL){

return 1;

}

node* tmp=t->root;

while(1){

if(tmp==NULL)

return 1;

if(tmp->value==value){

n->value=tmp->value;

n->left=tmp->left;

n->right=tmp->right;

n->parent=tmp->parent;

return 0;

}

if(value > tmp->value)

tmp=tmp->right;

else if(value < tmp->value)

tmp=tmp->left;

}

}



void init(tree* t){

t->root=NULL;

t->size=0;

}



int _remove(tree* t,int value){

if(t->root==NULL){

return 1;

}

node* tmp=t->root;

while(1){

if(tmp==NULL)

return 1;

if(tmp->value==value){

if(tmp->left==NULL && tmp->right==NULL){

if(tmp->parent->left==tmp)

tmp->parent->left=NULL;

else if(tmp->parent->right==tmp)

tmp->parent->right=NULL;

t->size--;

free(tmp);

return 0;

}

else if(tmp->left!=NULL && tmp->right==NULL){

if(tmp->parent->left==tmp)

tmp->parent->left=tmp->left;

else if(tmp->parent->right==tmp)

tmp->parent->right=tmp->left;

t->size--;

free(tmp);

return 0;

}

else if(tmp->left==NULL &&

 

tmp->right!=NULL){

if(tmp->parent->left==tmp)

tmp->parent->left=tmp->right;

else if(tmp->parent->right==tmp)

tmp->parent->right=tmp->right;

t->size--;

free(tmp);

return 0;

}

else{

tmp->value=removeMin(tmp->right);

t->size--;

return 0;

}



}

if(value > tmp->value)

tmp=tmp->right;

else if(value < tmp->value)

tmp=tmp->left;

}

}



int removeMin(node* n){

if(n!=NULL){

if(n->left!=NULL)

return removeMin(n->left);

else{

if(n->right!=NULL){

n->parent->right=n->right;

n->right=n->parent;

}else

n->parent->left=NULL;

int res=n->value;

free(n);

n=NULL;

return res;

}

} 

}



void printTree(tree* t){

if(t->root!=NULL){ 

node** nodes_to_print1 = malloc(sizeof(node)*SIZE);

node** nodes_to_print2 = malloc(sizeof(node)*SIZE);

int next_free_pos[2]={0,0},values_for_printing[2]={0,0},is_1=1;

printf("%d", t->root->value);

nodes_to_print1[next_free_pos[0]]=t->root->left;

next_free_pos[0]++;

nodes_to_print1[next_free_pos[0]]=t->root->right;

next_free_pos[0]++;

if(t->root->left!=NULL && t->root->right!=NULL){

values_for_printing[0]=1;

printf(" "); 

}



while(values_for_printing[0] || values_for_printing[1]){

if(is_1){

values_for_printing[1]=0;

for(int i=0;i<next_free_pos[0];i++){

if(nodes_to_print1[i]!=NULL){

printf("%d",nodes_to_print1[i]->value);

nodes_to_print2[next_free_pos[1]]=nodes_to_print1[i]->left;

next_free_pos[1]++;

nodes_to_print2[next_free_pos[1]]=nodes_to_print1[i]->right; 

next_free_pos[1]++;

if(nodes_to_print1[i]->left!=NULL || nodes_to_print1[i]->right!=NULL)

values_for_printing[1]=1;

}else{

printf("_");

nodes_to_print2[next_free_pos[1]]=NULL;

next_free_pos[1]++;

nodes_to_print2[next_free_pos[1]]=NULL;

next_free_pos[1]++;

}

if(i+1!=next_free_pos[0]){

printf(" ");

}

}

next_free_pos[0]=0;

is_1=0;

values_for_printing[0]=0;

free(nodes_to_print1);

nodes_to_print1 = malloc(sizeof(node)*SIZE);

}else{

values_for_printing[0]=0;

for(int i=0;i<next_free_pos[1];i++){

if(nodes_to_print2[i]!=NULL){

printf("%d",nodes_to_print2[i]->value);

nodes_to_print1[next_free_pos[0]]=nodes_to_print2[i]->left;

next_free_pos[0]++;

nodes_to_print1[next_free_pos[0]]=nodes_to_print2[i]->right; 

next_free_pos[0]++;

if(nodes_to_print2[i]->left!=NULL || nodes_to_print2[i]->right!=NULL)

values_for_printing[0]=1;

}else{

printf("_");

nodes_to_print1[next_free_pos[0]]=NULL;

next_free_pos[0]++;

nodes_to_print1[next_free_pos[0]]=NULL; 

next_free_pos[0]++;

}

if(i+1!=next_free_pos[1]){

printf(" ");

} 

}

next_free_pos[1]=0;

is_1=1;

values_for_printing[1]=0;

free(nodes_to_print2);

nodes_to_print2 = malloc(sizeof(node)*SIZE);

}

if(values_for_printing[0] || values_for_printing[1]){

printf(" ");

}

}

printf("\n");

}

else

printf("-\n");

}



void clear_branch(node* n){

if(n!=NULL){

if(n->left!=NULL)

clear_branch(n->left); 

if(n->right!=NULL)

clear_branch(n->right);

}

free(n);

n=NULL;

}



void clear(tree* t){

clear_branch(t->root);

t->root=NULL;

t->size=0;

}
