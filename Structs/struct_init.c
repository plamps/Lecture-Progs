#include <stdio.h>

// Structure definition
struct student {
  char name[50];
  char class[50];
  int id;
};

int main() {
  // Declare and initialize array of students
  struct student students[5] = {
                                {"Bob Dylan", "Department of Digital Systems", 1},
                                {"David Bowie", "Department of Medicine", 2},
                                {"Bob Marley", "Department of Electrical Engineering", 3},
                                {"Jack Johnson", "Department of Physical Education", 4},
                                {"Sarah Parker", "Department of Informatics", 5}
                               };

  // Display student information
  printf("Student Information\n");
  printf("Student Id \tName \t\t\tClass \n");
    
  for (int i = 0; i < 5; ++i) {
    printf("%7d \t%-20s \t%s\n",
           students[i].id, students[i].name,
           students[i].class);
  }

  return 0;
}