//Height of Tree 
//======================================
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
int HeightTree(Node *root){
    if(root==NULL)
    return 0;
    

    int leftAns=HeightTree(root->left);
    int rightAns=HeightTree(root->right);
    int ans=max(leftAns,rightAns)+1;
    return ans;
}
int main()
{
    Node *root=Build_Tree();
    cout<<"Height of Tree :"<<HeightTree(root);

    return 0;
}