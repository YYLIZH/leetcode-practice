#include <iostream>
#include <string>

using std::string;

class RBT;
class TreeNode
{
private:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    std::string element;
    int key;
    int color; // 0: Red, 1: black
    friend RBT;

public:
    TreeNode(int key, string str)
        : key(key), element(str) {};
};

class RBT
{
private:
    TreeNode *root;
    TreeNode *neel; // This is NIL
    void LeftRotation(TreeNode *x);
    void RightRotation(TreeNode *x);
    void InsertRBT(int key, string str);
    void InsertFixedUpRBT(TreeNode *current);
};

void RBT::LeftRotation(TreeNode *x)
{
    TreeNode *y = x->rightchild;
    x->rightchild = y->leftchild;

    if (y->leftchild != neel)
    {
        y->leftchild->parent = x;
    }

    y->parent = x->parent;
    if (x->parent == neel)
    {
        root = y;
    }
    else if (x->parent->leftchild == x)
    {
        x->parent->leftchild = y;
    }
    else
    {
        x->parent->rightchild = x;
    }
    y->leftchild = x;
    x->parent = y;
}

void RBT::RightRotation(TreeNode *y)
{
    TreeNode *x = y->leftchild;

    x->rightchild = y->leftchild;
    if (x->rightchild != neel)
    {
        x->rightchild->parent = y;
    }

    x->parent = y->parent;
    if (y->parent == neel)
    {
        root = x;
    }
    else if (y->parent->leftchild == y)
    {
        y->parent->leftchild = x;
    }
    else
    {
        y->parent->rightchild = x;
    }

    x->rightchild = y;
    y->parent = x;
}

void RBT::InsertRBT(int key, string str)
{
    TreeNode *y = neel;
    TreeNode *x = root;
    TreeNode *insert_node = new TreeNode(key, str);

    while (x != neel)
    {
        y = x;
        if (insert_node->key < x->key)
        {
            x = x->leftchild;
        }
        else
        {
            x = x->rightchild;
        }
    }

    insert_node->parent = y;

    if (y == neel)
    {
        this->root = insert_node;
    }
    else if (insert_node->key < y->key)
    {
        y->leftchild = insert_node;
    }
    else
    {
        y->rightchild = insert_node;
    }

    insert_node->leftchild = neel;
    insert_node->rightchild = neel;
    insert_node->color = 0;

    InsertFixedUpRBT(insert_node);
}

void RBT::InsertFixedUpRBT(TreeNode *current)
{
    // 0 is red
    // 1 is black
    while (current->parent->color == 0)
    {
        if (current->parent == current->parent->parent->leftchild)
        {
            TreeNode *uncle = current->parent->parent->rightchild;
            // Case 1 uncle is red
            if (uncle->color == 0)
            {
                current->parent->color = 1;
                uncle->color = 1;
                current->parent->parent->color = 0; // grandparent change to 0
                current = current->parent->parent;
            }
            // Case 2 & Case 3. Uncle is black
            else
            {
                if (current == current->parent->rightchild)
                { // case 2
                    current = current->parent;
                    LeftRotation(current);
                }
                // case 3
                current->parent->color = 1;
                current->parent->parent->color = 0;
                RightRotation(current->parent->parent);
            }
        }
        else
        {
            TreeNode *uncle = current->parent->parent->leftchild;
            // Case 1 if unclude is red
            if (uncle->color == 0)
            {
                current->parent->color = 1;
                uncle->color = 1;
                current->parent->parent->color = 0;
                current = current->parent->parent;
            }
            // Case 2 & case 3: uncle is black
            else
            {
                if (current == current->parent->leftchild)
                {
                    current = current->parent;
                    LeftRotation(current);
                }
                // Case 3
                current->parent->color = 1;
                current->parent->parent->color = 0;
                LeftRotation(current->parent->parent);
            }
        }
    }
    root->color = 1;
}