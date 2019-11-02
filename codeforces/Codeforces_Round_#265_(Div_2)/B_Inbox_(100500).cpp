#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <ctime>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
 
int main()
{
ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n;
    cin>>n;
    vector<int> letters(n);
    for(int c=0;c<n;c++) cin>>letters[c];
    int prec = -42;
    int res = 0;
    for(int c=0;c<n;c++)
    {
        if(letters[c]==1)
        {
            if(prec == c-1 || prec == -42)
            {
                res++;
            }
            else res+=2;
            prec = c;
        }
    }
    cout<<res;
}