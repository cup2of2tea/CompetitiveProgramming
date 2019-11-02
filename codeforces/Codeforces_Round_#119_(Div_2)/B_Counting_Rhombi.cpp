#include <iostream>
#include <vector>
using namespace std;
 
int main(void)
{
        int w, h;
        cin >> w >> h;
        long long W = ((w/2+1)*(w/2)-(w%2==0?w/2:0)), H=((h/2+1)*(h/2)-(h%2==0?h/2:0));
        cout << (H * W) << endl;
        return 0;
}