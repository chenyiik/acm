typedef long long T;T m=1e9+7,f[2],c[2],i,x,y=1;int main(){for(;i<30;i++)f[x]+=(c[x]%=m)-f[y]+(i<3?i*i:3-i%2)+m,c[x^=1]+=f[y^=1]*2,c[y]+=f[y]*3,printf("%d ",f[y]%=m);}
