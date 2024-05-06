#include "dorm.h"
#include <stdio.h>
#include <string.h>

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender){
    FILE *fd;
    fd = fopen("storage/dorm-repository.txt", "a");
    if (_gender == GENDER_MALE) {
        fprintf(fd, "%s|%d|male\n", _name, _capacity);
    } else if (_gender == GENDER_FEMALE) {
        fprintf(fd, "%s|%d|female\n", _name, _capacity);
    }
    fclose(fd);

    struct dorm_t dorm;
    strcpy(dorm.name, _name);
    dorm.capacity = _capacity;
    dorm.gender = _gender;
    dorm.residents_num = 0;

    return dorm;
}

void print_dorm(struct dorm_t *_dorm, int jumlah){
    for(int i = 0; i < jumlah; i++){
        if(_dorm[i].gender == GENDER_FEMALE){
            printf("%s|%d|female\n", _dorm[i].name, _dorm[i].capacity);
        } else if(_dorm[i].gender == GENDER_MALE) {
            printf("%s|%d|male\n", _dorm[i].name, _dorm[i].capacity);
        }
    }
}

void print_dorm_detail(struct dorm_t *_dorm, int jumlah){
    for(int i = 0; i < jumlah; i++){
        if(_dorm[i].gender == GENDER_FEMALE){
            printf("%s|%d|female|%d\n", _dorm[i].name, _dorm[i].capacity, _dorm[i].residents_num);
        } else if(_dorm[i].gender == GENDER_MALE){
            printf("%s|%d|male|%d\n", _dorm[i].name, _dorm[i].capacity, _dorm[i].residents_num);
        }
    }
}