#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
 
int main()
{
    int n;
    cin>>n;
    int i=0;
    for(int c=0;c<n;c++)
    {
        for(int c2=0;c2<n/2;c2++)
        {
            cout<<i+1<<" "<<n*n-i<<" ";
            i++;
        }
        cout<<endl;
    }
}