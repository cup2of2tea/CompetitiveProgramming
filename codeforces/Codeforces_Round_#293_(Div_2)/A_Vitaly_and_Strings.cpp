#include <iostream>
 
using namespace std;
 
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    string res = "";
    bool different = false;
    for(int c=0;c<s1.size();c++)
    {
        if(different && s1[c] != 'z')
        {
            cout<<res;
            cout<<'z';
            for(int c2=c+1;c2<s1.size();c2++) cout<<'a';
            return 0;
        }
        
        if(s1[c] == s2[c])
        {
            res=res+s1[c];
        }
        else if(s1[c]+1 == s2[c])
        {
            bool lower=false,upper=false;
            for(int c2=c+1;c2<s1.size();c2++)
            {
                if(s2[c2] != 'a') upper = true;
                if(s1[c2] != 'z') lower = true;
            }
            if(lower)
            {
                cout<<res;
                cout<<s1[c];
                for(int c2=c+1;c2<s1.size();c2++)
                {
                      if(s1[c2] != 'z') cout<<(char)(s1[c2]+1);
                      else cout<<'z';
                }
            }
            else if(upper)
            {
                cout<<res;
                cout<<s2[c];
                for(int c2=c+1;c2<s1.size();c2++)
                {
                      if(s2[c2] != 'a') cout<<(char)(s2[c2]-1);
                      else cout<<'a';
                }
            }
            else
            {
                cout<<"No such string";
            }
            return 0;
        }
        else
        {
            cout<<res;
            cout<<(char)(s1[c]+1);
            for(int c2=c+1;c2<s1.size();c2++) cout<<'a';
            return 0;
        }
    }
    cout<<"No such string";
}