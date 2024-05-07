#include "dorm.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct dorm_t create_dorm(char *input)
{
  struct dorm_t dorm;
  strcpy(dorm.name, strtok(input, "#"));
  dorm.capacity = atoi(strtok(NULL, "#"));
  char *gender = strtok(NULL, "#");
  dorm.gender = (strcmp(gender, "male") == 0) ? GENDER_MALE : GENDER_FEMALE;
  dorm.residents_num = 0;
  return dorm;
}

void print_dorm(struct dorm_t dorm)
{
  printf("%s|%hu|%s\n", dorm.name, dorm.capacity, (dorm.gender == GENDER_MALE) ? "male" : "female");
}

void print_dorm_detail(struct dorm_t dorm)
{
  printf("%s|%hu|%s|%hu\n", dorm.name, dorm.capacity, (dorm.gender == GENDER_MALE) ? "male" : "female", dorm.residents_num);
}

int find_dorm(char *dorm_name, int dorm_count, struct dorm_t *dorms)
{
  for (int i = 0; i < dorm_count; i++)
  {
    if (strcmp(dorm_name, dorms[i].name) == 0)
    {
      return i;
    }
  }
  return -1;
}