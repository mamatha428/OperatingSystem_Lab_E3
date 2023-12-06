//bestfit
//saripoyedaantlo chinnadi
#include<bits/stdc++.h>
using namespace std;

void bestfit(int blocks[],int bs,int process[],int ps){
    int allocated[ps];
    for(int i=0;i<ps;i++){
       allocated[i]=-1;
    }
    for(int i=0;i<ps;i++){
       int bestIndex=-1;
       for(int j=0;j<bs;j++){
         
           if(blocks[j]>=process[i]){
              if(bestIndex==-1){
                 bestIndex=j;
               }
               else if(blocks[bestIndex]>blocks[j]){
                   bestIndex=j;
               }
            }   
         }
         blocks[bestIndex]=blocks[bestIndex]-process[i];
         allocated[i]=bestIndex;
     }
     //printing
     cout<<"processNO\tprocess size\tblock allocated\n";
     for(int i=0;i<ps;i++){
        if(allocated[i]!=-1){
          cout<<i+1<<"\t\t"<<process[i]<<"\t\t"<<allocated[i]+1<<endl;
        }
        else{
            cout<<i+1<<"\t\t"<<process[i]<<"\t\t"<<"Not allocated"<<endl;
        }
     }    
}
            
                
int main(){
    int blocks[]={100,500,200,300,600};
    int bs=sizeof(blocks)/sizeof(blocks[0]);
    int process[]={212,417,112,426};
    int ps=sizeof(process)/sizeof(process[0]);
    bestfit(blocks,bs,process,ps);
    return 0;
}

