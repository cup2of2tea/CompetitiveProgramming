#include <iostream>
 
using namespace std;
 
int main()
{
    int tab[26]={0};
    string s;
    getline(cin,s);
    for(int c=0;c<s.size();c++) if(s[c]>='a'&&s[c]<='z') tab[s[c]-'a']++;
    int res = 0;
    for(int c=0;c<26;c++) res+=(tab[c]!=0);
    cout<<res;
}