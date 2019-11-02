#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
 
 
 
 
 
int main()
{
 
//    ifstream in("input.txt");
//#define cin in
//    srand(time(NULL));
    string s1,s2;
    cin>>s1>>s2;
//    int a = rand()%10+3;
//    int b = rand()%6+1;
//    s1.resize(a);
//    s2.resize(b);
//    for(int c=0;c<s1.size();c++) s1[c]=rand()%4+'a';
//    for(int c=0;c<s2.size();c++) s2[c]=rand()%4+'a';
//    cout<<s1<<endl<<s2<<endl;
    string sor1,sor2;
    sor1 = s1;
    sor2 = s2;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2)
    {
        cout<<"array"<<endl;
        return 0;
    }
    s1 = sor1;
    s2 = sor2;
    int i = 0;
    int c;
    for(c=0;c<s2.size();c++)
    {
        while(i < s1.size() && s1[i] != s2[c])
        {
            i++;
        }
        if(i == s1.size()) break;
        i++;
    }
    if(c==s2.size())
    {
        cout<<"automaton"<<endl;
        return 0;
    }
    vector<int> compte(26,0);
    for(int c=0;c<s2.size();c++) compte[s2[c]-'a']++;
    for(int c=0;c<s1.size();c++) compte[s1[c]-'a']--;
    for(int c=0;c<26;c++)
        if(compte[c]>0)
        {
            cout<<"need tree"<<endl;
            return 0;
        }
    cout<<"both"<<endl;
    return 0;
}