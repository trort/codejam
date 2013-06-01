#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

struct Node{
	__int64 order,x,y,r;
};

int r_comp(const void * x,const void * y){
    return -(((Node *)x)->r-((Node *)y)->r);
}

int order_comp(const void * x,const void * y){
    return ((Node *)x)->order-((Node *)y)->order;
}

__int64 long_rand(){
	__int64 re=0;
	re += rand();
	re <<= 15;
	re += rand();
	return re;
}

void _main(){
	__int64 N,W,L;
	Node stu[1002];
	__int64 i,j,k;
	fin>>N>>W>>L;
	for(i=0;i<N;i++){
		stu[i].order = i;
		fin>>stu[i].r;
	}
	
	qsort(stu,N,sizeof(Node),r_comp);
	
	__int64 x_try,y_try;
	for(i=0;i<N;i++){
	                 //cout<<"No "<<i<<" running, r = "<<stu[i].r<<endl;
		while(1){
			x_try = long_rand()%W;
			y_try = long_rand()%L;
			bool pass = true;
			for(j=0;j<i;j++){
				//int test=(x[j]-x_try)*(x[j]-x_try)+(y[j]-y_try)*(y[j]-y_try)-(r[i]+r[j])*(r[i]+r[j]);
				//fout<<test<<endl;
				if((stu[j].x-x_try)*(stu[j].x-x_try)+(stu[j].y-y_try)*(stu[j].y-y_try)<(stu[i].r+stu[j].r)*(stu[i].r+stu[j].r)){
					pass = false;
					break;
				}
			}
			if(pass){
				stu[i].x=x_try;
				stu[i].y=y_try;
				break;
			}
		}

	}
	
	qsort(stu,N,sizeof(Node),order_comp);
	
	for(i=0;i<N;i++) fout<<" "<<stu[i].x<<" "<<stu[i].y;
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
