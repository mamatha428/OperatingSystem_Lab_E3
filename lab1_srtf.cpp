//shortest time remaining first
//srtf
//preemptive scheduling algorithm
#include<bits/stdc++.h>
using namespace std;
struct process{
   int at;
   int bt;
   int tbt;//for printing purpose
   int ct;
   int tat;
   int wt;
};
int getp(struct process p[],int ct,int n){
   int i,mini=INT_MAX,x=-1;
   for(i=0;i<n;i++){
      if(p[i].at<=ct && p[i].bt!=0){
         if(p[i].bt<mini){
           mini=p[i].bt;
           x=i;
         }
         if(p[i].bt==mini){//whenver both bts are equal choose process which has lesser at value
           if(p[i].at<p[x].at){//actually it is coming to this condition,check once by dry run
             x=i;
             cout<<"came ";
           }
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
   cout<<"Enter at and bt values:";
   for(i=0;i<n;i++){
      cin>>p[i].at>>p[i].bt;
      p[i].tbt=p[i].bt;
   }
   //sum of all bt's for loop
   //as it is srtf
   for(i=0;i<n;i++){
      sum=sum+p[i].bt;
   }
   while(k<sum){
       h=getp(p,ct,n);
       if(h!=-1){
          cout<<"P"<<h+1<<"|";
          p[h].ct=ct+1;
          p[h].bt=p[h].bt-1;
          ct=p[h].ct;
          k++;
        }
        else{
          cout<<"-|";
          ct++;
        }
   }
   //printing
   cout<<"\nprocess\tAT\tBT\tCT\tTAT\tWT\n";
   for(i=0;i<n;i++){
      p[i].tat=p[i].ct-p[i].at;
      p[i].wt=p[i].tat-p[i].tbt;
      awt=awt+p[i].wt;
      atat=atat+p[i].tat;
      cout<<i+1<<"\t"<<p[i].at<<"\t"<<p[i].tbt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<endl;
   }
   cout<<"Average waiting time:"<<awt/n<<endl;
   cout<<"Average turn around time:"<<atat/n<<endl;
}
/* output
Enter number of processes:5
Enter at and bt values:3 1
1 4
4 2
0 6
2 3
P4|P2|P2|P1|P2|P2|P3|P3|P5|P5|P5|P4|P4|P4|P4|P4|
process	AT	BT	CT	TAT	WT
1	3	1	4	1	0
2	1	4	6	5	1
3	4	2	8	4	2
4	0	6	16	16	10
5	2	3	11	9	6
Average waiting time:3.8
Average turn around time:7


Enter number of processes:7
Enter at and bt values:5 1
2 1
4 3
1 10
3 4
1 8
2 6
-|P6|P2|P5|P5|P1|P5|P5|P3|P3|P3|P7|P7|P7|P7|P7|P7|P6|P6|P6|P6|P6|P6|P6|P4|P4|P4|P4|P4|P4|P4|P4|P4|P4|
process	AT	BT	CT	TAT	WT
1	5	1	6	1	0
2	2	1	3	1	0
3	4	3	11	7	4
4	1	10	34	33	23
5	3	4	8	5	1
6	1	8	24	23	15
7	2	6	17	15	9
Average waiting time:7.42857
Average turn around time:12.1429

Enter number of processes:6
Enter at and bt values:0 8
1 6
2 5
3 2
4 4
5 1
P1|P2|P2|P4|P4|P6|P2|P2|P2|P2|P5|P5|P5|P5|P3|P3|P3|P3|P3|P1|P1|P1|P1|P1|P1|P1|
process	AT	BT	CT	TAT	WT
1	0	8	26	26	18
2	1	6	10	9	3
3	2	5	19	17	12
4	3	2	5	2	0
5	4	4	14	10	6
6	5	1	6	1	0
Average waiting time:6.5
Average turn around time:10.8333
*/


   
          
