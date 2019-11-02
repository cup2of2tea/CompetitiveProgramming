#include <iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s[0]=='2'&&s[1]=='3'&&(s[3]>'3'||(s[3]=='3'&&s[4]>'2')))
        cout<<"00:00";
    else if(s[1]<s[3]||(s[1]==s[3]&&s[0]<=s[4])||s[1]>='6')
    {   if(s[1]>='5')
            cout<<(char)(s[0]+1)<<"0:0"<<(char)(s[0]+1);
        else
            cout<<s[0]<<(char)(s[1]+1)<<":"<<(char)(s[1]+1)<<s[0];
    }
    else
        cout<<s[0]<<s[1]<<":"<<s[1]<<s[0];
}