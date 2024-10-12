#include <iostream>
#include <string>
#include <queue>

class BinaryTree;
class TreeNode
{
public:
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode *parent;
    std::string str;

    TreeNode()
        : leftChild(0), rightChild(0), parent(0), str("") {};
    TreeNode(std::string s)
        : leftChild(0), rightChild(0), parent(0), str(s) {};
    friend class BinaryTree;
};

class BinaryTree
{
public:
    TreeNode *root;
    BinaryTree()
        : root(0) {};
    BinaryTree(TreeNode *node)
        : root(node) {};

    void Preorder(TreeNode *current);
    void Inorder(TreeNode *current);
    void Postorder(TreeNode *current);
    void Levelorder();

    TreeNode *leftmost(TreeNode *current);
    TreeNode *rightmost(TreeNode *current);

    TreeNode *InorderSuccessor(TreeNode *current);
    TreeNode *InorderPredecessor(TreeNode *current);

    void Inorder_by_parent(TreeNode *root);
    void Inorder_Reverse(TreeNode *root);
};

void BinaryTree::Preorder(TreeNode *current)
{
    if (current)
    {
        std::cout << current->str << " ";
        Preorder(current->leftChild);
        Preorder(current->rightChild);
    }
}

void BinaryTree::Inorder(TreeNode *current)
{
    if (current)
    {
        Inorder(current->leftChild);
        std::cout << current->str << " ";
        Inorder(current->rightChild);
    }
}

void BinaryTree::Postorder(TreeNode *current)
{
    if (current)
    {
        Postorder(current->leftChild);
        Postorder(current->rightChild);
        std::cout << current->str << " ";
    }
}

void BinaryTree::Levelorder()
{
    std::queue<TreeNode *> q;
    q.push(this->root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        std::cout << current->str << " ";

        if (current->leftChild != NULL)
        {
            q.push(current->leftChild);
        }
        if (current->rightChild != NULL)
        {
            q.push(current->rightChild);
        }
    }
}

TreeNode *BinaryTree::leftmost(TreeNode *current)
{
    while (current->leftChild != NULL)
    {
        current = current->leftChild;
    }
    return current;
}

TreeNode *BinaryTree::InorderSuccessor(TreeNode *current)
{
    if (current->rightChild != NULL)
    {
        return leftmost(current->rightChild);
    }

    TreeNode *successor = current->parent;
    while (successor != NULL && current == successor->rightChild)
    {
        current = successor;
        successor = successor->parent;
    }
    return successor;
}

void BinaryTree::Inorder_by_parent(TreeNode *root)
{
    TreeNode *current = new TreeNode;
    current = leftmost(root);

    while (current)
    {
        std::cout << current->str << " ";
        current = InorderSuccessor(current);
    }
}

TreeNode *rightmost(TreeNode *current)
{
    while (current->rightChild != NULL)
    {
        current = current->rightChild;
    }
    return current;
}

TreeNode *BinaryTree::InorderPredecessor(TreeNode *current)
{
    if (current->leftChild != NULL)
    {
        return rightmost(current->leftChild);
    }

    TreeNode *predecessor = current->parent;
    while (predecessor != NULL && current == predecessor->leftChild)
    {
        current = predecessor;
        predecessor->parent;
    }
    return predecessor;
}

void BinaryTree::Inorder_Reverse(TreeNode *root)
{
    TreeNode *current = new TreeNode;
    current = rightmost(root);

    while (current)
    {
        std::cout << current->str << " ";
        current = InorderPredecessor(current);
    }
}

int main()
{

    TreeNode *nodeA = new TreeNode("A");
    TreeNode *nodeB = new TreeNode("B");
    TreeNode *nodeC = new TreeNode("C");
    TreeNode *nodeD = new TreeNode("D");
    TreeNode *nodeE = new TreeNode("E");
    TreeNode *nodeF = new TreeNode("F");
    TreeNode *nodeG = new TreeNode("G");
    TreeNode *nodeH = new TreeNode("H");
    TreeNode *nodeI = new TreeNode("I");

    // Link Child Pointer
    nodeA->leftChild = nodeB;
    nodeA->rightChild = nodeC;

    nodeB->leftChild = nodeD;
    nodeB->rightChild = nodeE;

    nodeE->leftChild = nodeG;
    nodeE->rightChild = nodeH;

    nodeC->leftChild = nodeF;
    nodeF->rightChild = nodeI;

    // Link Parent Pointer
    nodeB->parent = nodeA;
    nodeC->parent = nodeC;
    nodeD->parent = nodeB;
    nodeE->parent = nodeB;
    nodeF->parent = nodeC;
    nodeG->parent = nodeE;
    nodeH->parent = nodeE;
    nodeI->parent = nodeF;

    BinaryTree T(nodeA);
    T.Preorder(T.root);
    std::cout << std::endl;
    T.Inorder(T.root);
    std::cout << std::endl;
    T.Postorder(T.root);
    std::cout << std::endl;
    T.Levelorder();
    std::cout << std::endl;

    T.Inorder_by_parent(T.root);
    T.Inorder_Reverse(T.root);
    return 0;
}