/*
 * Program: Student Grade Analyzer
 * Complexity: Structs, multiple conditional branches, logic processing
 */

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

struct Student {
    int id;
    int marks_math;
    int marks_science;
    int marks_english;
    float average;
    char grade;
    int passed; // 1 for pass, 0 for fail
};

int main() {
    struct Student students[MAX_STUDENTS];
    int i;
    int total_math = 0;
    int total_science = 0;
    int pass_count = 0;
    int fail_count = 0;

    // Initialize Data (Hardcoded to avoid user input issues in automated analysis)
    for(i = 0; i < MAX_STUDENTS; i++) {
        students[i].id = i + 1001;
        students[i].marks_math = 50 + (i * 4); // Generate varied marks
        students[i].marks_science = 60 + (i * 3);
        students[i].marks_english = 70 - (i * 2);
        students[i].passed = 0;
    }

    // Manual override to create edge cases
    students[0].marks_math = 95;
    students[2].marks_science = 30; // Fail case
    students[5].marks_english = 35; // Borderline

    printf("--- Student Result Processing ---\n");

    // Processing Loop
    for(i = 0; i < MAX_STUDENTS; i++) {
        // Calculate Average
        int sum = students[i].marks_math + students[i].marks_science + students[i].marks_english;
        students[i].average = sum / 3.0;

        // Assign Grade based on conditionals
        if (students[i].average >= 90) {
            students[i].grade = 'A';
        } else if (students[i].average >= 80) {
            students[i].grade = 'B';
        } else if (students[i].average >= 70) {
            students[i].grade = 'C';
        } else if (students[i].average >= 60) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }

        // Determine Pass/Fail Status
        // Rule: Must have > 40 in all subjects OR average > 60
        int math_pass = (students[i].marks_math >= 40);
        int sci_pass = (students[i].marks_science >= 40);
        int eng_pass = (students[i].marks_english >= 40);

        if ((math_pass && sci_pass && eng_pass) || (students[i].average > 60)) {
            students[i].passed = 1;
            pass_count++;
        } else {
            students[i].passed = 0;
            fail_count++;
        }

        // Accumulate totals for stats
        total_math += students[i].marks_math;
        total_science += students[i].marks_science;
    }

    // Analysis Reporting
    printf("ID\tMath\tSci\tEng\tAvg\tGrade\tStatus\n");
    printf("----------------------------------------------------\n");
    
    for(i = 0; i < MAX_STUDENTS; i++) {
        printf("%d\t%d\t%d\t%d\t%.1f\t%c\t", 
            students[i].id, 
            students[i].marks_math, 
            students[i].marks_science, 
            students[i].marks_english, 
            students[i].average, 
            students[i].grade);
        
        if(students[i].passed) {
            printf("PASS\n");
        } else {
            printf("FAIL\n");
        }
    }

    // Class Statistics
    printf("\n--- Class Statistics ---\n");
    printf("Total Students: %d\n", MAX_STUDENTS);
    printf("Pass Count: %d\n", pass_count);
    printf("Fail Count: %d\n", fail_count);

    if (pass_count > fail_count) {
        printf("Overall Class Performance: GOOD\n");
    } else {
        printf("Overall Class Performance: NEEDS IMPROVEMENT\n");
    }

    // Find Topper
    int topper_idx = 0;
    float max_avg = -1.0;
    
    for(i = 0; i < MAX_STUDENTS; i++) {
        if(students[i].average > max_avg) {
            max_avg = students[i].average;
            topper_idx = i;
        }
    }
    printf("Class Topper ID: %d with %.2f%%\n", students[topper_idx].id, max_avg);

    return 0;
}
