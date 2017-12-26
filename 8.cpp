#include <iostream>
using namespace std;


void kelemnt(int *arr, int left, int right, int k) {
    int i = left;
    int j = right;
    for (int i=left;i<j;i++){
        if (arr[i]>arr[j]){
            swap(arr[i],arr[j-1]);
            swap(arr[j],arr[j-1]);
            j--;
            i--;
        }
    }
    if (k==j){
        cout <<endl<<arr[j]<<endl;
        return;
    }
    if (k<=j)
        kelemnt(arr,left,j-1,k);
    else
        kelemnt(arr,j+1,right,k);
};

int main(){
    int n,k;
    cout <<"enter n,k"<<endl;
    cin >>n>>k;
    int *arr=new int[n];
    for (int i=0;i<n;i++){
        arr[i]=abs(rand());
        cout <<arr[i]<<endl;
    }
    kelemnt(arr,0,n-1,k-1);
}
