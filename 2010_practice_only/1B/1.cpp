#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string dir[100000];
int dir_s;

bool check(string s){
    int i;
    for(i=0;i<dir_s;i++){
                         if(s.compare(dir[i])==0) return 0;
    }
    return 1;
}

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("A-large-practice.in");
    fout.open("result.out");
    int T;
    fin>>T;
    int i,j,k;
    int N,M;
    string line;
    string needed;
    int index,count;
    for(i=0;i<T;i++){
                     dir_s=0;
                     count=0;
                     fin>>N>>M;
                     for(j=0;j<N;j++){
                                      fin>>line;
                                      //length=line.length();
                                      index=line.find('/',1);
                                      while(index!=-1){
                                              if(check(line.substr(0,index))) dir[dir_s++]=line.substr(0,index);
                                              index=line.find('/',index+1);
                                      }
                                      if(check(line)) dir[dir_s++]=line;
                     }
                     
                     for(j=0;j<M;j++){
                                      fin>>line;
                                      index=line.find('/',1);
                                      while(index!=-1){
                                              needed=line.substr(0,index);
                                              if(check(needed)){
                                                                count++;
                                                                dir[dir_s++]=line.substr(0,index);
                                              }
                                              index=line.find('/',index+1);
                                      }
                                      needed=line;
                                      if(check(needed)){
                                                        count++;
                                                        dir[dir_s++]=needed;
                                      }
                     }
                     
                     fout<<"Case #"<<i+1<<": ";
                     fout<<count;
                     fout<<endl;
    }
}
