#include <iostream>
#include <vector>

class Matrix {
public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<int>(cols, 0));
    }

    void inputMatrix() {
        std::cout << "Enter matrix data:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Enter element at position (" << i + 1 << "," << j + 1 << "): ";
                std::cin >> data[i][j];
            }
        }
    }

    Matrix operator+(const Matrix& other) const {
        log("Adding matrices");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        log("Subtracting matrices");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        log("Multiplying matrices");
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix operator/(const Matrix& other) const {
        log("Dividing matrices");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (other.data[i][j] != 0) {
                    result.data[i][j] = data[i][j] / other.data[i][j];
                } else {
                    log("Error: Division by zero");
                }
            }
        }
        return result;
    }

    void log(const std::string& message) const {
        std::cout << "Log: " << message << std::endl;
    }

    void printMatrix() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    int rows;
    int cols;
    std::vector<std::vector<int> > data;
};

int main() {
    int rows, cols;

    std::cout << "Enter the number of rows for matrices: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns for matrices: ";
    std::cin >> cols;

    Matrix matrix1(rows, cols);
    Matrix matrix2(rows, cols);

    matrix1.inputMatrix();
    matrix2.inputMatrix();

    Matrix sum = matrix1 + matrix2;
    Matrix difference = matrix1 - matrix2;
    Matrix product = matrix1 * matrix2;
    Matrix quotient = matrix1 / matrix2;

    std::cout << "Sum of matrices:" << std::endl;
    sum.printMatrix();

    std::cout << "Difference of matrices:" << std::endl;
    difference.printMatrix();

    std::cout << "Product of matrices:" << std::endl;
    product.printMatrix();

    std::cout << "Quotient of matrices:" << std::endl;
    quotient.printMatrix();

    return 0;
}

