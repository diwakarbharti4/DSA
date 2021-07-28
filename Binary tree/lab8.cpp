#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
}*root;

void print(struct node *root,int &aa){
    aa--;
    if(aa<=0)
        return ;
    if(root!=NULL){
        cout<<root->data<<" ";
        print(root->left,aa);
        print(root->right,aa);
    }
}
struct node* create(int data){
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void insert(struct node *&root,int data,queue<struct node *> &Q){
    if(root==NULL){
        root=create(data);
        return ;
    }
    else Q.push(root);
    if(root->left==NULL){
        root->left=create(data);
        return ;
    }
    else Q.push(root->left);
    if(root->right==NULL){
        root->right=create(data);
        return ;
    }
    else Q.push(root->right);
    Q.pop();
    insert(Q.front(),data,Q);

}
void deletea(struct node *root, queue<struct node *> &Q,struct node *&top){
    if(root==NULL){
        cout<<"Empty";
        return ;
    }
    if(root->left==NULL){
        top=root;
        return ;
    }
    else {
        //top=root->left;
        Q.push(root->left);
    }
    if(root->right=NULL){
        top=root->left;
        return ;
    }
    else {
        top=root->right;
        Q.push(root->right);
    }
    top=Q.front();
    Q.pop();
    if(Q.empty()){
        top=NULL;
        return ;
    }
    delete(Q.front(),Q,top);

}

int main(){
    

    

    while(1){
        cout<<"1 to insert, ";
        cout<<" 2 to insert";
        cout<<" 3 to delete, ";
        cout<<"0 for break"<<endl;
        int i;
        cin>>i;

        if(i==1){
            int data;
            cout<<"Enter data  ";
            cin>>data;
            int f=0;
    
            queue<struct node *> Q;
            insert(root,data,Q);
        }
        if(i==2){
            int a=50;
            print(root,a);
            cout<<"\n";
        }
        if(i==3){
            queue<struct node *> Q;
            if(root!=NULL)
                Q.push(root);
            struct node *top=root;
            deletea(root,Q,top);
            top=NULL;
        }
        if(i==0)
            break;
    }
}