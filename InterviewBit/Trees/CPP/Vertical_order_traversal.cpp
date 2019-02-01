/*Given a binary tree, Print vertical order traversal of it.
Go through the example and image for more details.

Example :
Given binary tree:

      6
    /   \
   3     7
  / \     \
 2   5     9
prints
    2
    3
    6 5
    7
    9

Note : If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* new_node(int data)
{
    struct Node *n = new Node;
    n->data = data;
    n->left = n->right =NULL;
    return n;
}


void get_vertical_order(Node *root, int hd, map<int, vector<int>> &m)
{
    if(root == NULL)
        return;

    m[hd].push_back(root->data);
    get_vertical_order(root->left, hd-1, m);
    get_vertical_order(root->right, hd+1, m);
}

void print_vertical_order(Node *root)
{
    map<int, vector<int>> m;
    int hd = 0;

    get_vertical_order(root, hd, m);

    map<int, vector<int>> :: iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        for(int i=0;i<it->second.size();i++)
            cout << it->second[i] << " ";
        cout <<endl;
    }
}

int main()
{
    Node *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->left = new_node(6);
    root->right->left->right = new_node(8);
    root->right->right = new_node(9);

    cout <<"Vertical Order traversal : ";
    cout <<endl;
    print_vertical_order(root);

    return 0;
}
