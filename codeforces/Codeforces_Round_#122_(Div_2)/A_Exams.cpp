#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
 
 
int main()
{
    int N,k;
    cin>>N>>k;
    int c;
    for(c=0;c<N;c++)
    {
        int k2=k-2*c;
        if(3*(N-c)<=k2&&5*(N-c)>=k2)
            break;
    }
    cout<<c<<endl;
}