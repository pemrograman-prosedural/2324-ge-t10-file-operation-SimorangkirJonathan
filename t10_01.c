// 12S23030 -Simorangkir Jonathan
//12S23045 - Chintya Reginauli Rajaguguk 
#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

#define MAX_DORMS 100
#define MAX_STUDENTS 1000

void print_dorm_detail(struct dorm_t *dorm) {
    printf("%s|%hu|%s|%hu\n", dorm->name, dorm->capacity, gender_to_string(dorm->gender), dorm->residents_num);
}

void print_student_detail(struct student_t *student) {
    printf("%s|%s|%s|%s|%s\n", student->id, student->name, student->year, gender_to_string(student->gender), student->dorm ? student->dorm->name : "unassigned");
}

int main(int _argc, char **_argv)
{
    struct dorm_t dorms[MAX_DORMS];
    int num_dorms;
    struct student_t students[MAX_STUDENTS];
    int num_students;

    load_dorms(dorms, &num_dorms);
    load_students(students, &num_students);

    for (int i = 0; i < num_dorms; i++) {
        print_dorm_detail(&dorms[i]);
    }

    for (int i = 0; i < num_students; i++) {
        print_student_detail(&students[i]);
    }

    return 0;
}   