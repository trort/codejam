#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<sstream>
#include<vector>
#include<cstdlib>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

void _main(){
	__int64 N,D;
	__int64 d[10005],l[10005];
	int i,j,k;
	fin>>N;
	for(i=0;i<N;i++) fin>>d[i]>>l[i];
	fin>>D;
	
	__int64 reach[10005];
	for(i=0;i<N;i++) reach[i]=0;
	reach[0]=2*d[0];
	for(i=0;i<N-1;i++){
		for(j=i+1;d[j]<=reach[i];j++){
			reach[j]=max(reach[j],min(d[j]+l[j],d[j]+(d[j]-d[i])));
		}
	}
	for(i=0;i<N;i++){
		if(reach[i]>=D){
			fout<<"YES";
			return;
		}
	}
	fout<<"NO";
	return;
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
