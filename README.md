# Student Record Management System

This is a simple **C** console application for managing student records, built as a college assignment.

## Project Structure
```
student-record-ai-c/
├── 590032076.c          # Source code (named with your SAP ID)
├── README.md            # This file – documentation
├── AI_USAGE_LOG.md      # Log of AI‑assisted development steps
└── tests/
    ├── sample_input.txt   # Scripted input to exercise all features
    └── sample_output.txt  # Expected console output from the script
```

## Features
- Store up to **100** students, each with up to **8** semester SGPA values.
- Core operations: **add**, **search**, **display**, **delete**, **calculate CGPA**, **average CGPA per year**.
- **Bubble‑sort** by SAP ID or alphabetically by name.
- **Academic advisor** that prints a performance message based on CGPA thresholds:
  - `9.0–10.0` → *Excellent Performance*
  - `8.0–8.99` → *Good Performance*
  - `6.0–7.99` → *Needs Improvement*
  - `< 6.0`   → *Requires Immediate Attention*
- Interactive **11‑option menu** using a `do‑while` loop and `switch`‑case.

## Build & Run (Windows)
```bat
rem Change to the project folder
cd "C:\Users\Kanishk Gupta\.gemini\antigravity\scratch\student-record-ai-c"

rem Compile with GCC (MinGW or MSYS2 must be on PATH)
gcc 590032076.c -o student_app.exe

rem Run interactively
student_app.exe
```

### Run the automated test
```bat
student_app.exe < tests\sample_input.txt > tests\sample_output.txt
```
The `sample_output.txt` file contains the full console transcript demonstrating the program’s behaviour.

## Usage Notes
- **Input handling:** after every `scanf` we clear the input buffer to avoid stray new‑lines interfering with subsequent `fgets` calls.
- **SGPA entry:** you are prompted for the number of semesters already completed; the remaining SGPA slots are zero‑filled.
- **Sorting:** both sort functions use simple bubble sort – sufficient for the small fixed‑size array.

## Development Log
All incremental changes (adding structs, functions, menu, tests, etc.) are recorded in `AI_USAGE_LOG.md`.

## Git workflow (quick reference)
```bash
git init
git add .
git commit -m "Initial commit – full Student Record Management System"
# add more commits as you evolve the project
```

---
*Created with the assistance of Antigravity AI (Google DeepMind).*