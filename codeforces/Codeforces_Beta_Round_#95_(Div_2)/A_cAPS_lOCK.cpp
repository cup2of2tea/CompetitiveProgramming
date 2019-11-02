#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <set>
using namespace std;
 
int main()
{
 
    string s;
    int upper=0,lower=0;
    getline(cin,s);
    for(int c=0;c<s.size();c++)
        if(s[c]>='A'&&s[c]<='Z')
            upper++;
    int taille=s.size();
     int dec='A'-'a';
    int dec2='a'-'A';
    if((s[0]>='a'&&s[0]<='z'&&upper==taille-1)||upper==taille)
    {
        for(int c=0;c<taille;c++){if(s[c]>='A'&&s[c]<='Z')
            cout<<((char)(s[c]+dec2));
            else cout<<(char)(s[c]+dec);}
    }
    else
    {
        cout<<s;
    }
}