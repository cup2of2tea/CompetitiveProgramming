#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    vector<string> s(3);
    for(int c=0;c<3;c++)
        cin>>s[c];
    for(int c=0;c<3;c++)
        for(int c2=0;c2<3;c2++)
            if(c==1&&c2==1)
                continue;
            else if(s[c][c2]!=s[2-c][2-c2])
            {
                cout<<"NO";
                return 0;
            }
    cout<<"YES";
}