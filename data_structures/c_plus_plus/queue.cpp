#include <iostream>
#include <queue>

class QueueNode
{
private:
    int data;
    QueueNode *next;

public:
    QueueNode()
        : data{0}, next{0} {};
    QueueNode(int x)
        : data{x}, next{0} {};
    friend class QueueList;
};

class QueueList
{
private:
    QueueNode *front;
    QueueNode *back;
    int size;

public:
    QueueList() : front{0}, back{0}, size{0} {};
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int GetFront();
    int GetBack();
    int GetSize();
};

void QueueList::Push(int x)
{
    if (IsEmpty())
    {
        front = new QueueNode(x);
        back = front;
        size++;
        return;
    }

    QueueNode *newNode = new QueueNode(x);
    back->next = newNode;
    back = newNode;
    size++;
}

void QueueList::Pop()
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty.\n";
        return;
    }

    QueueNode *deleteNode = front;
    front = front->next;
    delete deleteNode;
    deleteNode = 0;
    size--;
}

int QueueList::GetFront()
{

    if (IsEmpty())
    {
        std::cout << "Queue is empty.\n";
        return -1;
    }

    return front->data;
}

int QueueList::GetBack()
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty.\n";
        return -1;
    }
    return back->data;
}

bool QueueList::IsEmpty()
{
    return ((front && back) == 0);
}

int QueueList::GetSize()
{
    return size;
}

int main()
{

    QueueList q;
    if (q.IsEmpty())
    {
        std::cout << "Queue is empty.\n";
    }
    q.Push(24);
    std::cout << "\nAfter push 24: \n";
    std::cout << "front: " << q.GetFront() << "    back: " << q.GetBack() << "\n";
    q.Push(8);
    std::cout << "\nAfter push 8: \n";
    std::cout << "front: " << q.GetFront() << "    back: " << q.GetBack() << "\n";
    q.Push(23);
    std::cout << "\nAfter push 23: \n";
    std::cout << "front: " << q.GetFront() << "    back: " << q.GetBack() << "\n";
    q.Push(13);
    std::cout << "\nAfter push 13: \n";
    std::cout << "front: " << q.GetFront() << "    back: " << q.GetBack() << "\n";
    q.Pop();
    std::cout << "\nAfter pop the front element: \n";
    std::cout << "front: " << q.GetFront() << "     back: " << q.GetBack() << "\n";
    q.Push(35);
    std::cout << "\nAfter push 35: \n";
    std::cout << "front: " << q.GetFront() << "     back: " << q.GetBack() << "\n";
    q.Pop();
    std::cout << "\nAfter pop the front element: \n";
    std::cout << "front: " << q.GetFront() << "    back: " << q.GetBack() << "\n";
    q.Pop();
    std::cout << "\nAfter pop the front element: \n";
    std::cout << "front: " << q.GetFront() << "    back: " << q.GetBack() << "\n";
    q.Pop();
    std::cout << "\nAfter pop the front element: \n";
    std::cout << "front: " << q.GetFront() << "    back: " << q.GetBack() << "\n";
    q.Pop();
    std::cout << "\nAfter pop the front element: \n";
    q.Pop();

    return 0;
}