#include <iostream>
#include "horspool.h"
int main()
{
    Horspool hp("The quick brown fox jumped over the lazy dog.");
    std::cout << "The index at which pattern was found: " << hp.match("quick") << std::endl;
    std::cout << "The index at which pattern was found: " << hp.match("x k") << std::endl;
    std::cout << "The index at which pattern was found: " << hp.match("lazy") << std::endl;
}