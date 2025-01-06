#include <bits/stdc++.h>
using namespace std;

struct Process {
    int a, b, no, priority, wt, tat, ct;
};

Process read(int i) {
    Process p;
    cout << "The process no.: " << i << endl;
    p.no = i;
    cout << "Enter the arrival time: ";
    cin >> p.a;
    cout << "Enter the burst time: ";
    cin >> p.b;
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

void priorityScheduling(vector<Process>& p, int n) {
    vector<int> g;
    float att = 0, awt = 0;
    int mct = INT_MIN;
    sort(p.begin(), p.end(), [](const Process &a, const Process &b) {
        if (a.a == b.a) return a.priority < b.priority;
        return a.a < b.a;
    });
    g.push_back(p[0].a);
    for (int i = 0; i < n; i++) {
        g.push_back(g[i] + p[i].b);
        p[i].wt = g[i] - p[i].a;
        p[i].tat = g[i + 1] - p[i].a;
        p[i].ct = g[i + 1];
        mct = max(mct, p[i].ct); 
        awt += p[i].wt;  
        att += p[i].tat;  
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
    priorityScheduling(p, n);
    return 0;
}
