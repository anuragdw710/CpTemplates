#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
//---------------------------------------------------------------------------------
ll dx[4] = {0, 0, 1, -1}; 
ll dy[4] = {1, -1, 0, 0};
ll ddx[8] = { -1, 0, 0, 1, 1, -1, 1, -1}; 
ll ddy[8] = {0, 1, -1, 0, 1, -1, -1, 1};
const ll dddx[16] = {1, 0, 0, -1, 1, 1, -1, -1, 2, 2, 1, 1, -1, -1, -2, -2};
const ll dddy[16] = {0, -1, 1, 0, -1, 1, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1};
ll ddxK[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
ll ddyK[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
//----------------------------------------------------------------------------------------
/*check Function for grid[***]*/
bool check(ll i,ll j, ll n,ll m) {
  if(i<0 || j<0 || i>=n || j>=m){
    return 0;
  }
  return 1;
}
//----------------------------------------------------------------------------------
/*dfs in o(v+e)*/
const ll MAX_N=10e5+10;
ll n,m;
vector<ll> adj[MAX_N];