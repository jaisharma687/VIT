#include <bits/stdc++.h>
using namespace std;

struct Process {
    int no, b, a, rt, wt, tat, ct;
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

void roundRobin(vector<Process>& p, int n, int tq) {
    int time = 0, completed = 0, mct = INT_MIN;
    float awt = 0, att = 0;
    queue<int> readyQueue;
    vector<bool> inQueue(n, false);
    sort(p.begin(), p.end(), [](const Process& a, const Process& b) {
        return a.a < b.a;
    });
    for (int i = 0; i < n; i++) {
        if (p[i].a <= time) {
            readyQueue.push(i);
            inQueue[i] = true;
        }
    }
    while (completed < n) {
        if (readyQueue.empty()) {
            time++;
            for (int i = 0; i < n; i++) {
                if (p[i].a <= time && p[i].rt > 0 && !inQueue[i]) {
                    readyQueue.push(i);
                    inQueue[i] = true;
                }
            }
            continue;
        }
        int index = readyQueue.front();
        readyQueue.pop();
        inQueue[index] = false;
        if (p[index].rt > 0) {
            if (p[index].rt <= tq) {
                time += p[index].rt;
                p[index].rt = 0;
                p[index].ct = time;
                mct = max(mct, p[index].ct);
                p[index].tat = time - p[index].a;
                p[index].wt = p[index].tat - p[index].b;
                awt += p[index].wt;
                att += p[index].tat;
                completed++;
            } else {
                time += tq;
                p[index].rt -= tq;
            }
        }
        for (int i = 0; i < n; i++) {
            if (p[i].a <= time && p[i].rt > 0 && !inQueue[i]) {
                readyQueue.push(i);
                inQueue[i] = true;
            }
        }
        if (p[index].rt > 0) {
            readyQueue.push(index);
            inQueue[index] = true;
        }
    }
    awt /= n;
    att /= n;
    printResults(p, awt, att, mct);
}

int main() {
    int n, tq;
    vector<Process> p;
    cout << "Enter the number of processes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        p.push_back(read(i));
    }
    cout << "Enter the time quantum: ";
    cin >> tq;
    roundRobin(p, n, tq);
    return 0;
}