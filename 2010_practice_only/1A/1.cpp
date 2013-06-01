#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int T,K,N;
char mat[51][51];

int checkblue(){
    int i,j,k;
    bool line;
    for(i=0;i<N;i++) for(j=0;j<N;j++){
                     if(mat[i][j] == 'B'){
                                  if(j+K<=N){
                                             line = true;
                                             for(k=1;k<K;k++){
                                                              if(mat[i][j+k] != 'B'){
                                                                             line = false;
                                                                             break;
                                                              }
                                             }
                                             if(line) return 1;
                                  }
                                  
                                  if(i+K<=N){
                                             line = true;
                                             for(k=1;k<K;k++){
                                                              if(mat[i+k][j] != 'B'){
                                                                             line = false;
                                                                             break;
                                                              }
                                             }
                                             if(line) return 1;
                                  }
                                  
                                  if(j+K<=N && i+K<=N){
                                             line = true;
                                             for(k=1;k<K;k++){
                                                              if(mat[i+k][j+k] != 'B'){
                                                                             line = false;
                                                                             break;
                                                              }
                                             }
                                             if(line) return 1;
                                  }
                                  
                                  if(j>=K-1 && i+K<=N){
                                             line = true;
                                             for(k=1;k<K;k++){
                                                              if(mat[i+k][j-k] != 'B'){
                                                                             line = false;
                                                                             break;
                                                              }
                                             }
                                             if(line) return 1;
                                  }
                     }
    }
    return 0;
}

int checkred(){
    int i,j,k;
    bool line;
    for(i=0;i<N;i++) for(j=0;j<N;j++){
                     if(mat[i][j] == 'R'){
                                  if(j+K<=N){
                                             line = true;
                                             for(k=1;k<K;k++){
                                                              if(mat[i][j+k] != 'R'){
                                                                             line = false;
                                                                             break;
                                                              }
                                             }
                                             if(line) return 2;
                                  }
                                  
                                  if(i+K<=N){
                                             line = true;
                                             for(k=1;k<K;k++){
                                                              if(mat[i+k][j] != 'R'){
                                                                             line = false;
                                                                             break;
                                                              }
                                             }
                                             if(line) return 2;
                                  }
                                  
                                  if(j+K<=N && i+K<=N){
                                             line = true;
                                             for(k=1;k<K;k++){
                                                              if(mat[i+k][j+k] != 'R'){
                                                                             line = false;
                                                                             break;
                                                              }
                                             }
                                             if(line) return 2;
                                  }
                                  
                                  if(j>=K-1 && i+K<=N){
                                             line = true;
                                             for(k=1;k<K;k++){
                                                              if(mat[i+k][j-k] != 'R'){
                                                                             line = false;
                                                                             break;
                                                              }
                                             }
                                             if(line) return 2;
                                  }
                     }
    }
    return 0;
}

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("A-large-practice.in");
    fout.open("result.out");
    //int T,K,N;
    fin>>T;
    char v[51][51];
    //char mat[51][51];
    int ans;
    int i,j,k,l;
    for(i=0;i<T;i++){
                     fin>>N>>K;
                     for(j=0;j<N;j++){
                                      fin>>v[j];
                                      l=0;
                                      for(k=N-1;k>=0;k--){
                                                          if(v[j][k]!='.') mat[j][l++] = v[j][k];
                                      }
                                      for(;l<N;l++) mat[j][l] = '.';
                     }
                     
                     ans = checkblue() + checkred();
                     
                     fout<<"Case #"<<i+1<<": ";
                     if(ans == 0) fout<<"Neither";
                     else if (ans == 1) fout<<"Blue";
                     else if (ans == 2) fout<<"Red";
                     else if (ans == 3) fout<<"Both";
                     //fout<<
                     fout<<endl;
    }
}
