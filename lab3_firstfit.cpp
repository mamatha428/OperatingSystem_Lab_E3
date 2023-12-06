//firstfit
//memory allocation
//saripoyedaantlo first block
#include<bits/stdc++.h>
using namespace std;
void firstfit(int block[],int bs,int process[],int ps){
   int allocated[ps];
   //firstly allocated array is of -1
   for(int i=0;i<ps;i++){
      allocated[i]=-1;
   }
   for(int i=0;i<ps;i++){
      for(int j=0;j<bs;j++){
          if(block[j]>=process[i]){
             allocated[i]=j;
             block[j]=block[j]-process[i];
             break;
           }
       }
  }
  cout<<"processNo\tprocess size\tblock allocated\tblock size\n";
  for(int i=0;i<ps;i++){
     if(allocated[i]!=-1){
       cout<<i+1<<"\t\t"<<process[i]<<"\t\t"<<allocated[i]+1<<"\t\t"<<block[i]<<endl;
     }
     else{
       cout<<i+1<<"\t\t"<<process[i]<<"\t\t"<<"Not allocated"<<"\t\t"<<block[i]<<endl;
     }
  }
}
/*
Enter number of blocks:5
Enter number of processes:4
Enter block sizes:100
500
200
300
600
Enter process sizes:212
417
112
426
processNo	process size	block allocated	block size
1		212		2		100
2		417		5		176
3		112		2		200
4		426		Not allocated		300
*/
  
             
             
int main(){
   int bs,ps,i;
   cout<<"Enter number of blocks:";
   cin>>bs;
   int block[bs];
   cout<<"Enter number of processes:";
   cin>>ps;
   int process[ps];
   cout<<"Enter block sizes:";
   for(i=0;i<bs;i++){
      cin>>block[i];
   }
   cout<<"Enter process sizes:";
   for(i=0;i<ps;i++){
       cin>>process[i];
   }
   firstfit(block,bs,process,ps);
   return 0;
}
    
