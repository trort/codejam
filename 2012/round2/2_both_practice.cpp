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

struct Node{
	int r;
	int num;
	double x,y;
};

int large_size(const void * a, const void * b)
{
  return -((*(Node*)a).r - (*(Node*)b).r);
}

int small_num(const void * a, const void * b)
{
  return ((*(Node*)a).num - (*(Node*)b).num);
}

void _main(){
	int W,L,N;
	fin>>N>>W>>L;
	Node node[1005];
	int i,j,k;
	for(i=0;i<N;i++){
		fin>>node[i].r;
		node[i].num = i;
	}
	
	qsort(node,N,sizeof(Node),large_size);
	for(i=0;i<N;i++){
		bool good = false;
		while(!good){
			node[i].x = double(rand())/double(RAND_MAX) * double(W);
			node[i].y = double(rand())/double(RAND_MAX) * double(L);
			good = true;
			for(j=0;j<i;j++){
				if(pow(double(node[i].x-node[j].x),2)+pow(double(node[i].y-node[j].y),2)<=pow(double(node[i].r+node[j].r),2)){
					good = false;
					break;
				}
			}
		}
	}
	qsort(node,N,sizeof(Node),small_num);
	for(i=0;i<N;i++){
		fout<<" "<<node[i].x<<" "<<node[i].y;
	}
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
