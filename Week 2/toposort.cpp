#include <bits/stdc++.h>
using namespace std ;

vector<vector<int> > adj ;
vector<bool> visit ;
vector<int> ans ;

void reach(int t)
  {
    visit[t]=true ;
    for(int i=0 ; i<adj[t].size() ; i++)
      if(!visit[adj[t][i]])
          reach(adj[t][i]) ;
    ans.push_back(t) ;
  }

int main()
  {
    int n, m;
    cin >> n >> m ;
    adj.resize(n+1) ;
    visit.assign(n+1, false) ;
    for (int i = 0; i < m; i++)
      {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
      }
    for(int i=0 ; i<n ; i++)
      if(!visit[i])
          reach(i) ;
    for(int i=ans.size()-1 ; i>=0 ; i--)
      cout<< ans[i]+1 << " " ;
    return 0 ;
  }
