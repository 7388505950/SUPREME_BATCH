//Diameter of Tree 
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
int Diameter_Tree(Node *root){
    if(root==NULL){
        return 0;
    }
    int Ans1=Diameter_Tree(root->left);
    int Ans2=Diameter_Tree(root->right);
    //in node term +1 but Edge remove 1 ..............
    int Ans3=HeightTree(root->left)+1+HeightTree(root->right);

    int Ans=max(Ans1,max(Ans2,Ans3));
    return Ans;
}
int main()
{
    Node *root=Build_Tree();
    //cout<<"Height of Tree :"<<HeightTree(root);
    cout<<"Diameter of Tree :"<<Diameter_Tree(root);

    return 0;
}