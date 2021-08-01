#include<iostream>
#include<vector>
using namespace std;

vector<int> selection_sort(int arr[],int n)
{	
	vector<int> comp_swap ;
	int min,temp,comp=0,swaps=0;

	for(int i=0;i<n-1;i++)
	{	min = i;
		for(int j=i+1;j<n;j++)
		{	comp++;
			if(arr[min]>arr[j])
			{
				min = j;
			}
		}
		swaps++;
		if(min!= i)
		{	
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
	comp_swap.push_back(comp);
	comp_swap.push_back(swaps);

	return comp_swap;
}


int main()
{	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];

		vector<int> v = selection_sort(arr,n);

		for(int i=0;i<n;i++)
			cout<<arr[i]<<"\t";

		cout<<"\nComparisons = "<<v[0];
		cout<<"\nSwaps = "<<v[1];

	}
	return 0;
}