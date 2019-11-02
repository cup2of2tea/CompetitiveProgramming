#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <bitset>
 
using namespace std;
 
typedef long long llint;
 
const int MAXN = 1000010;
const int BASE = 13;
 
int N;
char str[ MAXN ];
llint hash[ MAXN ];
llint base[ MAXN ];
 
llint get_hash( int x, int y ) {
        return hash[y] - base[y-x+1] * hash[x-1];
}
 
int valid(int len) {
        int lo = 2;
        int hi = len+1;
        
        while (hi < N) {
                llint h = get_hash( lo, hi );
                if (h == hash[len]) return 1;
                hi += 1;
                lo += 1;
        }
        
        return 0;
}
 
int main()
{
        scanf("%s", str);
        N = strlen(str);
        
        base[0] = 1;
        for (int i = 1; i <= N; ++i) {
                base[i] = base[i-1] * BASE;
                hash[i] = hash[i-1] * BASE + str[i-1];          
        }
        
        //printf("has : %lld, %lld\n", hash[3], get_hash(7, 9));
        
        char sol_found = 0;
        int sol_position = 0;
        for (int i = N-1; i > 0 && !sol_found; --i) { //puts("INC");
                llint h = get_hash(N-i+1, N);
                //printf("%lld %lld\n", hash[i], h);
                if (hash[i] == h) { //puts("AF");
                        sol_found = valid(i);
                        sol_position = i;
                }
        }
        
        if (sol_found == 1) {
                for (int i = 0; i < sol_position; ++i)
                        putchar(str[i]);
                putchar('\n');
        } else {
                puts("Just a legend");
        }
}