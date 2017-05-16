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
#include "pancakes.h"

using namespace std;

typedef long long ll;

int main() {
  ll N = GetStackSize();
  ll N_nodes = NumberOfNodes();
  ll my_id = MyNodeId();
  ll start_id = N * MyNodeId() / N_nodes;
  ll end_id = N * (MyNodeId() + 1) / N_nodes;
  ll previous_end = 0LL;
  if (end_id > start_id && my_id > 0 && start_id > 0)
    previous_end = GetStackItem(start_id - 1);
  ll count = 0;
  for (ll i = start_id; i < end_id; ++ i) {
    ll item = GetStackItem(i);
    if (item < previous_end) count ++;
    previous_end = item;
  }
  PutLL(0, count);
  Send(0);
  // cout << "local process finished" << endl;

  if (MyNodeId() == 0) {
    ll sum = 1;
    for (ll i = 0; i < N_nodes; ++ i) {
      Receive(i);
      ll t_count = GetLL(i);
      sum += t_count;
    }
    printf("%lld\n", sum);
  }

  return 0;
}
