#include <iostream>
#include <string>
#define MAX 10
using namespace std;

class Orders {
    string pizza_name;
    string pizza_type;
    string pizza_price;

public:
    void take_order() {
        cout << " Pizza Name : ";
        cin >> pizza_name;
        cout << " Pizza Type : ";
        cin >> pizza_type;
        cout << " Pizza Price : ";
        cin >> pizza_price;
    }

    void display() const {
        cout << " Pizza Name : " << pizza_name << endl;
        cout << " Pizza Type : " << pizza_type << endl;
        cout << " Pizza Price : " << pizza_price << endl;
    }
};

class Queue {
private:
    Orders queue[MAX];  
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(const Orders& val) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (front == -1) {
            front = 0; 
        }
        queue[++rear] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Order Number: " << front + 1 << endl;
        queue[front].display();
        front++;
        
        if (front > rear) {
            front = rear = -1;
        }
    }

    Orders peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            Orders emptyOrder;
            return emptyOrder;
        }
        return queue[front];
    }

    int size()  {
        if (isEmpty()) {
            return 0;
        }
        return (rear - front + 1);
    }

    void display(){
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue: [ " << endl;
        cout << endl;
        for (int i = front; i <= rear; i++) {
            cout << "Order Number : " << i << endl;
            cout << endl;
            queue[i].display();
            cout << endl;
        }
        cout << "]" << endl;
    }
};

int main() {
    Queue q;
    int choice;

    do {
        cout << "\nQueue Operations Menu:" << endl;
        cout << "1. Order" << endl;
        cout << "2. Mark Order As Done" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Orders val;
            val.take_order();
            q.enqueue(val);
            q.display();
            break;
        }
        case 2:
            q.dequeue();
            q.display();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
