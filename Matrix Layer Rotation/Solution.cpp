#include <iostream>
using std::cin; using std::cout; using std::endl;

// Stores a 2D array in a linear array. Stores columns in consecutive order and uses
// x + m_height * y to return indexes as if the linear array was a 2D array.
class Matrix {
    long long *array;
    int m_height;

public:
    Matrix( int h, int w ) : m_height( h ), array( new long long[ w * h ] ) {}

    ~Matrix() { delete[] array; }

    long long at( int x, int y ) const {
        return array[ index( x, y ) ];
    }

    void set(int x, int y, long long number) {
        array[ index( x, y) ] = number;
    }

protected:
    int index( int x, int y ) const {
        return x + m_height * y;
    }
};

void rotate_matrix(Matrix &, int, int, int, int);

int main() {

    int rows, columns, min_rotations, layers;
    long long rotations, number;

    cin >> rows >> columns >> rotations;

    layers = std::min(rows/2, columns/2);
    Matrix matrix(rows, columns);

    // Fills matrix with values
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j) {
            cin >> number;
            matrix.set(i,j,number);
        }
    }

    // Performs proper number of matrix rotations. Modulus is used to determine
    // if the requested number of rotations will result in a full rotation, if so
    // then only the remainder rotations are carried out.
    for(int i = 0, cnt = 1; i < layers; ++i, cnt += 2) {
        min_rotations = rotations % (2*(rows-cnt) + 2*(columns-cnt));
        for(int j = 0; j < rotations; ++j) {
            rotate_matrix(matrix, rows, columns, i, i);
        }
    }

    // Prints matrix
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j) {
            cout << matrix.at(i,j) << ' ';
        }
        cout << endl;
    }
}

void rotate_matrix(Matrix &matrix, int rows, int columns, int row_index, int column_index) {
    long long temp;
    --rows, --columns;

    // Iterate through the top of a layer
    for (int top = column_index; top < columns - column_index; ++top) {
        temp = matrix.at(row_index, top);
        matrix.set(row_index, top, matrix.at(row_index, top + 1));
        matrix.set(row_index, top + 1, temp);
    }
    // Iterate through the right side of a layer
    for (int right = row_index; right < rows - row_index; ++right) {
        temp = matrix.at(right, columns - column_index);
        matrix.set(right, columns - column_index, matrix.at(right + 1, columns - column_index));
        matrix.set(right + 1, columns - column_index, temp);
    }
    // Iterate through the bottom of a layer
    for (int bottom = columns - column_index; bottom > column_index; --bottom) {
        temp = matrix.at(rows - row_index, bottom);
        matrix.set(rows - row_index, bottom, matrix.at(rows - row_index, bottom - 1));
        matrix.set(rows - row_index, bottom - 1, temp);
    }
    // Iterate through the left side of a layer
    for (int left = rows - row_index; left > row_index + 1; --left) {
        temp = matrix.at(left, column_index);
        matrix.set(left, column_index, matrix.at(left - 1, column_index));
        matrix.set(left - 1, column_index, temp);
    }
}
