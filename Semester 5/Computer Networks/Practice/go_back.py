import time
import random

timeout = 2
total_loss_prob = 0.5

def sender(total_frames,window_size):
    next_frame = 0
    last_ack = -1
    retrans = 0
    while last_ack < total_frames - 1:
        window_end = min(window_size+next_frame,total_frames)
        for frame in range (next_frame,window_end):
            print(f"Sending frame {frame}")
        ack, last_ack,re = reciever(window_end,last_ack)
        retrans += re
        if ack:
            next_frame = last_ack + 1
        else:
            retrans += window_end - next_frame
            print(f"Timeout! Resending the frame {next_frame}")
        time.sleep(1)
    calculate_efficiency(total_frames,retrans)
    
def reciever(window_end, last_ack):
    re = 0
    ack = False
    for frame in range (last_ack+1,window_end):
        if random.random() > total_loss_prob:
            print(f"Acknowleding frame {frame}");
            last_ack = frame
            ack = True
            break
        else:
            print(f"Frame {frame} lost")
            re += 1
    time.sleep(timeout)
    return ack,last_ack,re

def calculate_efficiency(total, re):
    efficiency = (total/(total+re))*100
    print(f"Efficiency is {efficiency:.2f}")

total_frames = int(input("Enter the total number of frames to send: "))
window_size = int(input("Enter the window size (N): "))
sender(total_frames, window_size)