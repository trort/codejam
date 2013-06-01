#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

string _main(){
       string R="";
       long x1,x2,y1,y2,px,py;
       int N,M;
       fin>>N>>M;
       int i,j,k;
       fin>>x1>>y1>>x2>>y2;
       double beta,alpha1,alpha2;
       double r1,r2;
       double area,a1,a2;
       beta=atan2(double(y2-y1),double(x2-x1));
       if(beta>PI/2 || beta <-PI/2){
                    long temp;
                    temp=x1;x1=x2;x2=temp;
                    temp=y1;y1=y2;y2=temp;
                    beta=atan2(double(y2-y1),double(x2-x1));
       }
       for(i=0;i<M;i++){
                        fin>>px>>py;
                        alpha1=atan2(double(py-y1),double(px-x1));
                        alpha2=atan2(double(py-y2),double(px-x2));
                        r1=sqrt(double((px-x1)*(px-x1)+(py-y1)*(py-y1)));
                        r2=sqrt(double((px-x2)*(px-x2)+(py-y2)*(py-y2)));
                        
                        if ((alpha1>beta-PI/2 && alpha1<beta+PI/2) && (alpha2>beta-PI/2 && alpha2<beta+PI/2)){//2 side
                           alpha1=abs(alpha1-beta);
                           a1=r1*r1*(0.5*alpha1-0.5*cos(alpha1)*sin(alpha1));
                           alpha2=abs(alpha2-beta);
                           a2=r2*r2*(0.5*(PI-alpha2)+0.5*cos(alpha2)*sin(alpha2));
                           //cout<<i<<"2side";
                        }
                        else if((alpha1<beta-PI/2 || alpha1>beta+PI/2) && (alpha2<beta-PI/2 || alpha2>beta+PI/2)){//1 side
                             if(alpha1<0) alpha1+=2*PI;
                             if(alpha2<0) alpha2+=2*PI;
                             alpha1=abs(PI-abs(alpha1-beta));
                             a1=r1*r1*(0.5*(PI-alpha1)+0.5*cos(alpha1)*sin(alpha1));
                             alpha2=abs(PI-abs(alpha2-beta));
                             a2=r2*r2*(0.5*alpha2-0.5*cos(alpha2)*sin(alpha2));
                             //cout<<i<<"1side";
                        }
                        else{ //between
                              alpha1=abs(alpha1-beta);
                              a1=r1*r1*(0.5*alpha1-0.5*cos(alpha1)*sin(alpha1));
                              alpha2=abs(PI-abs(alpha2-beta));
                              a2=r2*r2*(0.5*alpha2-0.5*cos(alpha2)*sin(alpha2));
                              //cout<<i<<"between"<<endl;
                              //cout<<alpha1<<" "<<alpha2<<endl<<a1<<" "<<a2<<endl;
                        }
                        
                        area=2*(a1+a2);
                        fout.precision(7);
                        fout<<" "<<fixed<<area;
       }
       //cin>>R;
       return R;
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<":";
            fout<<_main();
            fout<<endl;
    }
}
