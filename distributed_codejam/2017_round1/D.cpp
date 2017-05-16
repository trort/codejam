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
#include "todd_and_steven.h"

using namespace std;

typedef long long ll;

const long long MOD = 1000000007;

int main() {
  ll N_Todd = GetToddLength();
  ll N_Steven = GetStevenLength();
  ll N_nodes = NumberOfNodes();
  ll my_id = MyNodeId();
  ll min_value = min(GetToddValue(0), GetStevenValue(0));
  ll max_value = max(GetToddValue(N_Todd-1), GetStevenValue(N_Steven-1)) + 1;

  ll start_value = (max_value - min_value) * my_id / N_nodes + min_value;
  ll end_value = (max_value - min_value) * (my_id + 1) / N_nodes + min_value;

  ll left, right, pivot;
  ll Todd_start_id, Steven_start_id, Todd_end_id, Steven_end_id;
  left = 0;
  right = N_Todd;
  while (right - left > 1){
    pivot = (left + right) / 2;
    if (GetToddValue(pivot) == start_value) {
      Todd_start_id = pivot;
      left = pivot;
      break;
    }
    if (GetToddValue(pivot) > start_value) right = pivot;
    else left = pivot + 1;
  }
  if (left < N_Todd && GetToddValue(left) >= start_value) Todd_start_id = left;
  else Todd_start_id = right;

  left = 0;
  right = N_Steven;
  while (right - left > 1){
    pivot = (left + right) / 2;
    if (GetStevenValue(pivot) == start_value) {
      Steven_start_id = pivot;
      left = pivot;
      break;
    }
    if (GetStevenValue(pivot) > start_value) right = pivot;
    else left = pivot + 1;
  }
  if (left < N_Steven && GetStevenValue(left) >= start_value) Steven_start_id = left;
  else Steven_start_id = right;

  //cout<<start_value<<endl;
  //cout<<Todd_start_id<<endl;
  //cout<<Steven_start_id<<endl;

  if (my_id > 0){
    PutLL(my_id - 1, Todd_start_id);
    PutLL(my_id - 1, Steven_start_id);
    Send(my_id - 1);
    //cout<<"Sent"<<endl;
  }

  if (my_id != N_nodes-1){
    Receive(my_id + 1);
    Todd_end_id = GetLL(my_id + 1);
    Steven_end_id = GetLL(my_id + 1);
    //cout<<"Received"<<endl;
  }
  else{
    Todd_end_id = N_Todd;
    Steven_end_id = N_Steven;
  }
  //cout<<Todd_end_id<<endl;
  //cout<<Steven_end_id<<endl;

  ll my_count = (Todd_end_id - Todd_start_id) + (Steven_end_id - Steven_start_id);
  PutLL(0, my_count);
  Send(0);

  //cout<<my_count<<endl;

  if (my_id == 0){
    ll sum_by_now = 0;
    for (ll i = 0; i < N_nodes; ++ i) {
      PutLL(i, sum_by_now);
      Send(i);

      Receive(i);
      sum_by_now += GetLL(i);
    }
  }

  Receive(0);
  ll count_index = GetLL(0);
  ll next_value = -1;
  ll my_mod_sum = 0;

  ll i_Todd = Todd_start_id;
  ll i_Steven = Steven_start_id;
  ll Todd_head = -1;
  ll Steven_head = -1;
  if (i_Todd < Todd_end_id){
    Todd_head = GetToddValue(i_Todd);
    i_Todd++;
  }
  if (i_Steven < Steven_end_id){
    Steven_head = GetStevenValue(i_Steven);
    i_Steven++;
  }
  while (Steven_head != -1 && Todd_head != -1){
    if (Steven_head < Todd_head){
      next_value = Steven_head;
      if (i_Steven < Steven_end_id){
        Steven_head = GetStevenValue(i_Steven);
        i_Steven++;
      }
      else Steven_head = -1;
    }
    else{
      next_value = Todd_head;
      if (i_Todd < Todd_end_id){
        Todd_head = GetToddValue(i_Todd);
        i_Todd++;
      }
      else Todd_head = -1;
    }
    my_mod_sum = (my_mod_sum + (next_value^count_index)) % MOD;
    count_index ++;
  }
  while (Steven_head != -1){
    next_value = Steven_head;
    if (i_Steven < Steven_end_id){
      Steven_head = GetStevenValue(i_Steven);
      i_Steven++;
    }
    else Steven_head = -1;
    my_mod_sum = (my_mod_sum + (next_value^count_index)) % MOD;
    count_index ++;
  }
  while (Todd_head != -1){
    next_value = Todd_head;
    if (i_Todd < Todd_end_id){
      Todd_head = GetToddValue(i_Todd);
      i_Todd++;
    }
    else Todd_head = -1;
    my_mod_sum = (my_mod_sum + (next_value^count_index)) % MOD;
    count_index ++;
  }

  PutLL(0, my_mod_sum);
  Send(0);

  if (MyNodeId() == 0) {
    ll sum = 0;
    for (ll i = 0; i < N_nodes; ++ i) {
      Receive(i);
      ll t_count = GetLL(i);
      sum = (t_count + sum)%MOD;
    }
    printf("%lld\n", sum);
  }

  return 0;
}
