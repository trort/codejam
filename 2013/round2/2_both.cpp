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
	int N;
	unsigned __int64 P;
	fin>>N>>P;
	if(P == (unsigned __int64)1<<N){
		fout<<P-1<<" "<<P-1;
		return;
	}
	unsigned __int64 grant,poss;
	unsigned __int64 total = ((unsigned __int64)1<<N)-1;
	
	//grant
	int index=0;
	for(int i=N-1;i>=0;i--){
		if(!((P-1) & ((unsigned __int64)1<<i))){
               //fout<<i<<endl;
			index = N-i;
			break;
		}
	}
	//fout<<index<<endl;
	grant =0;
	for(int i=0;i<index;i++){
		grant += ((unsigned __int64)1<<i);
	}
	grant = grant -1;
	
	//poss
	index=0;
	for(int i=N;i>=0;i--){
		if(P & ((unsigned __int64)1<<i)){
			index = N-i-1;
			break;
		}
	}
	poss =0;
	for(int i=0;i<=index;i++){
		poss += ((unsigned __int64)1<<i);
	}
	poss = total - poss;
	fout<<grant<<" "<<poss;
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
