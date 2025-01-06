#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>
#define MAX_TREE_HT 100 

void bubbleSort(int arr[], char arr2[], int n, int descending) {
    int i, j, temp;
    char temp2;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if ((arr[j] > arr[j + 1]) || (arr[j] == arr[j+1] && (descending ? arr2[j] < arr2[j+1] : arr2[j] > arr2[j+1]))) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                temp2 = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp2;
            }
        }
    }
}

struct MinHeapNode { 
    char data;
    unsigned freq; 
    struct MinHeapNode *left, *right; 
}; 

struct MinHeap { 
    unsigned size; 
    unsigned capacity; 
    struct MinHeapNode** array; 
}; 

struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode)); 
    temp->left = temp->right = NULL; 
    temp->data = data; 
    temp->freq = freq; 
    return temp; 
} 

struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap)); 
    minHeap->size = 0; 
    minHeap->capacity = capacity; 
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*)); 
    return minHeap; 
} 

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a; 
    *a = *b; 
    *b = t; 
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx; 
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2; 
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) 
        smallest = left; 
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) 
        smallest = right; 
    if (smallest != idx) { 
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); 
        minHeapify(minHeap, smallest); 
    } 
}

int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1); 
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0]; 
    minHeap->array[0] = minHeap->array[minHeap->size - 1]; 
    --minHeap->size; 
    minHeapify(minHeap, 0); 
    return temp; 
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size; 
    int i = minHeap->size - 1; 
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) { 
        minHeap->array[i] = minHeap->array[(i - 1) / 2]; 
        i = (i - 1) / 2; 
    } 
    minHeap->array[i] = minHeapNode; 
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1; 
    int i; 
    for (i = (n - 1) / 2; i >= 0; --i) 
        minHeapify(minHeap, i); 
}

void printArr(int arr[], int n) {
    int i; 
    for (i = 0; i < n; ++i) 
        printf("%d", arr[i]); 
    printf("\n"); 
}

int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right); 
}

struct MinHeap* createAndBuildMinHeap(char data[],int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size); 
    for (int i = 0; i < size; ++i) 
        minHeap->array[i] = newNode(data[i], freq[i]); 
    minHeap->size = size; 
    buildMinHeap(minHeap); 
    return minHeap; 
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top; 
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size); 
    while (!isSizeOne(minHeap)) { 
        left = extractMin(minHeap); 
        right = extractMin(minHeap); 
        top = newNode('$', left->freq + right->freq); 
        top->left = left; 
        top->right = right; 
        insertMinHeap(minHeap, top); 
    } 
    return extractMin(minHeap); 
}

void printCodes(struct MinHeapNode* root, int arr[], int top, char hash[][MAX_TREE_HT]) {
    if (root->left) { 
        arr[top] = 0; 
        printCodes(root->left, arr, top + 1, hash); 
    } 
    if (root->right) { 
        arr[top] = 1; 
        printCodes(root->right, arr, top + 1, hash); 
    } 
    if (isLeaf(root)) { 
        int n = (int)(root->data - 'A');
        char code[MAX_TREE_HT];
        for (int i = 0; i < top; i++) {
            code[i] = arr[i] == 0 ? '0' : '1';
        }
        code[top] = '\0';
        strcpy(hash[n], code);
    } 
}

void HuffmanCodes(char data[], int freq[], int size, char hash[][MAX_TREE_HT]) { 
    bubbleSort(freq, data, size, 0);
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size); 
    int arr[MAX_TREE_HT], top = 0; 
    printCodes(root, arr, top, hash); 
}

int main() { 
    char str[100];
    scanf("%99[^\n]", str);
    int freq[26] = {0};
    char visited[26] = {0};
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            int index = toupper(str[i]) - 'A';
            freq[index]++;
        }
    }
    char A[100];
    int F[100];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        int n = (int)(toupper(str[i]) - 'A');
        if (visited[n] == 0 && isalpha(str[i])) {
            visited[n]++;
            printf("%c-%d\n", toupper(str[i]), freq[n]);
            F[j] = freq[n];
            A[j] = toupper(str[i]);
            j++;
        }
    }
    printf("HUFFMAN CODE\n");
    char hash[26][MAX_TREE_HT] = {""};
    HuffmanCodes(A, F, j, hash);
    bubbleSort(F, A, j, 1);
    for (int k = j-1; k > -1; k--) {
        printf("%c %s\n", A[k], hash[A[k] - 'A']);
    }
    return 0; 
}