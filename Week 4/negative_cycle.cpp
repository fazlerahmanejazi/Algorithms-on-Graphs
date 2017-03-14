#include <bits/stdc++.h>
using namespace std ;

#define inf 1000000
int T, n, m, a, b, w ;
vector<vector<pair<int, int> > > adj ;
pair<int, int> temp ;
vector<int> dist ;

bool f0rd()
  {
    for(int i=0 ; i<n ; i++)
      {
      	bool check=true ;
        for(int j=0 ; j<n ; j++)
          {
            for(int k=0 ; k<adj[j].size() ; k++)
              {
                temp=adj[j][k] ;
                if(dist[temp.first]>dist[j]+temp.second)
                  {
                  	check=false ;
                  	dist[temp.first]=dist[j]+temp.second ;
                  	if(i==n-1) return true ;
                  }
              }
          }
        if(check) return false ;
      }
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  cin>> n >> m ;
  adj.clear() ;
  dist.assign(n+1, inf) ;
  adj.resize(n+1) ;
  for(int i=0 ; i<m ; i++)
    {
      cin>> a >> b >> w ;
      adj[a].push_back(make_pair(b,w)) ;
    }
  if(f0rd()) cout<< 1 ;
  else cout<< 0 ;
   return 0 ;
 }
