#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    vector <pair<string,string> > equipage;
    int nb;
    cin>>nb;
    equipage.resize(nb);
    for(int c=0;c<nb;c++)
    {
            string s1,s2;
            cin>>s1>>s2;
            equipage[c].first=s1;
            equipage[c].second=s2;
    }
    for(int c=0;c<nb;c++)
    {
        if(equipage[c].second=="rat")
            cout<<equipage[c].first<<endl;
    }
    for(int c=0;c<nb;c++)
    {
        if(equipage[c].second=="woman"||equipage[c].second=="child")
            cout<<equipage[c].first<<endl;
    }
    for(int c=0;c<nb;c++)
    {
        if(equipage[c].second=="man")
            cout<<equipage[c].first<<endl;
    }
    for(int c=0;c<nb;c++)
    {
        if(equipage[c].second=="captain")
            cout<<equipage[c].first<<endl;
    }
}