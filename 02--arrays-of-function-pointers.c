#include <stdio.h>

#define STUDENTS 3
#define EXAMS 4

void minimumGrade(int (*studentGradesArray)[EXAMS], size_t students, size_t exams);
void maximumGrade(int (*studentGradesArray)[EXAMS], size_t students, size_t exams);
void studentGradeAverage(int (*studentGradesArray)[EXAMS], size_t studentIndex, size_t exams);
void printArray(int (*studentGradesArray)[EXAMS], size_t students, size_t exams);

int main() {
  int studentGrades[STUDENTS][EXAMS] = {
    {77, 68, 86, 73},
    {96, 87, 89, 78},
    {70, 90, 86, 81}};

  void (*processGrades[4])(int [][EXAMS], size_t, size_t) = {
      printArray,
      minimumGrade,
      maximumGrade,
      studentGradeAverage
  };

  int userInput = 0;
  printf("Welcome to the Student Grades program!\n");

  while(1)
  {
    printf("= = = = = = = = = = = = = = = \n"); //visual separator
    printf("\nEnter a choice: \n\t0  Print the array of grades\n\t1  Find the minimum grade\n\t2  Find the maximum grade\n\t3  Print the average on all tests for each student\n\t4  End program\n");

    if (scanf("%d", &userInput) != 1) { //if input is not an integer
      printf("Invalid input. Please enter a number (0-4).\n");
      while (getchar() != '\n'); // clear the input
      continue;
    }

    printf("= = = = = = = = = = = = = = = \n"); //visual separator

    if (userInput >= 0 && userInput < 4) {
      processGrades[userInput](studentGrades, STUDENTS, EXAMS); // call the function pointer
    } else if (userInput == 4) {
      return 0;
    } else {
      printf("Invalid input. Please enter a number between 0 and 4.\n");
    }
  }

  return 0;
}

/**
 * minimumGrade()
 * Finds the minimum grade out of all students, and then prints it
 *
 * @*studentGradesArray[]: Pointer to the 2D array of student grades
 * @students: Number of students
 * @exams: Number of exams
 */
void minimumGrade(int (*studentGradesArray)[EXAMS], size_t students, size_t exams) {
  int min = **studentGradesArray; // Start with the first element
  for (int *arrayPtr = &studentGradesArray[0][0]; arrayPtr < &studentGradesArray[students][0]; arrayPtr++) {
      if (*arrayPtr < min) {
          min = *arrayPtr;
      }
  }
  printf("The minimum grade of all students is: %d\n", min);
}

/**
 * maximumGrade()
 * Finds the maximum grade out of all students and then prints it
 *
 * @*studentGradesArray[]: Pointer to the 2D array of student grades
 * @students: Number of students
 * @exams: Number of exams
 */
void maximumGrade(int (*studentGradesArray)[EXAMS], size_t students, size_t exams) {
  int max = **studentGradesArray;
  for (int *arrayPtr = &studentGradesArray[0][0]; arrayPtr < &studentGradesArray[students][0]; arrayPtr++) {
    if (*arrayPtr > max) {
        max = *arrayPtr;
    }
  }
  printf("The maximum grade of all students is: %d\n", max);
}

/**
 * studentGradeAverage()
 * Calculates the average grade for each student, printing them out seperately
 *
 * @*studentGradesArray[]: Pointer to the 2D array of student grades
 * @students: Number of students
 * @exams: Number of exams
 */
void studentGradeAverage(int (*studentGradesArray)[EXAMS], size_t students, size_t exams) {
  for (size_t i = 0; i < students; i++) {
    float gradesSum = 0.0;
    for (size_t i = 0; i < exams; i++) {
      gradesSum += studentGradesArray[i][i];
    }
    printf("Student %zu average is: %.2f\n", i+1, (gradesSum / exams));
  }
}

/**
 * printArray()
 * Prints the contents of a 2D array of integers
 *
 * @*studentGradesArray[]: Pointer to the 2D array of student grades
 * @students: Number of students
 * @exams: Number of exams
 */
void printArray(int (*studentGradesArray)[EXAMS], size_t students, size_t exams) {
  printf("\t");
  for (size_t i = 0; i < exams; i++) {
    printf("\t[%zu]", i);
  }

  for (int i = 0; i < students; i++) {
    printf("\nStudent %d: ", i + 1);
    putchar('\t');

    for (size_t j = 0; j < exams; j++) {
      printf("%d\t", studentGradesArray[i][j]);
    }

    putchar('\n');
  }

  putchar('\n');
}
