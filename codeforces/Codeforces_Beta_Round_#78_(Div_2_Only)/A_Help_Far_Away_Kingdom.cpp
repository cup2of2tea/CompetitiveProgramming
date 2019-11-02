#include <iostream>
using namespace std;
 
int main()
{
        string s;
        cin>>s;
        int c=0;
        while(s[c]!='.')
                c++;
        if(c>0&&s[c-1]=='9')
        {
                        cout<<"GOTO Vasilisa.";
                        return 0;
        }
        for(int c2=0;c2<c-1;c2++)
                        cout<<s[c2];
        if(c<s.size()-1&&s[c+1]>='5')
                cout<<(char)(s[c-1]+1);
        else
                cout<<(char)(s[c-1]);
}