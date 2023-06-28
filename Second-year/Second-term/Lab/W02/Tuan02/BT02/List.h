#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cassert>
#include <string>
using namespace std;
// Định nghĩa Node
struct Node
{
    string data;
    Node *next;
};
// Định nghĩa lớp list
class List
{
private:
    Node *Head;
    int count;
    Node *makeNode(const string &val);

public:
    List();
    ~List();
    void insert(int pos, const string &val);
    void erase(int pos);
    string get(int pos) const;
    void print() const;
    int size() const;
};
#endif