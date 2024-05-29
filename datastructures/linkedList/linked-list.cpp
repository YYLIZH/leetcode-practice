#include <iostream>

class LinkedList;

class ListNode
{
private:
    int data;
    ListNode *next;

public:
    ListNode() : data(0), next(0){};
    ListNode(int a) : data(a), next(0){};
    friend class LinkedList;
};

class LinkedList
{
private:
    ListNode *first;

public:
    LinkedList() : first(0){};
    void PrintList();
    void Push_front(int x);
    void Push_back(int x);
    void Delete(int x);
    void Clear();
    void Reverse();
};

void LinkedList::PrintList()
{
    if (first == 0)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    ListNode *curr = first;
    while (curr != 0)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

void LinkedList::Push_front(int x)
{
    ListNode *newNode = new ListNode(x);
    newNode->next = first;
    first = newNode;
}

void LinkedList::Push_back(int x)
{
    ListNode *newNode = new ListNode(x);

    if (first == 0)
    {
        first = newNode;
        return;
    }

    ListNode *current = first;
    while (current->next != 0)
    {
        current = current->next;
    }
    current->next = newNode;
}

void LinkedList::Delete(int x)
{
    ListNode *curr = first,
             *prev = 0;

    while (curr != 0 && curr->data != x)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == 0)
    {
        std::cout << "There is no " << x << " in list." << std::endl;
    }
    else if (curr == first)
    {
        first = curr->next;
        delete curr;
        curr = 0;
        return;
    }
    else
    {
        prev->next = curr->next;
        delete curr;
        curr = 0;
        return;
    }
}

void LinkedList::Clear()
{
    while (first != 0)
    {
        ListNode *curr = first;
        first = first->next;
        delete curr;
        curr = 0;
    }
}

void LinkedList::Reverse()
{
    if (first == 0 || first->next == 0)
    {
        return;
    }

    ListNode *prev = 0,
             *curr = first,
             *prec = first->next;

    while (prec != 0)
    {
        curr->next = prev;
        prev = curr;
        curr = prec;
        prec = prec->next;
    }

    curr->next = prev;
    first = curr;
}

int main()
{

    LinkedList list;    // 建立LinkedList的object
    list.PrintList();   // 目前list是空的
    list.Delete(4);     // list是空的, 沒有4
    list.Push_back(5);  // list: 5
    list.Push_back(3);  // list: 5 3
    list.Push_front(9); // list: 9 5 3
    list.PrintList();   // 印出:  9 5 3
    list.Push_back(4);  // list: 9 5 3 4
    list.Delete(9);     // list: 5 3 4
    list.PrintList();   // 印出:  5 3 4
    list.Push_front(8); // list: 8 5 3 4
    list.PrintList();   // 印出:  8 5 3 4
    list.Reverse();     // list: 4 3 5 8
    list.PrintList();   // 印出:  4 3 5 8
    list.Clear();       // 清空list
    list.PrintList();   // 印出: List is empty.

    return 0;
}