#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    vector<int> act(N);
    for(int c=0;c<N;c++) cin>>act[c];
    sort(act.begin(),act.end());
    for(int c=0;c<N;c++) cout<<act[c]<<" ";
}