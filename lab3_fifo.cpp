//fifo page replacement algorithm
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
/*
   int pages;
   cout<<"Enter the number of pages:";
   cin>>pages;
   int a[pages];
   cout<<"Enter the process numbers:";
   for(i=0;i<pages;i++){
      cin>>a[i];
   }*/
   int a[]={7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1};
   int pages=sizeof(a)/sizeof(a[0]);
   int frames;
   cout<<"Enter number of frames:";
   cin>>frames;
   int i,j,s,pf=0;
   int temp[frames];
   for(i=0;i<frames;i++){
      temp[i]=-1;
   }
   cout<<"Input Page\tFrame1\t\tFrame2\t\tFrame3"<<endl;
   for(i=0;i<pages;i++){
      s=0;
      for(j=0;j<frames;j++){
         if(a[i]==temp[j]){
            s++;
            pf--;
         }
      }
      pf++;
      if(pf<=frames && s==0){//first filling frames at the brginning
        temp[i]=a[i];
      }
      else if(s==0){//whenever page not found in full frames then replacement fifo happens here
        temp[(pf-1)%frames]=a[i];
      }
      cout<<a[i]<<"\t\t";
      for(j=0;j<frames;j++){
         if(temp[j]!=-1)
           cout<<temp[j]<<"\t\t";
         else
           cout<<"-"<<"\t\t";
      }
      cout<<endl;
  }
  cout<<"Page faults:"<<pf<<endl;
  cout<<"Page Hits:"<<pages-pf<<endl;
 }
  
   
   
