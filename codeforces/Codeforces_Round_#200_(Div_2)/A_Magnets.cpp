#include <iostream>
 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    string prec="";
    int res=0;
    for(int c=0;c<n;c++)
    {
        string s;
        cin>>s;
        if(s!=prec) res++;
        prec=s;
    }
    cout<<res;
}