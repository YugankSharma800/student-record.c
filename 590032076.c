    #include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SEMESTERS 8

typedef struct {
    int sapID;
    int rollNo;
    char name[50];
    char phone[15];
    char email[50];
    int year;
    int semester;
    float sgpa[MAX_SEMESTERS];
} Student;

// Global array to hold student records and a counter
Student students[MAX_STUDENTS];
int studentCount = 0;

// Helper to clear the stdin buffer after scanf
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Remove trailing newline from a string read by fgets
void trimNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Add a new student record
int addStudent(void) {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum number of students reached (%d).\n", MAX_STUDENTS);
        return 0;
    }
    Student *s = &students[studentCount];
    printf("Enter SAP ID: ");
    if (scanf("%d", &s->sapID) != 1) return 0;
    clearInputBuffer();

    printf("Enter Roll No: ");
    if (scanf("%d", &s->rollNo) != 1) return 0;
    clearInputBuffer();

    printf("Enter Name: ");
    fgets(s->name, sizeof(s->name), stdin);
    trimNewline(s->name);

    printf("Enter Phone: ");
    fgets(s->phone, sizeof(s->phone), stdin);
    trimNewline(s->phone);

    printf("Enter Email: ");
    fgets(s->email, sizeof(s->email), stdin);
    trimNewline(s->email);

    printf("Enter Year (1-4): ");
    if (scanf("%d", &s->year) != 1) return 0;
    clearInputBuffer();

    printf("Enter Semester (1-8): ");
    if (scanf("%d", &s->semester) != 1) return 0;
    clearInputBuffer();

    int completed = s->semester; // assuming SGPA is available for semesters completed
    if (completed > MAX_SEMESTERS) completed = MAX_SEMESTERS;
    printf("Enter SGPA for %d completed semesters (space separated): ", completed);
    for (int i = 0; i < completed; ++i) {
        if (scanf("%f", &s->sgpa[i]) != 1) s->sgpa[i] = 0.0f;
    }
    clearInputBuffer();
    // Zero‑fill remaining SGPA slots
    for (int i = completed; i < MAX_SEMESTERS; ++i) {
        s->sgpa[i] = 0.0f;
    }

    studentCount++;
    printf("Student added successfully.\n");
    return 1;
}

// Display a single student record
void displayStudent(const Student *s) {
    printf("--- Student Record ---\n");
    printf("SAP ID   : %d\n", s->sapID);
    printf("Roll No  : %d\n", s->rollNo);
    printf("Name     : %s\n", s->name);
    printf("Phone    : %s\n", s->phone);
    printf("Email    : %s\n", s->email);
    printf("Year     : %d\n", s->year);
    printf("Semester : %d\n", s->semester);
    printf("SGPA     : ");
    for (int i = 0; i < s->semester && i < MAX_SEMESTERS; ++i) {
        printf("%.2f ", s->sgpa[i]);
    }
    printf("\n");
}

// Display all stored students
void displayAll(void) {
    if (studentCount == 0) {
        printf("No student records to display.\n");
        return;
    }
    for (int i = 0; i < studentCount; ++i) {
        displayStudent(&students[i]);
    }
}

int searchStudent(void) {
    if (studentCount == 0) {
        printf("No records to search.\n");
        return 0;
    }
    int id;
    printf("Enter SAP ID to search: ");
    if (scanf("%d", &id) != 1) return 0;
    clearInputBuffer();
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].sapID == id) {
            displayStudent(&students[i]);
            return 1;
        }
    }
    printf("Student with SAP ID %d not found.\n", id);
    return 0;
}

int deleteStudent(void) {
    if (studentCount == 0) {
        printf("No records to delete.\n");
        return 0;
    }
    int id;
    printf("Enter SAP ID to delete: ");
    if (scanf("%d", &id) != 1) return 0;
    clearInputBuffer();
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].sapID == id) {
            for (int j = i; j < studentCount - 1; ++j) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student with SAP ID %d deleted.\n", id);
            return 1;
        }
    }
    printf("Student with SAP ID %d not found.\n", id);
    return 0;
}

// Calculate CGPA for a single student (average of completed semesters)
float calculateCGPA(const Student *s) {
    if (s->semester == 0) return 0.0f;
    float sum = 0.0f;
    int count = s->semester;
    if (count > MAX_SEMESTERS) count = MAX_SEMESTERS;
    for (int i = 0; i < count; ++i) {
        sum += s->sgpa[i];
    }
    return sum / count;
}

// Wrapper: ask for SAP ID and display the student's CGPA
void calculateStudentCGPA(void) {
    if (studentCount == 0) {
        printf("No records available.\n");
        return;
    }
    int id;
    printf("Enter SAP ID to calculate CGPA: ");
    if (scanf("%d", &id) != 1) return;
    clearInputBuffer();
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].sapID == id) {
            float cgpa = calculateCGPA(&students[i]);
            printf("Student SAP ID %d CGPA: %.2f\n", id, cgpa);
            return;
        }
    }
    printf("Student with SAP ID %d not found.\n", id);
}

// Average CGPA for each academic year (1‑4)
void averageYearCGPA(void) {
    if (studentCount == 0) {
        printf("No records available.\n");
        return;
    }
    float yearSum[5] = {0}; // index 1‑4 used
    int yearCount[5] = {0};
    for (int i = 0; i < studentCount; ++i) {
        int yr = students[i].year;
        if (yr >= 1 && yr <= 4) {
            float cgpa = calculateCGPA(&students[i]);
            yearSum[yr] += cgpa;
            yearCount[yr]++;
        }
    }
    printf("Average CGPA per Year:\n");
    for (int yr = 1; yr <= 4; ++yr) {
        if (yearCount[yr] > 0) {
            printf("Year %d: %.2f (based on %d student(s))\n", yr, yearSum[yr] / yearCount[yr], yearCount[yr]);
        } else {
            printf("Year %d: No data\n", yr);
        }
    }
}

// Bubble sort students by SAP ID (ascending)
void sortBySAP(void) {
    if (studentCount < 2) return;
    for (int i = 0; i < studentCount - 1; ++i) {
        for (int j = 0; j < studentCount - i - 1; ++j) {
            if (students[j].sapID > students[j + 1].sapID) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by SAP ID.\n");
}

// Bubble sort students alphabetically by name
void sortByName(void) {
    if (studentCount < 2) return;
    for (int i = 0; i < studentCount - 1; ++i) {
        for (int j = 0; j < studentCount - i - 1; ++j) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by name.\n");
}

// Academic advisor – give feedback based on CGPA thresholds
void academicAdvisor(float cgpa) {
    if (cgpa >= 9.0f && cgpa <= 10.0f) {
        printf("Excellent Performance (CGPA: %.2f)\n", cgpa);
    } else if (cgpa >= 8.0f && cgpa < 9.0f) {
        printf("Good Performance (CGPA: %.2f)\n", cgpa);
    } else if (cgpa >= 6.0f && cgpa < 8.0f) {
        printf("Needs Improvement (CGPA: %.2f)\n", cgpa);
    } else {
        printf("Requires Immediate Attention (CGPA: %.2f)\n", cgpa);
    }
}

int main(void) {
    int choice;
    do {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Display Student (by SAP ID)\n");
        printf("4. Display All Students\n");
        printf("5. Calculate CGPA (by SAP ID)\n");
        printf("6. Average CGPA by Year\n");
        printf("7. Delete Student\n");
        printf("8. Sort by SAP ID\n");
        printf("9. Sort by Name\n");
        printf("10. Academic Advisor\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        switch (choice) {
            case 1: addStudent(); break;
            case 2: searchStudent(); break;
            case 3: {
                // Reuse searchStudent to display a specific student
                // (searchStudent already prints the record)
                searchStudent();
                break;
            }
            case 4: displayAll(); break;
            case 5: calculateStudentCGPA(); break;
            case 6: averageYearCGPA(); break;
            case 7: deleteStudent(); break;
            case 8: sortBySAP(); break;
            case 9: sortByName(); break;
            case 10: {
                float cg;
                printf("Enter CGPA for advisor: ");
                if (scanf("%f", &cg) == 1) {
                    clearInputBuffer();
                    academicAdvisor(cg);
                } else {
                    clearInputBuffer();
                    printf("Invalid CGPA input.\n");
                }
                break;
            }
            case 11: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    } while (choice != 11);
    return 0;
}
