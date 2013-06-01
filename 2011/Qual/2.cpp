#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fin;
    fin.open("B-large.in");
    ofstream fout;
    fout.open("result.out");
    int T,C,D,N;
    char combine[256][256];
    bool d_kill[256][256];
    char temp[3];
    char Ele;
    char invoke[101];
    char final[101];
    int index;
    fin>>T;
    int i,j,k;
    for(i=0;i<T;i++){
                     memset(combine,0,256*256*sizeof(char));
                     memset(d_kill,0,256*256*sizeof(bool));
                     memset(final,'\0',101*sizeof(char));
                     
                     fin>>C;
                     for(j=0;j<C;j++){
                                      fin>>temp;
                                      combine[temp[0]][temp[1]]=temp[2];
                                      combine[temp[1]][temp[0]]=temp[2];
                     }
                     
                     fin>>D;
                     for(j=0;j<D;j++){
                                      fin>>temp;
                                      d_kill[temp[0]][temp[1]]=1;
                                      d_kill[temp[1]][temp[0]]=1;
                     }
                     
                     fin>>N;
                     fin>>invoke;
                     index=0;
                     for(j=0;j<N;j++){
                                      Ele=invoke[j];
                                      final[index++]=Ele;
                                      
                                      if(index>1){
                                                  if(combine[final[index-2]][Ele]){
                                                                                   final[index-2] = combine[final[index-2]][Ele];
                                                                                   Ele = final[index-2];
                                                                                   index -= 1;
                                                  }
                                                  for(k=0;k<index;k++){
                                                                       if(d_kill[final[k]][Ele]) index=0;
                                                  }
                                      }
                     }
                     
                     fout<<"Case #"<<i+1<<": [";
                     for(k=0;k < index-1;k++) fout<<final[k]<<", ";
                     if(index>0) fout<<final[index-1];
                     fout<<"]"<<endl;
    }
}
                     
