#include <bits/stdc++.h>
#define each(it,o) for(auto it = (o).begin(); it != (o).end(); ++ it)
 
 
using namespace std;
 
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
 
vector<string> split(string s, string sep){
    string act = "";
    vector<string> res;
    for(int c=0;c<s.size();c++) {
        bool split = false;
        for(int c2=0;c2<sep.size();c2++) {
            if(sep[c2] == s[c]) {
                split = true;
                break;
            }
        }
        if(split)  {
            res.push_back(act);
            act = "";
        } else {
            act = act + s[c];
        }
    }
    res.push_back(act);
    return res;
}
 
string removeChars(string s, string filters) {
    string res = "";
    for(int c=0;c<s.size();c++) {
        bool fine = true;
        for(int c2=0;c2<filters.size();c2++)  {
            if(filters[c2] == s[c]){
                fine = false;
                break;
            }
        }
        if(fine) res = res + s[c];
    }
    return res;
}
 
string replaceChars(string s, string from, string to) {
    for(int c=0;c<s.size();c++) {
        for(int c2=0;c2<from.size();c2++) {
            if(from[c2] == s[c]) {
                s[c] = to[c2%to.size()];
                break;
            }
        }
    }
    return s;
}
 
 
struct MaximumFlow {
	typedef int Index;
	typedef int Flow;
	static const Flow InfCapacity = INF;
	struct Edge {
		Index to;
		Flow capacity;
		Index rev;
	};
	vector<vector<Edge> > g;
	void init(Index n) { g.assign(n, vector<Edge>()); }
	void add(Index i, Index j, Flow capacity) {
		Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = 0;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}
	void addB(Index i, Index j, Flow capacity) {
		Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = capacity;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}
	Flow maximumFlow(int s, int t) {
		int n = g.size();
		vector<Index> level(n);
		Flow total = 0; bool update;
		do {
			update = false;
			fill(level.begin(), level.end(), -1); level[s] = 0;
			queue<Index> q; q.push(s);
			for(Index d = n; !q.empty() && level[q.front()] < d; ) {
				int u = q.front(); q.pop();
				if(u == t) d = level[u];
				each(e, g[u]) if(e->capacity > 0 && level[e->to] == -1)
					q.push(e->to), level[e->to] = level[u] + 1;
			}
			vector<Index> iter(n);
			for(Index i = 0; i < n; i ++) iter[i] = (int)g[i].size() - 1;
			while(1) {
				Flow f = augment(level, iter, s, t, InfCapacity);
				if(f == 0) break;
				total += f; update = true;
			}
		} while(update);
		return total;
	}
	Flow augment(vector<Index> &level, vector<Index> &iter, Index u, Index t, Flow f) {
		if(u == t || f == 0) return f;
		Index lv = level[u];
		if(lv == -1) return 0;
		level[u] = -1;
		for(; iter[u] >= 0; -- iter[u]) {
			Edge &e = g[u][iter[u]];
			if(level[e.to] <= lv) continue;
			Flow l = augment(level, iter, e.to, t, min(f, e.capacity));
			if(l == 0) continue;
			e.capacity -= l; g[e.to][e.rev].capacity += l;
			level[u] = lv;
			return l;
		}
		return 0;
	}
};
 
int main() {
    vector<int> sizes(6);
    for(int c=0;c<sizes.size();c++) cin>>sizes[c];
    int n;
    cin>>n;
    MaximumFlow m;
    m.init(n+6+2);
 
    for(int c=0;c<6;c++){
        m.add(c+2,1,sizes[c]);
    }
string poss[6] = {"S","M","L","XL","XXL","XXXL"};
    for(int c=0;c<n;c++) {
        m.add(0,8+c,1);
        string line;
        cin>>line;
        vector<string> possibilities = split(line,",");
        for(int c2=0;c2<possibilities.size();c2++) {
            for(int c3=0;c3<6;c3++) {
                    if(poss[c3] == possibilities[c2]) {
                            m.add(8+c,c3+2,1);
                    }
            }
        }
    }
 
    int res = m.maximumFlow(0,1);
 
    if(res != n) {
        cout<<"NO";
        return 0;
    }
 
 
 
 
    cout<<"YES"<<endl;
    for(int c=0;c<n;c++) {
        for(int c2=0;c2<m.g[8+c].size();c2++) {
            if(m.g[8+c][c2].capacity == 0) {
                cout<<poss[m.g[8+c][c2].to-2]<<endl;
            }
        }
    }
 
 
}