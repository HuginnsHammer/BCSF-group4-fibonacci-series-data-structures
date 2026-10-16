#include <chrono>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;
using Clock = chrono::steady_clock;

// Method 1: straightforward recursion.
long long fibonacciRecursive(int n) {
    if (n < 0) {
        throw invalid_argument("n must not be negative");
    }
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Method 2:the sequence in an array (vector).
// The returned vector contains F(0) through F(n).
vector<long long> fibonacciArray(int n) {
    if (n < 0) {
        throw invalid_argument("n must not be negative");
    }

    vector<long long> fib(n + 1, 0);
    if (n >= 1) {
        fib[1] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;
}

// Method 3: top-down dynamic programming (memoization).
long long fibonacciMemoized(int n, vector<long long>& memo,
                            vector<bool>& calculated) {
    if (n < 0) {
        throw invalid_argument("n must not be negative");
    }
    if (n <= 1) {
        return n;
    }
    if (calculated[n]) {
        return memo[n];
    }

    memo[n] = fibonacciMemoized(n - 1, memo, calculated)
            + fibonacciMemoized(n - 2, memo, calculated);
    calculated[n] = true;
    return memo[n];
}

long long totalRewards(const vector<long long>& rewards, int years) {
    long long total = 0;
    for (int year = 1; year <= years; ++year) {
        total += rewards[year];
    }
    return total;
}

void runRewardSystem() {
    int years;
    cout << "\nEnter completed loyalty years (1-90): ";

    if (!(cin >> years)) {
        cout << "Invalid input. Please enter a whole number.\n";
        return;
    }
    if (years < 1 || years > 90) {
        cout << "Please enter a number from 1 to 90.\n";
        return;
    }

    const vector<long long> rewards = fibonacciArray(years);

    cout << "\nCUSTOMER LOYALTY REWARD SCHEDULE\n";
    cout << "Year\tReward points\n";
    cout << "------------------------\n";
    for (int year = 1; year <= years; ++year) {
        cout << year << '\t' << rewards[year] << '\n';
    }
    cout << "------------------------\n";
    cout << "Total points: " << totalRewards(rewards, years) << '\n';
    cout << "\nThis is a demonstration of the reward rule, not a real customer account.\n";
}

template <typename Function>
double averageMilliseconds(Function function, int repetitions) {
    volatile long long resultSink = 0; // Keep the calculated result observable.
    const auto start = Clock::now();

    for (int i = 0; i < repetitions; ++i) {
        resultSink = resultSink + function();
    }

    const auto finish = Clock::now();
    (void)resultSink;
    const chrono::duration<double, milli> elapsed = finish - start;
    return elapsed.count() / repetitions;
}

void runBenchmark() {
    const int n = 30;
    const int repetitions = 5;

    for (int i = 0; i < 3; ++i) {
        (void)fibonacciRecursive(n);
        (void)fibonacciArray(n);
        vector<long long> memo(n + 1, 0);
        vector<bool> calculated(n + 1, false);
        calculated[0] = calculated[1] = true;
        (void)fibonacciMemoized(n, memo, calculated);
    }

    const double recursiveMs = averageMilliseconds(
        [n]() { return fibonacciRecursive(n); }, repetitions);

    const double iterativeMs = averageMilliseconds(
        [n]() {
            const vector<long long> values = fibonacciArray(n);
            return values[n];
        }, repetitions);

    const double memoizedMs = averageMilliseconds(
        [n]() {
            vector<long long> memo(n + 1, 0);
            vector<bool> calculated(n + 1, false);
            calculated[0] = calculated[1] = true;
            return fibonacciMemoized(n, memo, calculated);
        }, repetitions);

    cout << "\nPERFORMANCE COMPARISON (n = " << n << ")\n";
    cout << "Expected result F(30): " << fibonacciRecursive(n) << '\n';
    cout << fixed << setprecision(6);
    cout << "Naive recursion:    " << recursiveMs << " ms per call\n";
    cout << "Iterative array:    " << iterativeMs << " ms per call\n";
    cout << "Memoization:        " << memoizedMs << " ms per call\n";
    cout << "Times depend on your computer, compiler, and system load.\n";
}

int main() {
    cout << "FIBONACCI CUSTOMER LOYALTY REWARD SYSTEM\n";
    cout << "1. Generate a customer's reward schedule\n";
    cout << "2. Compare algorithm execution times (n = 30)\n";
    cout << "Choose an option (1 or 2): ";

    int choice;
    if (!(cin >> choice)) {
        cout << "Invalid choice. Please run the program again.\n";
        return 1;
    }

    if (choice == 1) {
        runRewardSystem();
    } else if (choice == 2) {
        runBenchmark();
    } else {
        cout << "Please choose option 1 or 2.\n";
        return 1;
    }

    return 0;
}
