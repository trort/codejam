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
#include "weird_editor.h"

using namespace std;

typedef long long ll;

const long long MOD = 1000000007;

ll Get10Mod(ll pad){
  if(pad <= 0){
    return 1LL;
  }
  else if (pad == 1){
    return 10LL;
  }
  else if (pad == 2){
    return 100LL;
  }
  else if (pad == 3){
    return 1000LL;
  }
  else if (pad == 4){
    return 10000LL;
  }
  else if (pad == 5){
    return 100000LL;
  }
  else if (pad == 6){
    return 1000000LL;
  }
  else if (pad == 7){
    return 10000000LL;
  }
  else if (pad == 8){
    return 100000000LL;
  }
  else {
    if (pad % 2 == 0){
      ll half = Get10Mod(pad/2);
      return (half * half) % MOD;
    }
    else{
      ll half = Get10Mod((pad-1)/2);
      return (half * half * 10) % MOD;
    }
  }
}

ll GetMod(ll N, ll offset){
  ll pad = N - offset - 1;
  ll ans = Get10Mod(pad);
  return ans;
}

int main() {
  ll N = GetNumberLength();
  ll N_nodes = NumberOfNodes();
  ll my_id = MyNodeId();
  ll start_id = N * MyNodeId() / N_nodes;
  ll end_id = N * (MyNodeId() + 1) / N_nodes;
  ll count[10];
  for(ll j = 0; j < 10; ++j) count[j] = 0;
  for (ll i = start_id; i < end_id; ++ i) {
    ll item = GetDigit(i);
    for(ll j = 0; j < item; ++j){
      count[j] = 0;
    }
    count[item] += 1;
  }
  for (ll j = 9; j > 0; --j)
    PutLL(0, count[j]);
  Send(0);
  // cout << "local process finished" << endl;

  if (MyNodeId() == 0) {
    ll global_count[10];
    for (ll j = 0; j < 10; ++j) global_count[j] = 0;
    for (ll i = 0; i < N_nodes; ++ i) {
      Receive(i);
      for (ll j = 9; j > 0; --j){
        ll t_count = GetLL(i);
        if (t_count > 0){
          for(ll k = 0; k < j; ++k){
            global_count[k] = 0;
          }
        }
        global_count[j] += t_count;
      }
    }
    ll offset[10];
    ll cur_offset = 0;
    for (ll j = 9; j >= 0; --j){
      offset[j] = cur_offset;
      cur_offset += global_count[j];
      //cout<<j<<endl;
      //cout<<global_count[j]<<endl;
      //cout<<offset[j]<<endl;
    }

    // send to other for calc
    for (ll i = 0; i < N_nodes; ++ i) {
      ll start_idx = cur_offset * i / N_nodes;
      ll end_idx = cur_offset * (i + 1) / N_nodes;
      for (ll j = 9; j > 0; --j){
        ll t_len = min(end_idx, offset[j-1]) - max(start_idx, offset[j]);
        t_len = max(t_len, 0LL);
        PutLL(i, t_len);
      }
      PutLL(i, start_idx);
      Send(i);
    }

  }

  // calc partial mod
  Receive(0);
  ll local_count[10];
  ll local_offset[10];
  ll local_init_offset;
  for (ll j = 9; j > 0; -- j){
    local_count[j] = GetLL(0);
  }
  local_init_offset = GetLL(0);
  ll local_cur_offset = local_init_offset;
  for(ll j = 9; j >= 0; -- j){
    local_offset[j] = local_cur_offset;
    local_cur_offset += local_count[j];
  }
  ll local_sum = 0;
  local_cur_offset = local_init_offset;
  for(ll j = 9; j > 0; -- j){
    for(ll k = 0; k < local_count[j]; ++k){
      local_sum = (j * GetMod(N, local_cur_offset) + local_sum) % MOD;
      local_cur_offset ++;
    }
  }
  PutLL(0,local_sum);
  Send(0);

  if (my_id == 0){
    ll global_sum = 0LL;
    for (ll i = 0; i < N_nodes; ++i){
      Receive(i);
      global_sum = (global_sum + GetLL(i)) % MOD;
    }
    printf("%lld\n", global_sum);
  }

  return 0;
}
