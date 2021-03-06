#include <iostream>
using namespace std;

/*BUBBLE SORT
Worst case:reverse sorted O(n^2)
Best case: already sorted O(n)
sorting in place auxiliary space O(1)
stable
adaptive*/

void bubble_sort(int arr[],int n)			
{											
	for(int i=0;i<n-1;i++)					
	{										
		bool flag=0;						
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				flag=1;
			}
		}
		if(flag==0)	return;
	}
}


/*INSERTION SORT
Best case:already sorted O(n)
Worst case:reverse sorted O(n^2)
Applying binary search 
to calculate the position of the data to be inserted doesn't reduce the time complexity of insertion sort. 
This is because insertion of a data at an appropriate position involves two steps: 
1. Calculate the position. 
2. Shift the data from the position calculated in step #1 one step right to create a gap where the data will be inserted.
Using binary search reduces the time complexity in step #1 from O(N) to O(logN).
But, the time complexity in step #2 still remains O(N).
So, overall complexity remains O(N^2).
suitable for linked list
A sorting technique is considered Online 
if it can accept new data while the procedure is ongoing i.e. 
complete data is not required to start the sorting operation.
adaptive
stable 
sorting in place*/

void insertion_sort(int arr[],int n)			
{												
	for(int i=1;i<n;i++)						 
	{											 
		int j=i-1;								
		int x=arr[i];							
		while(j>-1 && arr[j]>x)					
		{										
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=x;
	}
}


/*SELECTION SORT
time complexity: O(n^2)
not adaptive
not stable
never makes more than O(n) swaps
In Place:does not require extra space.*/
void selection_sort(int arr[],int n)		
{											
	for(int i=0;i<n-1;i++)					
	{										 
		int k=i,min=arr[i];					
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<min)
			{
				min=arr[j];
				k=j;
			}
		}
		swap(arr[i],arr[k]);
	}
}


/* MERGE ALGO
Given two sorted list of size m and n respectively.
The number of comparisons needed the worst case by the merge algorithm will be m+n-1
Auxiliary Space: O(n)*/

/* MERGE SORT
time comlexity O(nlogn) T(n) = 2T(n/2) +O(n)
Divide and Conquer
stable
suitable for linked list
not adaptive
not in place sorting*/

void merge(int arr[],int l,int mid,int r)		
{												
	int n1=mid-l+1;								
	int n2=r-mid;
	int L[n1],R[n2];							
	for(int i=0;i<n1;i++)
		L[i]=arr[l+i];
	for(int i=0;i<n2;i++)
		R[i]=arr[mid+1+i];
		
	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<R[j])
			arr[k++]=L[i++];
		else
			arr[k++]=R[j++];
	}
	while(i<n1)	arr[k++]=L[i++];
	while(j<n2)	arr[k++]=R[j++];
}
void merge_sort(int arr[],int l,int r)			
{												
	if(l<r)									
	{											
		int mid=l+(r-l)/2;						
		merge_sort(arr,l,mid);					
		merge_sort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}


/* QUICK SORT
worst case:Recurrence is T(n) = T(n-1) + O(n) time complexity is O(n^2) partition at one of the corner
best case :Recurrence is T(n) = 2T(n/2) + O(n) time complexity is O(nLogn) partition at middle
When first element or last element is chosen as pivot, worst case occurs for the sorted arrays.
choosing the middle element as pivot minimizes the chances of encountering worst case but it can go to O(n^2).
When we choose median as pivot element then after the partition algorithm it will go in the middle of the array 
A linear time median searching algorithm is used  to pick the median, so that the worst case time reduces to O(nLogn)
Divide and Conquer algorithm
Not stable
adpative*/

int partition(int arr[],int l,int r)			
{												
	int pivot=arr[l];					//pivot : first element 		 
	int j=l+1;									
    for(int i=l+1;i<=r;i++)
    {
    	if(arr[i]<pivot)
    		swap(arr[i],arr[j++]);
	}
	swap(arr[j-1],arr[l]);
	return j-1;
}

int partition2(int arr[],int l,int r)
{
	int pivot=arr[r];					//pivot : last element	
	int j=l;
    for(int i=l;i<=r-1;i++)
    {
    	if(arr[i]<pivot)
    		swap(arr[i],arr[j++]);
	}
	swap(arr[j],arr[r]);
	return j;
}

void quick_sort(int arr[],int l,int r)				
{													
	if(l<r)										
	{												
		int j=partition2(arr,l,r);				
		quick_sort(arr,l,j-1);					    
		quick_sort(arr,j+1,r);					 	
	}
}


int main()
{
	int arr[]={17,66,55,44,33,22,11,3};
	quick_sort(arr,0,7);
	for(int i=0;i<7;i++)
		cout<<arr[i]<<" ";
}
