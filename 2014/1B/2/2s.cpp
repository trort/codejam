// slow algorithm. Good enough for small set, not for large one

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<ctime>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

void _main(){
    unsigned int A,B,K;
    fin>>A>>B>>K;
    unsigned int i,j;
    int count=0;
    for(i=0;i<A;i++) for(j=0;j<B;j++){
        if((i&j)<K){
            count++;
            //fout<<i<<" "<<j<<endl;
        }
    }
    fout<<count;
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            _main();
            fout<<endl;
    }
}
