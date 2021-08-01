#include<iostream>
#include<vector>

using namespace std;

void merge(int arr[],int low, int mid, int high)
{
	int i = low;
	int j = mid+1;
	int k = 0;
	int temp[high-low];

	while(i<= mid && j<= high)
	{
		if(arr[i] < arr[j])
			{temp[k] = arr[i];
				i++;
			}
		else
		{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}

	while(i<=mid)
	{
		temp[k] = arr[i];
		i++;
		k++;
	}

	while(j<=high)
	{
		temp[k] = arr[j];
		j++;
		k++;
	}
	int a =0;
	for(int p =low ; p<=high ; p++)
		{arr[p] = temp[a];
			a++;
		}
}

void merge_sort(int arr[],int low,int high)
{
	if(low<high)
	{
		int mid = low+(high-low)/2;
		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}

}

int main()
{	int t;
	cin>>t;

	while(t--)
	{
		int n,i;
		cin>>n;

		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];

		merge_sort(arr,0,n-1);

		// for(int i =0;i<n;i++)
		// 	cout<<arr[i]<<"\t";

		for(i=0;i<n-1;i++)
		{
			if( arr[i] == arr[i+1] )
				{
					cout<<"YES";
					break;
				}
		}
		if( i == n-1)
		{
			cout<<"NO";
		}

	}
	return 0;
}


