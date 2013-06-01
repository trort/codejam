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

struct Node{
	__int64 o,e,p;
};

void _main(){
	int N,M;
	fin>>N>>M;
	int i,j,k;
	vector<Node> stop;
	stop.clear();
	__int64 count=0;
	for(i=0;i<M;i++){
		Node temp;
		fin>>temp.o>>temp.e>>temp.p;
		stop.push_back(temp);
	}
	for(i=0;i<stop.size();i++){
		Node temp=stop[i];
		for(j=0;j<i;j++){
			//fout<<i<<" "<<j<<endl;
			//fout<<temp.o<<" "<<temp.e<<" "<<stop[j].o<<" "<<stop[j].e<<endl;
			if(temp.o>stop[j].o && temp.o<=stop[j].e && temp.e>stop[j].e){
				int overlap = min(temp.p,stop[j].p);
				temp.p -= overlap;
				stop[j].p -= overlap;
				
				Node add;
				add.o=stop[j].o;
				add.e=temp.e;
				add.p=overlap;
				if(add.p>0) stop.push_back(add);
				add.o=temp.o;
				add.e=stop[j].e;
				add.p=overlap;
				if(add.p>0) stop.push_back(add);
				
				count += ((temp.o-stop[j].o)*(temp.e-stop[j].e)*overlap)%1000002013;
				//fout<<i<<endl;
				//fout<<temp.o<<" "<<temp.e<<" "<<temp.p<<" "<<stop[j].o<<" "<<stop[j].e<<" "<<stop[j].p<<endl;
				
				if(stop[j].p == 0){
					stop.erase(stop.begin()+j);
					j--;
					i--;	//the line i failed to realize during test
				}
			}
			else if(temp.o<stop[j].o && temp.e>=stop[j].o && temp.e<stop[j].e){
				int overlap = min(temp.p,stop[j].p);
				temp.p -= overlap;
				stop[j].p -= overlap;
				
				Node add;
				add.o=stop[j].o;
				add.e=temp.e;
				add.p=overlap;
				if(add.p>0) stop.push_back(add);
				add.o=temp.o;
				add.e=stop[j].e;
				add.p=overlap;
				if(add.p>0) stop.push_back(add);
				
				count += ((temp.o-stop[j].o)*(temp.e-stop[j].e)*overlap)%1000002013;
				//fout<<i<<endl;
				
				if(stop[j].p == 0){
					stop.erase(stop.begin()+j);
					j--;
					i--;	//the line i failed to realize during test
				}
			}
		}
		stop[i]=temp;
		if(stop[i].p == 0){
			stop.erase(stop.begin()+i);
			i--;
		}
		//fout<<temp.p<<endl;
	}
	fout<<count;
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
