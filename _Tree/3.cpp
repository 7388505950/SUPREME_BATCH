/* Traversal 
            --Inorder T
            --postorder T
            --Preorder T
*/


#include<iostream>
using namespace std;
class Node
{
  public:
     int data;
     Node* left;
     Node* right;
     Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
     }
};
Node* Build_Tree(){
    int data;
    cout<<"Enter the data "<<endl;
    cin>>data;
    if(data==-1)
    return NULL;
    // step A B C
    // A
    Node *root=new Node(data);
    // B
    cout<<"Enter the left data "<<endl;
    root->left=Build_Tree();
    // C
    cout<<"Enter the right data "<<endl;
    root->right=Build_Tree();

    return root;
}
void Inorder_OrderTraversal(Node *root)
{
    if(root==NULL){
        return;
    }
    Inorder_OrderTraversal(root->left);
    cout<<root->data<<" ";
    Inorder_OrderTraversal(root->right);
}
void Pre_Order_Traversal(Node *root){
     if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    Pre_Order_Traversal(root->left);
    Pre_Order_Traversal(root->right);
}
void Post_Order_Traversal(Node *root){
     if(root==NULL){
        return;
    }
  
    Post_Order_Traversal(root->left);
    Post_Order_Traversal(root->right);
    cout<<root->data<<" ";
}
int main()
{
    Node *root=Build_Tree();
    Inorder_OrderTraversal(root);
    cout<<endl;
    Pre_Order_Traversal(root);
    cout<<endl;
    Post_Order_Traversal(root);
    return 0;
}