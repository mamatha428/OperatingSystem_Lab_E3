//fcfs
//non-preemptive
//the processes which are having lesser at will be considered first 
#include<bits/stdc++.h>
using namespace std;
struct process{
   int at;
   int bt;
   int ct;
   int wt;
   int tat;
   int c;
};
int getp(struct process p[],int ct,int n){
    int i,mini=INT_MAX,x=-1;
    //here x=-1 wil be returned incase of ideal case
    for(i=0;i<n;i++){
       if(p[i].at<=ct && p[i].c!=1){
          if(p[i].at<mini){
            mini=p[i].at;
            x=i;
          }
       }
    }
    return x;
}

int main(){
   int n,i,h,k=0,ct=0;
   float awt=0,atat=0;
   cout<<"Enter number of processes:";
   cin>>n;
   struct process p[n];
   cout<<"Enter at and bt values:";
   for(i=0;i<n;i++){
      cin>>p[i].at>>p[i].bt;
   }
   while(k<n){
      //get process with lesser at value
      int h=getp(p,ct,n);
      if(h!=-1){
      //gant chat printing 
        cout<<"P"<<h+1<<"|";
        p[h].ct=ct+p[h].bt;
        ct=p[h].ct;
        p[h].tat=p[h].ct-p[h].at;
        p[h].wt=p[h].tat-p[h].bt;
        p[h].c=1;
        k++;
      }
      else{
        //ideal case
        cout<<"-|";
        ct++;
      }
  }
  //printing 
  cout<<"\nprocess\tAT\tBT\tCT\tWT\tTAT\n";
  for(i=0;i<n;i++){
     atat=atat+p[i].tat;
     awt=awt+p[i].wt;
     cout<<i+1<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].wt<<"\t"<<p[i].tat<<endl;
  }
}
  
        
      
      
      
      
      
      
      
      
      
      
      
        
  
