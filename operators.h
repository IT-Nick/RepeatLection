#pragma once
#include "matrix.h"

using namespace std;
istream& operator >>(istream& in, Matrix& m) {
    int num_rows, num_column;

    in >> num_rows >> num_column;
    m.Reset(num_rows, num_column);
    for(int row = 0; row < num_rows; row++) {
        for(int column = 0; column < num_column; column++) {
            in >> m.At(row, column);
        }
    }
    return in;
}

ostream& operator <<(ostream& out, const Matrix& m) {
    out << m.GetNumRows() << " " << m.GetNumColumns() << endl;
    for(int row = 0; row < m.GetNumRows(); row++) {
        for(int column = 0; column < m.GetNumColumns(); column++) {
            out << m.At(row, column) << " ";
        }
        out << endl;
    }

    return out;
}