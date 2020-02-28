#include<bits/stdc++.h>
using namespace std;
//for holding process info
struct Process{
    int id,a_t,b_t,c_t,t_t,w_t;
};
//for sorting process according to arrival time
bool compare(Process x,Process y){
    if(x.a_t==y.a_t)return x.b_t<y.b_t;
    else return x.a_t<y.a_t;
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
    int time=0;
    // as they are sorted we will calculate them one by one
    for(int i=0; i<n; i++){
        // if the process has not arrived then increase the time to the point of arrival time of this process.
        if(time<p[i].a_t){
            time=p[i].a_t;
        }
        // do the calculations.
        p[i].w_t=time-p[i].a_t;
        p[i].c_t=time+p[i].b_t;
        p[i].t_t=p[i].c_t-p[i].a_t;
        time=p[i].c_t;

    }
    // sort the process as their ID and Print them in a table format
    sort(p,p+n,compareid);
    double avgWaiting=0;
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
