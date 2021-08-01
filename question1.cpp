#include<iostream>
#include<vector>
using namespace std;

vector<int> insertion_sort(int arr[],int n)
{	
	int shifts = 0;
	int comp=0;
	vector<int> shft_comp;
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		int temp = arr[i];
		int min=i;
		while(j>=0 && arr[j] > temp)
		{	shifts ++;
			comp++;
			arr[j+1] = arr[j];
			min = j;
			j--;
		}
		shifts++;
		if(i!=min)
		{	
			arr[min] = temp;
		}
	}
		shft_comp.push_back(shifts);
		shft_comp.push_back(comp);

	return shft_comp;
}


int main()
{	
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];

		vector<int> v = insertion_sort(arr,n);
		
		for(int i=0;i<n;i++)
			cout<<arr[i]<<"\t";
		cout<<"\n"<<"Comparisons = "<<v[1];
		cout<<"\n"<<"Shifts = "<<v[0];
	
	}
	return 0;
}