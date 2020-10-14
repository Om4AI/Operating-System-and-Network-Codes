# include <iostream>
using namespace std;


int main()
{
    int n,mr,ca,a,i,t;
    int total_ca=0;
    cout<<"Enter the number of processes: \n";
    cin>>n;
    string names[n];
    int max_req[n];
    int extra[n];
    int curr_allo[n];
    cout<<"Enter the total resources available: \n";
    cin>>a;
    cout<<"Enter the processes: \n";
    for (i=0;i<n;i++)
    {
        cin>>names[i];
    }
    cout<<"Enter the max requirements for the processes: \n";
    for (i=0;i<n;i++)
    {
        cin>>t;
        max_req[i]=t;
        extra[i]=t;
    }
    cout<<"Enter the current allocation values: \n";
    for (i=0;i<n;i++)
    {
        cin>>curr_allo[i];
        total_ca+=curr_allo[i];
    }

    // Balance is the need after the current allocation
    int balance[n];
    for (i=0;i<n;i++)
    {
        balance[i]=max_req[i]-curr_allo[i];
    }
    // Printing the NEED of resources
    cout<<"The need for the processes: \n";
    for (i=0;i<n;i++)
    {
        cout<<balance[i]<<" ";
    }
    cout<<"\n\n";

    int bal;
    bal=a-total_ca;


    // Sorting Balance
    int j;
    for (i=0;i<n-1;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (balance[i]>balance[j])
            {
              swap(balance[i],balance[j]);
              swap(max_req[i],max_req[j]);
            }
            else
            continue;
        }
    }

    int f=0;
    int f_max_req[n];
    string f_names[n];

    // Conditions
    if (balance[0]>bal)
    {
        cout<<"Unsafe state !! \n";
    }
    else
    {
        for (i=0;i<n;i++)
        {
          if (bal>=balance[i])
          {
            bal-=balance[i];
            bal+=max_req[i];
            f_max_req[i]=max_req[i];
          }
          else
          {
            cout<<"Unsafe State!! \n";
            f=1;
            break;
          }
        }


        if (f==0)
        {
          for (i=0;i<n;i++)
          {
              for (j=0;j<n;j++)
              {
                  if (f_max_req[i]==extra[j])
                  {
                      f_names[i]=names[j];
                  }
                  else
                  continue;
              }
          }
          cout<<"The Safe Sequence: "<<endl;
          for (i=0;i<n;i++)
          {
              cout<<f_names[i]<<" ";
          }
        }
    }

}
