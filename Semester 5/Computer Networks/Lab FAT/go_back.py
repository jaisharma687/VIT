import time
import random

timeout = 2
frame_loss_probability = 0.5

def sender(total_frames, window_size):
    next_frame = 0
    ack_received = -1
    retransmissions = 0
    while ack_received < total_frames - 1:
        window_end = min(next_frame + window_size, total_frames)
        for frame in range(next_frame, window_end):
            print(f"Sending frame {frame}")
        ack, ack_received = receiver(window_end, ack_received)
        if ack:
            next_frame = ack_received + 1
        else:
            print("Timeout! Resending frames from", next_frame)
            retransmissions += window_end - next_frame
        time.sleep(1)
    calculate_efficiency(total_frames, retransmissions)

def receiver(window_end, last_ack):
    ack_received = False
    for frame in range(last_ack + 1, window_end):
        if random.random() > frame_loss_probability:
            print(f"Acknowledging frame {frame}")
            last_ack = frame
            ack_received = True
            break
        else:
            print(f"Frame {frame} lost")
    time.sleep(timeout)
    return ack_received, last_ack

def calculate_efficiency(total_frames, retransmissions):
    efficiency = (total_frames / (total_frames + retransmissions)) * 100
    print(f"Protocol efficiency: {efficiency:.2f}%")

total_frames = int(input("Enter the total number of frames to send: "))
window_size = int(input("Enter the window size (N): "))
sender(total_frames, window_size)