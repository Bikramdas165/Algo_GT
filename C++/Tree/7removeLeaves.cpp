// in this code we need to mirror the given generic tree
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> TreeQueue;
    TreeQueue.push(root);
    while (TreeQueue.size() != 0)
    {
        TreeNode<int> *front = TreeQueue.front();
        TreeQueue.pop();
        cout << "Enter the number of children of" << front->data << endl;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            int childData;
            cout << "enter the " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            TreeQueue.push(child);
        }
    }
    return root;
}
void PrintLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> tree;
    tree.push(root);
    while (tree.size() != 0)
    {
        TreeNode<int> *front = tree.front();
        tree.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            tree.push(front->children[i]);
        }
        cout << endl;
    }
}

void removeLeaves(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    // in case of modification and traversing the array or vector, do it from end.....
    for (int i = root->children.size() - 1; i >= 0; i--)
    {
        // check for the children of the root node which are leaf
        if (root->children[i]->children.size() == 0)
        {
            // to be completed..........................
        }
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        removeLeaves(root->children[i]);
    }
}

int main()
{
    TreeNode<int> *root = takeInput();
    PrintLevelWise(root);
    removeLeaves(root);
    PrintLevelWise(root);
}