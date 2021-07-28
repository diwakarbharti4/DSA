#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
}*root;
struct node *create(int data){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void print(struct node *root){
    if(root!=NULL){        
        print(root->left);
        cout<<root->data<<" ";
        print(root->right);
    }
}
void insert(struct node *&root,int data){
        if(root==NULL){
            root=create(data);
            return ;
        }
        if(root->data<data){
            insert(root->right,data);
        }
        else if(root->data>data){
            insert(root->left,data);          
        }
        else{
            cout<<"DUPLICATE"<<endl;
            return;
        }
}
struct node* search(struct node *&root,int key){
    if(root==NULL){
        cout<<"No key found here"<<endl;
        return NULL;
    }
    if(root->data==key){
        cout<<"key found"<<endl;
        return root;
    }
    else if(root->data<key){
        search(root->right,key);
    }
    else search(root->left,key);

}

void deletea(struct node *root,int key){
    struct node *n=search(root,key);
    struct node *m=search(root,key);

    if(n->left==NULL && n->right==NULL){
        free(n);
        return ;
    }
    else{
        if(n->right!=NULL){
            n=n->right;
            if(n->left==NULL){
                m->data=n->data;
                m->right=n->right;
                return ;
            }
            else{
                while(n->left->left!=NULL){
                    n=n->left;
                }
                m->data=n->left->data;
                n=n->left->right;

                return deletea(n,n->data);
            }
        }
        else{
            n=n->left;
            if(n->right==NULL){
                m->data=n->data;
                m->left=n->left;
                return ;
            }
        }
    }

}
int main(){
    cout<<"1 for insert"<<endl;
    cout<<"2 for print(Inorder)"<<endl;
    cout<<"3 for delete"<<endl;
     cout<<"4 for Search"<<endl;
    cout<<"0 for break"<<endl;
    while(1){
        int i;
        cin>>i;
        if(i==1){
            int data;
            cout<<"Enter Data ";
            cin>>data;
            insert(root,data);
        }
        if(i==2) {
            print(root);
            cout<<"\n";
        }
        if(i==3){
            cout<<"Enter key for deletion  ";
            int key;
            cin>>key;
            deletea(root,key);
        }
        if(i==4){
            int key;
            cout<<"Enter key for search  ";
            cin>>key;
            struct node* n=search(root,key);
            //cout<<n->data<<endl;
        }
        if(i==0)
            break;
    }
}