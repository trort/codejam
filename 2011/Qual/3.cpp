#include<iostream>
#include<fstream>
using namespace std;

int main(){
    int T,N,C;
    ifstream fin;
    fin.open("C-large.in");
    ofstream fout;
    fout.open("result.out");
    fin>>T;
    int i,j,k;
    //bool ok;
    int min,sum,check;
    for(i=1;i<=T;i++)
    {
                     fin>>N;
                     //ok=false;
                     min=9999999;
                     check=0;
                     sum=0;
                     for(k=0;k<N;k++)
                     {
                                     fin>>C;
                                     if(C < min) min = C;
                                     check = check ^ C;
                                     sum += C;
                     }
                     fout<<"Case #"<<i<<": ";
                     if(check) fout<<"NO";
                     else fout<<sum-min;
                     fout<<endl;
    }
    //cin>>T;
}
