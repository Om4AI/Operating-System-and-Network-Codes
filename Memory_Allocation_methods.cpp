#include <iostream>
using namespace std;

//                                    FIRST FIT BEGINS                                  //
void first_fit(int avail[],int tb_allocated[],int ex_1[],int nfb,int ab){
  int in_frag=0;
  int ex_frag=0;
  for (int i=0;i<ab;i++){
    int f=0;
    int j=0;
    int k=0;
    cout<<"Memory block sequence: ";
    for (int m=0;m<nfb;m++){
      cout<<avail[m]<<" ";
    }
    cout<<endl;
    while (f==0 && j<nfb){
      if (avail[j] >= tb_allocated[i]){
        f=1;
        cout<<"Process with size "<<tb_allocated[i]<<" is allocated successfully."<<endl;
        break;
      }
      else{
        j++;
      }
    }
    // while loop ended
    int sum_free_blocks=0;
    for (k=0;k<nfb;k++){
      sum_free_blocks+=avail[k];
    }
      // f==1
    if (f==1){
      avail[j]=avail[j]-tb_allocated[i];
    }
    // Process not allocated
    else{
      cout<<"The process with size "<<tb_allocated[i]<<" cannot be allocated to any memory block."<<endl;
      if (tb_allocated[i]<=sum_free_blocks){
        ex_frag+=tb_allocated[i];
      }
    }
  }
  for (int i=0;i<nfb;i++){
    if (ex_1[i]!=avail[i]){
      in_frag+=avail[i];
    }
  }
  cout<<"Final Memory block sequence: ";
  for (int m=0;m<nfb;m++){
    cout<<avail[m]<<" ";
  }
  cout<<endl;
  cout<<"Internal fragmentation: "<<in_frag<<endl;
  cout<<"External fragmentation: "<<ex_frag<<endl;
}
//                               FIRST FIT ENDED                                   //

//                               BEST FIT BEGINS                                   //
void best_fit(int avail[],int tb_allocated[],int ex_1[],int nfb,int ab){
  int in_frag=0;
  int ex_frag=0;
  // element:: tb_allocated[i]
  for (int i=0;i<ab;i++){
    int b=0;
    int f=0;
    int j;
    int k=0;
    cout<<"Memory block sequence: ";
    for (int m=0;m<nfb;m++){
      cout<<avail[m]<<" ";
    }
    cout<<endl;
    int min=100000;
    int m1=0;
    for (j=0;j<nfb;j++){
      if (avail[j]==tb_allocated[i]){
        f=1;
        b=1;
        cout<<"Process with size "<<tb_allocated[i]<<" is allocated successfully."<<endl;
        avail[j]=0;
        break;
      }
  //
      else if (avail[j]>tb_allocated[i]){
        f=1;
        if((avail[j]-tb_allocated[i])<min){
          min=avail[j]-tb_allocated[i];
          m1=j;
        }
        else{
          continue;
        }
      }
  // */                                  */
      else{
        continue;
      }
    }
  // Sum of the available blocks
  int sum_free_blocks=0;
  for (k=0;k<nfb;k++){
    sum_free_blocks+=avail[k];
  }
    if(f==1 && b!=1){
      cout<<"Process with size "<<tb_allocated[i]<<" is allocated successfully."<<endl;
      avail[m1]=min;
    }
    else if (f==0){
      cout<<"The process with size "<<tb_allocated[i]<<" cannot be allocated to any memory block."<<endl;
      if (tb_allocated[i]<=sum_free_blocks){
        ex_frag+=tb_allocated[i];
      }
    }
  }
  for (int i=0;i<nfb;i++){
    if (ex_1[i]!=avail[i]){
      in_frag+=avail[i];
    }
  }
  cout<<"Final Memory block sequence: ";
  for (int m=0;m<nfb;m++){
    cout<<avail[m]<<" ";
  }
  cout<<endl;
  cout<<"Internal fragmentation: "<<in_frag<<endl;
  cout<<"External fragmentation: "<<ex_frag<<endl;
}
//                                      BEST FIT ENDED                                 //

//                                      WORST FIT BEGINS                               //
void worst_fit(int avail[],int tb_allocated[],int ex_1[],int nfb,int ab){
  int in_frag=0;
  int ex_frag=0;
  // element:: tb_allocated[i]
  for (int i=0;i<ab;i++){
    int f=0;
    int j;
    int k=0;
    cout<<"Memory block sequence: ";
    for (int m=0;m<nfb;m++){
      cout<<avail[m]<<" ";
    }
    cout<<endl;
    int max=-1;
    int m1=0;
    for (j=0;j<nfb;j++){
      if (avail[j]>=tb_allocated[i]){
        f=1;
        if((avail[j]-tb_allocated[i])>max){
          max=avail[j]-tb_allocated[i];
          m1=j;
        }
        else{
          continue;
        }
      }
      else{
        continue;
      }
    }
  // Sum of the available blocks
  int sum_free_blocks=0;
  for (k=0;k<nfb;k++){
    sum_free_blocks+=avail[k];
  }
    if(f==1){
      cout<<"Process with size "<<tb_allocated[i]<<" is allocated successfully."<<endl;
      avail[m1]=max;
    }
    else if (f==0){
      cout<<"The process with size "<<tb_allocated[i]<<" cannot be allocated to any memory block."<<endl;
      if (tb_allocated[i]<=sum_free_blocks){
        ex_frag+=tb_allocated[i];
      }
    }
  }
  for (int i=0;i<nfb;i++){
    if (ex_1[i]!=avail[i]){
      in_frag+=avail[i];
    }
  }
  cout<<"Final Memory block sequence: ";
  for (int m=0;m<nfb;m++){
    cout<<avail[m]<<" ";
  }
  cout<<endl;
  cout<<"Internal fragmentation: "<<in_frag<<endl;
  cout<<"External fragmentation: "<<ex_frag<<endl;
}
//                                    WORST FIT ENDED                                      //

///       MAIN        ///
int main(){
  int nfb;
 // Free memory blocks
  cout<<"Total free blocks in memory: ";
  cin>>nfb;
  int avail[nfb];
  int ex_1[nfb];
  cout<<"Enter the free block sizes: ";
  for (int i=0;i<nfb;i++){
    int t;
    cin>>t;
    avail[i]=t;
    ex_1[i]=t;
  }
  // Processes to be allocated
  cout<<"Number of Processes to be allocated: ";
  int ab;
  cin>>ab;
  int tb_allocated[ab];
  cout<<"Sizes of processes to be allocated: ";
  for (int j=0;j<ab;j++){
    cin>>tb_allocated[j];
  }
  //  selection
  cout<<"Select the allocation method: \n1.First fit\n2.Best fit\n3.Worst fit\n";
  int s;
  cin>>s;
  switch (s) {
    case(1):first_fit(avail,tb_allocated,ex_1,nfb,ab);
    break;
    case(2):best_fit(avail,tb_allocated,ex_1,nfb,ab);
    break;
    case(3):worst_fit(avail,tb_allocated,ex_1,nfb,ab);
    break;
    default: cout<<"The best among all is the best fit algorithm !!";
    break;
  }
}
