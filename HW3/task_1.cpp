#include <string>
#include <iostream>
#include <cmath>

template <typename ValueType, size_t Rows, size_t Columns>
class Matrix {
public:
    // Constructor:
    Matrix() : data(new ValueType* [Rows]) {
        for (size_t i = 0; i < Rows; ++i)
            data[i] = new ValueType[Columns];

        for (size_t i = 0; i < Rows; i++)
            for (size_t j = 0; j < Columns; j++)
                data[i][j] = 0;
    }

    Matrix(const ValueType& num) : data(new ValueType* [Rows]) {
        for (size_t i = 0; i < Rows; ++i)
            data[i] = new ValueType[Columns];

        for (size_t i = 0; i < Rows; i++)
            for (size_t j = 0; j < Columns; j++)
                data[i][j] = num;
    }

    Matrix(const Matrix& other) : data(new ValueType* [Rows]) {
        for (size_t i = 0; i < Rows; ++i)
            data[i] = new ValueType[Columns];

        for (size_t i = 0; i < Rows; i++)
            for (size_t j = 0; j < Columns; j++)
                data[i][j] = other.data[i][j];
    }

    // Getters:
    int getRowCount() {
        return Rows;
    }

    int getColumnCount() {
        return Columns;
    }

    // Operator ():
    ValueType& operator()(const size_t& i, const size_t& j) {
        return data[i][j];
    }

    const ValueType& operator()(const size_t& i, const size_t& j) const {
        return data[i][j];
    }

    Matrix& operator= (const Matrix& other) {
        for (size_t i = 0; i < Rows; i++)
            for (size_t j = 0; j < Columns; j++)
                data[i][j] = other.data[i][j];
        return *this;
    }

    // Operator + 
    Matrix& operator+= (const Matrix& other) {
        for (size_t i = 0; i < Rows; i++)
            for (size_t j = 0; j < Columns; j++)
                data[i][j] += other.data[i][j];
        return *this;
    }

    Matrix operator+ (const Matrix& other) {
        Matrix<ValueType, Rows, Columns> result(0);
        for (size_t i = 0; i < Rows; i++)
            for (size_t j = 0; j < Columns; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // Operator -
    Matrix& operator-= (const Matrix& other) {
        for (size_t i = 0; i < Rows; i++)
            for (size_t j = 0; j < Columns; j++)
                data[i][j] -= other.data[i][j];
        return *this;
    }

    Matrix operator- (const Matrix& other) {
        Matrix<ValueType, Rows, Columns> result(0);
        for (size_t i = 0; i < Rows; i++)
            for (size_t j = 0; j < Columns; j++)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    // Operator * (for scalar k)
    Matrix& operator*= (const ValueType& num) {
        for (size_t i = 0; i < Rows; i++)
            for (size_t j = 0; j < Columns; j++)
                data[i][j] *= num;
        return *this;
    }

    Matrix operator* (const ValueType& num) {
        return Matrix(*this) *= num;
    }

    // Operator * (for two matrix)
    template <size_t OtherColumns>
    Matrix<ValueType, Rows, OtherColumns> operator* (const Matrix<ValueType, Columns, OtherColumns>& second) const {
        Matrix<ValueType, Rows, OtherColumns> result(0);
        if (Columns == second.getRowCount()) {
            for (size_t i = 0; i < Rows; i++)
                for (size_t j = 0; j < OtherColumns; j++)
                    for (size_t k = 0; k < Columns; k++)
                        result.data[i][j] += data[i][k] * second.data[k][j];
        }
        return result;
    }

    // Getters (marked as const):
    int getRowCount() const {
        return Rows;
    }

    int getColumnCount() const {
        return Columns;
    }

    // Operator compare:
    bool operator== (const Matrix& other) {
        for (size_t i = 0; i < Rows; i++)
            for (size_t j = 0; j < Columns; j++)
                if (data[i][j] != other.data[i][j])
                    return false;
        return true;
    }

    bool operator== (const Matrix& other) const {
        for (size_t i = 0; i < Rows; i++)
            for (size_t j = 0; j < Columns; j++)
                if (data[i][j] != other.data[i][j])
                    return false;
        return true;
    }

    // Transposed matrix function: 
    Matrix<ValueType, Columns, Rows> transposed() const {
        Matrix<ValueType, Columns, Rows> trp;
        for (int i = 0; i < Rows; ++i)
            for (int j = 0; j < Columns; ++j)
                trp.data[j][i] = data[i][j];
        return trp;
    }

    // Function print:
    void print() {
        for (size_t i = 0; i < Rows; i++) {
            for (size_t j = 0; j < Columns; j++) {
                std::cout << data[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    }

    // Destructor:
    ~Matrix() {
        for (size_t i = 0; i < Rows; i++)
            delete[] data[i];
        delete[] data;
    }

    // Create two dimensional array:
    ValueType** data = new ValueType * [Rows];

private:
    int row, col;
};

// Specialization for matrix (n,1)
template<typename ValueType, size_t N>
class Matrix<ValueType, 1, N> {
public:
    // Constructor: 
    Matrix() : data1(new ValueType* [1]) {
        for (size_t i = 0; i < 1; ++i)
            data1[i] = new ValueType[N];

        for (size_t i = 0; i < 1; i++)
            for (size_t j = 0; j < N; j++)
                data1[i][j] = 0;
    }

    Matrix(const ValueType& num) : data1(new ValueType* [1]) {
        for (size_t i = 0; i < 1; ++i)
            data1[i] = new ValueType[N];

        for (size_t i = 0; i < 1; i++)
            for (size_t j = 0; j < N; j++)
                data1[i][j] = num;;
    }

    Matrix(const Matrix& other) : data1(new ValueType* [1]) {
        for (size_t i = 0; i < 1; ++i)
            data1[i] = new ValueType[N];

        for (size_t i = 0; i < 1; i++)
            for (size_t j = 0; j < N; j++)
                data1[i][j] = other.data1[i][j];
    }

    // Operator: 
    ValueType& operator() (const size_t &i, const size_t &j) {
        return data1[i][j];
    }

    Matrix& operator= (const Matrix& other) {
        for (int i = 0; i < N; i++)
            data1[0][i] = other.data1[0][i];
        return *this;
    }

    Matrix operator+ (const Matrix& other) {
        Matrix<ValueType, 1, N> res(0);
        for (size_t i = 0; i < N; i++) {
            res.data1[0][i] = data1[0][i] + other.data1[0][i];
        }
        return res;
    }

    Matrix operator- (const Matrix& other) {
        Matrix<ValueType, 1, N> res(0);
        for (size_t i = 0; i < N; i++) {
            res.data1[0][i] = data1[0][i] - other.data1[0][i];
        }
        return res;
    }

    Matrix operator* (const ValueType& k) {
        Matrix<ValueType, 1, N> res(0);
        for (size_t i = 0; i < N; i++) {
            res.data1[0][i] = data1[0][i] * k;
        }
        return res;
    }

    // Fuction to calculate L2 Norm: 
    ValueType Norm() {
        ValueType result = 0;
        for (size_t i = 0; i < N; i++) {
            result += pow(data1[0][i], 2);
        }
        return result;
    }

    // Print Function:
    void print() {
        for (size_t i = 0; i < 1; i++) {
            for (size_t j = 0; j < N; j++) {
                std::cout << data1[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    }

    // Destructor: 
    ~Matrix() {
        for (size_t i = 0; i < 1; i++)
            delete[] data1[i];
        delete[] data1;
    }
    ValueType** data1 = new ValueType * [N];
};

int main() {
    // General case:
    int inputValue;
    Matrix<int, 2, 3> matrix1;
    std::cout << "Input of matrix 1" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> inputValue;
            matrix1(i, j) = inputValue;
        }
    }

    std::cout << "Input of matrix 2" << std::endl;
    Matrix<int, 3, 2> matrix2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            std::cin >> inputValue;
            matrix2(i, j) = inputValue;
        }
    }

    std::cout << "Matrix 1 is: " << std::endl;
    matrix1.print();

    std::cout << "Matrix 2 is: " << std::endl;
    matrix2.print();

    Matrix<int, 2, 2> matrix3 = matrix1 * matrix2;
    std::cout << "Matrix 1 x Matrix 2 is: " << std::endl;
    matrix3.print();

    std::cout << "Transpose matrix 1 x matrix 2 is: " << std::endl;
    Matrix<int, 2, 2> transposedMatrix = matrix3.transposed();
    transposedMatrix.print();

    // Specialization case: 
    Matrix<int, 1, 3> matrixX;
    Matrix<int, 1, 3> matrixY;
    int inputValueY;
    std::cout << "Input matrix X: " << std::endl;
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> inputValueY;
            matrixX(i, j) = inputValueY;
        }
    }

    std::cout << "Input matrix Y: " << std::endl;
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> inputValueY;
            matrixY(i, j) = inputValueY;
        }
    }

    Matrix<int, 1, 3> matrixZ = matrixX + matrixY;
    std::cout << "The matrix (X + Y) is: " << std::endl;
    matrixZ.print();
    std::cout << "L2 Norm is equal: " << std::endl;
    std::cout << matrixZ.Norm();

    return 0;
}
