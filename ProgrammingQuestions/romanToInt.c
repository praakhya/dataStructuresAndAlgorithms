#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum roman{
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000
};
int romanVal(char c)
{
    switch (c)
    {
        case ('I'): 
        {
            return I;
            break;
        }
        case ('V'): 
        {
            return V;
            break;
        }
        case ('X'): 
        {
            return X;
            break;
        }
        case ('L'): 
        {
            return L;
            break;
        }
        case ('C'): 
        {
            return C;
            break;
        }
        case ('D'): 
        {
            return D;
            break;
        }
        case ('M'): 
        {
            return M;
            break;
        }
    }
    return 0;
}
int roman_to_intOld (char *s)
{
    int int_num=0;
    char* copys = "";
    strcpy(copys,s);
    char prev_dig = *copys;
    ++copys;
    while (*copys!='\0')
    {
        char dig=*copys;
        int romanPrevDig = romanVal(prev_dig);
        int romanDig = romanVal(dig);
        if (romanPrevDig<romanDig)
        {
            int_num+=romanDig-romanPrevDig;
        }
        ++copys;
    }
    return int_num;
}
int roman_to_int(char *s)
{
    int int_num=0;
    int lastI = strlen(s)-1; 
    int prev_dig=0;
    while (lastI>=0)
    {
        int romanValI = romanVal(s[lastI]);
        if (romanValI>=prev_dig) 
        {
            int_num+=romanValI;
        }
        else
        {
            int_num-=romanValI;
        }
        prev_dig = romanValI;
        --lastI;
    }
    return int_num;
}
int main(void)
 {
  char str1[20];
  scanf("%[^\n]%*c", str1);
  printf("%d", roman_to_int(str1));
  return 0;
}