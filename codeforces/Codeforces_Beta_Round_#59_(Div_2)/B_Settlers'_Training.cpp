#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
bool all_k(vector<int> s,int k)
{
        for(int c=0;c<s.size();c++)
                if(s[c]<k)
                        return false;
        return true;
}
 
int main()
{
    int n,k;
        cin>>n>>k;
        vector<int> soldats(n);
        for(int c=0;c<n;c++)
                cin>>soldats[c];
        int gold=0;
        while(!all_k(soldats,k))
        {
                gold++;
                vector<int> soldats_2;
                soldats_2.resize(soldats.size());
                for(int c=0;c<soldats.size();c++) soldats_2[c]=soldats[c];
                for(int c=0;c<soldats.size();c++)
                        if((c==soldats.size()-1||soldats[c]!=soldats[c+1])&&soldats[c]<k)
                                soldats_2[c]=soldats[c]+1;
                for(int c=0;c<soldats.size();c++) soldats[c]=soldats_2[c];
        }
        cout<<gold;
}