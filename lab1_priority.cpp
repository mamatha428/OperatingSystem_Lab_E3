//non-preemptive priority
//according to the priority the process will be considered
#include<bits/stdc++.h>
using namespace std;
struct process{
     int at;
     int bt;
     int priority;
     int ct;
     int tat;
     int wt;
     int c;
};
int getp(struct process p[],int ct,int n){
     int i,mini=INT_MAX,x=-1;
     for(i=0;i<n;i++){
        if(p[i].at<=ct && p[i].c!=1){
           if(p[i].priority<mini){
              mini=p[i].priority;
              x=i;
           }
        }
     }
     return x;
}
//for greater value having higher priority
int getprior(struct process p[],int ct,int n){
     int i,maxi=INT_MIN,x=-1;
     for(i=0;i<n;i++){
        if(p[i].at<=ct && p[i].c!=1){
           if(p[i].priority>maxi){
              maxi=p[i].priority;
              x=i;
           }
        }
     }
     return x;
}
int main(){
     int n,h,i,ct=0,k=0;
     float awt=0,atat=0;
     cout<<"Enter number of processes:";
     cin>>n;
     struct process p[n];
     cout<<"Enter at,bt and priority values:";
     for(i=0;i<n;i++){
        cin>>p[i].at>>p[i].bt>>p[i].priority;
     }
     while(k<n){
        h=getprior(p,ct,n);
        if(h!=-1){
           cout<<"P"<<h+1<<"|";//gant chat printing
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
    cout<<"\nprocess\tAT\tBT\tCT\tpriority\tTAT\tWT\n";
    for(i=0;i<n;i++){
       atat=atat+p[i].tat;
       awt=awt+p[i].wt;
       cout<<i+1<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].priority<<"\t\t"<<p[i].tat<<"\t"<<p[i].wt<<endl;
    }
    cout<<"Average waiting time:"<<awt/n<<endl;
    cout<<"Average turn around time"<<atat/n<<endl;
}
/* output
Enter number of processes:5
Enter at,bt and priority values:0 4 2 
1 3 3
2 1 4
3 5 5
4 2 5
P1|P2|P3|P4|P5|
process	AT	BT	CT	priority	TAT	WT
1	0	4	4	2	4	0
2	1	3	7	3	6	3
3	2	1	8	4	6	5
4	3	5	13	5	10	5
5	4	2	15	5	11	9
Average waiting time:4.4
Average turn around time7.4
*/
     
