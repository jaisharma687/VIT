#include <bits/stdc++.h>
using namespace std;

struct Process {
    int no, a, b, priority, wt, tat, rt, ct;
};

Process read(int i) {
    Process p;
    cout << "The process no.: " << i << endl;
    p.no = i;
    cout << "Enter the arrival time: ";
    cin >> p.a;
    cout << "Enter the burst time: ";
    cin >> p.b;
    p.rt = p.b;
    cout << "Enter the priority: ";
    cin >> p.priority;
    return p;
}

void printResults(const vector<Process>& p, float awt, float att, int mct) {
    cout << "Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (const auto& process : p) {
        cout << "P" << process.no << "\t\t" << process.a << "\t\t" << process.b
            << "\t\t" << process.priority << "\t\t" << process.ct << "\t\t" 
            << process.wt << "\t\t" << process.tat << endl;
    }
    cout << "Average Waiting Time: " << awt << endl;
    cout << "Average Turnaround Time: " << att << endl;
    cout << "Completion Time: " << mct << endl;
}

void preemptivePriorityScheduling(vector<Process>& p, int n) {
    int time = 0, completed = 0, mct = INT_MIN;
    float awt = 0, att = 0;
    vector<bool> is_completed(n, false);
    while (completed < n) {
        int idx = -1;
        int highest_priority = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (p[i].a <= time && !is_completed[i] && p[i].priority < highest_priority) {
                highest_priority = p[i].priority;
                idx = i;
            }
        }
        if (idx != -1) {
            time++;
            p[idx].rt--;
            if (p[idx].rt == 0) {
                is_completed[idx] = true;
                completed++;
                p[idx].ct = time;
                mct = max(mct, p[idx].ct);
                p[idx].tat = p[idx].ct - p[idx].a;
                p[idx].wt = p[idx].tat - p[idx].b;
                awt += p[idx].wt;
                att += p[idx].tat;
            }
        } else {
            time++;
        }
    }
    awt /= n;
    att /= n;
    printResults(p, awt, att, mct);
}

int main() {
    int n;
    vector<Process> p;
    cout << "Enter the number of processes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        p.push_back(read(i));
    }
    preemptivePriorityScheduling(p, n);
    return 0;
}
