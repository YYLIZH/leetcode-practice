#include <iostream>
#include <string>
#include <queue>

using std::cout;
using std::endl;
using std::string;

class BST;
class TreeNode
{
private:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    int key;
    string element;

public:
    TreeNode()
        : leftchild(0), rightchild(0), parent(0), key(0), element("") {};
    TreeNode(int a, string b)
        : leftchild(0), rightchild(0), parent(0), key(a), element(b) {};

    int Getkey() { return key; }
    string GetElement() { return element; }

    friend class BST;
};

class BST
{
private:
    TreeNode *root;
    TreeNode *LeftMost(TreeNode *current);
    TreeNode *RightMost(TreeNode *current);

public:
    BST() : root(0) {};
    TreeNode *Search(int key);
    void InsertBST(int key, string element);
    void InorderPrint();
    void Levelorder();
    void DeleteBST(int key);
};

void BST::DeleteBST(int key)
{
    TreeNode *delete_node = Search(key);
    if (delete_node == NULL)
    {
        std::cout << "data not found.\n";
        return;
    }

    TreeNode *y = 0; // 真正要被刪掉的node
    TreeNode *x = 0; // 要被刪掉的node的child

    if (delete_node->leftchild == NULL || delete_node->rightchild == NULL)
    {
        y = delete_node;
    }
    else
    {
        y = Successor(delete_node);
    }

    if (y->leftchild != NULL)
    {
        x = y->leftchild;
    }
    else
    {
        x = y->rightchild;
    }

    // x 指向y的parent
    if (x != NULL)
    {
        x->parent = y->parent;
    }

    // y的parent指向x
    if (y->parent == NULL)
    {
        this->root = x;
    }
    else if (y == y->parent->leftchild)
    {
        y->parent->leftchild = x;
    }
    else
    {
        y->parent->rightchild = x;
    }

    if (y != delete_node)
    {                              // y是替身
        delete_node->key = y->key; // 把y的資料換到delete node上,相當於刪掉delete node
        delete_node->element = y->element;
    }
    delete y;
    y = 0;
}

int main()
{

    BST T;

    T.InsertBST(8, "龜仙人");
    T.InsertBST(1000, "悟空");
    T.InsertBST(2, "克林");
    T.InsertBST(513, "比克");

    cout << "Inorder Traversal:\n";
    T.InorderPrint();
    cout << endl
         << endl;
    cout << "Level-order Traversal:\n";
    T.Levelorder();
    cout << endl
         << endl;

    T.DeleteBST(8); // 刪除龜仙人(8), 確認比克(513)會成為新的root

    cout << "Level-order Traversal:\n";
    T.Levelorder();
    cout << endl
         << endl;

    TreeNode *node = T.Search(1000);
    if (node != NULL)
    {
        cout << "There is " << node->GetElement() << "(" << node->GetKey() << ")" << endl;
    }
    else
    {
        cout << "no element with Key(1000)" << endl;
    }

    node = T.Search(8);
    if (node != NULL)
    {
        cout << "There is " << node->GetElement() << "(" << node->GetKey() << ")" << endl;
    }
    else
    {
        cout << "no element with Key(8)" << endl;
    }

    return 0;
}