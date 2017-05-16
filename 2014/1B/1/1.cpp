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

void _main(){
    int i,j,k;
    int N;
    fin>>N;
    string org[105];
    for(i=0;i<N;i++) fin>>org[i];
    char minimal[105];  //minimized string
    minimal[0]=org[0][0];
    int min_size=1; //size for minimized sting
    for(i=1;i<org[0].size();i++){
        if(org[0][i] != minimal[min_size-1]) minimal[min_size++]=org[0][i];
    }
    //for(i=0;i<min_size;i++) fout<<minimal[i];
    //fout<<endl;
    int app[105][105];  //appear time at each sting for each char
    for(i=0;i<N;i++) for(j=0;j<min_size;j++) app[i][j]=0;
    for(i=0;i<N;i++){
        int min_index=0;
        for(j=0;j<org[i].size();j++){
            if(org[i][j]==minimal[min_index]) app[i][min_index]++;
            else if(min_index<min_size-1 && org[i][j]==minimal[min_index+1] && app[i][min_index]!=0) app[i][++min_index]++;
            else{
                //fout<<min_index<<" "<<min_size<<endl<<org[i][j]<<" "<<minimal[min_index]<<" "<<minimal[min_index+1]<<endl<<app[i][min_index]<<" "<<i<<" "<<j<<endl;
                //if(app[i][min_index]==0) fout<<"000000000000000000000000000000000";
                fout<<"Fegla Won";
                return;
            }
        }
        if(min_index<min_size-1){
            fout<<"Fegla Won";
            return;
        }
    }
    /*fout<<endl;
    for(i=0;i<N;i++){
        for(j=0;j<min_size;j++) fout<<app[i][j];
        fout<<endl;
    }*/

    int total_move = 0;
    for(i=0;i<min_size;i++){
        int min_move = 999999999;
        for(j=0;j<N;j++){
            int goal = app[j][i];
            int move_count = 0;
            for(k=0;k<N;k++) move_count += abs(app[k][i]-goal);
            if(move_count<min_move) min_move=move_count;
        }
        total_move += min_move;
    }
    //for(i=0;i<min_size;i++) total_move += abs(app[0][i]-app[1][i]);
    fout<<total_move;
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
