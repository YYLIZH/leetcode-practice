#include <iostream>

using std::cout;

class QueueArrayCircular
{
private:
    int capacity, front, back;
    int *queue;
    void DoubleCapacity();

public:
    QueueArrayCircular()
        : capacity(5), front(0), back(0)
    {
        queue = new int[capacity];
    }

    void Push(int x);
    void Pop();
    bool IsEmpty();
    bool IsFull();
    int GetFront();
    int GetBack();
    int GetSize();
    int GetCapacity();
};

void QueueArrayCircular::DoubleCapacity()
{
    int *newQueue = new int[capacity * 2];

    int j = front, size = GetSize();
    for (int i = 1; i <= size; i++)
    {
        newQueue[i] = queue[++j % capacity];
    }
    back = GetSize();
    front = 0;
    capacity *= 2;

    delete[] queue;
    queue = newQueue;
}

void QueueArrayCircular::Push(int x)
{
    if (IsFull())
    {
        DoubleCapacity();
    }
    back = (back + 1) % capacity;
    queue[back] = x;
}

void QueueArrayCircular::Pop()
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty.\n";
        return;
    }
    front = (front + 1) % capacity;
}

bool QueueArrayCircular::IsEmpty()
{
    return (front == back);
}

bool QueueArrayCircular::IsFull()
{
    return ((back + 1) % capacity == front);
}

int QueueArrayCircular::GetFront()
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty.\n";
        return -1;
    }
    return queue[(front + 1) % capacity];
}

int QueueArrayCircular::GetBack()
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty\n.";
        return -1;
    }
    return queue[back];
}

int QueueArrayCircular::GetSize()
{
    int size;
    if (front < back)
    {
        size = back - front;
    }
    else
    {
        size = capacity - (front - back);
    }
    return size;
}

int QueueArrayCircular::GetCapacity()
{
    return capacity;
}

void printCircularQueue(QueueArrayCircular queue)
{
    cout << "front: " << queue.GetFront() << "    back: " << queue.GetBack() << "\n"
         << "capacity: " << queue.GetCapacity() << "  number of elements: " << queue.GetSize() << "\n\n";
}

int main()
{

    QueueArrayCircular q;
    if (q.IsEmpty())
    {
        cout << "Queue is empty.\n\n";
    }
    q.Push(24);
    cout << "After push 24:\n";
    printCircularQueue(q);
    q.Push(8);
    q.Push(23);
    cout << "After push 8, 23:\n";
    printCircularQueue(q);
    q.Pop();
    cout << "After pop 24:\n";
    printCircularQueue(q);
    q.Push(13);
    cout << "After push 13:\n";
    printCircularQueue(q);
    q.Pop();
    cout << "After pop 8:\n";
    printCircularQueue(q);
    q.Push(35);
    cout << "After push 35:\n";
    printCircularQueue(q);
    q.Push(9);
    cout << "After push 9:\n";
    printCircularQueue(q);
    q.Push(64);
    cout << "After push 64:\n";
    printCircularQueue(q);
    return 0;
}