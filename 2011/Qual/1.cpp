#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main(){
    ifstream fin;
    fin.open("A-large.in");
    ofstream fout;
    fout.open("result.out");
    int T,N,P;
    char R;
    fin>>T;
    int i,j,k;
    int time,o_pos,b_pos;
    char lane;
    int t_need,t_have;
    for(i=0;i<T;i++){
                     fin>>N;
                     time=0;o_pos=1;b_pos=1;
                     lane='N';
                     t_have=0;
                     for(j=0;j<N;j++){
                                      fin>>R>>P;
                                      if(R == 'O'){
                                           t_need = abs(P - o_pos) + 1;
                                           o_pos=P;
                                      }
                                      else{
                                           t_need = abs(P - b_pos) + 1;
                                           b_pos=P;
                                      }
                                      
                                      if(R == lane){
                                           time += t_need;
                                           t_have += t_need;
                                      }
                                      else{
                                           if(t_need > t_have){
                                                     time += t_need - t_have;
                                                     t_have = t_need - t_have;
                                           }
                                           else{
                                                time += 1;
                                                t_have = 1;
                                           }
                                      }
                                      lane=R;
                     }
                     fout<<"Case #"<<i+1<<": "<<time<<endl;
    }
}
