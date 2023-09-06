#include <iostream>
#include <string>
class KMP {
    private:
    int n, m, q;
    std::string T,P;
    std::vector<int> pi;
    std::vector<int> computePrefix(std::string P) {
        int m = P.size();
        std::vector<int> pi(m);
        pi[0] = -1;
        int k=-1;
        for (int q=1; q<m; ++q) {
            while (k>-1 and P[k+1]!=P[q]) {
                k=pi[k];
            }
            if (P[k+1]==P[q]) {
                k = k + 1;
            }
            pi[q] = k;
        }
        std::cout << "Finished prefix computing" <<std::endl;
        return pi;
    }
    public:
    KMP(std::string T, std::string P) {
        this->T = T;
        this->P = P;
        n = T.size();
        m = P.size();
        pi = computePrefix(P);
        q=-1;
    }
    void match() {
        for (int i=0; i<n; ++i) {
            printf("i = %d, q = %d, T[%d] (%d) == P[%d] (%d)\n",i,q,i,T[i],q+1,P[q+1]);
            while (q > -1 && P[q+1]!=T[i]) {
                q=pi[q];
            }
            if (P[q+1]==T[i]) {
                ++q;
            }
            if (q==m-1) {
                std::cout << "Pattern occurs with shift " << i-m <<std::endl;
                q=pi[q];
            }
        }
    }
};

int main() {
    KMP* kmp = new KMP("bacbababaabcbab","abaabc");
    kmp->match();
    return 0;
}
