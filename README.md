See [subject](https://github.com/cariestevez/push_swap/blob/main/push_swap.en.subject.pdf)

# 🏋️‍♀️🔁  Push Swap
Program that receives a random set of integers as argument and returns to the standard output the smallest set of movements necessary to sort them.
The created algorithm is inspired by the [Mechanical Turk](https://en.wikipedia.org/wiki/Mechanical_Turk).

- It starts dividing the input in 2 stacks (A and B) and moving all of them to B except for 3 numbers, that are sorted immediately with a separate algorithm.

- It then loops calculating the number of stack rotations and pushes necessary for each number in stack B to reach its correct position in stack A.

- Once the "cheapest" number is found, it executes the calculated instruction(s) to move it to that position displaying it on the console.

The program terminates when the numbers are sorted.

## Usage:
* Compile the code using the `make` command
* Run `./push_swap` followed by the desired number of integers to execute the programm

> [!TIP]
> You can use this [visualizer](https://github.com/o-reo/push_swap_visualizer) created by another 42 student for a more complete experience.
