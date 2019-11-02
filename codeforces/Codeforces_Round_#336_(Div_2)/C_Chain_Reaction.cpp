#include <bits/stdc++.h>
using namespace std;
 
int rechercheBinaire(int z, vector<pair<int,int> > &v){
    int gauche = 0, droite = v.size()-1;
    while(gauche != droite) {
        int mid = (gauche+droite+1)/2;
        if(v[mid].first > z) droite = mid-1;
        else gauche = mid;
    }
    if(v[gauche].first > z) return -1;
    return gauche;
}
 
int main()
{
#ifndef ONLINE_JUDGE
//    #define cin in
//    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n;
    cin>>n;
    vector<pair<int,int> > beacons(n);
    for(int c=0;c<beacons.size();c++) {
        cin>>beacons[c].first>>beacons[c].second;
    }
    sort(beacons.begin(),beacons.end());
    int destruction = 0, save = 1;
    vector<int> simulation(n+10,0);
    for(int c=0;c<n;c++) {
        int i = rechercheBinaire(beacons[c].first - beacons[c].second-1,beacons);
        simulation[c+1] = simulation[i+1] + 1;
    }
    int res = (*max_element(simulation.begin(),simulation.end()));
    cout<<n-res;
}