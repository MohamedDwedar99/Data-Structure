#include <iostream>
#include <assert.h>

class Vector
{
    private:
        int * arr {nullptr};
        int size {0};
        int capacity {0};
        void expand_capacity(void);
    public:
        Vector(int size);
        ~Vector(); 
        int get(int idx);
        void set(int idx, int val);
        int find(int val);
        void print(void);
        int get_front(void);
        int get_back(void);
        void push_back(int val);
        void insert(int index, int val);
        void right_rotate(void);// Problem 1 HomeWork
        void left_rotate(void);// Problem 2 HomeWork
        void right_rotate(int times);// Problem 3 HomeWork
        int pop(int idx);// Problem 4 HomeWork
        int find_transposition(int value); // Problem 5 HomeWork
};

Vector::Vector(int size) : size(size){
    if (size < 0)
        size = 1;
    capacity = size +10;
    arr = new int[capacity];
}

Vector::~Vector()
{
    delete[] arr;
    arr = nullptr;
}
        
int Vector::get(int idx)
{
    assert(0 <= idx && idx < size);
    return arr[idx];
}

void Vector::set(int idx, int val)
{
    assert(0 <= idx && idx < size);
    arr[idx] = val;
}

int Vector::find(int val)
{
    for (int i = 0; i < size; i++)
    {
        if(val == arr[i])
        {
            return i;
        }
    }
    return -1;
}
void Vector::print(void)
{
    for (int i = 0; i < size; i++)
    
        std::cout << arr[i] << " ";
    
    std::cout << "\n";
}

int Vector::get_front(void)
{
    return arr[0];
}

int Vector::get_back(void)
{
    return arr[size-1];
}

void Vector::push_back(int val)
{
    if (size == capacity)
        expand_capacity();
    // increase add elemnt and size
    arr[size++] = val;
}

void Vector::insert(int index, int val)
{
    assert(index >= 0 && index < size);
    if (size == capacity)
        expand_capacity();
    for (int i = size; i > index; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[index] = val;
    size++;
}
void Vector::expand_capacity(void)
{
    capacity*= 2;
    int * arr2  = new int[capacity];
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }
    delete[] arr;
    arr = arr2;

}

// Problem 1 HomeWork
void Vector::right_rotate(void){
    int temp = arr[size-1];
    for (int i = size-1; i >= 0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

// Problem 2 HomeWork
void Vector::left_rotate(void){
    int temp = arr[0];
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[size-1] = temp;
}

// Problem 3 HomeWork
void Vector::right_rotate(int times)
{
    int * arr2 = new int[capacity];
    for (int i = 0; i < size; i++)
    {
        int location = (i+times)%(size);
        arr2[location] = arr[i];
    }
    delete[] arr;
    arr = arr2;
    arr2 = nullptr;
}

// Problem 4 HomeWork
int Vector::pop(int idx){
    assert(0 <= idx && idx < size);
    int ret = arr[idx];
    for(int i = idx; i < size; i++)
    {
        arr[i] = arr[i+1];
    }
    size--;
    return ret;
}

// Problem 5 HomeWork
int Vector::find_transposition(int value)
{
    int ret = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            ret = value;
            if (i > 0)
            {
                arr[i] = arr[i-1];
                arr[i-1] = ret;
            }
        }
    }
    return ret;
}
int main (void)
{
    Vector v(10);
    for (int i = 0; i < 10; i++)
    {
        v.set(i,i);
    }
    v.print();
    int ret = v.find_transposition(2);
    v.print();
    std::cout << ret;
    return 0;
}