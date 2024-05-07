#include "repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dorm_t create_dormitory_repository(char *input)
{
  struct dorm_t dorm;
  strcpy(dorm.dorm_name, strtok(input, "|"));
  dorm.dorm_capacity = atoi(strtok(NULL, "|"));
  char *gender = strtok(NULL, "|");
  dorm.dorm_gender = (strcmp(gender, "male") == 0) ? GENDER_MALE : GENDER_FEMALE;
  dorm.num_residents = 0;
  return dorm;
}

struct student_t create_student_repository(char *input)
{
  struct student_t student;
  strcpy(student.id, strtok(input, "|"));
  strcpy(student.name, strtok(NULL, "|"));
  strcpy(student.year, strtok(NULL, "|"));
  char *gender = strtok(NULL, "|");
  student.gender = (strcmp(gender, "male") == 0) ? GENDER_MALE : GENDER_FEMALE;
  student.dorm = malloc(sizeof(struct dorm_t));
  strcpy(student.dorm->dorm_name, "unassigned");

  return student;
}