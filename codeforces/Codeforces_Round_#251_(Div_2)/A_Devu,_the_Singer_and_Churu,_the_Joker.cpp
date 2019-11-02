#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int n,d;
    cin>>n>>d;
    vector<int> v(n);
    int tot = 0;
    for(int c=0;c<n;c++)
    {
        cin>>v[c];
        tot+=v[c];
    }
    int count2 = (n-1)*2 ;
    tot+=count2*5;
    if(tot > d)
    {
        cout<<-1;
        return 0;
    }
    cout<<count2+(d-tot)/5;
}