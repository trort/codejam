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
__int64 L,X;
int value[10005],rvalue[10005];
string s;

int mult(int x, int y){
    int ans;
    int sign = 1;
    if(x<0){sign *= -1; x = -x;}
    if(y<0){sign *= -1; y = -y;}
    if(x == 1) ans = y;
    else if(y == 1) ans = x;
    else if(x == y) ans = -1;
    else if(x == 2 && y == 3) ans = 4;
    else if(x == 2 && y == 4) ans = -3;
    else if(x == 3 && y == 2) ans = -4;
    else if(x == 3 && y == 4) ans = 2;
    else if(x == 4 && y == 2) ans = 3;
    else if(x == 4 && y == 3) ans = -2;
    else cout<<x<<" "<<y<<" "<<"ERROR!\n";
    return sign*ans;
}

int get_value(int start, int stop){
    //cout<<"Call "<<start<<" "<<stop<<endl;
    int para;
    int div1 = (start/L + 1)*L;
    if(stop < div1){ // no bound cross
        start %= L;
        stop %= L;
        para = 1;
        for(int i=start; i<=stop; i++)
            para = mult(para,(s[i] - 'i' + 2));
    }
    else{ // cross bound
        para = rvalue[start - (div1-L)];
        while(stop - div1 >= L){
            para = mult(para,value[L-1]);
            div1 += L;
        }
        para = mult(para,value[stop-div1]);
    }
    return para;
}

bool _main(){
    fin>>L>>X;
    if(X>12) X = (X%12)+12;
    fin>>s;
    int t;
    for(int i=0; i<L; i++){
        t = s[i] - 'i' + 2;
        if(i==0) value[i] = t;
        else value[i] = mult(value[i-1],t);
        //cout<<"value "<<value[i]<<endl;
    }
    //cout<<"value done\n";
    for(int i=L-1; i>=0; i--){
        t = s[i] - 'i' + 2;
        if(i==L-1) rvalue[i] = t;
        else rvalue[i] = mult(t,rvalue[i+1]);
        //cout<<"rvalue "<<rvalue[i]<<endl;
    }
    //cout<<"rvalue done\n";
    //fout<<value[L-1]<<" "<<rvalue[0]<<endl;

    int LL = X*L;
    int para1,para2,para3;
    int i,j;
    for(i=0; i<LL; i++){
        para1 = get_value(0, i);
        if(para1 == 2) break;
    }
    for(j=LL-1; j>=0; j--){
        para3 = get_value(j,LL-1);
        if(para3 == 4) break;
    }
    // IMPORTANT: no need for searching all possibilities, just need first encounter
    //fout<<i<<" "<<j<<endl;
    if(i>=LL || j<0 || j-i<=1) return false;
    else{
        para2 = get_value(i+1,j-1);
        if(para2 == 3) return true;
        else return false;
    }
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
        fout<<"Case #"<<i+1<<": ";
        cout<<"Case #"<<i+1<<" is runing"<<endl;
        fout<<(_main()?"YES":"NO");
        fout<<endl;
    }
}
