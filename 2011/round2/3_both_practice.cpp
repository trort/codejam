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

vector<__int64> prime;

void prepare(){
	prime.clear();
	for(__int64 i=2;i<=1000000;i++){
		bool good = true;
		for(int j=0;j<prime.size();j++){
			if(i%prime[j] == 0){
				good = false;
				break;
			}
		}
		//fout<<i<<"\t"<<good<<endl;
		if(good) prime.push_back(i);
	}
	//for(int i=0;i<prime.size();i++) fout<<prime[i]<<endl;
}

void _main(){
	__int64 N;
	fin>>N;
	//fout<<N<<endl;
	if(N == 1){
		fout<<0;
		return;
	}
	int count = 0;
	for(int i=0;i<prime.size();i++){
		int power=0;
		__int64 num = N;
		while(num>=prime[i]){
			num /= prime[i];
			power ++;
		}
		if(power >= 1) count += power-1;
	}
	fout<<count+1;
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    prepare();
    cout<<"Prepare done!\n";
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            _main();
            fout<<endl;
    }
}
