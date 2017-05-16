// OOM error
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const int MAX = 1000001;
bool win[1000001][1000001];

void prepare(){
     int i,j,k;
     bool bwin;
     for (i=1;i<MAX;i++) win[i][i]=0;
     for (i=2;i<MAX;i++) win[1][i]=win[i][1]=1;
     for (i=2;i<MAX;i++) for(j=i+1;j<MAX;j++){
         bwin=1;
         for(k=1;i*k<j;k++){
                            bwin = bwin && win[j-i*k][i];
         }
         if(bwin) win[i][j]=win[j][i]=0;
         else win[i][j]=win[j][i]=1;
     }
}

int main(){
    prepare();

    ifstream fin;
    ofstream fout;
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    int A1,A2,B1,B2;
    int count;
    fin>>T;
    int i,j,k;
    for(i=0;i<T;i++){
                     fin>>A1>>A2>>B1>>B2;
                     count = 0;
                     for(j=A1;j<=A2;j++) for(k=B1;k<=B2;k++){
                                         if(win[j][k]) count++;
                     }

                     fout<<"Case #"<<i+1<<": ";
                     fout<<count;
                     fout<<endl;
    }
}
