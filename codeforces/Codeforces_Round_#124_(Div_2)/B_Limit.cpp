#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
 
 
int abs(int n)
{
    return n<0?-n:n;
}
 
int pgcd (int a,int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    return pgcd(b,a%b);
}
 
 
int main()
{
    int n,m;
    cin>>n>>m;
    n++;
    m++;
    vector<int> a(n);
    vector<int> b(m);
    for(int c=0;c<n;c++)
        cin>>a[c];
    for(int c=0;c<m;c++)
        cin>>b[c];
    if(n!=m)
    {
        if(n>m)
        {
            if((a[0]>0&&b[0]>0)||(a[0]<0&&b[0]<0))
            {
                cout<<"Infinity";
                return 0;
            }
            else
            {
                cout<<"-Infinity";
                return 0;
            }
        }
        else
        {
            cout<<"0/1";
            return 0;
        }
    }
    else
    {
        if((a[0]<0&&b[0]>0)||(a[0]>0&&b[0]<0))
            cout<<"-";
        cout<<abs(a[0])/pgcd(abs(a[0]),abs(b[0]))<<"/"<<abs(b[0])/pgcd(abs(a[0]),abs(b[0]));
        return 0;
    }
}