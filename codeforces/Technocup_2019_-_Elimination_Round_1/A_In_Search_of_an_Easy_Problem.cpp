#include <iostream>
using namespace std;
 
int main() {
    int N;
    cin>>N;
    for(int c=0;c<N;c++) {
        int z;
        cin>>z;
        if(z) {
            cout<<"hard"<<endl;
            return 0;
        }
    }
    cout<<"easy";
}