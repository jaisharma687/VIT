import heapq
import collections

def huffman_coding(text):
    # Frequency of each character
    frequency = collections.Counter(text)
    # Priority queue to hold the characters and their frequencies
    priority_queue = [[weight, [symbol, ""]] for symbol, weight in frequency.items()]
    heapq.heapify(priority_queue)

    # Tree construction
    while len(priority_queue) > 1:
        low = heapq.heappop(priority_queue)
        high = heapq.heappop(priority_queue)
        for pair in low[1:]:
            pair[1] = '0' + pair[1]
        for pair in high[1:]:
            pair[1] = '1' + pair[1]
        heapq.heappush(priority_queue, [low[0] + high[0]] + low[1:] + high[1:])

    # Generating Huffman codes
    huffman_codes = {}
    for pair in heapq.heappop(priority_queue)[1:]:
        huffman_codes[pair[0]] = pair[1]

    return frequency, huffman_codes

# Test Input
text = "ADAM IS IN MADAMS KITCHEN"

# Get the frequency of characters and Huffman codes
frequency, huffman_codes = huffman_coding(text.replace(" ", ""))

# Print the results
print("FREQUENCY OF ALPHABETS")
for char, freq in frequency.items():
    print(f"{char}-{freq}")

print("\nHUFFMAN CODE IS")
for char, code in sorted(huffman_codes.items(), key=lambda x: (-len(x[1]), x[1])):
    print(f"{char}-{code}")