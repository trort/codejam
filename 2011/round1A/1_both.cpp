#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int gcd(int x,int y){
    int t;
    if(x>y){
            t=x;
            x=y;
            y=t;
    }
    int r=y%x;
    if(r==0) return x;
    else return gcd(r,x);
}

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("A-large.in");
    fout.open("result.out");
    int T;
    fin>>T;
    int i,j,k;
    int PD,PG;
    __int64 N;
    
    for(i=0;i<T;i++){
                     fin>>N>>PD>>PG;
                     
                     fout<<"Case #"<<i+1<<": ";
                     
                     if(PG==0 && PD!=0) fout<<"Broken";
                     else if(PG==100 && PD!=100) fout<<"Broken";
                     else if(PD==0) fout<<"Possible";
                     else{
                          if(100/gcd(PD,100)>N) fout<<"Broken";
                          else fout<<"Possible";
                     }
                     
                     fout<<endl;
    }
}
