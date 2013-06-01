#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct rope{
       int a;
       int b;
};

bool cross(rope x,rope y){
     if((x.a>y.a && x.b<y.b) || (x.a<y.a && x.b>y.b)) return 1;
     else return 0;
}

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("A-large-practice.in");
    fout.open("result.out");
    int T;
    int N;
    int count;
    rope line[1001];
    fin>>T;
    int i,j,k;
    for(i=0;i<T;i++){
                     fin>>N;
                     count = 0;
                     for(j=0;j<N;j++){
                                      fin>>line[j].a>>line[j].b;
                                      for(k=0;k<j;k++){
                                                       if(cross(line[j],line[k])) count ++;
                                      }
                     }
                     
                     fout<<"Case #"<<i+1<<": ";
                     fout<<count;
                     fout<<endl;
    }
}
