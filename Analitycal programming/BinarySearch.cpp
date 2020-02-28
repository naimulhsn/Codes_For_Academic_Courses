#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int arr[], int len, int val)
{
    int high=len-1;
    int low=0;
    int mid;
    int index=-1;
    while(high>=low){
        mid=(high+low)/2;
        if(val==arr[mid]){
            index=mid;
            break;
        }
        else if(val<arr[mid])
            high=mid-1;
        else low=mid+1;
    }
    return index;
}

int bs_upper_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid = (l + h) / 2;
        if (x >= a[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}

int bs_lower_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid = (l + h) / 2;
        if (x <= a[mid]) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
int main()
{
    int n,a[10000];
    cin>>n;
    for(int i=0; i<n; i++)cin>>a[i];
    sort(a,a+n);
    int indx=BinarySearch(a,n,5);
    if(indx==-1)cout<<"Value not found!!!\n";
    else{
        cout<<"Value found at index : "<<indx<<endl;
    }
    return 0;
}
