# 🧠 Banker's Algorithm Simulation in C

A comprehensive C program to simulate the **Banker's Algorithm** — a classic resource allocation and deadlock avoidance strategy in Operating Systems. This project demonstrates how operating systems can determine whether a resource allocation request can be safely granted without leading the system into an unsafe state.

---

## 📌 Overview

The **Banker’s Algorithm** is used to avoid deadlocks by ensuring that a system only grants resource requests **if it remains in a safe state** afterward. This program takes static input for 5 processes and 3 resource types, calculates the **Need** matrix, and determines a **safe sequence**, if it exists.

---

## 🧰 Features

- ✅ Simulates the Banker's Algorithm in C
- ✅ Calculates `Need = Max - Allocation`
- ✅ Identifies if the system is in a **safe or unsafe state**
- ✅ Displays a valid **safe sequence of process execution**
- ✅ Well-commented and modular code structure
- ✅ Clean and understandable logic for educational purposes

---

## 📂 Project Structure

```
bankers-algorithm/
├── bankers.c         # Main C program implementing the algorithm
└── README.md         # Project description and documentation
```
👉 **[View the Full Code Here](https://github.com/ZiyadAzzaz/bankers-algorithm/blob/main/bankers.c)**

---

## 🛠️ How It Works

1. **Allocation Matrix**: Current allocation of each resource to every process.
2. **Max Matrix**: Maximum resource demand by each process.
3. **Available Vector**: Current available resources in the system.
4. **Need Matrix**: Computed as `Need = Max - Allocation`.
5. **Work Vector**: Simulates available resources during the algorithm.
6. **Finish Flags**: Boolean array indicating completed processes.
7. **Safe Sequence**: If found, system is in safe state; else, unsafe.

---

## 🧪 Sample Data (Hardcoded in Code)

```c
int available[R] = {3, 3, 2};

int max[P][R] = {
  {7, 5, 3},
  {3, 2, 2},
  {9, 0, 2},
  {2, 2, 2},
  {4, 3, 3}
};

int allocation[P][R] = {
  {0, 1, 0},
  {2, 0, 0},
  {3, 0, 2},
  {2, 1, 1},
  {0, 0, 2}
};
```

---

## 🧾 Output Example

```
System is in a SAFE state.
Safe sequence is: P1 -> P3 -> P4 -> P0 -> P2
```

---

## 🧵 Code Walkthrough

### 🔸 Step 1: Define the System State
```c
int available[R];       // Resources currently available
int max[P][R];          // Max demand of each process
int allocation[P][R];   // Resources allocated
int need[P][R];         // Resources still needed = max - allocation
```

### 🔸 Step 2: Main Algorithm Loop
- Check each process:
  - If `need <= available`, simulate its execution
  - Add its allocation back to available
  - Add process to the safe sequence
- Repeat until all processes are safely completed or system is unsafe

---

## 📌 Why This Project?

This is a **foundational OS project** taught in Operating Systems courses worldwide. It helps students understand:

- Process scheduling  
- Deadlock conditions  
- Resource allocation safety  
- Critical thinking in systems programming

---

## 🚀 How to Compile and Run

### 🖥️ On Linux/macOS:
```bash
gcc bankers.c -o bankers
./bankers
```

### 🪟 On Windows (MinGW):
```bash
gcc bankers.c -o bankers.exe
bankers.exe
```

---

## 📚 Learning Objectives

By completing this project, you will:

- Understand deadlock avoidance techniques  
- Learn how operating systems validate resource requests  
- Improve your C programming and logic implementation skills  
- Prepare for OS lab exams and technical interviews  

---

## 🧱 Possible Extensions

- Accept **dynamic user input** instead of hardcoded data  
- Add support for **more processes and resource types**  
- Create a **GUI version** using Python + Tkinter or Java Swing  
- Implement **live simulation** showing steps of execution  
- Add **file I/O** to read matrices from external `.txt` files  

---

## 🙋‍♂️ Author

**Ziyad Azzaz**  
AI & Robotics Engineer
GitHub: [Ziyad Azzaz](https://github.com/ZiyadAzzaz)

---

## 📜 License

This project is released under the MIT License — free to use, modify, and share.
