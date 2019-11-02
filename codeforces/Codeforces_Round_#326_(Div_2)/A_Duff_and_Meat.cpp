#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
 
 
 
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> p(n);
    for(int c=0;c<n;c++)
    {
        cin>>a[c]>>p[c];
    }
    int mini = 10000000;
    int res = 0;
    for(int c=0;c<n;c++)
    {
        mini = min(mini, p[c]);
        res+= mini*a[c];
    }
    cout<<res;
    return 0;
}