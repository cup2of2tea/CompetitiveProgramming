#include <bits/stdc++.h>
#define each(it,o) for(auto it = (o).begin(); it != (o).end(); ++ it)
 
 
using namespace std;
 
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define DEBUG(x) cout << #x << " = " << x << endl;
#define PR(a,n) cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; puts("");
#define PR0(a,n) cout << #a << " = "; REP(_,n) cout << a[_] << ' '; puts("");
#define _MAX_COST 1000111
#define _MAX_FLOW 1000111
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
 
#define _MAX_COST 1000111
#define _MAX_FLOW 1000111
 
template<class Flow = int, class Cost = int>
struct MinCostFlow {
   struct Edge {
      int t;
      Flow f;
      Cost c;
      Edge*next, *rev;
      Edge(int _t, Flow _f, Cost _c, Edge*_next) :
            t(_t), f(_f), c(_c), next(_next) {
      }
   };
   vector<Edge*> E;
 
   int addV() {
      E.push_back((Edge*) 0);
      return E.size() - 1;
   }
   Edge* makeEdge(int s, int t, Flow f, Cost c) {
      return E[s] = new Edge(t, f, c, E[s]);
   }
   Edge* addEdge(int s, int t, Flow f, Cost c) {
      Edge*e1 = makeEdge(s, t, f, c), *e2 = makeEdge(t, s, 0, -c);
      e1->rev = e2, e2->rev = e1;
      return e1;
   }
   pair<Flow, Cost> minCostFlow(int vs, int vt) { //flow,cost
      int n = E.size();
      Flow flow = 0;
      Cost cost = 0;
      const Cost MAX_COST = _MAX_COST;
      const Flow MAX_FLOW = _MAX_FLOW;
      for (;;) {
         vector<Cost> dist(n, MAX_COST);
         vector<Flow> am(n, 0);
         vector<Edge*> prev(n);
         vector<bool> inQ(n, false);
         queue<int> que;
 
         dist[vs] = 0;
         am[vs] = MAX_FLOW;
         que.push(vs);
         inQ[vs] = true;
 
         while (!que.empty()) {
            int u = que.front();
            Cost c = dist[u];
            que.pop();
            inQ[u] = false;
            for (Edge*e = E[u]; e; e = e->next)
               if (e->f > 0) {
                  Cost nc = c + e->c;
                  if (nc < dist[e->t]) {
                     dist[e->t] = nc;
                     prev[e->t] = e;
                     am[e->t] = min(am[u], e->f);
                     if (!inQ[e->t]) {
                        que.push(e->t);
                        inQ[e->t] = true;
                     }
                  }
               }
         }
 
 
         if (dist[vt] == MAX_COST)
            break;
         Flow by = am[vt];
         int u = vt;
         flow += by;
         cost += by * dist[vt];
         while (u != vs) {
            Edge*e = prev[u];
            e->f -= by;
            e->rev->f += by;
                u = e->rev->t;
         }
      }
      return make_pair(flow, cost);
   }
};
 
MinCostFlow<int,int> mcmf;
int main() {
    string t;
    cin>>t;
    int n;
    cin>>n;
 
    int start = mcmf.addV();
    int arrival = mcmf.addV();
 
    vector<int> alphabet(26);
 
    for(int c=0;c<26;c++) {
        alphabet[c] = mcmf.addV();
    }
 
    vector<int> sIndex(n);
    for(int c=0;c<n;c++) {
        sIndex[c] = mcmf.addV();
    }
    vector<int> compte(26,0);
    for(int c=0;c<t.size();c++) compte[t[c]-'a']++;
 
    for(int c2=0;c2<26;c2++) {
        mcmf.addEdge(start,alphabet[c2],compte[c2],0);
    }
 
 
    for(int c=0;c<n;c++) {
        fill(compte.begin(),compte.end(),0);
        string s;
        cin>>s;
        int limite;
        cin>>limite;
 
        for(int c2=0;c2<s.size();c2++) compte[s[c2]-'a']++;
 
        for(int c2=0;c2<26;c2++) {
            mcmf.addEdge(alphabet[c2],sIndex[c],compte[c2],0);
        }
        mcmf.addEdge(sIndex[c],arrival,limite,c+1);
    }
    pair<int,int> res = mcmf.minCostFlow(start,arrival);
    if(res.first != t.size()) {
        cout<<-1;
    } else {
        cout<<res.second;
    }
    return 0;
}