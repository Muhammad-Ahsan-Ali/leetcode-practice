#include <iostream>
#include <vector>
using namespace std;

class Queue
{
private:
    vector<int> array;
    int front;
    int rear;
    int size;

public:
    Queue() : front(0), rear(0), size(0) {}
    void enqueue(int val);
    int dequeue();
    int get_front();
    bool empty();
};

bool Queue ::empty()
{
    return rear == front;
}

void Queue ::enqueue(int val)
{
    array.push_back(val);
    rear++;
}

int Queue ::dequeue()
{
    int value = array[front];
    front++;
    return value;
}

int Queue ::get_front()
{
    int value = array[front];
    return value;
}

class MyStack
{
private:
    int stackTop;
    Queue q1;
    Queue q2;

public:
    MyStack() : stackTop(-1) {}
    void push(int val);
    int pop();
    int top();
    bool empty() { return stackTop == -1; }
};

void MyStack ::push(int val)
{

    while (!q1.empty())
    {
        q2.enqueue(q1.dequeue());
    }

    q1.enqueue(val);

    stackTop++;

    while (!q2.empty())
    {
        q1.enqueue(q2.dequeue());
    }
}

int MyStack ::pop()
{
    stackTop--;
    return q1.dequeue();
}

int MyStack ::top()
{
    return q1.get_front();
}

int main()
{
    return 0;
}