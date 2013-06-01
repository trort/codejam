#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const int INF=99999999;

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("B-large-practice.in");
    fout.open("result.out");
    int T,D,I,M,N;
    int a[101];
    int cost[101][256];
    int mod,ins;
    int best;
    fin>>T;
    int i,j,k,l;
    for(i=0;i<T;i++){
                     fin>>D>>I>>M>>N;
                     for(j=0;j<N;j++) fin>>a[j];
                     
                     for(k=0;k<256;k++){
                                        cost[0][k]=min(D,abs(k-a[0]));
                     }
                     
                     for(j=1;j<N;j++) for(k=0;k<256;k++){
                                      best=INF;
                                      mod=abs(k-a[j]);
                                      for(l=0;l<256;l++){
                                                         if(abs(k-l)<=M) ins=0;
                                                         else if(M==0) ins=INF;
                                                         else ins=((abs(k-l)-1)/M)*I;
                                                         if(best>cost[j-1][l]+ins+mod) best=cost[j-1][l]+ins+mod;
                                      }
                                      if(best>cost[j-1][k]+D) best=cost[j-1][k]+D;
                                      
                                      cost[j][k]=best;
                     }
                     
                     fout<<"Case #"<<i+1<<": ";
                     best=INF;
                     for(k=0;k<256;k++){
                                        if(best>cost[N-1][k]) best=cost[N-1][k];
                     }
                     fout<<best;
                     fout<<endl;
    }
}
