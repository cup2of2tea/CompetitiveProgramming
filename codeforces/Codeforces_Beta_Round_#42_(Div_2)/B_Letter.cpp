#include <iostream>
using namespace std;
 
int main()
{
    string s1,s2;
    int tableau[52]={0};
    getline(cin,s1);
    int dec='z'-'a';
    for(int c=0;c<s1.size();c++)
        if(s1[c]==' ') continue;
        else if(s1[c]<='z'&&s1[c]>='a') tableau[s1[c]-'a']++;
        else tableau[s1[c]-'A'+dec]++;
    getline(cin,s2);
    for(int c=0;c<s2.size();c++)
        if(s2[c]==' ') continue;
        else if(s2[c]<='z'&&s2[c]>='a') {if(tableau[s2[c]-'a']>0) tableau[s2[c]-'a']--; else{cout<<"NO";return 0;}}
        else if(tableau[s2[c]-'A'+dec]>0) tableau[s2[c]-'A'+dec]--; else {cout<<"NO";return 0;}
    cout<<"YES";
 
}