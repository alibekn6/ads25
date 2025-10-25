# Lab 2 Solutions - ADS (Linked Lists)

All problems from ADS Lab 02 solved and tested. This lab focuses on **Linked List** data structures.

## Problems Solved

### Problem A - Nearest Number
**Algorithm**: Linear search for minimum distance
- Find element with minimum absolute difference from k
- Return first occurrence if multiple matches
- **Complexity**: O(n)

### Problem B - Jonathan the Poet
**Algorithm**: Linked list cyclic shift
- Find new head by traversing k positions
- Connect tail to old head
- Break at new tail position
- **Complexity**: O(n)

### Problem C - Kuanyshbek
**Algorithm**: Delete every second element
- Iterate through list, removing next node each time
- Skip to next odd-positioned element
- **Complexity**: O(n)

### Problem D - List Modes
**Algorithm**: Frequency counting with map
- Count frequency of each element
- Find maximum frequency
- Output all elements with max frequency in descending order
- **Complexity**: O(n log n)

### Problem E - Database
**Algorithm**: Remove consecutive duplicates
- Track previous name, add only if different
- Sort unique names alphabetically
- **Complexity**: O(n log n)

### Problem F - Insertion of Node
**Algorithm**: Linked list insertion at position
- Handle edge case: insertion at head (position 0)
- Traverse to position-1, insert new node
- **Complexity**: O(n)

### Problem H - Zoro and Seven Sword Style
**Algorithm**: Complete linked list operations suite
- **insert**: Add at position p - O(n)
- **remove**: Delete from position p - O(n)
- **print**: Display all elements - O(n)
- **replace**: Move node from p1 to p2 - O(n)
- **reverse**: Reverse entire list - O(n)
- **cyclic_left**: Rotate left x times - O(n)
- **cyclic_right**: Rotate right x times - O(n)

### Problem I - Doubly Linked List
**Algorithm**: Doubly linked list implementation
- Maintain both prev and next pointers
- Operations: add_front, add_back, erase_front, erase_back, front, back, clear
- All operations in O(1) except clear which is O(n)

### Problem K - One-time Guests
**Algorithm**: First non-repeating character with queue
- Use frequency map to track character counts
- Use queue to maintain order of unique characters
- Remove repeated characters from queue front
- **Complexity**: O(n) per character

### Problem L - Ragnarok
**Algorithm**: Kadane's algorithm on linked list
- Maximum subarray sum using dynamic programming
- Traverse linked list once, tracking current and max sum
- Reset current sum when it becomes negative
- **Complexity**: O(n)

## How to Compile and Run

```bash
# Compile any solution
g++ problem.cpp -o problem.out

# Run with input
./problem.out < input.txt

# Or pipe input
echo "test input" | ./problem.out
```

## Test Results

All problems tested with provided examples - **100% pass rate**.

## Key Concepts Covered

- **Singly Linked Lists**: Creation, traversal, insertion, deletion
- **Doubly Linked Lists**: Bidirectional navigation
- **Cyclic Operations**: Rotation and shifting
- **List Manipulation**: Reversing, replacing, moving nodes
- **Algorithm Adaptation**: Applying classic algorithms (Kadane's) to linked lists
- **Stream Processing**: Real-time character processing
