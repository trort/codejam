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
	int N;
	int x[2005];
	fin>>N;
	int i,j,k;
	for(i=1;i<=N-1;i++){
		fin>>x[i];
	}
	
	//check
	for(i=1;i<N;i++){
		for(j=i+1;j<x[i];j++){
			if(x[j]>x[i]){
				fout<<" Impossible";
				return;
			}
		}
	}
	cout<<"check!\n";
	
	//give
	int h[2005],slope[2005];
	const int LIMIT = 99999999;
	for(i=1;i<=N;i++) h[i]=-1;
	for(i=1;i<=N;i++) slope[i]=0;
	
	slope[1]=0;
	for(i=1;i<N;i++){
		for(j=i+1;j<x[i];j++){
			slope[j]=slope[i]+1;
		}
	}
	cout<<"slope!\n";
	
	h[N]=LIMIT/2;
	for(i=N;i>=1;i--){
		for(j=1;j<i;j++){
			if(x[j]==i){
				h[j] = h[i]-slope[j]*(i-j);
			}
		}
	}
	cout<<"height!\n";
	
	//output
	for(i=1;i<=N;i++) fout<<" "<<h[i];
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<":";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            _main();
            fout<<endl;
    }
}
