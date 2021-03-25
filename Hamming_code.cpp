#include<iostream>
using namespace std;

void errordetection(int a[]){
    int p4,p2,p1,pos=0;
    p4 = a[0]^a[1]^a[2]^a[3];
    p2 = a[0]^a[1]^a[4]^a[5];
    p1 = a[6]^a[4]^a[0]^a[2];
    pos+= (p4*4+p2*2+p1*1);
    if (pos ==0){
        cout<<"No error detected";
    }
    else{
        cout<<"\nError detected in "<<pos<<" position !";
    }
}


int main(){
    cout<<"Name: Om Mule\n";
    cout<<"Reg. No: 19BCE0439\n";
    int a[4];
    cout<<"\nEnter the 4 bit data: ";
    for (int i=0;i<4;i++){
        cin>>a[i];
    }
    int codeword[7];
    int p1,p2,p4;
    codeword[0] = a[0];
    codeword[1] = a[1];
    codeword[2] = a[2];
    codeword[3] = (a[0]^a[1]^a[2]);
    codeword[4] = a[3];
    codeword[5] = (a[3]^a[1]^a[0]);
    codeword[6] = (a[0]^a[2]^a[3]);
    cout<<"\nCodeword: ";
    for (int i=0;i<7;i++){
        cout<<codeword[i];
    }
    cout<<"\n\nReceiver's Side: \n";
    cout<<"\nEnter the received word: ";
    int arr[7];
    for (int i=0;i<7;i++){
        cin>>arr[i];
    }
    errordetection(arr);
}