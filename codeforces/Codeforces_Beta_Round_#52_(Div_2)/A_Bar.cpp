#include <iostream>
#include <vector>
using namespace std;
string tab[11]={"ABSINTH", "BEER","BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE","TEQUILA", "VODKA", "WHISKEY", "WINE"};
 
int itoa_2(string s)
{
    int total=0;
    for(int c=0;c<s.size();c++)
        total=total*10+(s[c]-'0');
    return total;
}
bool in_tab(string s)
{
    for(int c=0;c<11;c++)
    {
        if(s==tab[c])
            return true;
    }
    return false;
}
 
 
int main()
{
    string s;
    int n;
    cin>>n;
    int total=0;
    for(int c=0;c<n;c++)
    {
        cin>>s;
        if(s[0]<='9'&&s[0]>='0')
        {
            int z=itoa_2(s);
            if(z<18)
                total++;
        }
        else if(in_tab(s))
                total++;
    }
    cout<<total;
}