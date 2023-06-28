#include "Stack.cpp"
#include <iostream>

using namespace std;

int main()
{
    Stack myStack(3);

    myStack.push(10);
    cout << "Pushed: 10" << endl;
    myStack.push(20);
    cout << "Pushed: 20" << endl;
    myStack.push(30);
    cout << "Pushed: 30" << endl
         << endl;

    cout << "Popped: " << myStack.pop() << endl;
    cout << "Popped: " << myStack.pop() << endl
         << endl;

    myStack.push(40);
    cout << "Pushed: 40" << endl;
    myStack.push(50);
    cout << "Pushed: 50" << endl
         << endl;

    cout << "Popped: " << myStack.pop() << endl;
    cout << "Popped: " << myStack.pop() << endl;
    cout << "Popped: " << myStack.pop() << endl;

    return 0;
}
