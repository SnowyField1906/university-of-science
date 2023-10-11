#include "List.h"

Node *List::makeNode(const string &val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

List::List()
{
    Head = nullptr;
    count = 0;
}

List::~List()
{
    while (Head)
    {
        Node *temp = Head->next;
        delete Head;
        Head = temp;
    }
}

void List::insert(int pos, const string &val)
{
    assert(pos >= 0 && pos <= count);
    Node *newNode = makeNode(val);
    if (pos == 0)
    {
        newNode->next = Head;
        Head = newNode;
    }
    else
    {
        Node *prev = Head;
        for (int i = 0; i < pos - 1; i++)
        {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
    count++;
}

void List::erase(int pos)
{
    assert(pos >= 0 && pos < count);
    Node *delNode;
    if (pos == 0)
    {
        delNode = Head;
        Head = Head->next;
    }
    else
    {
        Node *prev = Head;
        for (int i = 0; i < pos - 1; i++)
        {
            prev = prev->next;
        }
        delNode = prev->next;
        prev->next = delNode->next;
    }
    delete delNode;
    count--;
}

string List::get(int pos) const
{
    assert(pos >= 0 && pos < count);
    Node *curr = Head;
    for (int i = 0; i < pos; i++)
    {
        curr = curr->next;
    }
    return curr->data;
}

void List::print() const
{
    Node *curr = Head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int List::size() const
{
    return count;
}
