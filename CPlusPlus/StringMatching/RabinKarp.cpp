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
    }
    int plainMatch(std::string text, std::string pattern,int start,int size) {
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
        int n=T.size(), m=P.size(), h=(int) pow(base,m-1)%q, d=base, s;
        int p = horner(P,m); //numeric value of pattern
        int ts = horner(T.substr(0, m),m);
        for (s=0; s<n-m; ++s) {
                std::cout << "p: " <<p << ", ts: "<<ts<<std::endl;
                std::cout << "P: " <<P << ", T[s:s+m]: "<<T.substr(s,m)<<std::endl;
            if (p==ts) {
                if (plainMatch(T,P,s+1,m)) {
                return s;
                }
            }
            if(s<n-m){
                ts = nextTs(ts,s,m);
                
            }
        }
        if (p==ts) {
            return s;
        }
        return -1;
    }
    int horner(std::string P, int m) {
        int p=0;
        for (int i=0; i<m; ++i) {
            p = (base*p + P[i])%q;
            
        }
        return p%q;
    }
    
    private:
    int negativeModulus(int a, int b) {
        return (a%b + b)%b;
    }
    int nextTs(int ts, int s, int m) {
        int h = (int) pow(base,m-1)%q;
        int tsP1 = (base*(ts - (int) h*T[s+1]) + T[s+m+1]);
        int modVal = negativeModulus(tsP1,q);
        return modVal;
    }
    int recursiveProduct(std::string P, int m) {
        if (m==0) {
            return P[m];
        }
        int val=P[m] + 10*recursiveProduct(P,m-1);
        return val%q;
    }
};
int negativeModulus(int a, int b) {
    return (a%b + b)%b;
}
int main() {
    RabinKarp* rk = new RabinKarp("2359023141526739921",13,255);
    int found = rk->match("31");
    std::cout << found << std::endl;
    return 0;
}