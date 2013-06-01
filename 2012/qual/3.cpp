#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

int _main(){
	int A, B, n, m;
	fin>>A>>B;
	
	int i,j,k,l,shift;
	int count = 0;
	int recyc[11];
	int recycled;
	bool good;
	string input, output;
	for(i=A; i<=B; i++){
		n = i;
		recycled = 0;
		stringstream temp;
		temp<<n;
		input = temp.str();
		l = input.length();
		output.resize(l);
		for(shift=1; shift<l; shift++){
			for(j=0; j<l; j++){
				output[j] = input[(j+l-shift)%l];
			}
			istringstream buffer(output);
			buffer>>m;
			if(m>=A && m>n && m<=B){
				good = true;
				for(k=0; k<recycled; k++){
					if(m == recyc[k]){
						good = false;
						break;
					}
				}
				if(good){
					count++;
					recyc[recycled++] = m;
				}
			}
		}
	}
	return count;
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
