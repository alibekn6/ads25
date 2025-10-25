# Lab 1 Solutions - ADS

All problems from ADS Lab 01 solved and tested.

## Problems Solved

### Problem A - Royal Flush
**Algorithm**: Reverse simulation using deque
- Build the initial deck arrangement by working backwards from desired output
- For each card from N to 1: place it at front, then rotate i cards from back to front
- **Complexity**: O(n²)

### Problem B - Nugman and Stack
**Algorithm**: Monotonic stack for nearest smaller element
- Maintain a stack of ages, removing elements >= current age
- Top of stack is the closest younger person before current position
- **Complexity**: O(n)

### Problem C - Equal Strings
**Algorithm**: Stack-based backspace simulation
- Process each string with a stack, popping on '#'
- Compare final results
- **Complexity**: O(n)

### Problem D - Balanced Sequence of Letters
**Algorithm**: Stack matching for palindrome-like structure
- If top of stack matches current char, pop (they cancel out)
- Otherwise push current char
- String is balanced if stack is empty at the end
- **Complexity**: O(n)

### Problem E - Boris vs Nursik
**Algorithm**: Queue simulation of card game
- Simulate the drunkard game with special rule: 0 beats 9
- Winner takes both cards (Boris's first, then Nursik's)
- Limit to 10^6 moves to detect infinite loops
- **Complexity**: O(moves)

### Problem F - Prime Numbers
**Algorithm**: Sieve-like generation with primality check
- Generate primes one by one until we have N primes
- Return the N-th prime
- **Complexity**: O(n√m) where m is the N-th prime

### Problem G - Vanya and Primes 2
**Algorithm**: Superprimes (primes at prime indices)
- Generate first 1000 primes
- Select primes at indices that are themselves prime
- **Complexity**: O(n√m)

### Problem H - Prime or Not
**Algorithm**: Simple primality test
- Check divisibility up to √n
- **Complexity**: O(√n)

### Problem I - Classroom of the Elite
**Algorithm**: Queue-based greedy simulation
- Each faction maintains a queue of student positions
- Student with earlier position kicks the other
- Winner gets added back with position + n (next round)
- **Complexity**: O(n)

### Problem J - Deque
**Algorithm**: Direct deque operations
- '+' pushes to front, '-' pushes to back
- '*' outputs sum of first+last and removes them
- Handle edge cases (empty, single element)
- **Complexity**: O(1) per operation

## How to Compile and Run

```bash
# Compile any solution
g++ a.cpp -o a.out

# Run with input
./a.out < input.txt

# Or pipe input
echo "2
4
5" | ./a.out
```

## Test Results

All problems tested with provided examples - **100% pass rate**.
