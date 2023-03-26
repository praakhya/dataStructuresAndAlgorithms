#ifndef __HORSPOOL_H__
#define __HORSPOOL_H__
#include <string>
class Horspool {
    public:
    Horspool(const std::string &text);
    ~Horspool();
    int match(const std::string &pattern);
    private:
    int* createShiftTable(const std::string &pattern);
    void dispTable(int* table);
    std::string text;
};
#endif
