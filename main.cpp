#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<unistd.h>
#include<vector>
#define Trace(m) cout<<#m"="<<(m)<<endl;
using namespace std;

int fc[10];
int sfc[10];
#define setp(no,t,n) fc[no]=t;strcpy(&name[no][0],n);
char name[10][50];
vector<int>x;
int l;

void init(){
	x.resize(l);
	//	fc[0]=13;strcpy(name[0][1],"BinQian");//bin qian.
	setp(0,13,"BinQian");
	setp(1,15,"CuiFen");
	setp(2,15,"CiBao");
	setp(3,28,"YunSi");
	setp(4,20,"TuiBo");
	setp(5,10,"QQQ");
	setp(6,8,"LinDong");
	setp(7,13,"TianHuo");
	setp(8,15,"YinShen");
	setp(9,15,"HuoRen");
	for(int i=0;i<10;i++){
		sfc[i]=2*fc[i]-l;
	}
}
int range(int min,int max){
	return min+(max+1-min)*rand()/((long)RAND_MAX+1);
}
void assign(){
	for(int i=0;i<x.size();i++){
		x[i]=range(0,9);
	}
}

bool verify(){
	bool containAll[10];
	int count=0;
	cout<<"verify(l="<<l<<"):";
	//memset(containAll,10,sizeof(bool),0);
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<",";
		if(!containAll[x[i]]){
			count++;
			containAll[x[i]]=true;
		}
		for(int j=i+1;j<x.size();j++){
			if(x[i]==x[j]){
				int sc=sfc[x[i]];
				if(abs(l-2*abs(i-j))>sc){
					cout<<"Error: i:"<<i<<" j:"<<j<<endl;
					return false;
				}
			}
		}
	}
	cout<<endl;
	if(count<10){
		for(int i=0;i<10;i++){
			if(!containAll[i]){
				cout<<"Error: i:"<<i<<" is not contained"<<endl;
				break;
			}
		}

		cout<<"Count<10"<<endl;
		return false;
	}

}
int main(){
	l=4;
	init();
	assign();
	verify();

	cout<<"Hello World."<<endl;
	return 0;
}
