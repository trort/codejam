#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

void _main(){
     int R,C,D;
     int mass[501][501];
     char temp;
     int i,j,k,l,m,n;
     fin>>R>>C>>D;
     for(i=0;i<R;i++) for(j=0;j<C;j++){
                      fin>>temp;
                      mass[i][j] = temp - '1';
     }
     
     int max=2;
     
     int m_x,m_y,exp;
     
     for (i=0;i<R-2;i++) for (j=0;j<C-2;j++){
         for (k=max;k+i<=R && k+j<=C;k++){
             m_x=0;m_y=0;
             for (m=i;m<i+k;m++) for (n=j;n<j+k;n++){
                 if ((m==i && n==j) || (m==i && n==j+k-1) || (m==i+k-1 && n==j) || (m==i+k-1 && n==j+k-1)) continue;
                 else{
                      m_x += mass[m][n]*(2*(m-i) - (k-1));
                      m_y += mass[m][n]*(2*(n-j) - (k-1));
                 }
             }
             if (((m_x) == 0) && ((m_y) == 0) && k>max){
                max=k;
             }
         }
     }
     if(max<3) fout<<"IMPOSSIBLE";
     else fout<< max;
     return;
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
