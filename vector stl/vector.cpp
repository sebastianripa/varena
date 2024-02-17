#include <bits/stdc++.h>

using namespace std;

template <class T>
class Vector
{
    int _size = 0, _capacity = 1;
    T *arr;
    public:
    void reserve(int arg)
    {
        if(arg > _capacity)
        {
            T *new_arr;
            new_arr = new T[arg];
            for(int i = 0; i <= arg; ++i)
                new_arr[i] = arr[i];
            swap(arr, new_arr);
            delete [] new_arr;
            _capacity = arg;
        }
    }
    int size()
    {
        return _size;
    }
    void push_back(T x)
    {
        if(_capacity == _size)
            reserve(_capacity*2);
        arr[_size++] = x;
    }
    T &operator [](int x)
    {
        return arr[x];
    }
};

int main()
{
    int n;
    
}