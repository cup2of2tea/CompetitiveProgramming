#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    map<int,int> buy;
    map<int,int> sell;
    int n,d;
    cin>>n>>d;
    for(int c=0;c<n;c++) {
        string command;
        cin>>command;
        int price,number;
        cin>>price>>number;
        if(command == "B") {
            buy[-price] += number;
        } else {
            sell[price] += number;
        }
    }
    vector<pair<int,int> > toReverse;
    int i=0;
    for(map<int,int>::iterator it = sell.begin();it != sell.end() && i < d; i++,it++)
        toReverse.push_back(make_pair(it->first, it ->second));
    reverse(toReverse.begin(),toReverse.end());
    i=0;
    for(int c=0;c<toReverse.size();c++) {
        cout<<"S "<<toReverse[c].first<<" "<<toReverse[c].second<<endl;
    }
    for(map<int,int>::iterator it = buy.begin();it != buy.end() && i < d; i++,it++) {
        cout<<"B "<<-(it->first)<<" "<<(it->second)<<endl;
    }
}