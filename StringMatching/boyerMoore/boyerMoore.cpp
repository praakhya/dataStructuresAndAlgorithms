#include <iostream>
#include <string>
#include "boyerMoore.h"
#include <algorithm>
BoyerMoore::BoyerMoore(const std::string &text)
{
    this->text = text;
}
BoyerMoore::~BoyerMoore() {
    std::cout << "Destroying BoyerMoore" << std::endl;
}
int BoyerMoore::match(const std::string &pattern)
{
    
}
int *BoyerMoore::createBadSymbTable(const std::string &pattern)
{
    int *table = new int[256];                      //Creating a table of 256 characters (ASCII characters) where each index is the ASCII number of a character
    std::fill_n(table, 256, pattern.length());           //Setting all numbers of the table as length og the pattern (it is the default shift value for characters that are not present in the pattern)
    int i=0;
    for (int i=0; i<pattern.length()-1; ++i)        //Looping through the pattern to set the shift values for those characters that are present in the pattern.
    {
        table[pattern[i] - 0] = table[pattern[i]] - i -1;   //Current shift value for that char. - index of character in pattern - 1 (the distance of the character from the right)
    }
    return table;
}
int *BoyerMoore::createGoodSuffTable(const std::string &pattern)
{
    suffixEntry *table[pattern.length()];                      //Creating a table of 256 characters (ASCII characters) where each index is the ASCII number of a character
    std::fill_n(table, 256, pattern.length());           //Setting all numbers of the table as length og the pattern (it is the default shift value for characters that are not present in the pattern)
    int m=pattern.length();
    std::string suffix = new char[m];
    for (int k=1; k<m; ++k)
    {
        for (int i=0; i<k; ++i)
        {
            suffix[i] = pattern[m-k-i];
        }
    }
    
}
