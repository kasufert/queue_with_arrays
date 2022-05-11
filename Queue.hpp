#include"Stack.hpp"
template<typename T>
class Queue
{
    Stack<T> rear;
    Stack<T> head;
    
    void reorganize()
    {
        while (!rear.empty())
        {
            head.push(rear.top());
            rear.pop();
        }
    }
public:
    Queue()
    : rear(), head()
    {}

    T dequeue()
    {
        if (head.empty())
        {
            reorganize();
        }
        return head.pop();
    }

    void enqueue(T x)
    {
        rear.push(x);
    }

    T peek()
    {
        if (head.empty())
        {
            reorganize();
        }
        return head.top();
    }
    
    bool empty()const
    {
        return head.empty() && rear.empty();
    }
};