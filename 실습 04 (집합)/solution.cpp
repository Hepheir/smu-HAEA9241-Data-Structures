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

class Node {
public:
    Student *student;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(Student *student);
};

class BinaryTree {
public:
    Node *root = nullptr;
    void add(Student *student);
    Student *find(const char *name);
};

int main() {
    BinaryTree tree;

    return 0;
}

Node::Node(Student *student) {
    this->student = student;
}