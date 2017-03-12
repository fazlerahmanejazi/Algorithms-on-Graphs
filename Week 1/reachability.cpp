#include <bits/stdc++.h>
using namespace std ;

vector<vector<int> > adj ;
vector<bool> visit ;

void reach(int t)
  {
    visit[t]=true ;
    for(int i=0 ; i<adj[t].size() ; i++)
      if(!visit[adj[t][i]])
        reach(adj[t][i]) ;
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
        adj[y - 1].push_back(x - 1);
      }
    int x, y ;
    cin >> x >> y ;
    reach(x-1) ;
    if(visit[y-1]) cout<< 1 ;
    else cout<< 0 ;
    return 0 ;
  }
