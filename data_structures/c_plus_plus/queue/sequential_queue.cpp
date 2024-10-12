#include <iostream>

class QueueArraySequential
{
private:
    int capacity, front, back;
    int *queue;
    void DoubleCapacity();

public:
    QueueArraySequential()
        : capacity(5), front(-1), back(-1)
    {
        queue = new int[capacity];
    };
    void Push(int x);
    void Pop();
    bool IsEmpty();
    bool IsFull();
    int GetFront();
    int GetBack();
    int GetSize();
    int GetCapacity();
};

void QueueArraySequential::DoubleCapacity()
{
    capacity *= 2;
    int *newQueue = new int[capacity];

    int j = -1;
    for (int i = front + 1; i <= back; i++)
    {
        j++;
        newQueue[j] = queue[i];
    }
    front = -1;
    back = j;
    delete[] queue;
    queue = newQueue;
}

void QueueArraySequential::Push(int x)
{
    if (IsFull())
    {
        DoubleCapacity();
    }
    queue[++back] = x;
}

void QueueArraySequential::Pop()
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty.\n";
        return;
    }
    front++;
}

bool QueueArraySequential::IsFull()
{
    return (back + 1 == capacity);
}

bool QueueArraySequential::IsEmpty()
{
    return (front == back);
}

int QueueArraySequential::GetFront()
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty.";
        return -1;
    }
    return queue[front + 1];
}
int QueueArraySequential::GetBack()
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty.";
        return -1;
    }
    return queue[back];
}
int QueueArraySequential::GetSize()
{
    return (back - front);
}

int QueueArraySequential::GetCapacity()
{
    return capacity;
}

void printSequentialQueue(QueueArraySequential queue)
{
    std::cout << "front: " << queue.GetFront() << "   back: " << queue.GetBack() << "\n"
              << "capacity: " << queue.GetCapacity() << "   number of elements: " << queue.GetSize() << "\n\n";
}

int main()
{

    QueueArraySequential q;
    if (q.IsEmpty())
    {
        std::cout << "Queue is empty.\n\n";
    }
    q.Push(24);
    std::cout << "After push 24: \n";
    printSequentialQueue(q);
    q.Push(8);
    q.Push(23);
    std::cout << "After push 8, 23: \n";
    printSequentialQueue(q);
    q.Pop();
    std::cout << "After pop 24: \n";
    printSequentialQueue(q);
    q.Push(13);
    std::cout << "After push 13: \n";
    printSequentialQueue(q);
    q.Pop();
    std::cout << "After pop 8: \n";
    printSequentialQueue(q);
    q.Push(35);
    std::cout << "After push 35: \n";
    printSequentialQueue(q);
    q.Push(9);
    std::cout << "After push 9: \n";
    printSequentialQueue(q);

    return 0;
}