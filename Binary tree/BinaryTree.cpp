#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node* create(int data){
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
int main(){
    struct node *p=create(1);
    struct node *p1=create(2);
    struct node *p2=create(3);
    p->left=p1;
    p->right=p2;

}