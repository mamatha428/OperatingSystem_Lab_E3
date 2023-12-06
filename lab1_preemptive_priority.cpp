//preemptive priority
//accoring to the priority
#include<bits/stdc++.h>
using namespace std;
struct process{
    int at;
    int bt;
    int tbt;
    int priority;
    int ct;
    int tat;
    int wt;
};

int getp(struct process p[],int ct,int n){
    int i,mini=INT_MAX,x=-1;
    for(i=0;i<n;i++){//i kept comma here though error not came but segmentation fault came
       if(p[i].at<=ct && p[i].bt!=0){
          if(p[i].priority<mini){
            mini=p[i].priority;
            x=i;
          }
          if(p[i].priority==mini){
            if(p[i].at<p[x].at){
              x=i;
            }
          }
       }
    }
    return x;
}
//for greater value is taken as more priority then we have this getp
int getprior(struct process p[],int ct,int n){
    int i,maxi=INT_MIN,x=-1;
    for(i=0;i<n;i++){
       if(p[i].at<=ct && p[i].bt!=0){
          if(p[i].priority>maxi){
             maxi=p[i].priority;
             x=i;
          }
       }
    }
    return x;
}
int main(){
    int n,i,h,ct=0,k=0,sum=0;
    float awt=0,atat=0;
    cout<<"Enter number of processes:";
    cin>>n;
    struct process p[n];
    cout<<"Enter at,bt and priority values:";
    for(i=0;i<n;i++){
       cin>>p[i].at>>p[i].bt>>p[i].priority;
       p[i].tbt=p[i].bt;
    }
    //calculating sum
    for(i=0;i<n;i++){
       sum=sum+p[i].bt;
    }
    while(k<sum){
       h=getp(p,ct,n);
       if(h!=-1){
          cout<<"P"<<h+1<<"|";
          p[h].ct=ct+1;
          ct=p[h].ct;
          p[h].bt=p[h].bt-1;
          k++;
       }
       else{
          cout<<"-|";
          ct++;
       }
    }
    cout<<"\nprocess\tAT\tBT\tpriority\tCT\tTAT\tWT\n";
    for(i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].tbt;
        awt=awt+p[i].wt;
        atat=atat+p[i].tat;
        cout<<i+1<<"\t"<<p[i].at<<"\t"<<p[i].tbt<<"\t"<<p[i].priority<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<endl;
    }
    cout<<"Average waiting time:"<<awt/n<<endl;
    cout<<"Average turn around time:"<<atat/n<<endl;
}
/* output
Enter number of processes:7
Enter at,bt and priority values:0 4 2
1 2 4
2 3 6
3 5 1
4 1 8
5 4 3
11 6 2
P1|P1|P1|P4|P4|P4|P4|P4|P1|P6|P6|P7|P7|P7|P7|P7|P7|P6|P6|P2|P2|P3|P3|P3|P5|
process	AT	BT	priority	CT	TAT	WT
1	0	4	2	9	9	5
2	1	2	4	21	20	18
3	2	3	6	24	22	19
4	3	5	1	8	5	0
5	4	1	8	25	21	20
6	5	4	3	19	14	10
7	11	6	2	17	6	0
Average waiting time:10.2857
Average turn around time:13.8571
*/

     
