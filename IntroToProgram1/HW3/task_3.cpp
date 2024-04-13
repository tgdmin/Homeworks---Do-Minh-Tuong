#include <iostream>
#include <typeinfo>

// Meta-function to remove const, reference, pointer, and array qualifiers
template <typename OriginalType>
struct TrueType {
    using ResultType = OriginalType;
};

template <typename ElementType, size_t N>
struct TrueType<const ElementType[N]> : TrueType<ElementType> {};

template <typename ElementType, size_t N>
struct TrueType<ElementType[N]> : TrueType<ElementType> {};

template <typename OriginalType>
struct TrueType<const OriginalType> : TrueType<OriginalType> {};

template <typename OriginalType>
struct TrueType<OriginalType&> : TrueType<OriginalType> {};

template <typename OriginalType>
struct TrueType<OriginalType&&> : TrueType<OriginalType> {};

template <typename OriginalType>
struct TrueType<OriginalType*> : TrueType<OriginalType> {};

// Meta-function to remove const, reference, pointer, and array qualifiers,
// but keep cv-qualifiers for non-array types
template <typename OriginalType>
struct TrueTypeNoArray {
    using ResultType = OriginalType;
};

template <typename ElementType, size_t N>
struct TrueTypeNoArray<const ElementType[N]> : TrueTypeNoArray<ElementType> {};

template <typename ElementType, size_t N>
struct TrueTypeNoArray<ElementType[N]> : TrueTypeNoArray<ElementType> {};

template <typename OriginalType>
struct TrueTypeNoArray<const OriginalType> : TrueTypeNoArray<OriginalType> {};

template <typename OriginalType>
struct TrueTypeNoArray<OriginalType&> : TrueTypeNoArray<OriginalType> {};

template <typename OriginalType>
struct TrueTypeNoArray<OriginalType&&> : TrueTypeNoArray<OriginalType> {};

template <typename OriginalType>
struct TrueTypeNoArray<OriginalType*> : TrueTypeNoArray<OriginalType> {};

// Test function
template <typename TestType>
void testType() {
    std::cout << "Original type: " << typeid(TestType).name() << std::endl;
    std::cout << "TrueType type: " << typeid(typename TrueType<TestType>::ResultType).name() << std::endl;
    std::cout << "TrueTypeNoArray type: " << typeid(typename TrueTypeNoArray<TestType>::ResultType).name() << std::endl;
    std::cout << "------------------------" << std::endl;
}

int main() {
    // Test with various types
    testType<int>();
    testType<const int>();
    testType<int&>();
    testType<int&&>();
    testType<int*>();
    testType<int[1]>();
    testType<int[2]>();
    testType<const int[4]>();
    testType<const int* const[5]>();
    testType<const volatile int[6][7]>();

    return 0;
}
