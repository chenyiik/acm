#include<cstdio>
#include<map>
#include<string>
#include<iostream>
using namespace std;
map<string,string>mp;
int main(){
	mp["Rock"]="Paper";
	mp["Paper"]="Scissors";
	mp["Scissors"]="Rock";
	int n;
	scanf("%d",&n);
	while(n--){
		string str;
		cin>>str;
		cout<<mp[str]<<endl;
	}
	return 0;
}
