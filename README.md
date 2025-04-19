# Sorting Algorithms & Big O

## 📚 Project Overview

This project focuses on implementing various sorting algorithms in C and analyzing their time complexity using Big O notation. It explores both simple and advanced algorithms, applied to arrays and doubly linked lists. The goal is to understand algorithmic efficiency, stability, and adaptability for different types of data and constraints.

Pair programming is encouraged for collaborative learning and better problem-solving.

---

## ✨ Learning Objectives

- Understand and implement at least 4 sorting algorithms  
- Master the concept of Big O notation  
- Evaluate and compare the time complexity of sorting algorithms  
- Select the most efficient algorithm based on input data characteristics  
- Understand stable vs unstable sorting  
- Manipulate data in arrays and doubly linked lists  
- Handle advanced sorting scenarios such as deck sorting and radix-based approaches  

---

## ✅ Project Requirements

- **Language:** C (GNU89 standard)  
- **Compilation:** `gcc -Wall -Wextra -Werror -pedantic`  
- **Code Style:** Betty style  
- No global variables allowed  
- Max 5 functions per file  
- No use of standard library functions unless specified (e.g. `qsort` in Task 12)  
- All files must end with a new line  
- Header guards and prototypes must be included in `sort.h` and `deck.h`  
- A `README.md` file is mandatory  

---

## 🧠 Core Algorithms Implemented

| Task | Algorithm                         | File                          |
|------|-----------------------------------|-------------------------------|
| 0    | Bubble Sort                       | `0-bubble_sort.c`             |
| 1    | Insertion Sort (doubly linked)    | `1-insertion_sort_list.c`     |
| 2    | Selection Sort                    | `2-selection_sort.c`          |
| 3    | Quick Sort (Lomuto)               | `3-quick_sort.c`              |
| 4    | Shell Sort (Knuth sequence)       | `100-shell_sort.c`            |
| 5    | Cocktail Shaker Sort              | `101-cocktail_sort_list.c`    |
| 6    | Counting Sort                     | `102-counting_sort.c`         |
| 7    | Merge Sort                        | `103-merge_sort.c`            |
| 8    | Heap Sort                         | `104-heap_sort.c`             |
| 9    | Radix Sort                        | `105-radix_sort.c`            |
| 10   | Bitonic Sort                      | `106-bitonic_sort.c`          |
| 11   | Quick Sort (Hoare partition)      | `107-quick_sort_hoare.c`      |
| 12   | Deck Sort (doubly linked deck)    | `1000-sort_deck.c`            |

---

## 🧾 Data Structures

### Doubly Linked List Node

```c
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```

### Deck of Cards

```c
typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;
```

---

## 🧪 Testing

- Use the provided `main.c` files for each task to test functionality.
- For performance testing, generate large datasets using random.org or custom scripts.
- Test edge cases (empty array, 1-element array, already sorted data, etc.).
- For linked list tasks, ensure memory integrity after sorting.

---

## 📊 Big O Complexity Reference

Each algorithm has a corresponding `.O` file (e.g. `0-O`, `1-O`, ...) listing its complexity:

- Best Case
- Average Case
- Worst Case

### 📌 Use the correct notation:

- `O(1)`
- `O(n)`
- `O(n^2)`
- `O(log(n))`
- `O(nlog(n))`

✳️ Avoid constants and never write something like O(2n) — use short notation like O(n).

---

## 📝 Tasks

### ✔️ Mandatory Tasks

- `0-bubble_sort.c` — Bubble sort with printed swaps  
- `1-insertion_sort_list.c` — Insertion sort on a doubly linked list  
- `2-selection_sort.c` — Selection sort with printed swaps  
- `3-quick_sort.c` — Quick sort using Lomuto partition  

### ✔️ Advanced Tasks

- `100-shell_sort.c` — Shell sort using Knuth sequence  
- `101-cocktail_sort_list.c` — Cocktail shaker sort on a doubly linked list  
- `102-counting_sort.c` — Counting sort with printed counting array  
- `103-merge_sort.c` — Merge sort with printed merge steps  
- `104-heap_sort.c` — Heap sort using sift-down method  
- `105-radix_sort.c` — LSD radix sort with step prints  
- `106-bitonic_sort.c` — Bitonic sort with debug logs  
- `107-quick_sort_hoare.c` — Quick sort using Hoare partition scheme  
- `1000-sort_deck.c` — Sorts a deck of cards (doubly linked list of structs)  

---

## 🧑‍💻 Authors

Abdullatif Alzaher, Donna Almadani.
