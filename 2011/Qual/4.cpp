#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("D-large.in");
    fout.open("result.out");
    int T,N;
    int Data[1002];
    bool mark[1002];
    int time,count,index;
    int i,j,k;
    fin>>T;
    for(i=0;i<T;i++){
                     fin>>N;
                     for(j=1;j<=N;j++) fin>>Data[j];
                     for(j=1;j<=N;j++) mark[j]=0;
                     time = 0;
                     for(j=1;j<=N;j++){
                                      if(!mark[j]){
                                                   mark[j]=1;
                                                   //count=0;
                                                   if(Data[j]==j) continue;
                                                   else{
                                                        index=Data[j];
                                                        count=1;
                                                        while(index!=j){
                                                                        mark[index]=1;
                                                                        count++;
                                                                        index=Data[index];
                                                        }
                                                        time += count;
                                                   }
                                      }
                     }
                     fout<<"Case #"<<i+1<<": "<<time<<".000000"<<endl;
    }
}
