#pragma once
#include<iostream>
template<typename T>
class Queue
{
private:
    size_t count;
    size_t numArrays;
    size_t arraySize;
    size_t front;
    size_t back;
    T** arrays;
    void appendArray();
    void ditchBack();
public:
    Queue();
    ~Queue();
    void enqueue(T item);
    T dequeue();
    T peek()const;
    bool empty()const;
    size_t size()const;
};

template<typename T>
Queue<T>::Queue()
{

}

template<typename T>
Queue<T>::~Queue()
{

}

template<typename T>
void Queue<T>::enqueue(T item)
{

}

template<typename T>
T Queue<T>::dequeue()
{
    return nullptr;
}

template<typename T>
T Queue<T>::peek() const
{
    return nullptr;
}

template<typename T>
bool Queue<T>::empty() const
{
    return false;
}

template<typename T>
size_t Queue<T>::size() const {
    return 0;
}

template<typename T>
void Queue<T>::appendArray()
{
    ++numArrays;
    T** old_arrays = arrays;
    arrays = new T*[numArrays];
    memcpy(arrays, old_arrays, (sizeof(T*)*(numArrays-1)));
    // At this point arrays can hold one more array
    arrays[numArrays-1] = new T[arraySize];
}

template<typename T>
void Queue<T>::ditchBack()
{
    T* firstArr = arrays[0];
    arrays = arrays+1;
    delete firstArr;
}
