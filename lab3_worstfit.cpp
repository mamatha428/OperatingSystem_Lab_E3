//worst fit
//process saripoyedaantlo peddadi
#include<bits/stdc++.h>
using namespace std;

void worstfit(int blocks[],int bs,int process[],int ps){
   int allocated[ps];
   memset(allocated,-1,sizeof(allocated));
   for(int i=0;i<ps;i++){
       int worstIndex=-1;
       for(int j=0;j<bs;j++){
          if(blocks[j]>=process[i]){
             if(worstIndex==-1)
               worstIndex=j;
             else if(blocks[worstIndex]<blocks[j])
               worstIndex=j;
           }
        }
        if(worstIndex!=-1){//if in case no block is suitable for given process
        //then b[-1] doen not exits that means that process is not allocated
        //if we do not write this condition b[-1] is not defines
          allocated[i]=worstIndex;
          blocks[worstIndex]=blocks[worstIndex]-process[i];
        }
    }
    //printing
    cout<<"processNo\tprocess size\tblock allocated\n";
    for(int i=0;i<ps;i++){
       if(allocated[i]!=-1){
          cout<<i+1<<"\t\t"<<process[i]<<"\t\t"<<allocated[i]+1<<endl;
       }
       else{
          cout<<i+1<<"\t\t"<<process[i]<<"\t\t"<<"Not Allocated"<<endl;
       }
    }
}
          
           
int main(){
   int blocks[]={100,500,200,300,600};
   int bs=sizeof(blocks)/sizeof(blocks[0]);
   int process[]={212,417,112,426};
   int ps=sizeof(process)/sizeof(process[0]);
   worstfit(blocks,bs,process,ps);
   return 0;
}

