#include <iostream>
#include <string>
#include "horspool.h"
#include <algorithm>
Horspool::Horspool(const std::string &text)
{
    this->text = text; //The text to which the pattern has to be matched
}
Horspool::~Horspool() {
    std::cout << "Destroying Horspool" << std::endl;    //Destroying the class object
}
int Horspool::match(const std::string &pattern)
{
    int *table = createShiftTable(pattern);         //Creating shift table
    int m = pattern.length(), n=text.length();      //Setting a variable m & n to depict pattern and text size respectively.
    int i=m-1;
    while (i<n)                       //Looping through the text starting from length of pattern
    {
        int k=0;                                    //Setting k, the looping variable for the pattern
        while (k<m && pattern[m-1-k]==text[i-k])    //Running a loop while k is less than length of the pattern and the current pattern character matches current text character
        {
            ++k;                                    //incrementing k 
        }
        if (k==m)                                   //If after looping, the value of k reaches the length of the pattern, then, all characters of the pattern matched that of the text.
        {
            return i-m+1;                           //Returning index where pattern was found. (Index of text character - (last index of pattern))
        }
        else
        {
            i=i+table[text[i]];                     //Incrementing the text loop variable by the shift value of current text character
        }
        
    }
    delete[] table;                                 //Deleting the shift table
    return -1;                                      //If loop was exited, that means pattern did not match. so -1 was returned.
}
int *Horspool::createShiftTable(const std::string &pattern)
{
    int *table = new int[256];                      //Creating a table of 256 characters (ASCII characters) where each index is the ASCII number of a character
    std::fill_n(table, 256, pattern.length());           //Setting all numbers of the table as length of the pattern (it is the default shift value for characters that are not present in the pattern)
    int i=0;
    int zero = 0;   //Used to set ascii value of characters
    for (int i=0; i<pattern.length()-1; ++i)        //Looping through the pattern to set the shift values for those characters that are present in the pattern.
    {
        table[pattern[i] - zero] = table[pattern[i]] - i -1;   //Current shift value for that char. - index of character in pattern - 1 (the distance of the character from the right)
    }
    return table;
}
void Horspool::dispTable(int* table)                //Displaying the table for debugging purposes
    {

        for (int i=0; i<256; ++i)
        {
            std::cout << table[i] << " ";
            if (i+1%4==0)
            {
                std::cout << std::endl;
            }
        }
    }
