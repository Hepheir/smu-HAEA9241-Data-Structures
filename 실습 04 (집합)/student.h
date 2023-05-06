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
    StudentNode *left;
    StudentNode *right;

    StudentNode(Student *student);
    ~StudentNode();

    void insert(StudentNode *node);
    Student *findByName(const char *name);
    int countStudentsBetterThan(const Student *student);
};

class StudentTree {
public:
    StudentNode *root;

    StudentTree();
    ~StudentTree();

    void readFile(const char *filename);
    void insert(Student *student);
    Student *findByName(const char *name);
    int countStudentsBetterThan(const Student *student);
};
