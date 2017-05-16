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

float avg=0.0;
int inv[130];

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int c=0;c<T;c++){
            cout<<"Case #"<<c+1<<" is runing"<<endl;

                int N;
                int i,j,k;
                int a[1005];
                fin>>N;
                inv[c]=0;

                for(i=0;i<N;i++){
                    fin>>a[i];
                }
                for(i=0;i<N;i++){
                        if(a[i]<i) inv[c]++;
                }
                avg += inv[c];

    }
    int count = 0;
    avg /= T;
    for(int c=0;c<T;c++){
            fout<<"Case #"<<c+1<<": ";
            //fout<<inv[c]<<endl;
            if(inv[c]<avg) {fout<<"BAD"<<endl;count++;}
            else if(inv[c]>avg) fout<<"GOOD"<<endl;
            else{
                float k = float(rand())/RAND_MAX;
            //cout<<k<<endl;
                if(k<(avg-240000)/10000.0) {fout<<"BAD"<<endl;count++;}
                else fout<<"GOOD"<<endl;
            }
    }
    cout<<count<<endl;
    cout<<avg<<endl;
}
