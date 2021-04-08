# include <iostream>
using namespace std;

void chkerror(int f2[], int n){
    int f1[n], c= 0, f=0;
    int sum[n];
    cout<<"\n\nEnter the received sum of numbers: ";
    for (int i=0; i<n ;i++){
        cin>>f1[i];
    }

    for (int i = n-1; i>=0; i--){
        if (f1[i]==0 && f2[i]==0 && c==0){
            sum[i] = 0;
            c = 0;
        }
        else if (f1[i]==0 && f2[i]==0 && c==1){
            sum[i] = 1;
            c = 0;
        }
        else if (f1[i]==0 && f2[i]==1 && c==0){
            sum[i] = 1;
            c = 0;
        }
        else if (f1[i]==0 && f2[i]==1 && c==1){
            sum[i] = 0;
            c = 1;
        }
        else if (f1[i]==1 && f2[i]==0 && c==0){
            sum[i] = 1;
            c = 0;
        }
        else if (f1[i]==1 && f2[i]==0 && c==1){
            sum[i] = 0;
            c = 1;
        }
        else if (f1[i]==1 && f2[i]==1 && c==0){
            sum[i] = 0;
            c = 1;
        }
        else if (f1[i]==1 && f2[i]==1 && c==1){
            sum[i] = 1;
            c = 1;
        }
    }

    for (int i=0; i<n; i++){
        if (sum[i]==0){
            f = 1;
            break;
        }
    }
    if (f==1){cout<<"\n\nError occured !";}
    else{cout<<"\n\nNo Error !";}


}



void checksum(int sum[], int n){
    int chksum[n];
    cout<<"\n\nThe sum is: ";
    for(int i=0; i<n; i++){
        cout<< sum[i]<<"";
    }
    // Find the checksum
    for (int i=0; i<n; i++){
        chksum[i] = 1- sum[i];
    }

    cout<<"\n\nThe checksum is: ";
    for(int i=0; i<n; i++){
        cout<< chksum[i]<<"";
    }

    chkerror(chksum, n);
}


void addbin(int f1[], int f2[], int n){
    // Variables
    int sum[n];
    int c =0;
    int carr[n];


    // Sum the numbers
    for (int i = n-1; i>=0; i--){
        if (f1[i]==0 && f2[i]==0 && c==0){
            sum[i] = 0;
            c = 0;
        }
        else if (f1[i]==0 && f2[i]==0 && c==1){
            sum[i] = 1;
            c = 0;
        }
        else if (f1[i]==0 && f2[i]==1 && c==0){
            sum[i] = 1;
            c = 0;
        }
        else if (f1[i]==0 && f2[i]==1 && c==1){
            sum[i] = 0;
            c = 1;
        }
        else if (f1[i]==1 && f2[i]==0 && c==0){
            sum[i] = 1;
            c = 0;
        }
        else if (f1[i]==1 && f2[i]==0 && c==1){
            sum[i] = 0;
            c = 1;
        }
        else if (f1[i]==1 && f2[i]==1 && c==0){
            sum[i] = 0;
            c = 1;
        }
        else if (f1[i]==1 && f2[i]==1 && c==1){
            sum[i] = 1;
            c = 1;
        }
    } 

    // Handle the carry if any
    if (c==1){
        c=0;
        // Set up the carry array
        for (int i=0; i<n; i++){
            carr[i] = 0;
        }
        carr[n-1] = 1;

        addbin(sum, carr, n);
    }
    else if (c==0){
        checksum(sum,n);
    }
}



int main(){
    int n;

    cout<<"\n\nName: Om Mule\n"<<"Reg No: 19BCE0439\n\n";

    // Accept inputs
    cout<<"Enter the size of the frames: ";
    cin>>n;
    int f1[n];
    int f2[n];
    cout<<"Enter the 1st Frame: ";
    for (int i=0; i<n; i++){
        cin>> f1[i];
    }
    cout<<"Enter the 2nd Frame: ";
    for (int i=0; i<n; i++){
        cin>> f2[i];
    }
    addbin(f1, f2, n);
    
}