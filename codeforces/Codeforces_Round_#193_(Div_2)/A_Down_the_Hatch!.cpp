#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<char> prec(3,'0');
    int res = 0;
    for(int c=0;c<s.size();c++)
    {
        int z = c%n;
        if(z==0)
        {
            char mini = (*min_element(prec.begin(),prec.end()));
            char maxi = (*max_element(prec.begin(),prec.end()));
            if(mini == maxi && mini != '0')
            {
                res++;
                s[c]=s[c-1];
            }
            else if(c+1<s.size()) s[c]=s[c+1];
        }
        prec[0]=prec[1];
        prec[1]=prec[2];
        prec[2]=s[c];
    }
    cout<<res<<endl;
}