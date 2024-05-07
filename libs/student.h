#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

struct student_t
{
    char student_id[12];
    char student_name[40];
    char enrollment_year[5];
    enum gender_t student_gender;
    struct dorm_t *assigned_dorm;
};

struct student_t create_student_record(char *input);
void display_student(struct student_t student);
void display_student_detail(struct student_t student);
void assign_student_to_dorm(struct dorm_t *dorm, struct student_t *student, char *student_id, char *dorm_name, int student_count, int dorm_count, int find_student_id(char *student_id, int student_count, struct student_t *students), int locate_dorm(char *dorm_name, int dorm_count, struct dorm_t *dorms));
int find_student_id(char *student_id, int student_count, struct student_t *students);
void transfer_student(struct dorm_t *dorm, struct student_t *student, char *student_id, char *dorm_name, int student_count, int dorm_count, int find_student_id(char *student_id, int student_count, struct student_t *students), int locate_dorm(char *dorm_name, int dorm_count, struct dorm_t *dorms));
void check_dorm_empty(char *dorm_name, int student_count, int dorm_count, struct student_t *students, struct dorm_t *dorms, int locate_dorm(char *dorm_name, int dorm_count, struct dorm_t *dorms));
#endif