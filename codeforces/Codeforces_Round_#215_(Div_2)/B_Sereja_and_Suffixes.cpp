#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<bool> visites(1000000,false);
    vector<int> v(n);
    for(int c=0;c<n;c++)
        cin>>v[c];
    vector<int> count(n);
    int act = 0;
    for(int c=n-1;c>=0;c--)
    {
        if(!visites[v[c]]) act++;
        visites[v[c]]=true;
        count[c]=act;
    }
    for(int c=0;c<m;c++)
    {
        int a;
        cin>>a;
        a--;
        cout<<count[a]<<endl;
    }
}