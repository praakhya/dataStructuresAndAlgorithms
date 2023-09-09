#include <iostream>
#include <vector>
class Fibonacci_bottomUp {          //(Tabulation)
    private:
    std::vector<int> F;             // This vector is used to tabulate the results
    int n;
    public:
    Fibonacci_bottomUp(int n) {
        F.resize(n, 0);             // Make a vector of size 'n' to hold 'n' numbers of the fib sequence.
        this->n = n;
        F[1] = 1;                   // Set the default fib value for the 1st index, which is 1.
        for (int i=2; i<n; ++i) {
            F[i] = F[i-1] + F[i-2]; // Calculating the fibonacci values for indices from 2 to n based on previous fibonacci terms.
        }
    }
    std::vector<int> getSequence() {
        return F;
    }
    int getNthTerm() {
        return F[n-1];
    }
};

class Fibonacci_recursive {           // (Plain Recursion)
    private:
    std::vector<int> F;
    int n;
    int i;
    public:
    Fibonacci_recursive(int n) {
        F.resize(n, 0);             // Make a vector of size 'n' to hold 'n' numbers of the fib sequence.
        this->n = n;
        calculateSequence(n);
    }
    std::vector<int> getSequence() {
        return F;
    }
    int getNthTerm() {
        return F[n-1];
    }
    private:
    int calculateSequence(int n) {
        if (n==1 || n==0) {
            std::cout << n << "\n";
            return n;
        }
        F[n] = calculateSequence(n-1)+calculateSequence(n-2);
        std::cout << F[n] << " ";
        return F[n];
    }
};

int fibonacci(int n) {
    // Fibonacci_bottomUp* f = new Fibonacci_bottomUp(n);
    Fibonacci_recursive* f = new Fibonacci_recursive(n);
    return f->getNthTerm();
}
std::vector<int> fibSequence(int n) {
    // Fibonacci_bottomUp* f = new Fibonacci_bottomUp(n);
    Fibonacci_recursive* f = new Fibonacci_recursive(n);
    return f->getSequence();
}
void displayVect(std::vector<int> v) {
    for (int i=0; i<v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    displayVect(fibSequence(n));
    std::cout << "nth term: " << fibonacci(n);
    return 0;
}