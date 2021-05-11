#include <iostream>
using namespace std;

int main(){
    int f, w, total = 0;
    cout<<endl<<"Name: Om Mule"<<endl<<"Reg. No: 19BCE0439"<<endl<<endl;
    cout<<endl<<"Total number of frames: ";
    cin>>f;
    cout<<endl<<"Enter N value/ Window Size: ";
    cin>>w;

    int fr = w, ak=0,c=0, last_sent = 0;
    cout<<"-------------------Selective Repeat ARQ-----------------------";
    cout<<endl<<"Receiver's End: "<<endl<<endl<<"Respond as follows: "<<endl<<"1-Frame received"<<endl<<"0-Frame lost"<<endl;
    cout<<endl<<"Sending the first "<<w<<" frames......"<<endl;
    total += w;
    for (int i=1; i<=f; i++){
        int t;
        cout<<endl<<"Receiver's acknowledgement for frame "<<i<<" :";
        cin>>t;
        if (t ==1){ak+=1;}
        // Frame received 
        if (t == 1){
            if (fr<f){
                fr +=1 ;
                cout<<endl<<"\t\t\tSending frame "<<fr<<"......."<<endl;
                total+=1;
                last_sent = 1;
            }
            else if (fr == f && c==0 && last_sent == 0){
                c+=1;
                cout<<endl<<"\t\t\tSending frame "<<fr<<"......."<<endl;
                total += 1;
            }
        }

        // Frame lost
        if (t == 0){
            cout<<"\t\t\tFrame Lost, sending frame "<<ak+1 <<" again........."<<endl;
            total += 1;
            i -= 1;
        }
    }

    cout<<endl<<"Total Frames sent: "<<total<<endl;
    cout<<endl<<endl<<"Transmission completed !"<<endl<<"------------------------------------"<<endl;
    
}
