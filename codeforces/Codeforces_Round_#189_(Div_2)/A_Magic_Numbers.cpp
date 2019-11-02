#include <iostream>
 
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    for(int c=0;c<s.size();)
    {
        if(s[c]!='1')
        {
            cout<<"NO";
            return 0;
        }
        else
        {
            int nb_four=0;
            c++;
            for(;c<s.size()&&s[c]=='4'&&nb_four<2;c++)
            {
                nb_four++;
            }
         }
    }
    cout<<"YES";
}