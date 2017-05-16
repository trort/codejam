#include<string>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<ctime>
#include<iostream>

#include<message.h>
#include "majority.h"

using namespace std;

typedef long long ll;

int main() {
  ll N = GetN();
  ll N_nodes = NumberOfNodes();
  ll start_id = N * MyNodeId() / N_nodes;
  ll end_id = N * (MyNodeId() + 1) / N_nodes;
  ll cand = -1;
  ll count = 0;
  for (ll i = start_id; i < end_id; ++ i) {
    ll vote = GetVote(i);
    if (vote == cand) count += 1;
    else{
      if(count > 0) count -= 1;
      else{
        cand = vote;
        count = 1;
      }
    }
  }
  PutLL(0, cand);
  PutLL(0, count);
  Send(0);
  // cout << "local process finished" << endl;

  if (MyNodeId() == 0) {
    ll global_cand = -1;
    ll global_count = 0;
    for (ll i = 0; i < N_nodes; ++ i) {
      Receive(i);
      ll t_cand = GetLL(i);
      ll t_count = GetLL(i);
      if (t_cand == global_cand) global_count += t_count;
      else {
        global_count -= t_count;
        if (global_count < 0) {
          global_cand = t_cand;
          global_count = - global_count;
        }
      }
    }
    // verify cand
    for (ll i = 0; i < N_nodes; ++ i) {
      PutLL(i, global_cand);
      Send(i);
    }
  }


  Receive(0);
  ll to_verify = GetLL(0);
  ll verify_count = 0;
  for (ll i = start_id; i < end_id; ++ i) {
    ll vote = GetVote(i);
    if (vote == to_verify) verify_count ++ ;
  }
  PutLL(0, verify_count);
  Send(0);

  if (MyNodeId() == 0){
    ll global_sum = 0;
    for (ll i = 0; i < N_nodes; ++i){
      Receive(i);
      global_sum += GetLL(i);
    }
    if (2 * global_sum > N) cout << to_verify << endl;
    else cout << "NO WINNER" << endl;
  }

  return 0;
}
