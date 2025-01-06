#include <bits/stdc++.h>
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

void fcfs(vector<Process>& p, int n) {
    vector<int> g;
    float att = 0, awt = 0;
    int mct = INT_MIN;
    sort(p.begin(), p.end(), [](const Process &a, const Process &b) {
        return a.a < b.a;
    });
    g.push_back(p[0].a);
    for (int i = 0; i < n; i++) {
        g.push_back(max(g[i], p[i].a) + p[i].b);
        p[i].ct = g[i + 1];
        mct = max(mct, p[i].ct);
        p[i].wt = p[i].ct - p[i].a - p[i].b;
        p[i].tat = p[i].ct - p[i].a;
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
    fcfs(p, n);
    return 0;
}