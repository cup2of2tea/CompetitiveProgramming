#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
int main()
{
    map<char,int> dispo;
    string s,t;
    cin>>s>>t;
    for(int c=0;c<t.size();c++) dispo[t[c]]++;
    
    string seconde = "";
    
    int yay = 0, woops = 0;
    
    for(int c=0;c<s.size();c++)
    {
        if(dispo[s[c]])
        {
            yay++;
            dispo[s[c]]--;
        }
        else seconde+=(s[c]>='A'&&s[c]<='Z'?s[c]-'A'+'a':s[c]-'a'+'A');
        
    }
    
    for(int c=0;c<seconde.size();c++)
    {
        if(dispo[seconde[c]])
        {
            woops++;
            dispo[seconde[c]]--;
        }
    }
    cout<<yay<<" "<<woops<<endl;
}
    