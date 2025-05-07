#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class MaxHeap
{
private:
    int heap[30];
    int size;

public:
    MaxHeap() { size = 0; }

    void upheap(int index)
    {
        int parent_index = floor((index - 1) / 2);
        if (heap[parent_index] < heap[index])
        {
            int temp = heap[parent_index];
            heap[parent_index] = heap[index];
            heap[index] = temp;
            upheap(parent_index);
        }
    }

    void insert(int val)
    {
        if (size == 0)
        {
            heap[0] = val;
            size++;
        }
        else
        {
            heap[size] = val;
            cout << "Element Inserted!\n";
            size++;
            cout << "Re-organizing heap......\n";
            upheap(size - 1);
            cout << "Re-organizing heap done!!!!!\n";
        }
    }

    void downheap(int index)
    {
        int left_index = 2 * index + 1;
        int right_index = 2 * index + 2;
        int next_large_number = index;

        if (left_index < size && heap[left_index] > heap[next_large_number])
        {
            next_large_number = left_index;
        }

        if (right_index < size && heap[right_index] > heap[next_large_number])
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

    void remove()
    {
        if (size == 0)
        {
            cout << "Can't Remove from empty heap\n";
            return;
        }

        cout << "Removed Value : " << heap[0] << endl;

        heap[0] = heap[size - 1];
        heap[size - 1] = 0;
        size--;
        cout << "Re-organizing heap......\n";
        downheap(0);
        cout << "Re-organizing heap done!!!!!\n";
    }

    void getMax()
    {
        if (size == 0)
        {
            cout << "Heap is empty\n";
            return;
        }
        cout << "Max value in heap: " << heap[0] << endl;
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

class MinHeap
{
private:
    int heap[30];
    int size;

public:
    MinHeap() { size = 0; }

    void upheap(int index)
    {
        int parent_index = floor((index - 1) / 2);
        if (heap[parent_index] > heap[index])
        {
            int temp = heap[parent_index];
            heap[parent_index] = heap[index];
            heap[index] = temp;
            upheap(parent_index);
        }
    }

    void insert(int val)
    {
        if (size == 0)
        {
            heap[0] = val;
            size++;
        }
        else
        {
            heap[size] = val;
            cout << "Element Inserted!\n";
            size++;
            cout << "Re-organizing heap......\n";
            upheap(size - 1);
            cout << "Re-organizing heap done!!!!!\n";
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

    void remove()
    {
        if (size == 0)
        {
            cout << "Can't Remove from empty heap\n";
            return;
        }

        cout << "Removed Value : " << heap[0] << endl;

        heap[0] = heap[size - 1];
        heap[size - 1] = 0;
        size--;
        cout << "Re-organizing heap......\n";
        downheap(0);
        cout << "Re-organizing heap done!!!!!\n";
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
    bool exit = false;
    int isMaxheap;
    cout << "Enter Your Choice : \n1. Max Heap\n2. Min Heap\n3. Exit\n";
    cin >> isMaxheap;

    if (isMaxheap <= 2) {
        if (isMaxheap == 1) {
            cout << "Initializing Max Heap........\n";
            MaxHeap h;
            int choice, val;
            do
            {
                cout << "\nMenu:\n";
                cout << "1. Insert element\n";
                cout << "2. Remove element\n";
                cout << "3. Get max element\n";
                cout << "4. Display heap\n";
                cout << "5. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;
        
                switch (choice)
                {
                case 1:
                    cout << "Enter value to insert: ";
                    cin >> val;
                    h.insert(val);
                    break;
                case 2:
                    h.remove();
                    break;
                case 3:
                    h.getMax();
                    break;
                case 4:
                    h.display();
                    break;
                case 5:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                }
            } while (choice != 5);
        }
        else {
            cout << "Initializing Min Heap........\n";
            MinHeap h;
            int choice, val;
            do
            {
                cout << "\nMenu:\n";
                cout << "1. Insert element\n";
                cout << "2. Remove element\n";
                cout << "3. Get min element\n";
                cout << "4. Display heap\n";
                cout << "5. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;
        
                switch (choice)
                {
                case 1:
                    cout << "Enter value to insert: ";
                    cin >> val;
                    h.insert(val);
                    break;
                case 2:
                    h.remove();
                    break;
                case 3:
                    h.getMin();
                    break;
                case 4:
                    h.display();
                    break;
                case 5:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                }
            } while (choice != 5);
        }
    }

    return 0;
}
