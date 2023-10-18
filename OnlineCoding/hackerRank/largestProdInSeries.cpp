#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int greatestProduct(string N, int K)
{
    cout << "   string: " << N << endl;
    if (N.length() == 1)
    {
        cout << "       single character" << endl;
        return N[0] - '0';
    }
    else if (N.length() == K)
    {
        cout << "       string length matches K: ";
        int prod = 1;
        for (int i = 0; i < K; ++i)
        {
            prod *= (N[i] - '0');
        }
        cout << prod << endl;
        return prod;
    }
    else
    {
        int breakPoint = 0;
        int maxVal = 0;
        while (breakPoint < N.length() - K)
        {
            cout << "       breakpoint: " << breakPoint << endl;
            int currentMax = max(greatestProduct(N.substr(0, breakPoint), K), greatestProduct(N.substr(breakPoint, N.length()), K));
            cout << "       current max: " << currentMax << endl;
            if (currentMax > maxVal)
            {
                maxVal = currentMax;
            }
            cout << "       max: " << maxVal << endl;
        }
        return maxVal;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++)
    {
        int t;
        cin >> t;
        for (int a0 = 0; a0 < t; a0++)
        {
            int n;
            int k;
            cin >> n >> k;
            string num;
            cin >> num;
            printf("n: %d, k:%d, num: %s\n",n,k,num.c_str());
            cout << greatestProduct(num, k) << endl;
        }
        return 0;
    }
}