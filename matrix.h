#pragma once
using namespace std;

class Matrix {
public:
    Matrix() {
        num_rows_ = 0;
        num_columns_ = 0;
    }

    Matrix(int num_rows, int num_columns) {
        num_rows_ = num_rows;
        num_columns_ = num_columns;
        Reset(num_rows, num_columns);
    }

    void Reset(int num_rows, int num_columns) {
        num_rows_ = num_rows;
        num_columns_ = num_columns;
        elements_.assign(num_rows, vector<char>(num_columns));
    }

    char At(int row, int column) const {
        return elements_.at(row).at(column);
    }

    char& At(int row, int column) {
        return elements_.at(row).at(column);
    }

    int GetNumRows() const {
        return num_rows_;
    }

    int GetNumColumns() const {
        return num_columns_;
    }

private:
    int num_rows_;
    int num_columns_;

    vector<vector<char>> elements_;


};