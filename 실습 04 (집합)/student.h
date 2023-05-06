#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

#define MAX_STR_LEN 36

class Student {
public:
    char name[MAX_STR_LEN];
    char gender;
    char address[MAX_STR_LEN];
    char department[MAX_STR_LEN];
    float gpa;
    int height;
    int weight;

    void fread(FILE *fp);
};

class StudentNode {
public:
    Student *student;
    StudentNode *left = nullptr;
    StudentNode *right = nullptr;

    void insert(StudentNode *node);
    Student *search(const char *name);
};

class StudentTree {
public:
    StudentNode *root = nullptr;

    void readFile(const char *filename);
    void insert(Student *student);
    Student *search(const char *name);
};
