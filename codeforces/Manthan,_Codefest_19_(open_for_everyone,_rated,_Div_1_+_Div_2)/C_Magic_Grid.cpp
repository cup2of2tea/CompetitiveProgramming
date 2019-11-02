#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>
#include <limits>
#include <queue>
#include <iomanip>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;
 
int pattern[4][4]={{8,9,1,13},{3,12,7,5},{0,2,4,11},{6,10,15,14}};
 
bool verify(vector<vector<int> > &grid) {
    set<int> s;
    for(int c=0;c<grid.size();c++) {
        int r = 0;
        int col = 0;
        for(int c2=0;c2<grid[c].size();c2++) {
            r ^= grid[c][c2];
            col ^= grid[c2][c];
        }
        s.insert(r);
        s.insert(col);
    }
    if(s.size() != 1) {
        return false;
    }
    return true;
}
 
 
int main() {
    //  std::cout << "Maximum value for int: " << std::numeric_limits<int>::max() << '\n';
 
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    int offset = 0;
    vector<vector<int> > res(N,vector<int>(N));
    for(int c=0;c<N/4;c++) {
        for(int c2=0;c2<N/4;c2++) {
            for(int c3=0;c3<4;c3++) {
                for(int c4=0;c4<4;c4++) {
                    res[c*4+c3][c2*4+c4]=pattern[c3][c4]+offset;
                }
            }
            offset+=16;
        }
    }
    for(int c=0;c<N;c++) {
        for(int c2=0;c2<N;c2++) {
            cout<<res[c][c2]<<" ";
        }
        cout<<endl;
    }
    /*if(verify(res)) {
        cout<<"wut"<<endl;
    }*/
}
 