#include <iostream>

class StackArray
{
private:
    int top;               // index of top element
    int capacity;          // Allocated memory space of array
    int *stack;            // Array representing stack
    void DoubleCapacity(); // Double the capacity of stack
public:
    StackArray() : top(-1), capacity(1) // Constructor
    {
        stack = new int[capacity];
    }
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};

void StackArray::DoubleCapacity()
{
    capacity *= 2;                     // Double capacity
    int *newStack = new int[capacity]; // Create new stack

    for (int i = 0; i < capacity / 2; i++)
    { // Copy element to new stack
        newStack[i] = stack[i];
    }

    delete[] stack; // release the memory of stack
    stack = newStack;
}

void StackArray::Push(int x)
{
    if (top == capacity - 1)
    {
        DoubleCapacity(); // If array is full, double the capacity
    }

    stack[++top] = x; // update top and put x into stack
}

void StackArray::Pop()
{
    if (IsEmpty())
    {
        std::cout << "Stack is empty\n";
        return;
    }
    top--;
}

bool StackArray::IsEmpty()
{
    return (top == -1);
}

int StackArray::Top()
{
    if (IsEmpty())
    {
        std::cout << "Stack is empty.\n";
        return -1;
    }

    return stack[top];
}

int StackArray::getSize()
{
    return top + 1; // return the number of elements in stack
}

int main()
{
    StackArray s;
    s.Pop();
    s.Push(14);
    s.Push(9);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    s.Push(7);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    s.Pop();
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;

    return 0;
}
