# include <iostream>

using namespace std;

int main(){
    int frames,n,c = 0;
    cout<<endl<<"Enter the total number of frames: ";
    cin>>n;
    // Instructions
    cout<<"------------------------------------";
    cout<<endl<<"Receiver's End: "<<endl<<endl<<"Respond as follows: "<<endl<<"1-Frame received"<<endl<<"0-Frame lost"<<endl;

    // Sender
    cout<<endl<<"Starting to send "<<n<<" frames using Stop & Wait ARQ Protocol......"<<endl<<endl;

    // Sending process
    for (int i=1; i<=n; i++){
        int t;
        cout<<endl<<"Sending frame "<<i<<endl<<"Receiver's acknowledgement: ";
        cin>>t;
        if (t==0){
            cout<<endl<<"Frame Lost: Resending frame "<<i<<"......"<<endl;
            c+=1;
        }
        else{cout<<"Frame Sent"<<endl;}
    }
    cout<<endl<<endl<<"Total frames lost: "<<c<<endl<<endl<<"------------------------------------";
    
}
