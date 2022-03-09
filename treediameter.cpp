#include<bits/stdc++.h>
using namespace std;



int main()
{
	
	string s;
	cin>>s;
	string s1=s;
	sort(s1.begin(),s1.end());
	sort(s.rbegin(),s.rend());
	int n=s1.size();
	int i;
	string ans;
	int res=0;
	for(i=0;i<n;i++)
	{
int x1=s1[i]-'0';
int x2=s[i]-'0';
x1+=x2;
res=res+x1;
ans=ans+(char)(res%10);
res/=10;
	}
	while(res)
	{	
		ans=ans+(char)(res%10);
		res/=10;
	}
	int c=ans.size();
	for(i=c-1;i>=0;i--)
	{
	cout<<ans[i];
	}
	cout<<ans<<endl;
for(auto x:m1)
{

}
return 0;
}