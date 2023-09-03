#include <iostream>
#include "Matrix.cpp"

int main() {
    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of cols: ";
    std::cin >> cols;
    int val, row, col;
    char ch;
    Matrix m = Matrix(row,col);
    std::cout << "1. Add value\n2. Remove value\n3. Display Matrix\n4. Display Row\n5. Get row\n6. Get column\n7. Get Matrix\nq. Quit\n";
    std::cin >> ch;
    
    while (ch!='q') {
        switch(ch) {
            case ('1'): {
                std::cout << "Enter value: ";
                std::cin >> val;
                std::cout << "Enter row: ";
                std::cin >> row;
                std::cout << "Enter col: ";
                std::cin >> col;
                m.add(val,row,col);
                break;
            }
            case ('2'): {
                std::cout << "Enter row: ";
                std::cin >> row;
                std::cout << "Enter col: ";
                std::cin >> col;
                m.remove(row,col);
                break;
            }
            case ('3'): {
                m.display();
                break;
            }
            case ('4'): {
                std::cout << "Enter row: ";
                std::cin >> row;
                m.displayRow(row);
                break;
            }
            case ('5'): {
                break;
            }
            case ('6'): {
                break;
            }
            case ('7'): {
                break;
            }
            case ('q'): {
                std::cout << "Thank you.\n";
                break;
                break;
            }
            default: {
                std::cout << "Invalid\n";
                break;
            }
        }
        std::cout << "1. Add value\n2. Remove value\n3. Display Matrix\n4. Display Row\n5. Get row\n6. Get column\n7. Get Matrix\nq. Quit\n";
        std::cin >> ch;
    }
    return 0;
}