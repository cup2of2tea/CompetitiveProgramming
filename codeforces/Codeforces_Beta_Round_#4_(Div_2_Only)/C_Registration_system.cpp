#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    map<string,int> m;
        int d;
        cin>>d;
        for(int c=0;c<d;c++)
        {
                string s;
                cin>>s;
                if(m[s]>0)
                {
                        string nb;
                        cout<<s<<m[s]<<endl;
                        m[s]++;
                }
                else
                {
                        cout<<"OK"<<endl;
                        m[s]=1;
                }
        }
                
}