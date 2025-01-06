#include<bits/stdc++.h>
using namespace std;

struct Process {
    int a, b, no, wt, tat, ct;
};

Process read(int i) {
    Process p;
    cout << "The process no.: " << i + 1 << endl;
    p.no = i + 1;
    cout << "Enter the arrival time: ";
    cin >> p.a;
    cout << "Enter the burst time: ";
    cin >> p.b;
    return p;
}

void printResults(const vector<Process>& p, float awt, float att, int mct) {
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (const auto& process : p) {
        cout << "P" << process.no << "\t\t" << process.a << "\t\t" << process.b
            << "\t\t" << process.ct << "\t\t" << process.wt << "\t\t" << process.tat << endl;
    }
    cout << "Average Waiting Time: " << awt << endl;
    cout << "Average Turnaround Time: " << att << endl;
    cout << "Completion Time: "<< mct << endl;
}

void sjfs(vector<Process>& p) {
    int n = p.size();
    float awt = 0, att = 0, curr_time = 0;
    vector<bool> done(n, false);
    int completed = 0, mct = INT_MIN;
    while (completed < n) {
        int idx = -1, min_burst = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].a <= curr_time && p[i].b < min_burst) {
                min_burst = p[i].b;
                idx = i;
            }
        }
        if (idx == -1) {
            curr_time++;
            continue;
        }
        p[idx].wt = curr_time - p[idx].a;           
        p[idx].tat = p[idx].wt + p[idx].b;          
        p[idx].ct = curr_time + p[idx].b;           
        curr_time += p[idx].b;                      
        done[idx] = true;
        mct = max(mct, p[idx].ct);
        completed++;
        awt += p[idx].wt;
        att += p[idx].tat;
    }
    
    awt /= n;
    att /= n;
    printResults(p, awt, att, mct);
}

int main() {
    int n;
    vector<Process> p;
    cout << "Enter number of processes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        p.push_back(read(i));
    }
    sjfs(p);
    return 0;
}
