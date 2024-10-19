#include <iostream>
using namespace std;

void send_frame(int frame_num) {
    cout << "Sending frame: " << frame_num << endl;
}

void receive_ack(int frame_num) {
    cout << "Acknowledgment received for frame: " << frame_num << endl;
}

int main() {
    int total_frames;
    
    cout << "Enter the total number of frames to be sent: ";
    cin >> total_frames;
    
    int seq_num = 0;
    
    for (int i = 1; i <= total_frames; i++) {
        send_frame(seq_num);
        receive_ack(seq_num);
        seq_num = (seq_num + 1) % 2;
    }
    
    cout << "All frames sent and acknowledged successfully!" << endl;
    
    return 0;
}