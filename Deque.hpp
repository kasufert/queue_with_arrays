#include"InternalStack.hpp"
using namespace std;
template<typename T>
class Deque {
    InternalStack<T> rear;
    InternalStack<T> head;
    
    void reorganize()
    {
        while (!rear.empty())
        {
            head.push(rear.top());
            rear.pop();
        }
    }
public:
    Deque()
    : rear(), head()
    {}

    void push_front(T x)
    {
        head.push(x);
    }
    T pop_front()
    {
        if (head.empty())
        {
            reorganize();
        }
        T item = head.top();
        head.pop();
        return item;
    }
    void push_back(T x)
    {
        rear.push(x);
    }
    T pop_back()
    {
        if (rear.empty())
        {
            return head.steal_bottom();
        }
        return rear.pop();
    }

    T peek_front()
    {
        if (head.empty())
        {
            reorganize();
        }
        return head.top();
    }
    T peek_back()
    {
        if (rear.empty())
        {
            return head.peek_bottom();
        }
        else return rear.top();
    }
    
    bool empty()const
    {
        return head.empty() && rear.empty();
    }
};