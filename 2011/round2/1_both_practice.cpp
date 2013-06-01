#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<iomanip>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

struct Node{
	int w,L;
};

int compare (const void * a, const void * b)
{
  return ( (*(Node*)a).w - (*(Node*)b).w );
}

void _main(){
	int X,S,R,N;
	double t;
	fin>>X>>S>>R>>t>>N;
	int i,j,k;
	int B,E;
	Node way[1005];
	for(i=0;i<N;i++){
		fin>>B>>E>>way[i].w;
		way[i].L = E-B;
	}
	qsort(way,N,sizeof(Node),compare);
	
	double time = 0.0;
	double temp;
	for(i=0;i<N;i++) X -= way[i].L;
	temp = double(X)/double(R);
	if(temp>t){
		time += t + (X-t*double(R))/S;
		t -= t;
	}
	else{
		time += temp;
		t -= temp;
	}
	for(i=0;i<N;i++){
		temp = double(way[i].L)/double(R+way[i].w);
		if(temp>t){
			time += t + (way[i].L-t*double(R+way[i].w))/(S+way[i].w);
			t -= t;
		}
		else{
			time += temp;
			t -= temp;
		}
	}
	fout<<setprecision(9)<<time;
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
