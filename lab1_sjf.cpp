//shortest job first-sjf
//non preemptive
//process will be considered according to their lowest bt values
#include<bits/stdc++.h>
using namespace std;
struct process{
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int c;
};
//returning lowest bt valued process index
int getp(struct process p[],int ct,int n){
    int i,mini=INT_MAX,x=-1;
    //here x=-1 is returned whenever ideal case comes
    for(i=0;i<n;i++){
       if(p[i].at<=ct && p[i].c!=1){
         if(p[i].bt<mini){
           mini=p[i].bt;
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
       h=getp(p,ct,n);
       if(h!=-1){
       cout<<"P"<<h+1<<"|";
          p[h].ct=ct+p[h].bt;
          ct=p[h].ct;//because for the next process this will be the ct
          p[h].tat=p[h].ct-p[h].at;
          p[h].wt=p[h].tat-p[h].bt;
          p[h].c=1;
          k++;
       }
       else{
          //ideal case printing
          cout<<"-|";
          ct++;
       }
    }
    //printing
    cout<<"\nprocess\tAT\tBT\tCT\tTAT\tWT\n";
    for(i=0;i<n;i++){
       cout<<i+1<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<endl;
       atat=atat+p[i].tat;
       awt=awt+p[i].wt;
    }
    cout<<"Average waiting time:"<<awt/n<<endl;
    cout<<"Average turn around time:"<<atat/n<<endl;
}
/* output
Enter number of processes:7
Enter at and bt values:5 1
2 1
4 3
1 10
3 4
1 8
2 6
-|P6|P1|P2|P3|P5|P7|P4|
process	AT	BT	CT	TAT	WT
1	5	1	10	5	4
2	2	1	11	9	8
3	4	3	14	10	7
4	1	10	34	33	23
5	3	4	18	15	11
6	1	8	9	8	0
7	2	6	24	22	16
Average waiting time:9.85714
Average turn around time:14.5714
*/
    
    
    
    
    
    
    
