// C++ program for page replacement algorithms 
#include <iostream> 
#include<bits/stdc++.h> 
using namespace std; 


int main() 
{ 
int capacity = 4; 
int arr[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; 

deque<int> q(capacity); 
int count=0; 
int page_faults=0; 
deque<int>::iterator itr; 
q.clear(); 
for(int i:arr) 
{ 

	// Insert it into set if not present 
	// already which represents page fault 
	itr = find(q.begin(),q.end(),i); 
	if(!(itr != q.end())) 
	{ 

	++page_faults; 

	// Check if the set can hold equal pages 
	if(q.size() == capacity) 
	{ 
		q.erase(q.begin()); 
		q.push_back(i); 
		for(auto it=q.begin();it!=q.end();++it){
		   cout<<*it<<"\t";
		}
		cout<<endl;
		
	} 
	else{ 
		q.push_back(i); 
		if(q.size()==1)
		  cout<<q.begin()<<"\t"<<"-"<<"\t"<<"-";//i write for 3 frames
		if(q.size()==2)
		  cout<<q.begin()<<"\t"<<q.end()<<"\t"<<"-";
                if(q.size()>2){
                   for(auto it=q.begin();it!=q.end();++it){
                      cout<<*it<<"\t";
                   }
                   cout<<endl;
                }
	} 
	} 
	else
	{ 
	// Remove the indexes page 
	q.erase(itr); 

	// insert the current page 
	q.push_back(i);	
	for(auto it=q.begin();it!=q.end();++it){
	   cout<<*it<<"\t";
	}
	cout<<endl;	 
	} 

} 
cout<<"pf:"<<page_faults; 
} 
/*
int main(){
   int n=3;
   int a[n];
   for(int i=0;i<n;i++){
      cout<<a[i]<<" ";
   }
}*/

// This code is contributed by Akshit Saxena 
