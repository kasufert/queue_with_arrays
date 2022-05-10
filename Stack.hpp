#include"Deque.hpp"
template<typename T>
class Stack
{
        T* arr;
    int size;
    int count;
    void resize()
    {
        size *= 2;
        T* newArr = new T[size];
        for (int i = 0; i < count; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
public:
    Stack()
    : count(0), size(8)
    {
        arr = new T[size];
    }
    ~Stack()
    {
        delete[] arr;
    }
    void push(T item)
    {
        if (count >= size)
            resize();

        arr[count] = item;
        ++count;
    }
    T pop()
    {
        --count;
        return arr[count];
    }
    T top()const
    {
        return arr[count-1];
    }
    bool empty()const
    {
        return count == 0;
    }
};