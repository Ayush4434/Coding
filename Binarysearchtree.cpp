#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node* BST(Node* root,int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }
    if(root->data>val)
    {
        root = BST(root->left,val);
    }
    else{
        root->right = BST(root->right,val);
    }
    return root;
}
void inorderprint(Node* root)
{
    if(root==NULL)
        return;
    inorderprint(root->left);
    cout<<root->data;
    inorderprint(root->right);
}
bool searches(Node* root,int val)
{
    if(root==NULL)
        return false;
    if(root->data>val)
    {
        searches(root->left,val);
    }
    else if(root->data<val)
    {
        searches(root->right,val);
    }
    else{
        return true;
    }
}
Node* deleteNode(Node* root,int val)
{
    if(root==NULL)
        return NULL;
    if(root->data>val)
    {
        root->left = deleteNode(root->left,val);
    }
    else if(root->data<val)
    {
        root->right = deleteNode(root->right,val);
    }
    else
    {
        if(root->left==NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        /*Node* temp = inorder(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->val);*/
    }
    return root;
}
int main()
{
    Node* root = NULL;
    root = BST(root,10);
    BST(root,4);
    BST(root,6);
    BST(root,5);
    inorderprint(root);
    cout<<endl;
    if(searches(root,5))
        cout<<"found";
    else
        cout<<"NOT";
}
