# include <iostream>
using namespace std;

int page_fault(int el,int pf[],int npf){
  int j;
  int f=0;
  for (j=0;j<npf;j++){
    if (pf[j]==el){
      f=1;
      break;
    }
    else{
      continue;
    }
  }
  return f;
}

void print(int pf[],int npf){
  cout<<"Page Frames: ";
  for (int m=0;m<npf;m++){
    cout<<pf[m]<<" ";
  }
  cout<<endl;
}

//                                   FIFO                                    //
void FIFO(int ref_str[],int npf,int nrs){
  int p=0;
  int pf[npf];
  for (int k=0;k<npf;k++){
    pf[k]=-1;
  }
  int i;
  int page_faults=0;
  // Page fault f=1 means element is present
  print(pf,npf);
  for (i=0;i<nrs;i++){
    // el = ref_str[i]
    if (page_fault(ref_str[i],pf,npf)==1){
      // No page fault
      continue;
    }
    else if (page_fault(ref_str[i],pf,npf)==0){
      // Page fault occured
      page_faults+=1;
      // Check empty space
      int assi=0;
      for (int j=0;j<npf;j++){
        // Empty space available
        if (pf[j]==-1){
          pf[j]=ref_str[i];
          assi=1;
          break;
        }
        else{
          continue;
        }
      }
      // No empty space was present
      if (assi==0){
        pf[p]=ref_str[i];
        p++;
        assi=1;
        if (p==npf){
          p=0;
        }
      }
    }
    print(pf,npf);
  }
  cout<<"Page Faults: "<<page_faults;
}
//                             FIFO ENDED                                    //

//                                   LIFO                                    //
void LIFO(int ref_str[],int npf,int nrs){
  int pf[npf];
  for (int k=0;k<npf;k++){
    pf[k]=-1;
  }
  int i;
  int page_faults=0;
  // Page fault f=1 means element is present
  print(pf,npf);
  for (i=0;i<nrs;i++){
    // el = ref_str[i]
    if (page_fault(ref_str[i],pf,npf)==1){
      // No page fault
      continue;
    }
    else if (page_fault(ref_str[i],pf,npf)==0){
      // Page fault occured
      page_faults+=1;
      // Check empty space
      int assi=0;
      for (int j=0;j<npf;j++){
        // Empty space available
        if (pf[j]==-1){
          pf[j]=ref_str[i];
          assi=1;
          break;
        }
        else{
          continue;
        }
      }
      // No empty space was present
      if (assi==0){
        pf[npf-1]=ref_str[i];
        assi=1;
      }
    }
    print(pf,npf);
  }
  cout<<"Page Faults: "<<page_faults;
}
//                             LIFO ENDED                                    //

//                             LRU                                           //
void LRU(int ref_str[],int npf,int nrs){
  int p=0;
  int pf[npf];
  for (int k=0;k<npf;k++){
    pf[k]=-1;
  }
  int i;
  int page_faults=0;
  // Page fault f=1 means element is present
  print(pf,npf);
  for (i=0;i<nrs;i++){
    // el = ref_str[i]
    if (page_fault(ref_str[i],pf,npf)==1){
      // No page fault
      continue;
    }
    else if (page_fault(ref_str[i],pf,npf)==0){
      // Page fault occured
      page_faults+=1;
      // Check empty space
      int assi=0;
      for (int j=0;j<npf;j++){
        // Empty space available
        if (pf[j]==-1){
          pf[j]=ref_str[i];
          assi=1;
          break;
        }
        else{
          continue;
        }
      }
      // No empty space
      if (assi==0){
        int min=100000;
        for (int j=0;j<npf;j++){
          int found=0;
          int m=i-1;
          while (m>=0 && found==0){
            if (pf[j]==ref_str[m]){
              found=1;
              if (m<min){
                min=m;
              }
              break;
            }
            else{
              m--;
            }
          }
        }
        // min contains one to be replaced
        pf[min]=ref_str[i];
      }
    }
    print(pf,npf);
  }
  cout<<"Page Faults: "<<page_faults;
}
//                                  LRU Ended                                //

//                            Optimal Page replacement                       //
void Optimal(int ref_str[],int npf,int nrs){
  int p=0;
  int pf[npf];
  for (int k=0;k<npf;k++){
    pf[k]=-1;
  }
  int i;
  int page_faults=0;
  // Page fault f=1 means element is present
  print(pf,npf);
  for (i=0;i<nrs;i++){
    // el = ref_str[i]
    if (page_fault(ref_str[i],pf,npf)==1){
      // No page fault
      continue;
    }
    else if (page_fault(ref_str[i],pf,npf)==0){
      // Page fault occured
      page_faults+=1;
      // Check empty space
      int assi=0;
      for (int j=0;j<npf;j++){
        // Empty space available
        if (pf[j]==-1){
          pf[j]=ref_str[i];
          assi=1;
          break;
        }
        else{
          continue;
        }
      }
      // No empty space
      if (assi==0){
        int max=0;
        int replaced=0;
        for (int j=0;j<npf;j++){
          int found=0;
          int m=i+1;
          // Not found
          while (found==0 && m<nrs){
            if (pf[j]==ref_str[m]){
              found=1;
              if (m>max){
                max=m;
              }
              break;
            }
            else{
              m++;
            }
          }
          if (found==0){
            pf[j]=ref_str[i];
            replaced=1;
            break;
          }
        }
        if (replaced==0){
          pf[max]=ref_str[i];
        }
      }
    }
    print(pf,npf);
  }
  cout<<"Page Faults: "<<page_faults;
}

//                           Optimal Ended                                    //

//                                 LFU                                        //
void LFU(int ref_str[],int npf,int nrs){
  int p=0;
  int pf[npf];
  for (int k=0;k<npf;k++){
    pf[k]=-1;
  }
  int i;
  int page_faults=0;
  // Page fault f=1 means element is present
  print(pf,npf);
  for (i=0;i<nrs;i++){
    // el = ref_str[i]
    if (page_fault(ref_str[i],pf,npf)==1){
      // No page fault
      continue;
    }
    else if (page_fault(ref_str[i],pf,npf)==0){
      // Page fault occured
      page_faults+=1;
      // Check empty space
      int assi=0;
      for (int j=0;j<npf;j++){
        // Empty space available
        if (pf[j]==-1){
          pf[j]=ref_str[i];
          assi=1;
          break;
        }
        else{
          continue;
        }
      }
      // No empty space was present
      if (assi==0){
        int count=99999;
        int index=0;
        for (int j=0;j<npf;j++){
          // Counting the frequency of number
          int sum=0;
          for (int m=i-1;m>=0;m--){
            if (ref_str[m]==pf[j]){
              sum+=1;
            }
          }
          if (sum<count){
            count=sum;
            index=j;
          }
        }
      pf[index]=ref_str[i];
      }
    }
    print(pf,npf);
  }
  cout<<"Page Faults: "<<page_faults;
}
//                                   LFU Ended                               //


int main(){
  int npf;
  cout<<"Enter the number of page frames: ";
  cin>>npf;

  int nrs,i;
  cout<<"Enter the length of the reference string: ";
  cin>>nrs;
  int ref_str[nrs];
  cout<<"Enter the reference string: "<<endl;
  for (i=0;i<nrs;i++)
  {
    cin>>ref_str[i];
  }

  //Options

  cout<<" || ===================== || \n Choose one of the following page replacement algorithms: \n\t1. FIFO\n\t2. LIFO\n\t3. LRU\n\t4. LFU\n\t5. Optimal\n || ====================== ||"<<endl;

  int o;
  cin>>o;
  // Switch case
  switch (o) {
    case(1):FIFO(ref_str,npf,nrs);
    break;
    case(2):LIFO(ref_str,npf,nrs);
    break;
    case(3):LRU(ref_str,npf,nrs);
    break;
    case(4):LFU(ref_str,npf,nrs);
    break;
    case(5):Optimal(ref_str,npf,nrs);
    break;
    default:cout<<"Invalid selection !!";
    break;
  }
}
