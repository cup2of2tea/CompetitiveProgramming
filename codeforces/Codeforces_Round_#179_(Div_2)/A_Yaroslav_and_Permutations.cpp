#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    vector<int > count(1001,0);
    int n;
    cin>>n;
    for(int c=0;c<n;c++)
    {
        int z;
        cin>>z;
        count[z]++;
    }
    sort(count.rbegin(),count.rend());
    if(count[0]>(n+1)/2)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES";
    }
}