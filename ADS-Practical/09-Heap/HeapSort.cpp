#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class MinHeap
{
private:
    int heap[30];
    int size;

public:
    MinHeap()
    {
        cout << "Enter Number of Elements (less than 30): ";
        cin >> size;
        for (int i = 0; i < size; i++)
        {
            cout << "Heap[ " << i << " ] : ";
            cin >> heap[i];
        }
    }

    void downheap(int index)
    {
        int left_index = 2 * index + 1;
        int right_index = 2 * index + 2;
        int next_large_number = index;

        if (left_index < size && heap[left_index] < heap[next_large_number])
        {
            next_large_number = left_index;
        }

        if (right_index < size && heap[right_index] < heap[next_large_number])
        {
            next_large_number = right_index;
        }

        if (next_large_number != index)
        {
            int temp = heap[index];
            heap[index] = heap[next_large_number];
            heap[next_large_number] = temp;
            downheap(next_large_number);
        }
    }

    void sort()
    {
        for (int j = 0; j < size  ; j++)
        {
            for (int i = size; i >= 0; i--)
            {
                if(i < j) continue;
                downheap(i);
            }
        }
    }

    void getMin()
    {
        if (size == 0)
        {
            cout << "Heap is empty\n";
            return;
        }
        cout << "Min value in heap: " << heap[0] << endl;
    }

    void display()
    {
        cout << "\nHeap: { ";
        for (int i = 0; i < size; i++)
        {
            cout << heap[i];
            if (i != size - 1)
                cout << " , ";
            else
                cout << " ";
        }
        cout << "};\n";
    }
};

int main()
{
    MinHeap heap;
    cout << "Unsorted Array : ";
    heap.display();
    heap.sort();
    cout << "Sorted Array : ";
    heap.display();
    return 0;
}