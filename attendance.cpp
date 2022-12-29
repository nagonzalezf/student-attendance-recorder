#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define total_students 5 // NUMBER OF TOTAL STUDENTS, MODIFY THIS!!
#define file_name "attendance.txt"

typedef struct {
  char name[50];
  int total_attendances;
} Student;

int main() {
	// LIST OF STUDENT NAMES, MODIFY THIS!!
    Student students[total_students] = {
    {"Student name 1", 0},
    {"Student name 2", 0},
    {"Student name 3", 0},
    {"Student name 4", 0},
    {"Student name 5", 0}
  };
  
  printf("Welcome to NAGF Student Attendance Recorder!\n\n");
  
  int day, month, year;
  printf("Enter today's date (dd/mm/yyyy): ");
  scanf("%d/%d/%d", &day, &month, &year);

  for (int i = 0; i < total_students; i++) {
    char response;
    printf("Is student %s present? (y/n): ", students[i].name);
    scanf(" %c", &response);

    if (response == 'y') {
      students[i].total_attendances++;
    }
  }

  FILE* file = fopen(file_name, "a");
  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  fprintf(file, "Date: %d/%d/%d\n", day, month, year);
  for (int i = 0; i < total_students; i++) {
    fprintf(file, "%s: %d\n", students[i].name, students[i].total_attendances);
  }

  fclose(file);
  
  int total_attendances = 0;
  for (int i = 0; i < total_students; i++) {
    total_attendances += students[i].total_attendances;
  }
  double attendance_percentage = (double)total_attendances / total_students * 100;
  printf("\nStudents present today: %d\n", total_attendances);
  printf("\nAttendance percentage: %.2f%%", attendance_percentage);

  printf("\n\nPress any key to continue...\n\n");
  getch();

  printf("Good luck! May it be a master class!\n");
  
  return 0;
}

// https://github.com/nagonzalezf
