See [subject](https://github.com/cariestevez/push_swap/blob/main/push_swap.en.subject.pdf)

# 🏋️‍♀️🔁  Push Swap
Sorting algorithm that uses a limited set of operations on a stack data structure. The goal is to sort a list of integers with the fewest number of moves possible, using only two stacks and a predefined set of commands.

## Project Overview:
- Two-Stack Sorting Algorithm: Implement a sorting algorithm that uses two stacks (a and b) to sort a list of integers in ascending order.
- Operations: You can perform operations such as sa (swap the first two elements of stack a), pb (push the top element of stack a to stack b), ra (rotate all elements of stack a upwards), and their counterparts for stack b.
- Algorithmic Optimization: The challenge is not just to sort the numbers, but to do so in the fewest moves, requiring a deep understanding of algorithm design and complexity.

## Bonus Features:
- Checker Program: Develop a companion program called checker that verifies the correctness of the sorting algorithm. The checker program reads a sequence of operations and determines if they correctly sort the stack.
- Advanced Operations: Implement additional operations, such as rrr (reverse rotate both stacks simultaneously), to further optimize your sorting algorithm.
- Large Data Set Handling: Test and optimize your algorithm to efficiently handle larger data sets, ensuring both correctness and performance.

The created algorithm is inspired by the [Mechanical Turk](https://en.wikipedia.org/wiki/Mechanical_Turk).

- It starts dividing the input in 2 stacks (A and B) and moving all of them to B except for 3 numbers, that are sorted immediately with a separate algorithm.

- It then loops calculating the number of stack rotations and pushes necessary for each number in stack B to reach its correct position in stack A.

- Once the "cheapest" number is found, it executes the calculated instruction(s) to move it to that position displaying it on the console.

- The program ends when there are no more numbers in stack B.

## Technologies:
- Programming Language: C
- Operating System: Unix/Linux
- Data Structures: Stacks

## Usage:
* Compile the code using the `make` command
* Run `./push_swap` followed by the desired number of integers. You can use a [random number generator](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php) to test larger sets.
Add `| wc -l` to count the number of instructions used by my algorithm to sort the given numbers.

Bonus:
* Compile the bonus part of the project running `make bonus`
* Execute `ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG` to try out my tester and see if the numbers are sorted. Feel free to try with different numbers.

> [!TIP]
> You can use this [visualizer](https://github.com/o-reo/push_swap_visualizer) created by another 42 student for a more inmersive experience.
