# include<iostream>
using namespace std;

// void safe_state(int need[p][r],int max[p][r],int remaining[r])
// {
//
//
//
//
//
//
// }


int main()
{
  int r,p,i,j;
  cout<<"Enter the number of resources: ";
  cin>>r;
  cout<<"Enter the number of processes: \n";
  cin>>p;
  int avail[r];
  int curr_allo[p][r];
  int max[p][r],extra_max[p][r];
  int need[p][r];
  string re_names[r];
  string pro_names[p];

  cout<<"Enter the names of the resources";
  for (i=0;i<r;i++)
  {
    string t;
    cin>>t;
    re_names[i]=t;
  }

  cout<<"Enter the names of the processes";
  for (i=0;i<p;i++)
  {
    string t1;
    cin>>t1;
    pro_names[i]=t1;
  }


  // Getting the available resources
  cout<<"Enter the available resources: \n";
  for (i=0;i<r;i++)
  {
    cin>>avail[i];
  }

  // Getting the Max_req matrix

  cout<<"Enter the maximum requirements for processes: \n";
  for (i=0;i<p;i++)
  {
    for (j=0;j<r;j++)
    {
      cin>>max[i][j];
    }
  }
// Initializing the total curr allo matrix
  int total_ca[r];
  for (i=0;i<r;i++)
  {
    total_ca[i]=0;
  }

  // Getting the current allocation matrix

  cout<<"Enter the current allocation for the processes: \n";
  for (i=0;i<p;i++)
  {
    for (j=0;j<r;j++)
    {
      cin>>curr_allo[i][j];
      total_ca[j]+=curr_allo[i][j];
    }
  }
  // Computing the need matrix
  for (i=0;i<p;i++)
  {
    for (j=0;j<r;j++)
    {
      need[i][j]=max[i][j]-curr_allo[i][j];
    }
  }

  // Printing the need matrix
  cout<<"The Need Matrix is: \n";
  for (i=0;i<p;i++)
  {
    for(j=0;j<r;j++)
    {
      cout<<need[i][j]<<" ";
    }
    cout<<"\n";
  }


  int remaining[r];
  for (i=0;i<r;i++)
  {
    remaining[i]=avail[i]-total_ca[i];
  }
  safe_state(need,max,remaining);

}
