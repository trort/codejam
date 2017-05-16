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
#include "sandwich.h"

using namespace std;

typedef long long ll;

int main() {
  ll N = GetN();
  ll N_nodes = NumberOfNodes();
  ll start_id = N * MyNodeId() / N_nodes;
  ll end_id = N * (MyNodeId() + 1) / N_nodes;

  ll left_sum = 0;
  ll min_sum_from_left = 0;
  ll min_sum_end_here = 0;
  ll min_sum = 0;
  for (ll i = start_id; i < end_id; ++ i){
    ll taste = GetTaste(i);
    left_sum += taste;
    min_sum_from_left = min(min_sum_from_left, left_sum);
    min_sum_end_here = min(min_sum_end_here + taste, taste);
    min_sum = min(min_sum, min_sum_end_here);
  }
  ll total_sum = left_sum;

  ll right_sum = 0;
  ll min_sum_from_right = 0;
  for (ll i = end_id-1; i >= start_id; -- i) {
    right_sum += GetTaste(i);
    min_sum_from_right = min(min_sum_from_right, right_sum);
  }

  //cout<<"Local compute done"<<MyNodeId()<<endl;

  PutLL(0, total_sum);
  PutLL(0, min_sum_from_left);
  PutLL(0, min_sum_from_right);
  PutLL(0, min_sum);
  Send(0);

  if (MyNodeId() == 0) {
    std::vector<ll> seg_sum (N_nodes, 0);
    std::vector<ll> seg_left (N_nodes, 0);
    std::vector<ll> seg_right (N_nodes, 0);
    std::vector<ll> seg_both (N_nodes, 0);

    for (ll i = 0; i < N_nodes; ++i) {
      //cout << "Reading data from " << i << endl;
      Receive(i);
      ll tsum = GetLL(i);
      ll tleft = GetLL(i);
      ll tright = GetLL(i);
      ll tboth = GetLL(i);
      //cout << "Read data done from " << i << endl;
      seg_sum[i] = (tsum);
      seg_left[i] = (tleft);
      seg_right[i] = (tright);
      seg_both[i] = (tboth);
    }

    ll seg_min_sum = 0;
    for (int i = 0 ; i < N_nodes; ++ i) {
      for (int j = i; j < N_nodes; ++ j) {
        if (i == j) {
          seg_min_sum = min(seg_min_sum, seg_both[i]);
        }
        else {
          ll mid_seg_sum = seg_right[i] + seg_left[j];
          for (int k = i + 1; k < j; ++ k) mid_seg_sum += seg_sum[k];
          seg_min_sum = min(seg_min_sum, mid_seg_sum);
        }
      }
    }

    long long total_seg_sum = 0;
    for (int i = 0; i < N_nodes; ++ i) total_seg_sum += seg_sum[i];
    cout<<(total_seg_sum - seg_min_sum)<<endl;
  }
}
