#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    int N,M;
    cin>>N>>M;
    string s;
    cin>>s;
    int act = 0;
    for(int c=1;c<s.size();c++)
    {
        if(s[c]=='.' && s[c-1]=='.') act++;
    }
    for(int c=0;c<M;c++)
    {
        int i;
        string car;
        cin>>i>>car;
        i--;
        if(car=="." && s[i] != '.')
        {
            if(i>0 && s[i-1]=='.')
                act++;
            if(i+1<s.size() && s[i+1]=='.')
                act++;
        }
        else if(car!="." && s[i] =='.')
        {
            if(i>0 && s[i-1]=='.')
                act--;
            if(i+1<s.size() && s[i+1]=='.')
                act--;
        }
        s[i]=car[0];
        cout<<act<<endl;
    }
}