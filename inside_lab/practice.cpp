#include <iostream>
using namespace std;
int remove(int *arr,int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j] && i!=j){
                for(int k=j;k<n-1;k++){
                    arr[k]=arr[k+1];

                }
                n--;
                j--;
                
            }
        }
        
    }
    return n;

}
void reverse(int *arr,int n){
    int temp=0;
    for(int i=0;i<n/2;i++){
        temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
}
int main(){
    int arr[4]={1,2,3,4};
    reverse(arr,4);
    for(int i=0;i<4;i++){
        cout<<arr[i]<<", ";

    }

    return 0;
}