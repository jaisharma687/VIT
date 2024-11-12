#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int FirstComeFirstServe(const vector<int>& requests_fcfs, int head_fcfs) {
    int total_seek_fcfs = 0;
    for (int req_fcfs : requests_fcfs) {
        total_seek_fcfs += abs(req_fcfs - head_fcfs);
        head_fcfs = req_fcfs;
    }
    return total_seek_fcfs;
}

int ShortestSeekTimeFirst(vector<int> requests_sstf, int head_sstf) {
    int total_seek_sstf = 0;
    while (!requests_sstf.empty()) {
        auto closest_sstf = min_element(requests_sstf.begin(), requests_sstf.end(),
        [head_sstf](int a, int b) {
            return abs(a - head_sstf) < abs(b - head_sstf);
        });
        total_seek_sstf += abs(*closest_sstf - head_sstf);
        head_sstf = *closest_sstf;
        requests_sstf.erase(closest_sstf);
    }
    return total_seek_sstf;
}

int Elevator(vector<int> requests_scan, int head_scan, int max_scan) {
    int total_seek_scan = 0;
    requests_scan.push_back(0);
    requests_scan.push_back(max_scan - 1);
    sort(requests_scan.begin(), requests_scan.end());
    auto pos_scan = lower_bound(requests_scan.begin(), requests_scan.end(), head_scan);
    for (auto it = pos_scan; it != requests_scan.end(); ++it) {
        total_seek_scan += abs(*it - head_scan);
        head_scan = *it;
    }
    for (auto it = pos_scan - 1; it >= requests_scan.begin(); --it) {
        total_seek_scan += abs(*it - head_scan);
        head_scan = *it;
    }
    return total_seek_scan;
}

int CircularSCAN(vector<int> requests_cscan, int head_cscan, int max_cscan) {
    int total_seek_cscan = 0;
    requests_cscan.push_back(0);
    requests_cscan.push_back(max_cscan - 1);
    sort(requests_cscan.begin(), requests_cscan.end());
    auto pos_cscan = lower_bound(requests_cscan.begin(), requests_cscan.end(), head_cscan);
    for (auto it = pos_cscan; it != requests_cscan.end(); ++it) {
        total_seek_cscan += abs(*it - head_cscan);
        head_cscan = *it;
    }
    total_seek_cscan += abs(max_cscan - 1 - head_cscan);
    head_cscan = 0;
    for (auto it = requests_cscan.begin(); it < pos_cscan; ++it) {
        total_seek_cscan += abs(*it - head_cscan);
        head_cscan = *it;
    }
    return total_seek_cscan;
}

int Look(vector<int> requests_look, int head_look) {
    int total_seek_look = 0;
    sort(requests_look.begin(), requests_look.end());
    auto pos_look = lower_bound(requests_look.begin(), requests_look.end(), head_look);
    for (auto it = pos_look; it != requests_look.end(); ++it) {
        total_seek_look += abs(*it - head_look);
        head_look = *it;
    }
    for (auto it = pos_look - 1; it >= requests_look.begin(); --it) {
        total_seek_look += abs(*it - head_look);
        head_look = *it;
    }
    return total_seek_look;
}

int CircularLook(vector<int> requests_clook, int head_clook) {
    int total_seek_clook = 0;
    sort(requests_clook.begin(), requests_clook.end());
    auto pos_clook = lower_bound(requests_clook.begin(), requests_clook.end(), head_clook);
    for (auto it = pos_clook; it != requests_clook.end(); ++it) {
        total_seek_clook += abs(*it - head_clook);
        head_clook = *it;
    }
    for (auto it = requests_clook.begin(); it < pos_clook; ++it) {
        total_seek_clook += abs(*it - head_clook);
        head_clook = *it;
    }
    return total_seek_clook;
}

int main() {
    int num_disk_requests, starting_head, disk_capacity;
    
    cout << "Please enter the total number of disk requests: ";
    cin >> num_disk_requests;

    vector<int> disk_requests(num_disk_requests);
    cout << "Enter the disk requests: ";
    for (int i = 0; i < num_disk_requests; ++i) 
        cin >> disk_requests[i];

    cout << "Enter the starting head position: ";
    cin >> starting_head;

    cout << "Enter the total disk capacity: ";
    cin >> disk_capacity;

    int result_fcfs = FirstComeFirstServe(disk_requests, starting_head);
    int result_sstf = ShortestSeekTimeFirst(disk_requests, starting_head);
    int result_scan = Elevator(disk_requests, starting_head, disk_capacity);
    int result_cscan = CircularSCAN(disk_requests, starting_head, disk_capacity);
    int result_look = Look(disk_requests, starting_head);
    int result_clook = CircularLook(disk_requests, starting_head);

    cout << "FCFS Total Seek Time: " << result_fcfs << endl;
    cout << "SSTF Total Seek Time: " << result_sstf << endl;
    cout << "SCAN Total Seek Time: " << result_scan << endl;
    cout << "C-SCAN Total Seek Time: " << result_cscan << endl;
    cout << "LOOK Total Seek Time: " << result_look << endl;
    cout << "C-LOOK Total Seek Time: " << result_clook << endl;

    int min_total_seek = min({result_fcfs, result_sstf, result_scan, result_cscan, result_look, result_clook});
    
    cout << "The algorithm with the minimum seek time is: ";
    if (min_total_seek == result_fcfs) cout << "FCFS";
    else if (min_total_seek == result_sstf) cout << "SSTF";
    else if (min_total_seek == result_scan) cout << "SCAN";
    else if (min_total_seek == result_cscan) cout << "C-SCAN";
    else if (min_total_seek == result_look) cout << "LOOK";
    else if (min_total_seek == result_clook) cout << "C-LOOK";

    cout << " with a seek time of: " << min_total_seek << endl;

    return 0;
}