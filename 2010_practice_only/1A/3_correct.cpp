// correct one

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

//using namespace std;

const long long MAX=1000001;
long long begin[MAX],end[MAX];

void prepare(){
     long long i,j,k;
     begin[1]=1;
     end[1]=1;
     begin[2]=2;
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
    std::ifstream fin;
    std::ofstream fout;
    fin.open("C-large-practice.in");
    fout.open("result.out");
    int T;
    long long A1,A2,B1,B2;
    long long temp;
    __int64 count;
    fin>>T;
    long long i,j,k;
    for(i=0;i<T;i++){
                     fin>>A1>>A2>>B1>>B2;
                     count = 0;
                     for(j=A1;j<=A2;j++){
                                         temp=std::min(B2,end[j])-std::max(B1,begin[j])+1;
                                         if(temp<0) temp=0;
                                         count += B2-B1+1-temp;
                     }

                     fout<<"Case #"<<i+1<<": ";
                     fout<<count;
                     fout<<std::endl;
    }
}
