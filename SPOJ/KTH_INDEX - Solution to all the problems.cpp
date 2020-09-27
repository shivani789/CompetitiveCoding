#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,q;
	cin>>n>>q;
	long long a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	while(q--){
		long long l, r, p, k, flag=0;
		cin>>l>>r>>p>>k;
		for(int i=l-1;i<=r-1;i++){
			if(a[i]==p){
				--k;
				if(k==0){
					flag=1;
					cout<<i+1<<endl;
					break;
				}
			}
		}
		if(!flag)
		cout<<"-1"<<endl;
	}
	// your code goes here
	return 0;
}

