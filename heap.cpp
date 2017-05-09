#include<bits/stdc++.h>
using namespace std;
void max_heapify(int a[], int n, int i)
{
    int left=2*i;
    int right=2*i+1;
    int largest;
    if(left<=n && a[left]>a[i])
        largest=left;
    else
        largest=i;
    if(right<=n && a[right]>a[largest])
        largest=right;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        max_heapify(a,n,largest);

    }

}
void build_heap(int a[],int n)
{
    for(int i=n/2;i>=1;i--)
        max_heapify(a,n,i);
}
int main()
{

    int a[10];
    int n;
    cout<<"enter no of elements\n";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build_heap(a,n);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i];
    }
}
