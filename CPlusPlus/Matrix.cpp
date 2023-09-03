#include <iostream>
#include <vector>

class Matrix {
    private: std::vector<std::vector<int> > table;
    public:
    int rowCt;
    int colCt;
    Matrix(int row, int col) {
        rowCt=row;
        colCt=col;
        std::vector<int> tempRow(col,0);
        std::vector<std::vector<int> > table(row,tempRow);
    }
    void display() {
        std::cout << "[ " << std::endl;
        for (int i=0; i<this->rowCt; ++i) {
            displayRow(i);
            std::cout << "," <<std::endl;
        }
        std::cout << "] " << std::endl;

    }
    void displayRow(int rowNum) {
        std::cout << "[ ";
        for (int i=0; i<this->colCt; ++i) {
            std::cout << this->table[rowNum][i] << " ";
        }
        std::cout << "]";
    }
    std::vector<int> getRow(int rowNum) {
        return this->table[rowNum];
    }
    std::vector<int> getCol(int colNum) {
        std::vector<int> colVec(colCt);
        for (int i=0; i<this->rowCt; ++i) {
            colVec.push_back(this->table[i][colNum]);
        }
        return colVec;
    }
    std::vector<std::vector <int> > getMatrix() {
        return this->table;
    }
    void add(int val, int row, int col) {
        this->table[row][col] = val;
    }
    void remove(int row, int col) {
        this->table[row][col] = 0;
    }
    int getValue(int row, int col) {
        return this->table[row][col];
    }
};
