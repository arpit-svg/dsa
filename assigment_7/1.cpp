#include <iostream>
using namespace std;

void selection(int a[], int n){
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[m]) m=j;
        }
        int t=a[i];
        a[i]=a[m];
        a[m]=t;
    }
}
void insertion(int a[], int n){
    for(int i=1;i<n;i++){
        int x=a[i];
        int j=i-1;
        while(j>=0 && a[j]>x){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}
void bubble(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
void mergeArr(int a[], int l, int m, int r){
    int n1=m-l+1, n2=r-m;
    int x[100], y[100];
    for(int i=0;i<n1;i++) x[i]=a[l+i];
    for(int i=0;i<n2;i++) y[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(x[i]<y[j]) a[k++]=x[i++];
        else a[k++]=y[j++];
    }
    while(i<n1) a[k++]=x[i++];
    while(j<n2) a[k++]=y[j++];
}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        mergeArr(a,l,m,r);
    }
}
int part(int a[], int l, int r){
    int p=a[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<p){
            i++;
            int t=a[i]; a[i]=a[j]; a[j]=t;
        }
    }
    int t=a[i+1]; a[i+1]=a[r]; a[r]=t;
    return i+1;
}

void quick(int a[], int l, int r){
    if(l<r){
        int pi=part(a,l,r);
        quick(a,l,pi-1);
        quick(a,pi+1,r);
    }
}


