#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
 
int main()
{
    map<string,bool> m;
    int n;
    cin>>n;
    for(int c=0;c<n;c++)
    {
        string s;
        cin>>s;
        for(int c2=0;c2<s.size();c2++)
        {
            for(int c3=0;c3+c2<=s.size();c3++)
            {
                m[s.substr(c2,c3)]=true;
            }
        }
    }
    queue<string> bfs;
    bfs.push("");
    while(bfs.size()!=0)
    {
        string top=bfs.front();
        bfs.pop();
        if(!m[top])
        {
            cout<<top;
            return 0;
        }
        for(char c='a';c<='z';c++)
        {
            bfs.push(top+c);
        }
    }
}