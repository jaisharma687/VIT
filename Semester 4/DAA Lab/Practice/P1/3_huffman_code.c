#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

#define MAX_TREE_HT 100 

int* convertArrayToBinary(int arr[], int size) {
    int* binaryArray = (int*)malloc(size * sizeof(int));
    if (binaryArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; ++i) {
        int num = arr[i];
        int binary = 0;
        int base = 1;

        while (num > 0) {
            binary += (num % 2) * base;
            num /= 2;
            base *= 10;
        }

        binaryArray[i] = binary;
    }

    return binaryArray;
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

void bubbleSort(int arr[], char arr2[], int n) {
    int i, j, temp;
    char temp2;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
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

struct MinHeapNode* newNode(char data, unsigned freq) 
{ 
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

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b){ 
	struct MinHeapNode* t = *a; 
	*a = *b; 
	*b = t; 
} 

void minHeapify(struct MinHeap* minHeap, int idx){ 
	int smallest = idx; 
	int left = 2 * idx + 1; 
	int right = 2 * idx + 2;
	if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
	    smallest = left; 
	if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) 
		smallest = right; 
	if (smallest != idx) { 
	    swapMinHeapNode(&minHeap->array[smallest],&minHeap->array[idx]); 
		minHeapify(minHeap, smallest); 
	} 
} 

int isSizeOne(struct MinHeap* minHeap){ 
	return (minHeap->size == 1); 
} 

struct MinHeapNode* extractMin(struct MinHeap* minHeap) { 
	struct MinHeapNode* temp = minHeap->array[0]; 
	minHeap->array[0] = minHeap->array[minHeap->size - 1]; 
	--minHeap->size; 
	minHeapify(minHeap, 0); 
	return temp; 
} 

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode){ 
	++minHeap->size; 
	int i = minHeap->size - 1; 
	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq){ 
		minHeap->array[i] = minHeap->array[(i - 1) / 2]; 
		i = (i - 1) / 2; 
	} 
	minHeap->array[i] = minHeapNode; 
} 

void buildMinHeap(struct MinHeap* minHeap){ 
	int n = minHeap->size - 1; 
	int i; 
	for (i = (n - 1) / 2; i >= 0; --i) 
		minHeapify(minHeap, i); 
} 

void printArr(int arr[], int n){ 
	int i; 
	for (i = 0; i < n; ++i) 
		printf("%d", arr[i]); 
	printf("\n"); 
} 

int isLeaf(struct MinHeapNode* root){
	return !(root->left) && !(root->right); 
} 

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) { 
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
	while (!isSizeOne(minHeap)){
		left = extractMin(minHeap); 
		right = extractMin(minHeap);
		top = newNode('$', left->freq + right->freq); 
		top->left = left; 
		top->right = right; 
		insertMinHeap(minHeap, top); 
	}
	return extractMin(minHeap); 
} 

void printCodesAndUpdateArrays(struct MinHeapNode *root, char characters[], int encodedBits[], int arr[], int top, int *index)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodesAndUpdateArrays(root->left, characters, encodedBits, arr, top + 1, index);
    }
    if (root->right)
    {
        arr[top] = 1;
        printCodesAndUpdateArrays(root->right, characters, encodedBits, arr, top + 1, index);
    }
    if (isLeaf(root))
    {
        characters[*index] = root->data;
        int i;
        int encodedBit = 0;
        for (i = 0; i < top; i++)
            encodedBit = (encodedBit << 1) | arr[i];
        encodedBits[*index] = encodedBit;
        (*index)++;
    }
}

void HuffmanCodesAndGetArrays(char data[], int freq[], int size, char characters[], int encodedBits[])
{
    struct MinHeapNode *root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    int index = 0;
    printCodesAndUpdateArrays(root, characters, encodedBits, arr, top, &index);
}

int main() {
    char inputString[100];
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = '\0';
    int frequency[256] = {0};
    for (int i = 0; inputString[i] != '\0'; i++) {
        if (isalpha(inputString[i])) {
            frequency[(int)tolower(inputString[i])]++;
        }
    }
    int uniqueChars = 0;
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            uniqueChars++;
        }
    }
    char characters[uniqueChars];
    int freq[uniqueChars];
    int index = 0;
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            characters[index] = (char)i;
            freq[index] = frequency[i];
            index++;
        }
    }
    int encodedBits[uniqueChars];
    printf("Huffman code generated for the given text is\n");
    HuffmanCodesAndGetArrays(characters, freq, uniqueChars, characters, encodedBits);
    bubbleSort(encodedBits, characters, uniqueChars);
    int* binaryResult = convertArrayToBinary(encodedBits, uniqueChars);
    for (int i = 0; i < uniqueChars; i++)
    {
        printf("%c-%d\n", characters[i], binaryResult[i]);
    }

    return 0;
}