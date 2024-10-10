#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* BuildTree(node* root){
    cout<<"Enter data: ";
    int data;
    cin>>data;

    root=new node(data);

    if(data==-1)
    {return NULL;}

    cout<<"Enter the value to be inserted on the left of " << data << endl;
    root->left=BuildTree(root->left);
    cout<<"Enter the value to be inserted on the right of " << data << endl;
    root->right=BuildTree(root->right);
}

void inorder(node* root){
    if(root==NULL)
    {return;}

    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL)
    {return;}

    cout<<root->data<<"  ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL)
    {return;}
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<"  ";
}

int main(){
    int choice;
    node* root=NULL;
    root=BuildTree(root);
    while(1){
        cout<<endl;
        cout<<"----MENU----"<<endl;
        cout<<"1:-IN-Order"<<endl;  
        cout<<"2:-Pre-Order"<<endl;  
        cout<<"3:-Post-Order"<<endl;  
        cout<<"4:-Enter choice: ";
        cin>>choice;
    switch(choice){
    case 1:
    cout<<"In-order traversal is ";
    inorder(root);
    cout<<endl;
    break;
    case 2:
    cout<<"Pre-order traversal is ";
    preorder(root);
    cout<<endl;
    break;
    case 3:
    cout<<"Post-order traversal is ";
    postorder(root);
    cout<<endl;
    break;    
    default:
    cout<<"Invalid Choice:("<<endl<<"Please enter correct choice";
    break;
    }
    }
}