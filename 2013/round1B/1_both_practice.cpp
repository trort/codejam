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

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void _main(){
	int A,N;
	int mote[105];
	fin>>A>>N;
	int i,j,k;
	for(i=0;i<N;i++){
		fin>>mote[i];
	}
	qsort(mote,N,sizeof(int),compare);
	
	int count = 0;
	int ans = N;
	for(i=0;i<N;i++){
		if(mote[i]<A) A += mote[i];
		else{
			if(A<=1){
				count += N-i;
				ans = min(ans,count);
				break;
			}
			int add = 0;
			while(A<=mote[i]){
				add++;
				A += A-1;
			}
			//fout<<i<<" "<<add<<endl;
			if(N-i>add){
				count += add;
				A += mote[i];
			}
			else{
				count += N-i;
				ans = min(ans,count);
				break;
			}
		}
	}
	fout<<min(count,ans);
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
