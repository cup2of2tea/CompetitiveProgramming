    #include <iostream>
    #include <map>
    using namespace std;
    map<char,int> Map;
    char s[1<<20];
    int main() {
            cin >> s;
            long long res = 0;
            for(int i = 0; s[i]; i++) res += 2 * (Map[s[i]]++) + 1;
            cout << res << endl;
            return 0;
    }