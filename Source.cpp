#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
#include <vector>
template <typename T>
class SortableArray {
public:
    // Allocate `size` numbers of type T on the heap.
    SortableArray(int size);
    // Free/Delete the allocated memory on the heap.
    ~SortableArray();
    // Set the `position` in the array to be `value`.
    void set(int position, T value);
    // Return a reference to the `value` at `position` in the array.
    T& at(int position);
    // Sort all the values in the array so that the smallest item appears first.
    void sort();
    int size_;

private:
    
    T* data_;
};

class Disks
{
public:
    Disks():disks(0){}
    Disks(int disks):disks(disks){}
    int disks;
    bool operator <(const Disks& other)
    {
        return disks < other.disks;
    }
};

template <typename T>
SortableArray<T>::SortableArray(int size)
    : size_(size), data_(new T[size]) {}

template <typename T>
SortableArray<T>::~SortableArray()
{
    delete[] data_;
}

template <typename T>
void SortableArray<T>::set(int position, T value)
{
    data_[position] = value;
}

template <typename T>
T& SortableArray<T>::at(int position)
{
    return data_[position];
}

template <typename T>
void SortableArray<T>::sort()
{
    for (int i = 0; i < size_ - 1; i++)
    {
        for (int j = i + 1; j < size_; j++)
        {
            if (data_[j] < data_[i])
            {
                T temp = data_[i];
                data_[i] = data_[j];
                data_[j] = temp;
            }
        }
    }
}


void test_integers()
{
    SortableArray<int> a(10);

    int test_input[] = { 3, 5, 10, 0, 0, 1, 2, 8, 9, 17 };
    int test_output[] = { 0, 0, 1, 2, 3, 5, 8, 9, 10, 17 };
    for (int i = 0; i < 10; i++)
    {
        a.set(i, test_input[i]);
    }

    a.sort();

    for (int i = 0; i < 10; i++) 
    {
        assert(a.at(i) == test_output[i]);

        
    }
}

void test_strings() 
{
    SortableArray<std::string> a(4);

    std::string test_input[] = { "orange", "banana", "apple", "strawberry" };
    std::string test_output[] = { "apple", "banana", "orange", "strawberry" };
    for (int i = 0; i < 4; i++)
    {
        a.set(i, test_input[i]);
    }

    a.sort();

    for (int i = 0; i < 4; i++)
    {
        assert(a.at(i) == test_output[i]);

        
    }
}

void test_large_array()
{
    const int SIZE = 1000;
    SortableArray<int> a(SIZE);

    srand(time(0));
    for (int i = 0; i < SIZE; i++)
    {
        a.set(i, rand());
    }

    a.sort();

    for (int i = 0; i < SIZE - 1; i++)
    {
        assert(a.at(i) <= a.at(i + 1));

        
    }
}

void test_empty_array()
{
    SortableArray<int> a(0);

    a.sort();

    assert(a.size_ == 0);

   
}


void test_inverse_integers()
{
    SortableArray<int> a(10);

    int test_input[] = { 20, 17, 13, 11, 10, 9, 4, 3, 2, 1 };
    int test_output[] = { 1, 2, 3, 4, 9, 10, 11, 13, 17, 20 };
    for (int i = 0; i < 10; i++)
    {
        a.set(i, test_input[i]);
    }

    a.sort();

    for (int i = 0; i < 10; i++)
    {
        assert(a.at(i) == test_output[i]);

        
    }
}

void test_sorted_integers()
{
    SortableArray<int> a(10);

    int test_input[] = { 1, 2, 3, 4, 9, 10, 11, 13, 17, 20 };
    int test_output[] = { 1, 2, 3, 4, 9, 10, 11, 13, 17, 20 };
    for (int i = 0; i < 10; i++)
    {
        a.set(i, test_input[i]);
    }

    a.sort();

    for (int i = 0; i < 10; i++)
    {
        assert(a.at(i) == test_output[i]);

        
    }
}

void test_class()
{
    SortableArray<Disks> a(3);

    Disks test_input[] = { Disks(3), Disks(1), Disks(2) };
    Disks test_output[] = { Disks(1), Disks(2), Disks(3) };

    for (int i = 0; i < 3; i++)
    {
        a.set(i, test_input[i]);
    }

    a.sort();

    for (int i = 0; i < 3; i++)
    {
        assert(a.at(i).disks == test_output[i].disks);

    }
}

int main()
{
    test_integers();

    test_class();

    test_strings();
   
    test_large_array();
   
    test_empty_array();
   
    test_inverse_integers();
   
    test_sorted_integers();

    printf("All the test passed\n");
}