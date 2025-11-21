#include <iostream>
using namespace std;

void improved(int a[], int n){
    int s=0, e=n-1;
    while(s<e){
        int mn=s, mx=s;
        for(int i=s;i<=e;i++){
            if(a[i]<a[mn]) mn=i;
            if(a[i]>a[mx]) mx=i;
        }
        int t=a[s]; a[s]=a[mn]; a[mn]=t;
        if(mx==s) mx=mn;
        t=a[e]; a[e]=a[mx]; a[mx]=t;
        s++; e--;
    }
}

int main(){
    int n; cin>>n;
    int a[100];
    for(int i=0;i<n;i++) cin>>a[i];
    improved(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
