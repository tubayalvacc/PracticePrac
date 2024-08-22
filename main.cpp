//----------------------reverse queue---------------------
#include <iostream>
using namespace std;

// Node structure for the linked list implementation
struct Node {
    int data;       // Stores the data in the node
    Node* next;     // Pointer to the next node in the linked list
};

// Custom Queue class
class Queue {
private:
    Node* front;    // Pointer to the front of the queue
    Node* rear;     // Pointer to the rear of the queue

public:
    // Constructor to initialize the queue
    Queue() {
        front = nullptr;   // Initially, the queue is empty, so front is set to nullptr
        rear = nullptr;    // Initially, the queue is empty, so rear is set to nullptr
    }

    // Method to enqueue (add) an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node();  // Create a new node
        newNode->data = value;       // Set the node's data to the provided value
        newNode->next = nullptr;     // New node will be added at the end, so its next is nullptr

        if (rear == nullptr) {       // Check if the queue is empty
            front = rear = newNode;  // If empty, both front and rear point to the new node
        } else {
            rear->next = newNode;    // Otherwise, link the new node to the end of the queue
            rear = newNode;          // Update the rear pointer to the new node
        }
    }

    // Method to dequeue (remove) an element from the queue
    int dequeue() {
        if (front == nullptr) {      // Check if the queue is empty
            cout << "Queue is empty!" << endl;
            return -1;               // Return -1 if the queue is empty
        }
        int value = front->data;     // Store the data of the front node to return later
        Node* temp = front;          // Temporarily store the front node to delete it later
        front = front->next;         // Move the front pointer to the next node

        if (front == nullptr) {      // If the queue is now empty, update rear to nullptr
            rear = nullptr;
        }

        delete temp;                 // Delete the old front node to free memory
        return value;                // Return the data of the dequeued node
    }

    // Method to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;     // Queue is empty if front is nullptr
    }

    // Method to print the elements of the queue
    void printQueue() {
        Node* temp = front;          // Start from the front of the queue
        while (temp != nullptr) {    // Traverse until the end of the queue
            cout << temp->data << " ";  // Print the data of each node
            temp = temp->next;       // Move to the next node
        }
        cout << endl;                // Print a newline after printing all elements
    }
};

// Custom Stack class
class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr;   // Initially, the stack is empty, so top is set to nullptr
    }

    // Method to push (add) an element onto the stack
    void push(int value) {
        Node* newNode = new Node();  // Create a new node
        newNode->data = value;       // Set the node's data to the provided value
        newNode->next = top;         // Link the new node to the current top of the stack
        top = newNode;               // Update the top pointer to the new node
    }

    // Method to pop (remove) an element from the stack
    int pop() {
        if (top == nullptr) {        // Check if the stack is empty
            cout << "Stack is empty!" << endl;
            return -1;               // Return -1 if the stack is empty
        }
        int value = top->data;       // Store the data of the top node to return later
        Node* temp = top;            // Temporarily store the top node to delete it later
        top = top->next;             // Move the top pointer to the next node
        delete temp;                 // Delete the old top node to free memory
        return value;                // Return the data of the popped node
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;       // Stack is empty if top is nullptr
    }
};

// Function to reverse the elements of the queue
void reverseQueue(Queue& q) {
    Stack s;   // Create a stack to assist in reversing the queue

    // Transfer elements from the queue to the stack
    while (!q.isEmpty()) {      // Keep dequeueing until the queue is empty
        s.push(q.dequeue());    // Push each dequeued element onto the stack
    }

    // Transfer elements back from the stack to the queue
    while (!s.isEmpty()) {      // Keep popping until the stack is empty
        q.enqueue(s.pop());     // Enqueue each popped element back to the queue
    }
}

int main() {
    Queue q;           // Create a queue instance
    int element;       // Variable to store user input

    // User input for the elements to add to the queue
    cout << "" << endl;
    for (int i = 0; i <= 4; i++) { // Loop to get 5 elements from the user
        cin >> element;            // Read an integer from the user
        q.enqueue(element);        // Enqueue the element to the queue
    }

    // Reverse the queue
    reverseQueue(q);   // Call the function to reverse the queue

    // Print reversed queue
    cout << " \n";     // Print a newline for formatting
    q.printQueue();    // Print the elements of the reversed queue

    return 0;          // Return 0 to indicate successful execution
}


//--------------------------------5 values by using stack array -----------------------------

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
        top = -1;  // Stack is initially empty (indicated by -1)
    }

    // Method to push an element onto the stack
    void push(int value) {
        if (top >= MAX - 1) {         // Check if the stack is full
            cout << "Stack overflow!" << endl;  // Print an error if full
            return;                   // Exit the function
        }
        arr[++top] = value;           // Increment top and add value to the stack
        //cout << value << " pushed to stack" << endl;
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return top == -1;  // Stack is empty if top is -1
    }

    // Method to display the stack elements
    void display() {
        if (isEmpty()) {   // Check if the stack is empty
            cout << "Stack is empty!" << endl;
            return;        // Exit the function
        }
        cout << " " << endl;
        for (int i = top; i >= 0; i--) {  // Loop from the top to the bottom of the stack
            cout << arr[i] << " ";       // Print each element
        }
        cout << endl;    // Print a newline after displaying all elements
    }
};

int main() {
    Stack stack;  // Create a stack instance

    for (int i = 0; i < 5; i++){   // Loop to get 5 elements from the user
        int value;                 // Variable to store user input
        cout << " ";               // Prompt for user input
        cin >> value;              // Read an integer from the user
        stack.push(value);         // Push the value onto the stack
    }

    // Display the stack elements
    stack.display();   // Call the display method to print the stack elements
    return 0;          // Return 0 to indicate successful execution
}

