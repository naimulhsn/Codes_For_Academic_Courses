#include<bits/stdc++.h>
using namespace std;
//for holding process info
struct Process{
    int id,a_t,b_t,c_t,t_t,w_t,index;
};
//for sorting process according to arrival time
bool compare(Process x,Process y){
    if(x.a_t==y.a_t)return x.id<y.id;
    return x.a_t<y.a_t;
}

//for Overriding the priority queue to hold minimum burst time in the top
bool operator<(Process x, Process y){
    if(x.b_t==y.b_t){
        if(x.a_t==y.a_t)return x.id>y.id;
        return x.a_t>y.a_t;
    }
    return x.b_t > y.b_t;
}
//for sorting process according to id
bool compareid(Process x,Process y){
    return x.id<y.id;
}
int main()
{
    int n;
    cin>>n;
    Process p[n+1];
    int a[n+1],b[n+1];
    // Input stuff
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<n; i++)cin>>b[i];
    for(int i=0; i<n; i++){
        p[i].id=i+1;
        p[i].a_t=a[i];
        p[i].b_t=b[i];
    }
    //sort as arrival time
    sort(p,p+n,compare);
    for(int i=0; i<n; i++)p[i].index=i; // saving the index in the SJF;

    priority_queue <Process> pq;
    int time=0,it=0;

    while(it<n){
        if(pq.empty()){
            // if no process available we increase the time to the next process A_T
            if(time<p[it].a_t)time=p[it].a_t;
        }
        // Pushing the Process that are ready in the priority queue
        while(it<n && p[it].a_t<=time){
            pq.push(p[it]);
            it++;
        }
        // picking the one with minimum bust time from the queue.
        Process curr=pq.top();
        pq.pop();
        int pos=curr.index;
        // Calculating its C_T, T_T, W_T
        p[pos].c_t=time+p[pos].b_t;
        p[pos].t_t=p[pos].c_t- p[pos].a_t;
        p[pos].w_t=p[pos].t_t- p[pos].b_t;

        //Updating time
        time=p[pos].c_t;
    }
    // now all the remaining process is in the queue. and we will calculate them.
    while(!pq.empty()){
        Process curr= pq.top();
        pq.pop();
        int pos=curr.index;
        // Calculating its C_T, T_T, W_T
        p[pos].c_t=time+p[pos].b_t;
        p[pos].t_t=p[pos].c_t- p[pos].a_t;
        p[pos].w_t=p[pos].t_t- p[pos].b_t;
        //Updating Time
        time=p[pos].c_t;
    }


    //Sorting as the id for printing purpose
    sort(p,p+n,compareid);
    double avgWaiting=0;

    //Printing in a table format
    for(int j=0; j<100; j++)cout<<'-';
        cout<<"\n| process ID | Arrival_Time | Burst_Time | Completion_Time | Turnaround_Time | Waiting_Time |\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<100; j++)cout<<'-';
        cout<<"\n|      P"<<p[i].id<<"    ";
        cout<<"|      "<<p[i].a_t<<"      ";
        cout<<"|      "<<p[i].b_t<<"      ";
        cout<<"|      "<<p[i].c_t<<"         ";
        cout<<"|      "<<p[i].t_t<<"         ";
        cout<<"|      "<<p[i].w_t<<"      |\n";
        avgWaiting+=p[i].w_t;
    }
    for(int j=0; j<100; j++)cout<<'-';

    cout<<"\n\nAvarage Waiting time: "<<avgWaiting/n<<endl;
    return 0;
}

/*

5
1 2 3 4 5
7 5 1 2 8

*/

