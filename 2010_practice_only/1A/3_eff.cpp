#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const long MAX=1000001;
long begin[MAX],end[MAX];

void prepare(){
     long i,j,k;
     begin[1]=1;end[1]=1;begin[2]=2;
     k=3;
     for(i=1;i<MAX;i++){
                            end[i]=begin[i]+i-1;
                            //cout<<i<<": "<<end[i]<<endl;
                            if(end[i]>=MAX) end[i]=MAX-1;
                            for(;k<=end[i];k++){
                                                begin[k]=i;
                            }
     }
}

int main(){
    prepare();
    ifstream fin;
    ofstream fout;
    fin.open("C-large-practice.in");
    fout.open("result.out");
    int T;
    long A1,A2,B1,B2;
    long temp;
    __int64 count;
    fin>>T;
    long i,j,k;
    for(i=0;i<T;i++){
                     fin>>A1>>A2>>B1>>B2;
                     count = 0;
                     for(j=A1;j<=A2;j++){
                                         temp=min(B2,end[j])-max(B1,begin[j])+1;
                                         if(temp<0) temp=0;
                                         count += B2-B1+1-temp;
                     }
                     
                     fout<<"Case #"<<i+1<<": ";
                     fout<<count;
                     fout<<endl;
    }
}
