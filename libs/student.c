#include "student.h"
#include <stdio.h>
#include <string.h>

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender) {
    // Implementasi dari fungsi ini
}

void load_students(struct student_t *students, int *num_students) {
    FILE *file = fopen("student-repository.txt", "r");
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *id = strtok(line, "|");
        char *name = strtok(NULL, "|");
        char *year = strtok(NULL, "|");
        char *gender_str = strtok(NULL, "|");
        enum gender_t gender = strcmp(gender_str, "male") == 0 ? male : female;
        students[*num_students] = create_student(id, name, year, gender);
        (*num_students)++;
    }
    fclose(file);
}