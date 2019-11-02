#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int a,b;
    cin>>a>>b;
    vector <string> s(a);
    for(int c=0;c<a;c++)
        cin>>s[c];
    vector <vector <bool> > bol(a);
    for(int c=0;c<a;c++)
        bol[c].resize(b);
    for(int c=0;c<a;c++)
        for(int c2=0;c2<b;c2++)
            bol[c][c2]=true;
    for(int c=0;c<a;c++)
        for(int c2=0;c2<b;c2++)
            for(int c3=0;c3<b;c3++)
            {
                if(c2==c3)
                    continue;
                if(s[c][c2]==s[c][c3])
                    bol[c][c2]=bol[c][c3]=false;
            }
    for(int c=0;c<b;c++)
        for(int c2=0;c2<a;c2++)
            for(int c3=0;c3<a;c3++)
            {
                if(c2==c3)
                    continue;
                if(s[c2][c]==s[c3][c])
                    bol[c2][c]=bol[c3][c]=false;
            }
    for(int c=0;c<a;c++)
        for(int c2=0;c2<b;c2++)
                if(bol[c][c2])
                         cout<<s[c][c2];
}
 