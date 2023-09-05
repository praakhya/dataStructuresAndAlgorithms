#include <iostream>
#include <vector>
class Stack {
    private:
    int top=-1;
    std::vector<int> arr;
    public:
    void push(int val) {
        arr.push_back(val);
        ++top;
    }
    void pop() {
        arr.pop_back();
        --top;
    }
    int peek() {
        return this->arr[this->top];
    }
};

class Stack_Main
{
    void run()
    {
        Stack stack = Stack();
        char ch;
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