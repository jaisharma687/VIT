#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int search(int key, int frame_items[], int frame_occupied) {
    for (int i = 0; i < frame_occupied; i++)
        if (frame_items[i] == key)
            return 1;
    return 0;
}

int findLRU(int time[], int n) {
    int minimum = time[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

void FIFO(int pages[], int n, int frames) {
    int frame_items[frames];
    for (int i = 0; i < frames; i++) frame_items[i] = -1;
    int frame_occupied = 0;
    int page_faults = 0;
    int current = 0;
    printf("\nFIFO Page Replacement Algorithm\n");
    for (int i = 0; i < n; i++) {
        printf("\nFor page %d: ", pages[i]);
        if (!search(pages[i], frame_items, frame_occupied)) {
            if (frame_occupied < frames) {
                frame_items[frame_occupied] = pages[i];
                frame_occupied++;
            }
            else {
                frame_items[current] = pages[i];
                current = (current + 1) % frames;
            }
            page_faults++;
        }
        for (int j = 0; j < frame_occupied; j++)
            printf("%d ", frame_items[j]);
    }
    printf("\nTotal Page Faults (FIFO): %d\n", page_faults);
}

void LRU(int pages[], int n, int frames) {
    int frame_items[frames], time[frames];
    for (int i = 0; i < frames; i++) frame_items[i] = -1;
    int frame_occupied = 0;
    int page_faults = 0;
    
    printf("\nLRU Page Replacement Algorithm\n");
    for (int i = 0; i < n; i++) {
        printf("\nFor page %d: ", pages[i]);
        if (!search(pages[i], frame_items, frame_occupied)) {
            if (frame_occupied < frames) {
                frame_items[frame_occupied] = pages[i];
                time[frame_occupied] = i;
                frame_occupied++;
            }
            else {
                int pos = findLRU(time, frames);
                frame_items[pos] = pages[i];
                time[pos] = i;
            }
            page_faults++;
        }
        else {
            for (int j = 0; j < frame_occupied; j++) {
                if (frame_items[j] == pages[i]) {
                    time[j] = i;
                    break;
                }
            }
        }
        for (int j = 0; j < frame_occupied; j++)
            printf("%d ", frame_items[j]);
    }
    printf("\nTotal Page Faults (LRU): %d\n", page_faults);
}

// Updated Optimal Algorithm
int findOptimal(int pages[], int frame_items[], int n, int index, int frame_occupied) {
    int res = -1, farthest = index;
    for (int i = 0; i < frame_occupied; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame_items[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    return (res == -1) ? 0 : res;
}

void Optimal(int pages[], int n, int frames) {
    int frame_items[frames];
    for (int i = 0; i < frames; i++) frame_items[i] = -1;
    int frame_occupied = 0;
    int page_faults = 0;

    printf("\nOptimal Page Replacement Algorithm\n");
    for (int i = 0; i < n; i++) {
        printf("\nFor page %d: ", pages[i]);
        if (!search(pages[i], frame_items, frame_occupied)) {
            if (frame_occupied < frames) {
                frame_items[frame_occupied] = pages[i];
                frame_occupied++;
            } else {
                int pos = findOptimal(pages, frame_items, n, i + 1, frame_occupied);
                frame_items[pos] = pages[i];
            }
            page_faults++;
        }
        for (int j = 0; j < frame_occupied; j++)
            printf("%d ", frame_items[j]);
    }
    printf("\nTotal Page Faults (Optimal): %d\n", page_faults);
}

int main() {
    int frames, n;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    
    FIFO(pages, n, frames);
    LRU(pages, n, frames);
    Optimal(pages, n, frames);
    return 0;
}
