#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

struct pass{
       int B,E,w;
};

pass walk[1001];

int my_comp(const void * x,const void * y){
    return ((pass *)x)->w-((pass *)y)->w;
}

void _main(){
     int X,S,R,N;
     double T,time;
     fin>>X>>S>>R>>T>>N;
     int i,j,k;
     for(i=0;i<N;i++) fin>>walk[i].B>>walk[i].E>>walk[i].w;
     
     double save=0;
     i=0;
     int point=0;
     while(i<N){
                if (double(walk[i].B-point)/R <= T){
                   T -= double(walk[i].B-point)/R;
                   save += double(walk[i].B-point)/S - double(walk[i].B-point)/R;
                   point=walk[i].E;
                   i++;
                   continue;
                }
                else{
                     save += double(T*R)/S-T;
                     T-=T;
                     break;
                }
     }
     if (T>0.0 && i==N){
        if (double(X-point)/R <= T){
           T -= double(X-point)/R;
           save += double(X-point)/S - double(X-point)/R;
        }
        else{
             save += double(T*R)/S-T;
             T-=T;
        }
     }
     
     qsort(walk, N, sizeof(pass), my_comp);
     i=0;
     while(i<N){
                if (double(walk[i].E-walk[i].B)/(R+walk[i].w) <= T){
                   T -= double(walk[i].E-walk[i].B)/(R+walk[i].w);
                   save += double(walk[i].E-walk[i].B)/(S+walk[i].w) - double(walk[i].E-walk[i].B)/(R+walk[i].w);
                   //point=walk[i].E;
                   i++;
                   continue;
                }
                else{
                     save += double(T*(walk[i].w+R))/(walk[i].w+S)-T;
                     T-=T;
                     break;
                }
     }
     
     time = double(X)/S;
     for(i=0;i<N;i++) time -= (double(walk[i].E-walk[i].B)/(S) - double(walk[i].E-walk[i].B)/(S+walk[i].w));
     fout.precision(8);
     //fout<<time<<" "<<save<<" "<<time-save;
     fout<<time-save;
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
