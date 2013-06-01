#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string dict[10001];
string list[101];
int pt[10001];
bool die[10001];
int N,M;

void prepare(int list_num){
    string seq=list[list_num];
    int i,j,k;
    string word;
    int L;
    char letter;
    int point;
    int index,index_pre;
    
    bool possible;
    
    for(i=0;i<N;i++){
                     word=dict[i];
                     L=word.length();
                     point=0;
                     for(j=0;j<N;j++){
                                      if(dict[j].length()==L) die[j]=0;
                                      else die[j]=1;
                     }
                     die[i]=0;
                     
                     for(j=0;j<26;j++){
                                       letter=seq.at(j);
                                       possible = 0;
                                       for(k=0;k<N;k++){
                                                        if(die[k]) continue;
                                                        if(dict[k].find(letter)!=-1){
                                                                                     possible=1;
                                                                                     break;
                                                        }
                                       }
                                       if(!possible) continue;
                                       else{//letter possible
                                            if(word.find(letter)==-1){//not there
                                                                      point++;
                                                                      for(k=0;k<N;k++){
                                                                                       if(die[k]) continue;
                                                                                       if(dict[k].find(letter)!=-1) die[k]=1;
                                                                      }
                                            }
                                            else{//there
                                                 index=word.find(letter);
                                                 index_pre=-1;
                                                 while(index!=-1){
                                                                  for(k=0;k<N;k++){
                                                                                   if(die[k]) continue;
                                                                                   if(dict[k].at(index)!=letter) die[k]=1;
                                                                                   if(index>index_pre){
                                                                                                       if(dict[k].find(letter,index_pre+1)!=index) die[k]=1;
                                                                                   }
                                                                  }
                                                                  index_pre=index;
                                                                  index=word.find(letter,index+1);
                                                 }
                                                 for(k=0;k<N;k++){
                                                                  if(die[k]) continue;
                                                                  if(dict[k].find(letter,index_pre+1)!=index) die[k]=1;
                                                 }
                                            }
                                       }//end possible
                     }
                     pt[i]=point;
    }// i
}

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("sample.in");
    fout.open("output.out");
    int T;
    fin>>T;
    int i,j,k;
    int max,index;
    for(i=0;i<T;i++){
                     fin>>N>>M;
                     for(j=0;j<N;j++) fin>>dict[j];
                     for(j=0;j<M;j++) fin>>list[j];
                     
                     fout<<"Case #"<<i+1<<":";
                     for(j=0;j<M;j++){
                                      prepare(j);
                                      fout<<" ";
                                      max=-1;index=-1;
                                      for(k=0;k<N;k++){
                                                       if(pt[k]>max){
                                                                     max=pt[k];
                                                                     index=k;
                                                       }
                                      }
                                      fout<<dict[index];
                     }
                     fout<<endl;
    }
}
