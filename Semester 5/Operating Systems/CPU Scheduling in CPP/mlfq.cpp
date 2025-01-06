#include <bits/stdc++.h>
using namespace std;

struct Process {
    int no, a, b, rt, wt, tat, ct;
};

Process read(int i) {
    Process p;
    p.no = i + 1;
    cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
    cin >> p.a >> p.b;
    p.rt = p.b;
    return p;
}

void printRemainingTimes(const vector<Process>& p, const string& level) {
    cout << "\n" << level << " Remaining Time Table:\n";
    cout << "Process\tArrival Time\tBurst Time\tRemaining Time\tCompletion Time\n";
    for (const auto& process : p) {
        cout << "P" << process.no << "\t\t" << process.a << "\t\t" << process.b
            << "\t\t" << process.rt << "\t\t" << (process.rt == 0 ? process.ct : -1) << endl;
    }
}

void printResults(const vector<Process>& p, float awt, float att, int mct) {
    cout << "\nFinal Results:\n";
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (const auto& process : p) {
        cout << "P" << process.no << "\t\t" << process.a << "\t\t" << process.b
            << "\t\t" << process.ct << "\t\t" << process.wt << "\t\t" << process.tat << endl;
    }
    cout << "Average Waiting Time: " << awt << endl;
    cout << "Average Turnaround Time: " << att << endl;
    cout << "Maximum Completion Time: " << mct << endl;
}

void roundRobinOnePass(vector<Process>& p, int tq, int& time, queue<int>& readyQueue) {
    vector<bool> inQueue(p.size(), false);
    size_t initialQueueSize = readyQueue.size();
    for (size_t i = 0; i < initialQueueSize; ++i) {
        int index = readyQueue.front();
        readyQueue.pop();
        if (p[index].rt <= tq) {
            time += p[index].rt;
            p[index].rt = 0;
            p[index].ct = time;
        } else {
            time += tq;
            p[index].rt -= tq;
            readyQueue.push(index);
        }
        for (size_t j = 0; j < p.size(); ++j) {
            if (p[j].a <= time && p[j].rt > 0 && !inQueue[j]) {
                readyQueue.push(j);
                inQueue[j] = true;
            }
        }
    }
}

void fcfs(vector<Process>& p, int& time, queue<int>& readyQueue) {
    while (!readyQueue.empty()) {
        int index = readyQueue.front();
        readyQueue.pop();
        time = max(time, p[index].a);
        time += p[index].rt;
        p[index].rt = 0;
        p[index].ct = time;
    }
}

void mlfq(vector<Process>& p, int tq1, int tq2) {
    int time = 0;
    queue<int> q1, q2, q3;
    for (size_t i = 0; i < p.size(); ++i) {
        if (p[i].a <= time) q1.push(i);
    }
    roundRobinOnePass(p, tq1, time, q1);
    printRemainingTimes(p, "Level 1");
    for (size_t i = 0; i < p.size(); ++i) {
        if (p[i].rt > 0) q2.push(i);
    }
    roundRobinOnePass(p, tq2, time, q2);
    printRemainingTimes(p, "Level 2");
    for (size_t i = 0; i < p.size(); ++i) {
        if (p[i].rt > 0) q3.push(i);
    }
    fcfs(p, time, q3);
    printRemainingTimes(p, "Level 3");
    float awt = 0, att = 0;
    int mct = 0;
    for (auto& process : p) {
        process.tat = process.ct - process.a;
        process.wt = process.tat - process.b;
        awt += process.wt;
        att += process.tat;
        mct = max(mct, process.ct);
    }
    awt /= p.size();
    att /= p.size();
    printResults(p, awt, att, mct);
}

int main() {
    int n, tq1, tq2;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter Time Quantum for Level 1: ";
    cin >> tq1;
    cout << "Enter Time Quantum for Level 2: ";
    cin >> tq2;
    vector<Process> processes(n);
    for (int i = 0; i < n; ++i) {
        processes[i] = read(i);
    }
    mlfq(processes, tq1, tq2);
    return 0;
}

