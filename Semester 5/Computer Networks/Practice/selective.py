import time
import random

timeout = 2
total_loss_prob = 0.5

def reciever(total_frames, frames):
    acks = []
    for frame in frames:
        if frame < total_frames:
            if random.random() > total_loss_prob:
                print(f"Reciever: Acknowleding frame {frame}")
                acks.append(frame)
            else:
                print(f"Reciever: Acknowledment Lost for frame {frame}")
    return acks

def sender(total_frames, wind_size):
    next_frame = 0
    last_ack = -1
    retrans = 0
    unack_frames = {}
    succ_acks = 0
    ack_frames = set()
    frames_sent = 0
    while last_ack < total_frames - 1:
        while next_frame < min(total_frames,last_ack+wind_size+1):
            if next_frame not in unack_frames:
                print(f"Sender: Sending frame {next_frame}")
                frames_sent += 1
                unack_frames[next_frame] = time.time()
            next_frame += 1
        acks = reciever(total_frames,list(unack_frames.keys()))
        for ack in acks:
            print(f"Sender: Acknowledment Recieved for frame {ack}")
            if ack > last_ack:
                last_ack = ack
            if ack in unack_frames:
                del unack_frames[ack]
                succ_acks += 1
                ack_frames.add(ack)
        current_time = time.time()
        for frame in list(unack_frames.keys()):
            if current_time - unack_frames[frame] > timeout:
                print(f"Sender: Timeout! Resending the frame {frame}")
                retrans += 1
                frames_sent += 1
                unack_frames[frame] = current_time
        time.sleep(1)
        efficiency = succ_acks / (frames_sent + retrans) * 100
    print(f"Efficiency is {efficiency:.2f}")

total_frames = int(input("Enter the total number of frames to be sent: "))
wind_size = int(input("Enter the wind size (N): "))
sender(total_frames, wind_size)