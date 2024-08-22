//reverse queue 

#include <iostream>
using namespace std;

// Node structure for the linked list implementation
struct Node {
    int data;
    Node* next;
};

// Custom Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor to initialize the queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Method to enqueue (add) an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Method to dequeue (remove) an element from the queue
    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return -1; // Return -1 if the queue is empty
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return value;
    }

    // Method to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Method to print the elements of the queue
    void printQueue() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Custom Stack class
class Stack {
private:
    Node* top;

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr;
    }

    // Method to push (add) an element onto the stack
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Method to pop (remove) an element from the stack
    int pop() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return -1; // Return -1 if the stack is empty
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to reverse the elements of the queue
void reverseQueue(Queue& q) {
    Stack s;

    // Transfer elements from the queue to the stack
    while (!q.isEmpty()) {
        s.push(q.dequeue());
    }

    // Transfer elements back from the stack to the queue
    while (!s.isEmpty()) {
        q.enqueue(s.pop());
    }
}

int main() {
    Queue q;
    int element;



    // User input for the elements to add to the queue
    cout << "" << endl;
    for (int i = 0; i <= 4; i++) {
        cin >> element;
        q.enqueue(element);
    }

    // Reverse the queue
    reverseQueue(q);

    // Print reversed queue
    cout << " \n";
    q.printQueue();

    return 0;
}

//5 values by using stack array 

#include <iostream>
using namespace std;

// Define a class for the stack
class Stack {
private:
    static const int MAX = 100;  // Maximum size of the stack
    int arr[MAX];                // Array to hold stack elements
    int top;                     // Index of the top element in the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1;  // Stack is initially empty
    }

    // Method to push an element onto the stack
    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = value;
        //cout << value << " pushed to stack" << endl;
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Method to display the stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << " " << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;  // Create a stack instance

    for (int i = 0; i < 5; i++){
        int value;
        cout << " ";
        cin >> value;
        stack.push(value);  // Push the value onto the stack
    }

    // Display the stack elements
    stack.display();
    return 0;
}
