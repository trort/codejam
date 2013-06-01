#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

int _main(){
	int N, S, p;
	int score[101];
	int i;
	int sat_limit;
	int surp_limit;
	int sat_num = 0;
	int surp_num = 0;
	
	fin>>N>>S>>p;
	if(p >= 2){
	    sat_limit = 3*p-2;
	    surp_limit = 3*p-4;
	}
	else if(p == 1){
		sat_limit = 1;
		surp_limit = 1;
	}
	else if(p == 0){
		sat_limit = 0;
		surp_limit = 0;
	}
	for(i = 0; i < N; i++){
		fin>>score[i];
		if(score[i]>=sat_limit) sat_num++;
		else if(score[i]>=surp_limit) surp_num++;
	}
	return sat_num + min(surp_num,S);
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            fout<<_main();
            fout<<endl;
    }
}
