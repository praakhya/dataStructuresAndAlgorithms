#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool judgeCircle(char *moves)
{
    int x = 0, y = 0, i = 0;
    while (i < strlen(moves))
    {
        switch (moves[i])
        {
        case ('U'):
        {
            --y;
            break;
        }
        case ('D'):
        {
            ++y;
            break;
        }
        case ('L'):
        {
            --x;
            break;
        }
        case ('R'):
        {
            ++x;
            break;
        }
        }
        ++i;
    }
    if (x == 0 && y == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char arr[1000] = {};
    bool result;
    scanf("%s", arr);
    result = judgeCircle(arr);
    (result == 0) ? printf("false") : printf("true");
    return 0;
}