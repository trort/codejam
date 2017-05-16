#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<ctime>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

vector<int> link[1005];
int ct[1005][1005];

int treecount(int root,int parent){
    int i,j,k;
    int max1=-1,max2=-1;
    for(i=0;i<link[root].size();i++){
        if(link[root][i]==parent) continue;
        if(ct[link[root][i]][root]==-1) ct[link[root][i]][root]=treecount(link[root][i],root);
        if(ct[link[root][i]][root]>max1){
            max2=max1;
            max1=ct[link[root][i]][root];
        }
        else if(ct[link[root][i]][root]>max2)
            max2=ct[link[root][i]][root];
    }
    if(max1==-1 || max2==-1) return 1;
    else return (1+max1+max2);
}

void _main(){
    int N;
    int i,j,k;
    fin>>N;
    for(i=1;i<=N;i++) link[i].clear();
    for(i=0;i<N-1;i++){
        int a,b;
        fin>>a>>b;
        link[a].push_back(b);
        link[b].push_back(a);
    }
    int max=0;
    for(i=1;i<=N;i++) for(j=1;j<=N;j++) ct[i][j]=-1;
    for(i=1;i<=N;i++){
        int c=treecount(i,0);
        if(c>max) max=c;
    }
    fout<<(N-max);
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            _main();
            fout<<endl;
    }
}
