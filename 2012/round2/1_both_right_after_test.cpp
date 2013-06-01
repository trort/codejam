#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

__int64 larger(__int64 a, __int64 b){
    if(a>b) return a;
    else return b;
}
/*
bool swing(__int64 pos, __int64 vine){
	__int64 max = d[vine]-pos + d[vine];
	if(D<=max) return 1;
	else if(vine+1<N && d[vine+1]>max) return 0;
	else{
		__int64 index = vine+1;
		while(index<N && max>=d[index]){
			__int64 start = larger(d[vine],d[index]-l[index]);
			if(swing(start,index)) return 1;
			else index++;
		}
		return 0;
	}
}
*/
void _main(){
	__int64 i,j,k;
	
	__int64 N,D;
	__int64 d[10002],l[10002];
	
	fin>>N;
	for(i=0;i<N;i++) fin>>d[i]>>l[i];
	fin>>D;
	
	//if(swing(0,0)) fout<<"YES";
	//else fout<<"NO";
	
	__int64 pos[10002];
	for(i=0;i<N;i++) pos[i]=-1;
	pos[0] = 0;
	bool done = false;
	for(i=0;i<N;i++){
		if(pos[i]==-1){
			//fout<<"vine "<<i<<" cannot reach"<<endl;
			break;
		}
		__int64 max = d[i]-pos[i] + d[i];
		if(D<=max) done = true;
		__int64 index = i+1;
		while(index<N && max>=d[index]){
			if(pos[index]==-1) pos[index] = larger(d[i],d[index]-l[index]);
			index++;
		}
	}
	
	if(done) fout<<"YES";
	else fout<<"NO";
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    __int64 T;
    fin>>T;
    for(__int64 i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            _main();
            fout<<endl;
    }
}
