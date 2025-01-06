def stopAndWait(total_frames):
    seq_num = 0
    ack_num = 0
    for frame in range(1,total_frames+1):
        print(f"Sending the frame {frame} with Sequence Number {seq_num}")
        print(f"Waiting for Acknowledment from the Reciever with Acknowledment Number: {ack_num}")
        print(f"Acknowledment recieved for frame {frame} with Sequence Number {seq_num} and Acknowledment Number {ack_num}")
        seq_num = (seq_num + 1)%2
        ack_num = (ack_num + 1)%2
    print("All frames have been sent and acknowledged")

total_frames = int(input("Enter the total number of frames: "))
stopAndWait(total_frames)