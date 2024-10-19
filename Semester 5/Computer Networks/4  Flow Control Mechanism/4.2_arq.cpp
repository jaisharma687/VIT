#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define TIMEOUT 2

typedef struct {
    int sequence_number;
    char data[1024];
    bool ack_received;
} Frame;

void send_frame(Frame *frame) {
    printf("Sending Frame with Sequence Number: %d\n", frame->sequence_number);
    sleep(1);
}

bool receive_ack(int *ack) {
    if (rand() % 10 < 2) {
        printf("ACK for Sequence Number %d lost.\n", *ack);
        return false;
    }
    printf("ACK received for Sequence Number: %d\n", *ack);
    return true;
}

void sliding_window_go_back_arq(Frame *frames, int frame_count, int window_size, double *efficiency) {
    int base = 0, next_seq_num = 0, total_transmissions = 0, successful_transmissions = 0;

    while (base < frame_count) {
        while (next_seq_num < base + window_size && next_seq_num < frame_count) {
            if (!frames[next_seq_num].ack_received) {
                send_frame(&frames[next_seq_num]);
                total_transmissions++;
            }
            next_seq_num++;
        }

        clock_t start_time = clock();
        double elapsed_time = 0;
        bool timeout = false;

        while (elapsed_time < TIMEOUT) {
            for (int i = base; i < next_seq_num; i++) {
                if (!frames[i].ack_received) {
                    if (receive_ack(&frames[i].sequence_number)) {
                        frames[i].ack_received = true;
                        base++;
                        successful_transmissions++;
                    } else {
                        timeout = true;
                        break;
                    }
                }
            }
            elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

            if (timeout) {
                break;
            }
        }

        if (timeout || base < next_seq_num) {
            printf("Timeout occurred. Resending frames from %d...\n", base);
            for (int i = base; i < next_seq_num; i++) {
                if (!frames[i].ack_received) {
                    send_frame(&frames[i]);
                    total_transmissions++;
                }
            }
        }
    }

    *efficiency = (double)successful_transmissions / total_transmissions * 100;
}

int main() {
    int frame_count, window_size;
    double efficiency = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &frame_count);

    printf("Enter the window size (N): ");
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

    sliding_window_go_back_arq(frames, frame_count, window_size, &efficiency);

    printf("Efficiency of the protocol: %.2f%%\n", efficiency);

    free(frames);

    return 0;
}
