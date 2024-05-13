#include <iostream>
#include <vector>
#include <stdexcept>

//Matrix class
template<typename T>
class Matrix {
private:
    size_t rows; // number of rows
    size_t cols; // number of columns
    std::vector<std::vector<T>> data; 

public:
    // Constructor to make a matrix with the given size
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, std::vector<T>(cols)) {}

    // Another constructor to initialize with fancy lists
    Matrix(std::initializer_list<std::initializer_list<T>> list) {
        rows = list.size();
        cols = list.begin()->size();
        data.reserve(rows);
        for (auto& row : list) {
            if (row.size() != cols) {
                throw std::invalid_argument("All rows must have the same number of columns");
            }
            data.push_back(row);
        }
    }

    // this thing lets you access and modify the matrix elements
    T& operator()(size_t i, size_t j) {
        if (i >= rows || j >= cols) {
            throw std::out_of_range("Oops! Index out of range");
        }
        return data[i][j];
    }

    // this one is for accessing elements (read-only)
    const T& operator()(size_t i, size_t j) const {
        if (i >= rows || j >= cols) {
            throw std::out_of_range("Oops! Index out of range");
        }
        return data[i][j];
    }

    // returns the number of rows
    size_t numRows() const {
        return rows;
    }

    // returns the number of columns
    size_t numCols() const {
        return cols;
    }
};

// adding matrices like it's basic arithmetic
template<typename T>
Matrix<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs) {
    // making sure dimensions match for addition
    if (lhs.numRows() != rhs.numRows() || lhs.numCols() != rhs.numCols()) {
        throw std::invalid_argument("Mismatched sizes! Can't add these matrices");
    }

    // creating a result matrix of the same size
    Matrix<T> result(lhs.numRows(), lhs.numCols());

    // adding elements one by one
    for (size_t i = 0; i < lhs.numRows(); ++i) {
        for (size_t j = 0; j < lhs.numCols(); ++j) {
            result(i, j) = lhs(i, j) + rhs(i, j);
        }
    }
    return result;
}

// subtracting matrices
template<typename T>
Matrix<T> operator-(const Matrix<T>& lhs, const Matrix<T>& rhs) {
    // checking if sizes match for subtraction
    if (lhs.numRows() != rhs.numRows() || lhs.numCols() != rhs.numCols()) {
        throw std::invalid_argument("Oops! Size mismatch for subtraction");
    }

    // creating a result matrix of the same size
    Matrix<T> result(lhs.numRows(), lhs.numCols());

    // subtracting elements one by one
    for (size_t i = 0; i < lhs.numRows(); ++i) {
        for (size_t j = 0; j < lhs.numCols(); ++j) {
            result(i, j) = lhs(i, j) - rhs(i, j);
        }
    }
    return result;
}

// multiplying matrices, fancy stuff
template<typename T>
Matrix<T> operator*(const Matrix<T>& lhs, const Matrix<T>& rhs) {
    // making sure sizes match for multiplication
    if (lhs.numCols() != rhs.numRows()) {
        throw std::invalid_argument("Oops! Sizes don't match for multiplication");
    }

    // creating a result matrix with the right size
    Matrix<T> result(lhs.numRows(), rhs.numCols());

    // doing the multiplication dance
    for (size_t i = 0; i < lhs.numRows(); ++i) {
        for (size_t j = 0; j < rhs.numCols(); ++j) {
            for (size_t k = 0; k < lhs.numCols(); ++k) {
                result(i, j) += lhs(i, k) * rhs(k, j);
            }
        }
    }
    return result;
}

// lambda function to transpose a matrix
auto transpose = [](const Matrix<int>& mat) {
    // creating a result matrix with swapped dimensions
    Matrix<int> result(mat.numCols(), mat.numRows());

    // doing the transpose thing
    for (size_t i = 0; i < mat.numRows(); ++i) {
        for (size_t j = 0; j < mat.numCols(); ++j) {
            result(j, i) = mat(i, j);
        }
    }
    return result;
};

// function to find the trace of a matrix
template<typename T>
T trace(const Matrix<T>& mat) {
    // making sure it's a square matrix
    if (mat.numRows() != mat.numCols()) {
        throw std::invalid_argument("Oops! Only square matrices have traces");
    }

    // calculating the trace
    T result = 0;
    for (size_t i = 0; i < mat.numRows(); ++i) {
        result += mat(i, i);
    }
    return result;
}

// main function
int main() {
    // creating and initializing matrices
    Matrix<int> mat1 = {{1, 2, 3}, {4, 5, 6}};
    Matrix<int> mat2 = {{6, 5}, {4, 3}, {2, 1}};

    // printing the first matrix
    std::cout << "Matrix 1:\n";
    for (size_t i = 0; i < mat1.numRows(); ++i) {
        for (size_t j = 0; j < mat1.numCols(); ++j) {
            std::cout << mat1(i, j) << " ";
        }
        std::cout << "\n";
    }

    // printing the second matrix
    std::cout << "Matrix 2:\n";
    for (size_t i = 0; i < mat2.numRows(); ++i) {
        for (size_t j = 0; j < mat2.numCols(); ++j) {
            std::cout << mat2(i, j) << " ";
        }
        std::cout << "\n";
    }

    // adding two matrices and printing the result
    auto mat3 = mat1 + mat1;
    std::cout << "Matrix 3 (Matrix 1 + Matrix 1):\n";
    for (size_t i = 0; i < mat3.numRows(); ++i) {
        for (size_t j = 0; j < mat3.numCols(); ++j) {
            std::cout << mat3(i, j) << " ";
        }
        std::cout << "\n";
    }

    // multiplying two matrices and printing the result
    auto mat4 = mat1 * mat2;
    std::cout << "Matrix 4 (Matrix 1 * Matrix 2):\n";
    for (size_t i = 0; i < mat4.numRows(); ++i) {
        for (size_t j = 0; j < mat4.numCols(); ++j) {
            std::cout << mat4(i, j) << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
