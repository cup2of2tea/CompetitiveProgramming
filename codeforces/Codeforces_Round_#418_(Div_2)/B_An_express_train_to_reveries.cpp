#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
bool check(vector<int> &v) {
	vector<int> copie(v.size());
	copy(v.begin(),v.end(),copie.begin());
	sort(copie.begin(),copie.end());
	for(int c=0;c<v.size();c++) if(copie[c] != c+1) return false;
	return true;
}
 
int main() {
    
    int n;
    cin>>n;
    vector<int> v1(n),v2(n);
    for(int c=0;c<n;c++) {
        cin>>v1[c];
    }
    for(int c=0;c<n;c++) {
        cin>>v2[c];
    }
    int diff[1000] = {-1};
    int i = 0;
    for(int c=0;c<n;c++) {
        if(v1[c] != v2[c]) {
            diff[i++] = c;   
        }
    }
    vector<int> count1(n+1,0),count2(n+1,0);
    for(int c=0;c<n;c++) count1[v1[c]]++;
    for(int c=0;c<n;c++) count2[v2[c]]++;
    
    if(i <= 1) {
        for(int c=0;c<n;c++){
            if(count1[v1[c]] > 1 && c == diff[0]) {
                for(int c2=1;c2<=n;c2++) {
                    if(count1[c2] == 0) {
                        count1[c2] ++;
                        cout<<c2<<" ";
                        break;
                    }
                }
            } else {
                cout<<v1[c]<<" ";
            }
        }
    } else if(i == 2) {
		swap(v1[diff[0]],v2[diff[0]]);
 
		if(!check(v1)){
			swap(v1[diff[0]],v2[diff[0]]);
			swap(v1[diff[1]],v2[diff[1]]);
		}
		
        for(int c=0;c<n;c++) {
            cout<<v1[c]<<" ";
        }
    }
}