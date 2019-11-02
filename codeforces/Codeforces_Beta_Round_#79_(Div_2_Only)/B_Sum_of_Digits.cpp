#include <iostream>
#include <string>
 
using namespace std;
string itoa2(int total)
{
    string resultat="";
    while(total!=0)
    {
        resultat=(char)(total%10+'0')+resultat;
        total/=10;
    }
    return resultat;
}
 
int main()
{
    string s;
    cin>>s;
    if(s.size()<=1)
    {
        cout<<0;
        return 0;
    }
    int total=0;
    int c=0;
    while(true)
    {c++;
        for(int c2=0;c2<s.size();c2++)
            total+=s.at(c2)-'0';
        if(total<10)
            break;
        
        s=itoa2(total);total=0;
    }cout<<c;
}