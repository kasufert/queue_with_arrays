template<typename T>
class InternalStack
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
    InternalStack()
    : count(0), size(8)
    {
        arr = new T[size];
    }
    ~InternalStack()
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
    T steal_bottom()
    {
        T item = arr[0];
        for (int i = 0; i < count-1; ++i)
        {
            arr[i] = arr[i+1];
        }
        --count;
        return item;
    }
    T peek_bottom()
    {
        return arr[0];
    }
};