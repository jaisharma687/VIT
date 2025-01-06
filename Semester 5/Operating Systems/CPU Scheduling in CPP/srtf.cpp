#include <bits/stdc++.h>
using namespace std;

struct Process {
    int a, b, no, wt, tat, rt, ct;
};

Process read(int i) {
    Process p;
    cout << "The process no.: " << i + 1 << endl;
    p.no = i + 1;
    cout << "Enter the arrival time: ";
    cin >> p.a;
    cout << "Enter the burst time: ";
    cin >> p.b;
    p.rt = p.b;
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

void preemptive_sjf(vector<Process>& p) {
    int n = p.size();
    float awt = 0, att = 0;
    int curr_time = 0, completed = 0, mct = INT_MIN;
    vector<bool> done(n, false);
    while (completed < n) {
        int idx = -1, min_burst = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].a <= curr_time && p[i].rt < min_burst) {
                min_burst = p[i].rt;
                idx = i;
            }
        }
        if (idx == -1) {
            curr_time++;
            continue;
        }
        p[idx].rt--;
        curr_time++;
        if (p[idx].rt == 0) {
            done[idx] = true;
            completed++;
            p[idx].ct = curr_time;
            mct = max(mct, p[idx].ct);
            p[idx].tat = p[idx].ct - p[idx].a;
            p[idx].wt = p[idx].tat - p[idx].b;
            awt += p[idx].wt;
            att += p[idx].tat;
        }
    }
    awt /= n;
    att /= n;
    sort(p.begin(), p.end(), [](const Process& a, const Process& b) {
        return a.no < b.no;
    });
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
    preemptive_sjf(p);
    return 0;
}