#include<bits/stdc++.h>
using namespace std;
pair<int,int> largestRectangleArea(vector<int>& heights) 
{
    int max_area=0,second_area=0;
    heights.push_back(0);
    int sz=heights.size();
    int stack[sz];
    stack[0]=heights[0];
    int stack_idx=0;
    int i=1;
    while (stack_idx>=0 && i<sz) 
	{
        if (heights[i]>=stack[stack_idx]) 
		{
            stack[++stack_idx]=heights[i++];
            continue;
        }
        while (stack_idx>=0 && stack[stack_idx]>heights[i]) 
		{
            int area=stack[stack_idx]*(i-stack_idx);
            if (area>=max_area) {second_area=max_area;max_area=area;}
            stack_idx--;
        }
        while (stack_idx<i) stack[++stack_idx]=heights[i];
        i++;
    }
    return make_pair(max_area,second_area);
}
int getans(vector<vector<int>>& matrix) 
{
    int m=matrix.size();
    if (m==0) return 0;
    int n=matrix[0].size();
    if (n==0) return 0;
   	auto x=largestRectangleArea(matrix[0]);
   	vector<int> ans;
   	ans.push_back(x.first);ans.push_back(x.second);
    for (int i=1;i<m;i++) 
	{
        vector<int>& line_up=matrix[i-1];
        vector<int>& line=matrix[i];
        for (int j=0;j<n;j++) 
        if (line[j]==1) line[j]=line_up[j]+1;
        auto x=largestRectangleArea(line);
        ans.push_back(x.first);ans.push_back(x.second);
    }
    sort(ans.begin(),ans.end(),greater<int>());
	return ans[1];
}
vector<vector<int>> vec;
int main()
{
	int n,m;
	cin>>n>>m;
	vec.resize(n);
	for (int i=0;i<n;i++) vec[i].resize(m);
	for (int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		//cout<<s<<endl;
		for (int j=0;j<m;j++) vec[i][j]=(s[j]=='1');
	}
	cout<<getans(vec)<<endl;
	return 0;
}
