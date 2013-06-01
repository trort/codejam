#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

string _main(){
       string R="";
       int i,j,k;
       int P;
       int M[1030];
       int price[11][1030];
       //input
       fin>>P;
       int N=(1<<P);
       for(i=0;i<N;i++) fin>>M[i];
       for(i=P;i>0;i--) for(j=0;j<(1<<(i-1));j++) fin>>price[i][j];
       //initail
       bool mark[11][1030];
       for(i=P;i>0;i--) for(j=0;j<(1<<(i-1));j++) mark[i][j]=0;
       long count = 0;
       //calc
       for (i=0;i<N;i++){
           for (j=0;j<(P-M[i]);j++){
               if (mark[j+1][(i>>(P-j))]==0){
                  mark[j+1][(i>>(P-j))]=1;
                  count+=price[j+1][(i>>(P-j))];
               }
           }
       }
       fout<<count;
       return R;
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            fout<<_main();
            fout<<endl;
    }
}
