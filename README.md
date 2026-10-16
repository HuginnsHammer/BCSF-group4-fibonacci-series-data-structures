# BCSF Group 4 — Fibonacci Series and Data Structures

## Project Overview

This project explores the Fibonacci sequence and how different algorithms can be used to calculate Fibonacci numbers. The implementation is written in C++ and connects the topic to a customer loyalty reward system.

The project compares three approaches:

1. **Basic recursion** — calculates Fibonacci numbers using recursive function calls.
2. **Iterative array** — calculates and stores Fibonacci values iteratively.
3. **Memoization** — stores previously calculated results to avoid repeating calculations.

## Project Structure

```text
.
├── README.md
├── .gitignore
├── src/
│   └── FibonacciRewardSystem.cpp
└── report/
    └── Group4_Fibonacci_Case_Study_Report.pdf
```

## Requirements

- A C++ compiler such as GCC (`g++`)
- Support for the C++17 standard

## How to Compile

From the root directory of the repository, run:

```bash
g++ -std=c++17 -O2 src/FibonacciRewardSystem.cpp -o fibonacci_rewards
```

## How to Run

```bash
./fibonacci_rewards
```

Follow the prompts displayed by the program.

## Test Case

The case study uses `n = 30` as a Fibonacci test input. The expected Fibonacci result is:

```text
F(30) = 832040
```

Actual execution times depend on the computer and compiler settings. Refer to the report for the experiment and its results.

## Project Report

The full case study report is available here:

[`Group4_Fibonacci_Case_Study_Report.pdf`](report/Group4_Fibonacci_Case_Study_Report.pdf)

## Team

**BCSF Group 4**
## Team Members and Contributions

| Member Name | GitHub Username | Contribution |
|---|---|---|
| Edward | HuginnsHammer | Repository setup and Iterative Approach |
| Member 2 | S-Atieno | Dynamic programming |
| Member 3 | Lewis-Maxwell | Loyalty system application and conclusion |
| Member 4 | RAYANMUCHIRA254 | Recursive approach |
| Member 5 | mutukumoris-lang | Performance analysis and comparison |

This repository contains the team's C++ implementation and case study report for the Fibonacci Series and Data Structures project.
