#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#include "gender.h"

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender)
{
    struct student_t stud;
    strcpy(stud.year, _year);
    strcpy(stud.name, _name);
    strcpy(stud.id, _id);
    stud.gender = _gender;
    stud.dorm = malloc(sizeof(struct dorm_t));
    stud.dorm = NULL;

    return stud;
}

void print_students(struct student_t *_student, int jumlah)
{
    char stud_gender[10] = "";

    for(int x = 1; x < jumlah + 1; ++x)
    {
        if(_student[x].gender == 0)
        {
            strcpy(stud_gender, "male");
            printf("%s|%s|%s|%s\n", _student[x].id, _student[x].name, _student[x].year, stud_gender);
        }
        else if(_student[x].gender == 1)
        {
            strcpy(stud_gender, "female");
            printf("%s|%s|%s|%s\n", _student[x].id, _student[x].name, _student[x].year, stud_gender);
        }
    }
}

void print_students_detail(struct student_t *_student, int jumlah)
{
    char stud_gender[10] = "";

    for(int x = 1; x < jumlah + 1; ++x)
    {
        if (_student[x].dorm == NULL)
        {
            if(_student[x].gender == 0)
            {
                strcpy(stud_gender, "male");
                printf("%s|%s|%s|%s|unassigned\n", _student[x].id, _student[x].name, _student[x].year, stud_gender);
            }
            else if(_student[x].gender == 1)
            {
                strcpy(stud_gender, "female");
                printf("%s|%s|%s|%s|unassigned\n", _student[x].id, _student[x].name, _student[x].year, stud_gender);
            }
        }
        else
        {
            if(_student[x].gender == 0)
            {
                strcpy(stud_gender, "male");
                printf("%s|%s|%s|%s|%s\n", _student[x].id, _student[x].name, _student[x].year, stud_gender, _student[x].dorm->name);
            }
            else if(_student[x].gender == 1)
            {
                strcpy(stud_gender, "female");
                printf("%s|%s|%s|%s|%s\n", _student[x].id, _student[x].name, _student[x].year, stud_gender, _student[x].dorm->name);
            }
        }
    }
}

void assign_student(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name)
{
    if (_dorm->capacity > _dorm->residents_num)
    {
        if (_student->gender == _dorm->gender)
        {
            _student->dorm = _dorm;
            ++_dorm->residents_num;
        }
    }    
}   

void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *old_dorm, char *id, char *dorm_name)
{
    if (_dorm->capacity > _dorm->residents_num)
    {
        if (_student->gender == _dorm->gender)
        {
            _student->dorm = _dorm;
            ++_dorm->residents_num;
            --old_dorm->residents_num;
        }
    }
}

void unassign_student(struct student_t *_student, struct dorm_t *_dorm)
{
    _student->dorm = NULL;
    --_dorm->residents_num;
}
