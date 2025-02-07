#include <bits/stdc++.h>
using namespace std;

struct task
    {
        int taskId;
        string assigneeName;
        string reviewerName;
        string status;
        int estimateInHours;

    };

void AssigningReviewer(vector<task>tasks){
    int NumberOfTasks = tasks.size();
    cout<<NumberOfTasks<<endl;
    map<string,int>TotalWorkingHourOfIndivitual;

    for(int i=0 ; i<NumberOfTasks ; i++){
        TotalWorkingHourOfIndivitual[tasks[i].assigneeName] += tasks[i].estimateInHours * 3;

        if(tasks[i].reviewerName != "null"){
            TotalWorkingHourOfIndivitual[tasks[i].reviewerName] += task[i].estimateInHours;
        }
        
    }
    set<pair<int,string>>workingHoursInSorted;
    for(int i=0 ; i<NumberOfTasks ; i++){
        workingHoursInSorted.insert(tasks[i].assigneeName, TotalWorkingHourOfIndivitual[tasks[i].assigneeName]);
    }


    for(int i=0 ; i<NumberOfTasks ; i++){
        
        if(tasks[i].reviewerName == "null" && tasks[i].status = "in-review"){

            // assing member for review
            auto LowestWorkingHourOne = *workingHoursInSorted.begin();
            tasks[i].reviewerName = LowestWorkingHourOne.second;
            
            //updatin working hour
            workingHoursInSorted.erase(LowestWorkingHourOne);
            workingHoursInSorted.insert({LowestWorkingHourOne.first+task[i].estimateInHours, LowestWorkingHourOne.second})
        }
        
    }

    // print tasks with assigned reviewers
    for(int i=0 ; i<NumberOfTasks ; i++){
        cout<<tasks[i].taskId<<endl;
        cout<<tasks[i]. assigneeName<<endl;
        cout<<tasks[i].reviewerName<<endl;
        cout<<tasks[i].status<<endl;
        cout<<tasks[i].estimateInHours<<endl;
    }

}

void solve(int tc)
{
   
    
    vector<task>tasks;

    tasks.push_back({1, "Hasan", "Mahedi", "In-review", 8});
    AssigningReviewer(tasks);
    
}
    

int main()
{
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}