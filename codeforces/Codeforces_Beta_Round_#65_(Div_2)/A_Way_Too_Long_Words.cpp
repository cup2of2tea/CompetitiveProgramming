#include <iostream>
using namespace std;
 
int main()
{
    int nb_mots;
    string s;
    cin>>nb_mots;
    for(int c=0;c<nb_mots;c++)
    {
        cin>>s;
        if(s.size()>10)
            cout<<s.at(0)<<s.size()-2<<s.at(s.size()-1);
        else
            cout<<s;
        cout<<endl;
     }
}