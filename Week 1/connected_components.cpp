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
    int n, m, ans=0 ;
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
    for(int i=0 ; i<n ; i++)
      {
        if(!visit[i])
          {
            ans++ ;
            reach(i) ;
          }
      }
    cout<< ans ;
    return 0 ;
  }
