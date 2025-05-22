# 🍝 Philosophers

> One of the classic problems in computer science, brought to life with C and POSIX threads.

## 📘 Project Description

The **Dining Philosophers** problem is a concurrency challenge. The goal is to manage the behavior of several philosophers who alternate between thinking, eating, and sleeping—all while avoiding deadlocks and starvation. This project helps you understand and implement thread creation, mutexes, and synchronization.

## 📚 Rules of the Simulation

- Each philosopher must **take two forks** to eat.
- They **think**, **eat**, and **sleep** in cycles.
- A philosopher **dies** if they don't eat in time.
- Optional: Philosophers stop when they’ve each eaten a given number of times.

## 🛠️ Skills Learned

- POSIX Threads (`pthread`)
- Mutexes and race condition prevention
- Deadlock avoidance
- Timing and synchronization
- Robust error handling

## 🧪 How to Use

### 🧱 Compilation

```bash
make
