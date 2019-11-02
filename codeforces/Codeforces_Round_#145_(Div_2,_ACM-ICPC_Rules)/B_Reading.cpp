#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
#define cin in
#define cout out
    int N,K;
    cin>>N>>K;
    vector<pair<int,int> > v(N);
    for(int c=0;c<v.size();c++) 
    {
        cin>>v[c].first;
        v[c].second=c+1;
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    cout<<v[K-1].first<<endl;
    for(int c=0;c<K;c++)
        cout<<v[c].second<<" ";
}