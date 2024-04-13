#include <iostream>
#include <stdexcept>

template<typename T>
class deque {
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
    deque() : cap(10), frontIdx(0), backIdx(-1), numElem(0) {
        arr = new T[cap];
    }

    // destructor
    ~deque() {
        delete[] arr;
    }

    // copy constructor
    deque(const deque& other) : cap(other.cap), frontIdx(other.frontIdx), backIdx(other.backIdx), numElem(other.numElem) {
        arr = new T[cap];
        for (int i = 0; i < cap; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // assignment operator
    deque& operator=(const deque& other) {
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
};

int main() {
    deque<int> deque;

    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);

    std::cout << "size: " << deque.size() << std::endl;
    std::cout << "capacity: " << deque.get_cap() << std::endl;

    deque.pop_front();

    std::cout << "size after popping front: " << deque.size() << std::endl;

    return 0;
}
