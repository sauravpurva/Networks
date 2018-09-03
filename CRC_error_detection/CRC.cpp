#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n1,n2,n3;
	int a1,a2;
	vector<int>data;
	vector<int>key;
	vector<int>final;

	cout<<"Enter the size of data: "<<endl;
	cin>>n1;
	cout<<"Enter the value data: "<<endl;
	for(int i=0;i<n1;i++)
	{
		cin>>a1;
		data.push_back(a1);
	}
	cout<<"Enter the size of key: "<<endl;
	cin>>n2;
	cout<<"Enter the value key: "<<endl;
	for(int i=0;i<n2;i++)
	{
		cin>>a2;
		key.push_back(a2);

	}
	for(int j=0;j<n2-1;j++)
	{
		data.push_back(0);
	}

		for( int i=0;i<key.size();i++)
		{
			if(data[i]==key[i])
				final.push_back(0);
			else
				final.push_back(1);
		}
		for(int i=0;i<final.size();i++)
		{
			if(final[i]==0)
				final.erase(final.begin()+i);
		}
		for(int i=0;i<final.size();i++)
		{
			cout<<final[i];
		}


	return 0;
}