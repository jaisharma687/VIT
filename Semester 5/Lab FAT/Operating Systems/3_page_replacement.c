#include<stdio.h>

int search(int key, int arr[], int n){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}

void FIFO(int pages[], int n, int frames){
    int f[frames];
    for(int i=0;i<frames;i++) f[i] = -1;
    int m = 0;
    int faults = 0;
    int current = 0;
    printf("FIFO\n");
    for(int i=0;i<n;i++){
        if(!search(pages[i],f,m)){
            if(m<frames){
                f[m++] = pages[i];
            }
            else{
                f[current] = pages[i];
                current = (current + 1) % frames;
            }
            faults++;
        }
        printf("Page %d: ",pages[i]);
        for(int j=0;j<m;j++){
            printf("%d ",f[j]);
        }
        printf("\n");
    }
    printf("Page Faults: %d\n",faults);
}

int findLRU(int time[], int frames){
    int min = time[0];
    int pos = 0;
    for(int i=1;i<frames;i++){
        if(min>time[i]){
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

void LRU(int pages[], int n, int frames){
    int f[frames], time[frames];
    for(int i=0;i<frames;i++) f[i] = -1;
    int m = 0;
    int faults = 0;
    printf("LRU\n");
    for(int i=0;i<n;i++){
        if(!search(pages[i],f,m)){
            faults++;
            if(m<frames){
                f[m] = pages[i];
                time[m] = i;
                m++;
            }
            else{
                int pos = findLRU(time,frames);
                f[pos] = pages[i];
                time[pos] = i;
            }
        }
        else{
            for(int j=0;j<m;j++){
                if(pages[i]==f[j]){
                    time[j] = i;
                    break;
                }
            }
        }
        printf("Page %d: ",pages[i]);
        for(int j=0;j<m;j++){
            printf("%d ",f[j]);
        }
        printf("\n");
    }
    printf("Page Faults: %d\n",faults);
}

int findOptimal(int pages[], int n, int f[], int m, int idx){
    int pos = -1;
    int farthest = idx;
    for(int i=0;i<m;i++){
        int j;
        for(j=idx;j<n;j++){
            if(f[i]==pages[j]){
                if(j>farthest){
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if(j==n) return i;
    }
    return (pos==-1)?0:pos;
}

void Optimal(int pages[],int n, int frames){
    int f[frames];
    for(int i=0;i<frames;i++) f[i] = -1;
    int m = 0;
    int faults = 0;
    printf("Optimal\n");
    for(int i = 0;i<n;i++){
        if(!search(pages[i],f,m)){
            faults++;
            if(m<frames){
                f[m++] = pages[i];
            }
            else{
                int pos = findOptimal(pages,n,f,m,i+1);
                f[pos] = pages[i];
            }
        }
        printf("Pages %d: ",pages[i]);
        for(int j=0;j<m;j++){
            printf("%d ",f[j]);
        }
        printf("\n");
    }
    printf("Page Faults: %d",faults);
}

int main(){
    int n;
    printf("Enter the number of pages: ");
    scanf("%d",&n);
    int pages[n];
    printf("Enter the pages: ");
    for(int i=0;i<n;i++) scanf("%d",&pages[i]);
    int frames;
    printf("Enter the number of frames: ");
    scanf("%d",&frames);
    FIFO(pages,n,frames);
    LRU(pages,n,frames);
    Optimal(pages,n,frames);
    return 0;
}