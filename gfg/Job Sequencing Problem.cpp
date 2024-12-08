//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job {
    int id;       // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is over before or on deadline
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> JobScheduling(Job jbs[], const int n) {
        std::vector<Job> jobs(jbs, jbs+n);
        std::sort(jobs.begin(), jobs.end(), [](Job a, Job b) {return a.profit > b.profit;});
        int max_delay = 0;
        for (const auto& job : jobs) {
            max_delay = std::max(max_delay, job.deadline);
        }

        std::vector<bool> jobs_seq(max_delay + 1, false);
        int cnt = 0, max_profit = 0;

        for (const auto& job : jobs) {
            int i = job.deadline;

            while (jobs_seq[i] and i >= 1)
                i--;

            if (i >= 1) {
                max_profit += job.profit;
                jobs_seq[i] = true;
                cnt++;
            }
        }

        return {cnt, max_profit};
    }
};



//{ Driver Code Starts.
//    Driver program to test methods
int main() {
    freopen("input", "r", stdin);
    int t;
    // testcases
    cin >> t;

    while (t--) {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].deadline = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends
