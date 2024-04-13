#include <iostream>
#include <stdexcept>

template<typename T>
class Deque {
private:
    T* arr; // pointer to dynamic array
    int cap; // total capacity of the deque
    int frontIdx; // index of the front element
    int backIdx; // index of the back element
    int numElem; // number of elements in the deque

    void resize() {
        int newCap = cap * 2;
        T* newArr = new T[newCap];

        // copy elements to the new array
        for (int i = 0; i < numElem; ++i) {
            newArr[i] = arr[(frontIdx + i) % cap];
        }

        delete[] arr; // free the memory of the old array
        arr = newArr;
        frontIdx = 0;
        backIdx = numElem - 1;
        cap = newCap;
    }

public:
    // constructor
    Deque() : cap(10), frontIdx(0), backIdx(-1), numElem(0) {
        arr = new T[cap];
    }

    // destructor
    ~Deque() {
        delete[] arr;
    }

    // copy constructor
    Deque(const Deque& other) : cap(other.cap), frontIdx(other.frontIdx), backIdx(other.backIdx), numElem(other.numElem) {
        arr = new T[cap];
        for (int i = 0; i < cap; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // assignment operator
    Deque& operator=(const Deque& other) {
        if (this != &other) {
            delete[] arr;
            cap = other.cap;
            frontIdx = other.frontIdx;
            backIdx = other.backIdx;
            numElem = other.numElem;
            arr = new T[cap];
            for (int i = 0; i < cap; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    // push element to the front
    void push_front(const T& value) {
        if (numElem == cap) {
            resize();
        }
        frontIdx = (frontIdx - 1 + cap) % cap;
        arr[frontIdx] = value;
        ++numElem;
    }

    // push element to the back
    void push_back(const T& value) {
        if (numElem == cap) {
            resize();
        }
        backIdx = (backIdx + 1) % cap;
        arr[backIdx] = value;
        ++numElem;
    }

    // pop element from the front
    void pop_front() {
        if (numElem == 0) {
            throw std::runtime_error("deque is empty");
        }
        frontIdx = (frontIdx + 1) % cap;
        --numElem;
    }

    // pop element from the back
    void pop_back() {
        if (numElem == 0) {
            throw std::runtime_error("deque is empty");
        }
        backIdx = (backIdx - 1 + cap) % cap;
        --numElem;
    }

    // get the size of the deque
    int size() const {
        return numElem;
    }

    // get the capacity of the deque
    int get_cap() const {
        return cap;
    }

    // check if deque is empty
    bool empty() const {
        return numElem == 0;
    }

    // get the front element
    T& front() {
        if (empty()) {
            throw std::runtime_error("deque is empty");
        }
        return arr[frontIdx];
    }

    // get the back element
    T& back() {
        if (empty()) {
            throw std::runtime_error("deque is empty");
        }
        return arr[backIdx];
    }
};

template<typename T>
class Stack {
private:
    Deque<T> deque;

public:
    // push element to the stack
    void push(const T& value) {
        deque.push_back(value);
    }

    // pop element from the stack
    void pop() {
        if (empty()) {
            throw std::runtime_error("stack is empty");
        }
        deque.pop_back();
    }

    // get the top element of the stack
    T& top() {
        if (empty()) {
            throw std::runtime_error("stack is empty");
        }
        return deque.back();
    }

    // check if stack is empty
    bool empty() const {
        return deque.empty();
    }

    // get the size of the stack
    int size() const {
        return deque.size();
    }
};

int main() {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Size: " << stack.size() << std::endl;
    std::cout << "Top element: " << stack.top() << std::endl;

    stack.pop();

    std::cout << "Size after popping: " << stack.size() << std::endl;
    std::cout << "Top element after popping: " << stack.top() << std::endl;

    return 0;
}
