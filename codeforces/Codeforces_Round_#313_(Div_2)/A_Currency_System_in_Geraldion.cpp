#include <iostream>
#include <algorithm>
using namespace std; 
int main()
{
    int N;
    cin>>N;
    vector<int> v(N);
    for(int c=0;c<N;c++)
    	cin>>v[c];
    if((*min_element(v.begin(),v.end())) == 1)
    {
    	cout<<-1;
    }
    else cout<<1;
}