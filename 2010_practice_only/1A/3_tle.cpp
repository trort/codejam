// TLE error
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool win(int i,int j){
     if(i == j) return 0;
     else if(i==1 || j==1) return 1;
     else{
          if(i>j){
                  int temp=i;
                  i=j;
                  j=temp;
          }
          bool bwin=1;
          for(int k=1;i*k<j;k++) bwin = bwin && win(j-i*k,i);
          return !bwin;
     }
}

int main(){
    //prepare();

    ifstream fin;
    ofstream fout;
    fin.open("C-small-practice.in");
    fout.open("result.out");
    int T;
    int A1,A2,B1,B2;
    int count;
    fin>>T;
    int i,j,k;
    for(i=0;i<T;i++){
                     fin>>A1>>A2>>B1>>B2;
                     count = 0;
                     for(j=A1;j<=A2;j++) for(k=B1;k<=B2;k++){
                                         if(win(j,k)) count++;
                     }

                     fout<<"Case #"<<i+1<<": ";
                     fout<<count;
                     fout<<endl;
    }
}
