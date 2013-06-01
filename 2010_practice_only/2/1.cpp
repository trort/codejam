#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

void _main(){
     int k;
     int d[110][55];
     fin>>k;
     int i,j,l,m,n;
     for (i=1;i<=k;i++) for (j=0;j<i;j++) fin>>d[i][j];
     for (i=k+1;i<2*k;i++) for (j=0;j<2*k-i;j++) fin>>d[i][j];
     //find diamond
     int max=0;
     bool diamond;
     bool found=0;
     for (l=0;(!found) && l<k;l++){//size=k-l
         for (m=1;(!found) && (m<=2*l+1);m++) for (n=0;(!found) && (n<=l);n++){//starting [m][n]
             if(!(m==1 && n==0)||(m==2*l+1 && n==l)||(m==l+1 && n==0)||(m==l+1 && n==l)) continue;
             diamond=1;
             //check diamond
             for (i=0;(diamond && (i<(k-l)));i++) for (j=0;(diamond && (j<=i));j++){
                 if (d[m+i][n+j]!=d[m+i][n+i-j] || d[m+i][n+j]!=d[m+2*(k-l)-2-i][n+j]){
                    diamond = 0;
                    break;
                 }
             }
             if (diamond){
                found = 1;
                max = k-l;
                break;
             }
         }
     }
     fout<<((2*k-max)*(2*k-max)-k*k);
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            _main();
            fout<<endl;
    }
}
