import random
import time

timeout = 2
frame_loss_probability = 0.5

def sender(total_frames, wind_size):
    next_frame = 0
    last_ack = -1
    frames_sent = 0
    successful_acks = 0
    retransmissions = 0
    unack_frames = {}
    acknowledged_frames = set()
    while last_ack < total_frames - 1:
        while next_frame < total_frames and next_frame < last_ack + wind_size + 1:
            if next_frame not in unack_frames:
                print(f"Sender: Sending frame {next_frame}")
                frames_sent += 1
                unack_frames[next_frame] = time.time()
            next_frame += 1
        acks = receiver(total_frames, list(unack_frames.keys()))
        for ack in acks:
            print(f"Sender: Acknowledgment received for frame {ack}")
            if ack > last_ack:
                last_ack = ack
            if ack in unack_frames:
                del unack_frames[ack]
                acknowledged_frames.add(ack)
                successful_acks += 1
        current_time = time.time()
        for frame_id in list(unack_frames.keys()):
            if current_time - unack_frames[frame_id] > timeout:
                print(f"Sender: timeout! Resending frame {frame_id}")
                frames_sent += 1
                retransmissions += 1
                unack_frames[frame_id] = current_time
        time.sleep(1)
    efficiency = (successful_acks / (frames_sent + retransmissions)) * 100
    print(f"Protocol Efficiency: {efficiency:.2f}%")

def receiver(total_frames, frames_to_ack):
    acks = []
    for frame_id in frames_to_ack:
        if frame_id < total_frames:
            if random.random() > frame_loss_probability:
                print(f"Receiver: Acknowledging frame {frame_id}")
                acks.append(frame_id)
            else:
                print(f"Receiver: Lost acknowledgment for frame {frame_id}")
    return acks

total_frames = int(input("Enter the total number of frames to be sent: "))
wind_size = int(input("Enter the wind size (N): "))
sender(total_frames, wind_size)