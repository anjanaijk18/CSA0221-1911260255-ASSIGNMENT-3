Student Name: J K ANJANAI

Register Number: 1911260255

Department: B.Tech CSE

Course Code: CSA0221

Course Name: C Programming

Assignment Number: 3

1. Compiler and Version

Compiler: GCC (GNU Compiler Collection)

Language: C

Standard: C11

Check the installed compiler version:

gcc --version

Record the actual GCC version displayed by your computer.

2. Tasks and Program Results

TASK 1 – Searching a Library Catalogue

File: q1_searching_library.c

Implements Linear Search and Binary Search to find library accession numbers.

Result: Both searching methods locate the required accession number. Binary Search performs fewer comparisons for large sorted arrays.

Compilation:

gcc q1_searching_library.c -o task1

Execution:

./task1

TASK 2 – Sorting the Examination Hall Seating Register

File: q2_sorting_register.c

Implements Bubble Sort, Selection Sort and Insertion Sort. Measures comparisons and swaps or shifts for different input arrangements.

Result: All three algorithms arrange register numbers in ascending order. Insertion Sort performs efficiently on nearly sorted data.

Compilation:

gcc q2_sorting_register.c -o task2

Execution:

./task2

TASK 3 – Merging Two Merit Lists

File: q3_merge_merit_lists.c

Merges two already sorted merit lists in descending order into a third array.

Result: The program produces a combined descending merit list with O(m+n) time complexity.

Compilation:

gcc q3_merge_merit_lists.c -o task3

Execution:

./task3

TASK 4 – Two-Dimensional Arrays: District Rainfall Records

File: q4_rainfall_records.c

Uses a two-dimensional array to store rainfall records for 38 districts over 12 months.

The program calculates:

Annual rainfall total for each district.

Monthly average rainfall for the state.

Wettest district and month.

Rainfall-deficient districts.

Result: The program calculates district totals, monthly averages, maximum rainfall and deficient districts.

Compilation:

gcc q4_rainfall_records.c -o task4

Execution:

./task4

Additional Program – Row-wise and Column-wise Traversal

File: q4_traversal_timing.c

gcc q4_traversal_timing.c -o traversal
./traversal

Result: Compares the execution time of row-wise and column-wise traversal of a 2,000 × 2,000 array.

TASK 5 – Processing Text Without the Library

File: q5_string_processing.c

Uses character arrays and loops without string.h.

Operations:

Word counting.

Uppercase conversion.

String reversal.

Palindrome checking.

Result: Performs string operations without using string library functions.

Compilation:

gcc q5_string_processing.c -o task5

Execution:

./task5

Additional Program – String Library Functions

File: q5_string_library.c

gcc q5_string_library.c -o stringlib
./stringlib

Result: Demonstrates string operations using library functions such as strlen(), strcpy(), strcmp() and toupper().

TASK 6 – A Directory of Names: Sorting and Searching Strings

File: q6_directory_names.c

Uses fgets() to read names safely, strcmp() and strcpy() to sort names alphabetically, and Binary Search to locate a name.

It also detects duplicate names.

Result: Names are arranged alphabetically, searched efficiently and duplicate entries are identified.

Compilation:

gcc q6_directory_names.c -o task6

Execution:

./task6

TASK 7 – Election Counting Program from First Principles

File: q7_election_counting.c

Implements an election counting system supporting up to 12 candidates and 5,000 votes.

The program:

Counts valid and invalid votes.

Calculates votes received by each candidate.

Sorts candidates in descending order of votes.

Identifies the winner.

Detects election ties.

Result: Correctly counts votes, identifies invalid entries, displays candidates according to vote count and determines the winner or tie.

Compilation:

gcc q7_election_counting.c -o task7

Execution:

./task7

3. General Program Execution Instructions

Install GCC on your computer.

Open the Assignment 3 folder in VS Code.

Open the integrated terminal.

Navigate to the directory containing the C files.

Compile each program using its respective GCC command.

Execute the generated program.

Verify the output.

Upload the C source files and README.md to GitHub.

For Windows users: Run the generated executable using its .exe extension, for example:

task1.exe

4. Conclusion

This assignment demonstrates searching, sorting, merging, one-dimensional and two-dimensional arrays, string processing and election vote counting using C programming.

It provides practical understanding of Linear Search, Binary Search, Bubble Sort, Selection Sort, Insertion Sort, array operations and string-handling techniques. It also compares algorithm efficiency using time complexity, space complexity and experimental measurements.
