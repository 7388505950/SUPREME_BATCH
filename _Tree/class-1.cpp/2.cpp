//Level Order Traversal ===============
#include<iostream>
#include<queue>
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

void Level_Order_Traversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        // A
        Node *temp=q.front();
        //B
        q.pop();
        //C
        cout<<temp->data<<" ";
        //D-------------------
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
}

void Level_O_T_(Node* root)
{
    //===It will print in multi-line Level wise ===============

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
    
        q.pop();
        if(temp!=NULL)
        {
            cout<<endl;
            if(! q.empty()){
                q.push(NULL);
            }
        }
        else
        {
        cout<<temp->data<<" ";
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
        }
        
    }
}
int main()
{
    Node *root =Build_Tree();
    Level_Order_Traversal(root);
    cout<<endl;
    Level_O_T_(root);
    return 0;
}