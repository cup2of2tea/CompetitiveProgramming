#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    vector <int> di;
    int n;
    cin>>n;
    di.resize(n);
    for(int c=0;c<n-1;c++)
        cin>>di[c];
    int a,b;
    cin>>a>>b;
    int total=0;
    for(int c2=a-1;c2<b-1;c2++)
        total+=di[c2];
    cout<<total;
}