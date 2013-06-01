#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

int prime[1000001];
int C=1;

void prepare(){
     int i,j,k;
     prime[0]=2;
     //count=1;
     bool p;
     for (i=3;i<1000001;i++){
         p=1;
         for (j=0;p==1 && j<C;j++){
             if (i%prime[j] == 0) p=0;
         }
         if(p){
               prime[C]=i;
               C++;
         }
     }
     cout<<"prepare done"<<endl;
     return;
}

void _main(){
     __int64 N,NN;
     fin>>N;
     if(N==1){
              fout<<0;
              return;
     }
     int i,j,k;
     int p;
     __int64 spread=1;
     
     for (i=0;i<C;i++){
         p=0;
         NN=N;
         while(NN>=prime[i]){
                             p++;
                             NN /= prime[i];
         }
         if(p>1) spread += (p-1);
     }
     
     fout<<spread;
     return;
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    prepare();
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            _main();
            fout<<endl;
    }
}
