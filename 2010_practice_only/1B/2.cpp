#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("B-small-practice.in");
    fout.open("result.out");
    int C,N,K,B,T;
    int X[51],V[51];
    bool reach[51];
    int pass[51];
    int pass2[51];
    fin>>C;
    int i,j,k;
    int pick,end;
    for(i=0;i<C;i++){
                     fin>>N>>K>>B>>T;
                     for(j=0;j<N;j++) fin>>X[j];
                     for(j=0;j<N;j++) fin>>V[j];
                     
                     for(j=0;j<N;j++) reach[j]=(X[j]+V[j]*T>=B);
                     int pass_pre=0;
                     int tot=0;
                     for(j=N-1;j>=0;j--){
                                         pass[j]=pass_pre;
                                         if(!reach[j]) pass_pre++;
                                         else tot++;
                     }
                     
                     for(j=0;j<N;j++){
                                      pass2[j]=0;
                                      for(k=j+1;k<N;k++){
                                                       pass2[j] += !reach[k];
                                      }
                     }
                     
                     
                     end=0;
                     pick=0;
                     for(j=N-1;j>=0 && end<K;j--){
                                         if(reach[j]){
                                                      end++;
                                                      pick += pass2[j];
                                         }
                     }
                     
                     fout<<"Case #"<<i+1<<": ";
                     if(tot<K) fout<<"IMPOSSIBLE";
                     else fout<<pick;
                     fout<<endl;
    }
}
