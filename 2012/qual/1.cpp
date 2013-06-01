#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

string _main(){
	string inputline;
	string outputline;
	getline(fin,inputline);
	int i,l=inputline.length();
	outputline.resize(l);
	for(i=0; i<l; i++){
		switch(inputline[i]){
			case 'y':
				outputline[i]='a';
			break;
			case 'n':
				outputline[i]='b';
			break;
			case 'f':
				outputline[i]='c';
			break;
			case 'i':
				outputline[i]='d';
			break;
			case 'c':
				outputline[i]='e';
			break;
			case 'w':
				outputline[i]='f';
			break;
			case 'l':
				outputline[i]='g';
			break;
			case 'b':
				outputline[i]='h';
			break;
			case 'k':
				outputline[i]='i';
			break;
			case 'u':
				outputline[i]='j';
			break;
			case 'o':
				outputline[i]='k';
			break;
			case 'm':
				outputline[i]='l';
			break;
			case 'x':
				outputline[i]='m';
			break;
			case 's':
				outputline[i]='n';
			break;
			case 'e':
				outputline[i]='o';
			break;
			case 'v':
				outputline[i]='p';
			break;
			case 'z':
				outputline[i]='q';
			break;
			case 'p':
				outputline[i]='r';
			break;
			case 'd':
				outputline[i]='s';
			break;
			case 'r':
				outputline[i]='t';
			break;
			case 'j':
				outputline[i]='u';
			break;
			case 'g':
				outputline[i]='v';
			break;
			case 't':
				outputline[i]='w';
			break;
			case 'h':
				outputline[i]='x';
			break;
			case 'a':
				outputline[i]='y';
			break;
			case 'q':
				outputline[i]='z';
			break;
			default:
				outputline[i]=inputline[i];
			break;
		}
	}
	return outputline;
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    string inputline;
	getline(fin,inputline);
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            fout<<_main();
            fout<<endl;
    }
}
