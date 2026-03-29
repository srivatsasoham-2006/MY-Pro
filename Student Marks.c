#include <stdio.h>

#define MAX 100

// Function declarations
void inputMarks(int marks[], int n);
float calculateAverage(int marks[], int n);
char calculateGrade(float avg);
int findHighest(int marks[], int n);
int findLowest(int marks[], int n);

int main() {
    int n, marks[MAX];

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of students!\n");
        return 0;
    }

    inputMarks(marks, n);

    float avg = calculateAverage(marks, n);
    char grade = calculateGrade(avg);
    int highest = findHighest(marks, n);
    int lowest = findLowest(marks, n);

    printf("\n===== PERFORMANCE REPORT =====\n");
    printf("Average Marks: %.2f\n", avg);
    printf("Grade: %c\n", grade);
    printf("Highest Marks: %d\n", highest);
    printf("Lowest Marks: %d\n", lowest);

    return 0;
}

// Function to input marks
void inputMarks(int marks[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter marks for student %d: ", i + 1);
        scanf("%d", &marks[i]);

        if (marks[i] < 0 || marks[i] > 100) {
            printf("Invalid marks! Enter again.\n");
            i--; // retry same index
        }
    }
}

// Function to calculate average
float calculateAverage(int marks[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += marks[i];
    }
    return (float)sum / n;
}

// Function to assign grade
char calculateGrade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 75) return 'B';
    else if (avg >= 60) return 'C';
    else if (avg >= 50) return 'D';
    else return 'F';
}

// Function to find highest marks
int findHighest(int marks[], int n) {
    int max = marks[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] > max) {
            max = marks[i];
        }
    }
    return max;
}

// Function to find lowest marks
int findLowest(int marks[], int n) {
    int min = marks[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] < min) {
            min = marks[i];
        }
    }
    return min;
}
