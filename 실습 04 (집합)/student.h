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
private:
    Student *student;
    StudentNode *left;
    StudentNode *right;

public:
    StudentNode(Student *student);
    ~StudentNode();

    void insert(StudentNode *node);
    void print();

    Student *findByName(const char *name);
    int countStudentsBetterThan(const Student *student);
    bool hasNameRedundancy();
};

class StudentTree {
private:
    StudentNode *root;

public:
    StudentTree();
    ~StudentTree();

    void insert(Student *student);
    void print();

    void readFile(const char *filename);

    Student *findByName(const char *name);
    int countStudentsBetterThan(const Student *student);
    bool hasNameRedundancy();
};
