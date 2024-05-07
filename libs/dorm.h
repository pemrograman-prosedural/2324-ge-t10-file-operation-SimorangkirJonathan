#ifndef DORM_H
#define DORM_H

#include "gender.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

struct dorm_t
{
  char dorm_name[20];
  unsigned short dorm_capacity;
  enum gender_t dorm_gender;
  unsigned short num_residents;
};

struct dorm_t create_dormitory(char *input);
void display_dorm(struct dorm_t dorm);
void display_dorm_detail(struct dorm_t dorm);
int locate_dorm(char *dorm_name, int total_dorms, struct dorm_t *dorms);
#endif