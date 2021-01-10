#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
string A[]={"C","C#","D","D#","E","F","F#","G","G#","A","A#","B","C","C#","D","D#","E","F","F#","G","G#","A","A#","B","C","C#","D","D#","E","F","F#","G","G#","A","A#","B","C","C#","D","D#","E","F","F#","G","G#","A","A#","B"}; 
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		char N1[5],N2[5],N3[5];
		int i,p1,p2,p3;
		scanf("%s %s %s",N1,N2,N3);
		for(i=0;i<36;i++){
			if(strcmp(A[i].c_str(),N1)==0){
				p1=i;
				break;
			}
		}
		for(i++;i<36;i++){
			if(strcmp(A[i].c_str(),N2)==0){
				p2=i;
				break;
			}
		}
		for(i++;i<36;i++){
			if(strcmp(A[i].c_str(),N3)==0){
				p3=i;
				break;
			}
		}
		if(p2-p1==4&&p3-p2==3){
			puts("Major triad"); 
		}else if(p2-p1==3&&p3-p2==4){
			puts("Minor triad"); 
		}else puts("Dissonance");
	}
	return 0;
} 
