#include <iostream>
#include <string>
#include <math.h>

class RabinKarp {
    private:
    std::string T;
    int base, q;
    public:
    RabinKarp(std::string T, int q, int base) {
        this->T=T;
        this->q=q;
        this->base=base;
        std::cout << "Constructed RK\n";
    }
    int plainMatch(std::string text, std::string pattern,int start,int size) {
        std::cout << "in plain match: " << text << "," << pattern <<std::endl;
        int textI=start;
        for (int i=0; i<size; ++i) {
            if (text[textI]!=pattern[i]) {
                return 0;
            }
            ++textI;
        }
        return 1;
    }
    int match(std::string P) {
        std::cout << "in match\n";
        int n=T.size(), m=P.size(), h=(int) pow(base,m-1)%q, d=base, s;
        int p = horner(P,m); //numeric value of pattern
        int ts = horner(T.substr(0, m),m);
        std::cout << "p: " <<p << ", ts: "<<ts<<std::endl;
        for (s=0; s<n-m; ++s) {
                std::cout << "p: " <<p << ", ts: "<<ts<<std::endl;
                std::cout << "P: " <<P << ", T[s:s+m]: "<<T.substr(s,s+m)<<std::endl;
            if (p==ts) {
                std::cout<<"numbers equal\n";
                if (plainMatch(T,P,s+1,m)) {
                return s;
                }
            }
            if(s<n-m){
                ts = nextTs(ts,s,m);
            }
        }
        if (p==ts) {
            std::cout<<"numbers equal\n";
            return s;
        }
        return -1;
    }
    int horner(std::string pattern, int m) {
        std::cout << "in horner: "<<pattern<<std::endl;
        int p=(int) pattern[m-1];
        p+=recursiveProduct(pattern,m);
        return p%q;
    }
    
    private:
    int nextTs(int ts, int s, int m) {
        std::cout << "in nextTs\n";
        return (base*(ts - (int) pow(base,m-1)*T[s+1]) + T[s+m+1])%q;
    }
    int recursiveProduct(std::string P, int m) {
        std::cout << "in rec product\n";
        if (m==0 || m==1) {
            return (int) P[m];
        }
        return base*((int) P[m-2] + base*(recursiveProduct(P,m-3)));
    }
};

int main() {
    RabinKarp* rk = new RabinKarp("here is an example",13,26);
    int found = rk->match("example");
    std::cout << found << std::endl;
    return 0;
}