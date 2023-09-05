#include <iostream>
#include <vector>

class Matrix
{
private:
    std::vector<std::vector<int> > table;

public:
    int rowCt;
    int colCt;
    Matrix(int row, int col)
    {
        rowCt = row;
        colCt = col;
        std::vector<int> tempRow(col, 0);
        std::vector<std::vector<int> > table(row, tempRow);
    }
    void display()
    {
        std::cout << "[ " << std::endl;
        for (int i = 0; i < this->rowCt; ++i)
        {
            displayRow(i);
            std::cout << "," << std::endl;
        }
        std::cout << "] " << std::endl;
    }
    void displayRow(int rowNum)
    {
        std::cout << "[ ";
        for (int i = 0; i < this->colCt; ++i)
        {
            std::cout << this->table[rowNum][i] << " ";
        }
        std::cout << "]";
    }
    std::vector<int> getRow(int rowNum)
    {
        return this->table[rowNum];
    }
    std::vector<int> getCol(int colNum)
    {
        std::vector<int> colVec(colCt);
        for (int i = 0; i < this->rowCt; ++i)
        {
            colVec.push_back(this->table[i][colNum]);
        }
        return colVec;
    }
    std::vector<std::vector<int> > getMatrix()
    {
        return this->table;
    }
    void add(int val, int row, int col)
    {
        this->table[row][col] = val;
    }
    void remove(int row, int col)
    {
        this->table[row][col] = 0;
    }
    int getValue(int row, int col)
    {
        return this->table[row][col];
    }
};

class Mat_Main
{
    public:
    void run()
    {
        int rows, cols;
        std::cout << "Enter number of rows: ";
        std::cin >> rows;
        std::cout << "Enter number of cols: ";
        std::cin >> cols;
        int val, row, col;
        char ch;
        Matrix m = Matrix(row, col);
        std::cout << "1. Add value\n2. Remove value\n3. Display Matrix\n4. Display Row\n5. Get row\n6. Get column\n7. Get Matrix\nq. Quit\n";
        std::cin >> ch;

        while (ch != 'q')
        {
            switch (ch)
            {
            case ('1'):
            {
                std::cout << "Enter value: ";
                std::cin >> val;
                std::cout << "Enter row: ";
                std::cin >> row;
                std::cout << "Enter col: ";
                std::cin >> col;
                m.add(val, row, col);
                break;
            }
            case ('2'):
            {
                std::cout << "Enter row: ";
                std::cin >> row;
                std::cout << "Enter col: ";
                std::cin >> col;
                m.remove(row, col);
                break;
            }
            case ('3'):
            {
                m.display();
                break;
            }
            case ('4'):
            {
                std::cout << "Enter row: ";
                std::cin >> row;
                m.displayRow(row);
                break;
            }
            case ('5'):
            {
                break;
            }
            case ('6'):
            {
                break;
            }
            case ('7'):
            {
                break;
            }
            case ('q'):
            {
                std::cout << "Thank you.\n";
                break;
                break;
            }
            default:
            {
                std::cout << "Invalid\n";
                break;
            }
            }
            std::cout << "1. Add value\n2. Remove value\n3. Display Matrix\n4. Display Row\n5. Get row\n6. Get column\n7. Get Matrix\nq. Quit\n";
            std::cin >> ch;
        }
    }
};