# AI Usage Log

This log records the incremental development of the **Student Record Management System** with the assistance of Antigravity AI.

---
## Step 1 – Project scaffold
- Created project folder `student-record-ai-c/`.
- Added placeholder files: `README.md`, `AI_USAGE_LOG.md`, `tests/sample_input.txt`, `tests/sample_output.txt`.
- Created source file `590035264.c` containing the `Student` struct, global array, and a minimal `main()`.
- Verified compilation with `gcc` (no errors).

---
## Step 2 – Core CRUD functions
- Implemented `clearInputBuffer()` and `trimNewline()` helpers.
- Added `addStudent()`, `displayStudent()`, and `displayAll()`.
- Updated `main()` placeholder.
- Compiled successfully.

---
## Step 3 – Search & Delete
- Added `searchStudent()` to locate a record by SAP ID and display it.
- Added `deleteStudent()` which removes a record and shifts the array.
- Fixed duplicate `main()` causing compile errors.
- Re‑compiled – build succeeded.

---
## Step 4 – CGPA calculations
- Implemented `float calculateCGPA(const Student *s)` – averages SGPA for completed semesters.
- Added wrapper `calculateStudentCGPA()` (prompts for SAP ID and prints CGPA).
- Implemented `averageYearCGPA()` – computes average CGPA per academic year (1‑4).
- Cleaned up stray `main()` code and re‑compiled.

---
## Step 5 – Sorting
- Added bubble‑sort `sortBySAP()` (ascending by `sapID`).
- Added bubble‑sort `sortByName()` (alphabetical using `strcmp`).
- Confirmed successful compilation.

---
## Step 6 – Academic Advisor & Menu
- Implemented `academicAdvisor(float cgpa)` with the four performance thresholds.
- Built full interactive menu (11 options) using a `do‑while` loop and `switch‑case`.
- Fixed duplicate placeholder `main()` that caused compile errors.
- Final compilation succeeded – executable `student_app.exe` generated.

---
## Step 7 – Automated testing
- Created `tests/sample_input.txt` containing a scripted sequence that:
  - Adds five students covering all CGPA categories.
  - Searches for a non‑existent SAP ID.
  - Deletes a student.
  - Sorts by SAP ID and by name.
  - Invokes the academic advisor with CGPA `8.5`.
  - Exits.
- Ran the program with redirected input and captured output in `tests/sample_output.txt`.
- Verified that the output matches expected behavior (menu prompts, confirmations, sorting messages, advisor feedback, etc.).

---
## Step 8 – Documentation
- Added a comprehensive `README.md` describing project structure, features, build/run instructions, testing, usage notes, and a short Git workflow.
- Created this `AI_USAGE_LOG.md` to chronicle the development process.

---
## Additional actions
- Renamed the source file to match the user‑provided SAP ID `590032076.c`.
- Updated README with the new filename.

---
*All steps were performed on Windows within the Antigravity sandbox, using `gcc` for compilation and PowerShell for test execution.*