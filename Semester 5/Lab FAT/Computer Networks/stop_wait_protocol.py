def stop_and_wait_protocol(total_frames):
    sequence_number = 0
    for frame in range(1,total_frames+1 ):
        print(f"\nSending frame {frame} with sequence number {sequence_number}.")
        print(f"Waiting for acknowledgment for frame {frame}...")
        print(f"Acknowledgment received for frame {frame} with sequence number {sequence_number}.")
        sequence_number = (sequence_number + 1) % 2

total_frames = int(input("Enter the total number of frames to be sent: "))
stop_and_wait_protocol(total_frames)