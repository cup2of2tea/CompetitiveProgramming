#include <iostream>
 
using namespace std;
 
string couleur="GBIV";
 
 
int main()
{
        int n;
        cin>>n;
        cout<<"ROY";
        for(int c=3;c<n;c++)
                cout<<couleur.at(c%couleur.size());
}