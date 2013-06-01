#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const int LIMIT=510;
const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

int mass[LIMIT][LIMIT];
int m[LIMIT][LIMIT];
int m_x[LIMIT][LIMIT];
int m_y[LIMIT][LIMIT];

void _main(){
     int R,C,D;
     memset(m,0,sizeof(int)*LIMIT*LIMIT);
     memset(m_x,0,sizeof(int)*LIMIT*LIMIT);
     memset(m_y,0,sizeof(int)*LIMIT*LIMIT);
     char temp;
     int i,j,k,p,q;
     fin>>R>>C>>D;
     for(i=1;i<=R;i++) for(j=1;j<=C;j++){
                      fin>>temp;
                      mass[i][j] = temp - '0';
                      m[i][j]=m[i-1][j-1]+(m[i][j-1]-m[i-1][j-1])+(m[i-1][j]-m[i-1][j-1])+mass[i][j];
                      m_x[i][j]=m_x[i-1][j-1]+(m_x[i][j-1]-m_x[i-1][j-1])+(m_x[i-1][j]-m_x[i-1][j-1])+mass[i][j]*i;
                      m_y[i][j]=m_y[i-1][j-1]+(m_y[i][j-1]-m_y[i-1][j-1])+(m_y[i-1][j]-m_y[i-1][j-1])+mass[i][j]*j;
     }
     
     int max=2;
     
     for(i=1;i<=R-2;i++) for(j=1;j<=C-2;j++){
                         for(k=max+1;k+i<=R+1 && k+j<=C+1;k++){
                                          int blade_x,blade_y,blade_mass;
                                          blade_mass = m[i+k-1][j+k-1]+m[i-1][j-1]-m[i+k-1][j-1]-m[i-1][j+k-1];
                                                  blade_mass -= (mass[i][j]+mass[i][j+k-1]+mass[i+k-1][j]+mass[i+k-1][j+k-1]);
                                          blade_x = m_x[i+k-1][j+k-1]+m_x[i-1][j-1]-m_x[i+k-1][j-1]-m_x[i-1][j+k-1];
                                                  blade_x -= (mass[i][j]*i+mass[i][j+k-1]*i+mass[i+k-1][j]*(i+k-1)+mass[i+k-1][j+k-1]*(i+k-1));
                                          blade_y = m_y[i+k-1][j+k-1]+m_y[i-1][j-1]-m_y[i+k-1][j-1]-m_y[i-1][j+k-1];
                                                  blade_y -= (mass[i][j]*j+mass[i][j+k-1]*(j+k-1)+mass[i+k-1][j]*j+mass[i+k-1][j+k-1]*(j+k-1));
                                          
                                          //cout<<i<<" "<<j<<" "<<k<<endl;
                                          //cout<<blade_mass<<" "<<blade_x<<" "<<blade_y<<endl;
                                          //cin>>q;
                                                  
                                          int blade_x_exp_2 = blade_mass*(2*i+k-1);
                                          int blade_y_exp_2 = blade_mass*(2*j+k-1);
                                          
                                          if ((blade_x_exp_2 == blade_x*2) && (blade_y_exp_2 == blade_y*2) && k>max){
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
