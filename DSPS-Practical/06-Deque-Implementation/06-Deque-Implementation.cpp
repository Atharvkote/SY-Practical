#include <iostream>
#define MAX 5
using namespace std;

class Deque{
    
private:
    int deque[MAX];
    int front, rear;

public:
    Deque(){
        front = -1;
        rear = -1;
    }

    void insertRear(int val) {
        if (isFull()) {
            cout << "Queue is Full ! " << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = rear + 1;
        deque[rear] = val;
    }

    void insertFront(int val) {
        if (isFull() || front <= 0) {
            cout << "[ ERROR ]: Cannot add item at front end !!!" << endl;
            return;
        }
        front = front - 1;
        deque[front] = val;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Queue is Empty !!!" << endl;
            return;
        }
        int val = deque[front];
        cout << "Deleted element is : " << val << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = front + 1;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "[ ERROR ]: Cannot delete value at rear end !!" << endl;
            return;
        }
        int val = deque[rear];
        cout << "Deleted element is " << val << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            rear = rear - 1;
        }
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1;
    }

    int size() {
        if (isEmpty()) {
            return 0;
        }
        return rear - front + 1;
    }
};

int main() {
    Deque dq;
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertRear(30);
    cout << "Current size: " << dq.size() << endl;
    dq.deleteFront();
    cout << "Current size: " << dq.size() << endl;
    dq.deleteRear();
    cout << "Current size: " << dq.size() << endl;
    dq.insertFront(5);
    cout << "Current size: " << dq.size() << endl;
    return 0;
}
