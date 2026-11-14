# CCS 2214 – Data Structures and Algorithms: Task 3 (Code Questions)

All programs are written in C and were compiled with `gcc -Wall -Wextra` with no warnings.

| File | Question | What it does |
| --- | --- | --- |
| `q1_circular_queue.c` | 1 | Circular queue (enqueue, dequeue, display, wrap-around) |
| `q4a_sum_n.c` | 4(a) | Recursive sum of the first N natural numbers |
| `q4b_factorial.c` | 4(b) | Recursive factorial |
| `q4c_fibonacci_nth.c` | 4(c) | Recursive Nth Fibonacci term |
| `q4d_fibonacci_series.c` | 4(d) | Recursive generation of N Fibonacci terms |
| `q5_queue_enqueue_dequeue.c` | 5 | Menu-driven enqueue and dequeue on an array queue |
| `q6_sparse_matrix.c` | 6 | Sparse matrix stored as a triplet array |
| `q7_deque.c` | 7 | Double ended queue: front/rear insertion and deletion |

## How to compile and run

```bash
gcc -Wall -o q1 q1_circular_queue.c && ./q1
gcc -Wall -o q4a q4a_sum_n.c && ./q4a
# same pattern for the other files
