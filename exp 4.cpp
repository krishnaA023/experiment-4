
#include <iostream>
#include <stack>
#include <queue>
#include <chrono>

using namespace std;
using namespace chrono;

template <class T>
class MyStack
{
private:
    T data[10000];
    int top;

public:
    MyStack()
    {
        top = -1;
    }

    void push(T value)
    {
        if (top < 9999)
            data[++top] = value;
    }

    void pop()
    {
        if (top >= 0)
            top--;
    }
};

template <class T>
class MyQueue
{
private:
    T data[10000];
    int front, rear;

public:
    MyQueue()
    {
        front = 0;
        rear = -1;
    }

    void enqueue(T value)
    {
        if (rear < 9999)
            data[++rear] = value;
    }

    void dequeue()
    {
        if (front <= rear)
            front++;
    }
};

int main()
{
    int N, value;
    int arr[10000];

    cout << "Enter number of elements: ";
    cin >> N;

    if (N < 0 || N > 10000)
    {
        cout << "Invalid number of elements";
        return 0;
    }

    cout << "Enter " << N << " elements:\n";

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // Custom Stack
    auto start = high_resolution_clock::now();

    MyStack<int> myStack;

    for (int i = 0; i < N; i++)
        myStack.push(arr[i]);

    for (int i = 0; i < N; i++)
        myStack.pop();

    auto end = high_resolution_clock::now();

    auto customStackTime =
        duration_cast<microseconds>(end - start);

    // STL Stack
    start = high_resolution_clock::now();

    stack<int> stlStack;

    for (int i = 0; i < N; i++)
        stlStack.push(arr[i]);

    for (int i = 0; i < N; i++)
        stlStack.pop();

    end = high_resolution_clock::now();

    auto stlStackTime =
        duration_cast<microseconds>(end - start);

    // Custom Queue
    start = high_resolution_clock::now();

    MyQueue<int> myQueue;

    for (int i = 0; i < N; i++)
        myQueue.enqueue(arr[i]);

    for (int i = 0; i < N; i++)
        myQueue.dequeue();

    end = high_resolution_clock::now();

    auto customQueueTime =
        duration_cast<microseconds>(end - start);

    // STL Queue
    start = high_resolution_clock::now();

    queue<int> stlQueue;

    for (int i = 0; i < N; i++)
        stlQueue.push(arr[i]);

    for (int i = 0; i < N; i++)
        stlQueue.pop();

    end = high_resolution_clock::now();

    auto stlQueueTime =
        duration_cast<microseconds>(end - start);

    // Display Results
    cout << "\n--- Performance Comparison ---\n";

    cout << "Custom Stack Time: "
         << customStackTime.count() << " microseconds\n";

    cout << "STL Stack Time: "
         << stlStackTime.count() << " microseconds\n";

    cout << "Custom Queue Time: "
         << customQueueTime.count() << " microseconds\n";

    cout << "STL Queue Time: "
         << stlQueueTime.count() << " microseconds\n";

    return 0;
}
