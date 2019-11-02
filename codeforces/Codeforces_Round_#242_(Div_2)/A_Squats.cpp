#include <iostream>
using namespace std;
 
int main()
{
    int z;
    cin>>z;
    string s;
    cin>>s;
    int deb=0,ot=0;
    for(int c=0;c<s.size();c++) if(s[c]=='x') deb++; else ot++;
    int res = max(z/2-deb,z/2-ot);
    char change = (deb > z/2? 'x':'X');
    char to = (deb > z/2? 'X':'x');
    cout<<res<<endl;
    for(int c=0;c<s.size()&&res;c++) if(s[c]==change) {s[c]=to;res--;}
    cout<<s;
        
}