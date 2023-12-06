//C++ Program to implement Round Robin 
//Scheduling CPU Algorithm
/*
#include <iostream>
#include <vector>

/*at = Arrival time,
bt = Burst time,
time_quantum= Quantum time
tat = Turn around time,
wt = Waiting time

using namespace std;

int main(){
	int i,n,time,remain,temps=0,time_quantum;

	int wt=0,tat=0;

	cout<<"Enter the total number of process="<<endl;
	cin>>n;

	remain=n;
	// assigning the number of process to remain variable
 
	vector<int>at(n);
	vector<int>bt(n);
	vector<int>rt(n);
	//dynamic array declaration using vector method of (STL)
	//STL standard template library of C++

	cout<<"Enter the Arrival time, Burst time for All the processes"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>at[i];
		cin>>bt[i];
		rt[i]=bt[i];
	}

	cout<<"Enter the value of time QUANTUM:"<<endl;
	cin>>time_quantum;

	cout<<"\n\nProcess\t:Turnaround Time:Waiting Time\n\n";
	for(time=0,i=0;remain!=0;)
	{
		if(rt[i]<=time_quantum && rt[i]>0)
		{
			time += rt[i];
			//Addition using shorthand operators
			rt[i]=0;
			temps=1;
		}

		else if(rt[i]>0)
		{
			rt[i] -= time_quantum;
			//Subtraction using shorthand operators
			time += time_quantum;
			//Addition using shorthand operators
		}

		if(rt[i]==0 && temps==1)
		{
			remain--;
			//Desplaying the result of wating, turn around time:
			printf("Process{%d}\t:\t%d\t:\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
			cout<<endl;

			wt += time-at[i]-bt[i];
			tat += time-at[i];
			temps=0;
		}

		if(i == n-1)
			i=0;
		else if(at[i+1] <= time)
			i++;
		else
			i=0;
	}

	cout<<"Average waiting time "<<wt*1.0/n<<endl;
	cout<<"Average turn around time "<<tat*1.0/n<<endl;;

	return 0;
} */
/*
//another one
#include <iostream>
#include <climits>
using namespace std;

struct Process {
	int AT, BT, ST[20], WT, FT, TAT, pos;
};

int quant;

int main() {
	int n, i, j;

	// Taking Input
	cout << "Enter the no. of processes: ";
	cin >> n;
	Process p[n];

	cout << "Enter the quantum: " << endl;
	cin >> quant;

	cout << "Enter the process numbers: " << endl;
	for (i = 0; i < n; i++)
		cin >> p[i].pos;

	cout << "Enter the Arrival time of processes: " << endl;
	for (i = 0; i < n; i++)
		cin >> p[i].AT;

	cout << "Enter the Burst time of processes: " << endl;
	for (i = 0; i < n; i++)
		cin >> p[i].BT;

	// Declaring variables
	int c = n, s[n][20],temp[20],l=0;;
	float time = 0, mini = INT_MAX, b[n], a[n];

	// Initializing burst and arrival time arrays
	int index = -1;
	for (i = 0; i < n; i++) {
		b[i] = p[i].BT;
		a[i] = p[i].AT;
		for (j = 0; j < 20; j++) {
			s[i][j] = -1;
		}
	}

	int tot_wt, tot_tat;
	tot_wt = 0;
	tot_tat = 0;
	bool flag = false;

	while (c != 0) {
		mini = INT_MAX;
		flag = false;

		for (i = 0; i < n; i++) {
			float p = time + 0.1;
			if (a[i] <= p && mini > a[i] && b[i] > 0) {
				index = i;
				mini = a[i];
				flag = true;
			}
		}

		// if at =1 then loop gets out hence set flag to false
		if (!flag) {
			time++;
			continue;
		}

		// calculating start time
		j = 0;

		while (s[index][j] != -1) {
			j++;
		}

		if (s[index][j] == -1) {
			s[index][j] = time;
			p[index].ST[j] = time;
		}

		if (b[index] <= quant) {
			time += b[index];
			//for ready queue printing
			temp[l++]=index+1;
			cout<<"p"<<index+1<<endl;
			cout<<"time1:"<<time<<" "<<endl;
			b[index] = 0;
		} else {
			time += quant;
			temp[l++]=index+1;
			cout<<"p"<<index+1<<endl;
			cout<<"time2:"<<time<<" "<<endl;
			b[index] -= quant;
		}

		if (b[index] > 0) {
			a[index] = time + 0.1;
		}

		// calculating arrival, burst, final times
		if (b[index] == 0) {
			c--;
			p[index].FT = time;
			//cout<<"t:"<<p[index].FT<<" ";
			p[index].WT = p[index].FT - p[index].AT - p[index].BT;
			//cout<<"w:"<<p[index].WT<<" ";
			tot_wt += p[index].WT;
			p[index].TAT = p[index].BT + p[index].WT;
			tot_tat += p[index].TAT;
		}
	} // end of while loop

	// Printing output
	cout<<"Ready queue:";
	for(i=0;i<l;i++){
	    cout<<"P"<<temp[i]<<" ";
	}
	cout<<endl;
	cout << "\nProcess number ";
	cout << "Arrival time ";
	cout << "Burst time ";
	//cout << "\tStart time";
	//j = 0;
	//while (j != 10) {
	//	j += 1;
	//	cout << " ";
	//}
	cout << "\t\tFinal time";
	cout << "\tWait Time ";
	cout << "\tTurnAround Time" << endl;

	for (i = 0; i < n; i++) {
		cout << p[i].pos << "\t\t";
		cout << p[i].AT << "\t\t";
		cout << p[i].BT << "\t";
		//j = 0;
		//int v = 0;
		//while (s[i][j] != -1) {
			//cout << p[i].ST[j] << " ";
			//j++;
			//v += 3;
		//}
		//while (v != 40) {
			//cout << " ";
			//v += 1;
		//}
		cout << p[i].FT << "\t\t";
		cout << p[i].WT << "\t\t";
		cout << p[i].TAT << endl;
	}

	// Calculating average wait time and turnaround time
	double avg_wt, avg_tat;
	avg_wt = tot_wt / static_cast<double>(n);
	avg_tat = tot_tat / static_cast<double>(n);

	// Printing average wait time and turnaround time
	cout << "The average wait time is: " << avg_wt << endl;
	cout << "The average TurnAround time is: " << avg_tat << endl;

	return 0;
}
*/
//i wrote this
//preemptive sheduling algorithm 
//round robin code

#include<bits/stdc++.h>
using namespace std;
struct point{
   int at;
   int bt;
   int ct;
   int tat;
   int wt;
};
int main(){
   int n,quant;
   cout<<"Enter number of processes:";
   cin>>n;
   struct point p[n];
   cout<<"Enter at and bt values:";
   for(int i=0;i<n;i++){
      cin>>p[i].at>>p[i].bt;
   }
   cout<<"Enter quant value:";
   cin>>quant;
   int c=n,index=-1,l=0,i;
   float awt=0,atat=0,time=0,mini=INT_MAX,a[n],b[n];
   bool flag=false;
   //copying at values of struct to the a array
   //copying bt values of struct to the b array
   int temp[20];
   for(int i=0;i<n;i++){
      a[i]=p[i].at;
      b[i]=p[i].bt;
   }
   
   while(c!=0){
       mini=INT_MAX;
       flag=false;
       for(i=0;i<n;i++){
       float p=time+0.1;
          if(a[i]<=p && mini>a[i] && b[i]>0){
             mini=a[i];
             index=i;
             flag=true;
           }
       }
       if(!flag){
         time++;
         continue;
       }
       if(b[index]<=quant){
          temp[l++]=index+1;
          time=time+b[index];
          b[index]=0;
       }
       else{
          temp[l++]=index+1;
          time=time+quant;
          b[index]=b[index]-quant;
       }
       if(b[index]>0)
          a[index]=time+0.1;
       if(b[index]==0){
          c--;
          p[index].ct=time;
          p[index].wt=p[index].ct-p[index].at-p[index].bt;
          p[index].tat=p[index].wt+p[index].bt;
          atat=atat+p[index].tat;
          awt=awt+p[index].wt;
       }
   }
   //printing
   cout<<"Ready Queue:";
   for(i=0;i<l;i++){
      cout<<"P"<<temp[i]<<" ";
   }
   cout<<endl;
   cout<<"processNo\tAT\tBT\tCT\tWT\tTAT\n";
   for(i=0;i<n;i++){
      cout<<"P"<<i+1<<"\t\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].wt<<"\t"<<p[i].tat<<endl;
   }
   cout<<"Average waiting time:"<<awt/n<<endl;
   cout<<"Average turn around time:"<<atat/n<<endl;
}
   
   
          
         
   
   

