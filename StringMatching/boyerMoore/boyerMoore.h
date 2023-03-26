#ifndef __BOYERMOORE_H__
#define __BOYERMOORE_H__
#include <string>
class BoyerMoore {
    public:
    BoyerMoore(const std::string &text);
    ~BoyerMoore();
    int match(const std::string &pattern);
    private:
    int *createBadSymbTable(const std::string &pattern);
    int *createGoodSuffTable(const std::string &pattern);
    void dispTable(int* table);
    std::string text;
    struct suffixEntry
    {
        int k;
        int d;

    };
};
#endif