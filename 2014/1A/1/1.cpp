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
    int N,L;
    fin>>N>>L;
    __int64 outlet[155];
    __int64 device[155];
    int i,j,k;
    string temp;
    for(i=0;i<N;i++){
        fin>>temp;
        outlet[i]=0;
        for(j=0;j<L;j++){
            outlet[i] = outlet[i]<<1;
            outlet[i] += temp[j]-'0';
        }
    }
    for(i=0;i<N;i++){
        fin>>temp;
        device[i]=0;
        for(j=0;j<L;j++){
            device[i] = device[i]<<1;
            device[i] += temp[j]-'0';
        }
    }
    int min = L+1;
    for(i=0;i<N;i++){
        __int64 control = outlet[0] ^ device[i];
        bool poss = true;
        for(j=1;j<N;j++){
            bool found = false;
            for(k=0;k<N;k++){
                if(device[k] == (outlet[j]^control)){
                    found = true;
                    break;
                }
            }
            if(!found){
                poss = false;
                break;
            }
        }
        if(poss){
            int c=0;
            for(j=0;j<L;j++){
                if(control & ((__int64)1<<j)) c++;
            }
            //fout<<i<<" "<<c<<endl;
            if(c<min) min = c;
        }
    }
    if(min>L) fout<<"NOT POSSIBLE";
    else fout<<min;
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
