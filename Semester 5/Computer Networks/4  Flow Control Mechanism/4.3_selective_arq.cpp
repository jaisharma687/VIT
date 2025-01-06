#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TIMEOUT 3

typedef struct {
    int sequence_number;
    char data[1024];
    bool ack_received;
} Frame;

void send_frame(Frame *frame) {
    printf("Sending Frame with Sequence Number: %d\n", frame->sequence_number);
    sleep(1);
}

void receive_ack(Frame *frame) {
    if (rand() % 10 < 7) {
        printf("ACK received for Frame %d\n", frame->sequence_number);
        frame->ack_received = true;
    } else {
        printf("ACK lost for Frame %d\n", frame->sequence_number);
        frame->ack_received = false;
    }
}

void selective_repeat_arq(Frame *frames, int frame_count, int window_size) {
    int base = 0, next_seq_num = 0, sent_frames = 0, resent_frames = 0;
    clock_t start_time[frame_count];

    while (base < frame_count) {
        while (next_seq_num < base + window_size && next_seq_num < frame_count) {
            if (!frames[next_seq_num].ack_received) {
                send_frame(&frames[next_seq_num]);
                start_time[next_seq_num] = clock();
                sent_frames++;
            }
            next_seq_num++;
        }

        for (int i = base; i < next_seq_num; i++) {
            if (!frames[i].ack_received) {
                double elapsed_time = (double)(clock() - start_time[i]) / CLOCKS_PER_SEC;
                if (elapsed_time >= TIMEOUT) {
                    printf("Timeout for Frame %d. Resending...\n", frames[i].sequence_number);
                    send_frame(&frames[i]);
                    start_time[i] = clock();
                    resent_frames++;
                } else {
                    receive_ack(&frames[i]);
                }
            }
        }

        while (base < frame_count && frames[base].ack_received) {
            base++;
        }
    }

    double efficiency = (double)sent_frames / (sent_frames + resent_frames) * 100;
    printf("\nProtocol Efficiency: %.2f%%\n", efficiency);
}

int main() {
    int frame_count, window_size;

    printf("Enter the number of frames: ");
    scanf("%d", &frame_count);

    printf("Enter the window size: ");
    scanf("%d", &window_size);

    Frame *frames = (Frame *)malloc(frame_count * sizeof(Frame));
    if (frames == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < frame_count; i++) {
        printf("Enter data for Frame %d: ", i);
        scanf("%s", frames[i].data);
        frames[i].sequence_number = i;
        frames[i].ack_received = false;
    }

    selective_repeat_arq(frames, frame_count, window_size);

    free(frames);

    return 0;
}