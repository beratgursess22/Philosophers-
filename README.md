# Dining Philosophers Problem (Philo Project)

This project is a solution to the classical **Dining Philosophers Problem**, implemented in **C** using **POSIX threads (pthreads)** and **mutexes** to manage concurrency.

## 🧠 Problem Description

Five philosophers sit around a table doing one of three things: **thinking**, **eating**, or **sleeping**. A philosopher needs two forks to eat, one on the left and one on the right. The goal is to design a system where:
- No philosopher starves,
- Deadlocks are avoided,
- Mutual exclusion is maintained (no two philosophers use the same fork simultaneously).

## ⚙️ Features

- Thread-safe concurrency using `pthread` and `pthread_mutex_t`.
- Time management with `gettimeofday()` to track philosopher activities.
- Accurate simulation of philosopher states: **thinking**, **eating**, **sleeping**, and **died**.
- Command-line arguments to configure simulation behavior.

Arguments:

number_of_philosophers: Number of philosophers (and forks)

time_to_die: Time (ms) until a philosopher dies without eating

time_to_eat: Time (ms) a philosopher spends eating

time_to_sleep: Time (ms) a philosopher spends sleeping

number_of_times_each_philosopher_must_eat (optional): Simulation ends when each philosopher has eaten this many times

Goals Achieved

Prevented race conditions and deadlocks using mutexes and smart thread management.
Designed modular and maintainable C code.
Tested thoroughly under various timing and philosopher count scenarios.

## 🖥️ Usage

Compile the program:

```bash
make

/philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat (optional)]
