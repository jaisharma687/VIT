#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class PageManager {
    int maxPageTableCapacity, pageFrameSize, totalMemoryCapacity;
    vector<int> backingStore;
    unordered_map<int, int> pageTable;
    list<int> leastRecentlyUsedPages;
    unordered_map<int, list<int>::iterator> pageTableIterator;
    vector<int> mainMemoryFrames;

public:
    PageManager(int maxTableCapacity, int frameSizeBytes, int memoryCapacityBytes,
                const vector<int>& storage)
        : maxPageTableCapacity(maxTableCapacity), pageFrameSize(frameSizeBytes),
          totalMemoryCapacity(memoryCapacityBytes), backingStore(storage) {
        mainMemoryFrames.resize(totalMemoryCapacity / pageFrameSize, -1);
    }

    void accessPage(int virtualAddr) {
        int pageNum = virtualAddr / pageFrameSize;
        if (pageTable.find(pageNum) == pageTable.end()) {
            cout << "Page miss: Page " << pageNum << " not found in memory." << endl;
            handlePageFault(pageNum);
        } else {
            cout << "Page hit: Page " << pageNum << " is in frame: " << pageTable[pageNum] << endl;
            updateLRU(pageNum);
        }
    }

    void handlePageFault(int page) {
        int availableFrame = findAvailableFrame();
        if (availableFrame == -1) {
            availableFrame = replacePage();
        }
        pageTable[page] = availableFrame;
        mainMemoryFrames[availableFrame] = backingStore[page];
        cout << "Page " << page << " loaded into frame " << availableFrame << " from secondary storage." << endl;
        updateLRU(page);
    }

    int findAvailableFrame() {
        for (int i = 0; i < mainMemoryFrames.size(); i++) {
            if (mainMemoryFrames[i] == -1) return i;
        }
        return -1;
    }

    int replacePage() {
        int lruPage = leastRecentlyUsedPages.back();
        leastRecentlyUsedPages.pop_back();
        int replacedFrame = pageTable[lruPage];
        pageTable.erase(lruPage);
        cout << "Page " << lruPage << " evicted from frame " << replacedFrame << " due to replacement." << endl;
        return replacedFrame;
    }

    void updateLRU(int page) {
        if (pageTableIterator.find(page) != pageTableIterator.end()) {
            leastRecentlyUsedPages.erase(pageTableIterator[page]);
        }
        leastRecentlyUsedPages.push_front(page);
        pageTableIterator[page] = leastRecentlyUsedPages.begin();
    }
};

int main() {
    int pageTableLimit, frameSizeBytes, totalMemoryBytes;
    cout << "Enter the page table capacity: ";
    cin >> pageTableLimit;
    cout << "Enter the size of each page frame (in bytes): ";
    cin >> frameSizeBytes;
    cout << "Enter the total memory size (in bytes): ";
    cin >> totalMemoryBytes;

    int backingStoreSize;
    cout << "Enter the size of secondary storage (backing store): ";
    cin >> backingStoreSize;

    vector<int> backingStore(backingStoreSize);
    cout << "Enter data for each page in the secondary storage: ";
    for (int i = 0; i < backingStoreSize; i++) {
        cin >> backingStore[i];
    }

    PageManager memorySystem(pageTableLimit, frameSizeBytes, totalMemoryBytes, backingStore);

    int numVirtualAddresses;
    cout << "Enter the number of virtual addresses to access: ";
    cin >> numVirtualAddresses;
    cout << "Enter the virtual addresses: ";

    for (int i = 0; i < numVirtualAddresses; i++) {
        int virtualAddress;
        cin >> virtualAddress;
        memorySystem.accessPage(virtualAddress);
    }

    return 0;
}
