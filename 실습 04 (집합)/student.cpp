#include "student.h"

void Student::fread(FILE *fp) {
    fscanf(fp, "%s %c %s %s %f %d %d", name, &gender, address, department, &gpa, &height, &weight);
}

void StudentNode::insert(StudentNode *node) {
    if (strcmp(node->student->name, student->name) < 0) {
        if (left == nullptr) left = node;
        else left->insert(node);
    }
    else {
        if (right == nullptr) right = node;
        else right->insert(node);
    }
}

Student *StudentNode::findByName(const char *name) {
    if (strcmp(name, student->name) < 0) {
        if (left == nullptr) return nullptr;
        else return left->findByName(name);
    }
    else if (strcmp(name, student->name) > 0) {
        if (right == nullptr) return nullptr;
        else return right->findByName(name);
    }
    return student;
}

void StudentTree::readFile(const char *filename) {
    // 파일을 읽음과 동시에 트리를 채워감.
    // 이진 트리에서의 삽입은 항상 정렬된 상태를 유지함.
    FILE *fp = fopen(filename, "r");
    while (!feof(fp)) {
        Student *student = new Student();
        student->fread(fp);
        insert(student);
    }
    fclose(fp);
}

void StudentTree::insert(Student *student) {
    // 정렬된 상태를 유지하며 삽입.
    StudentNode *node = new StudentNode();
    node->student = student;

    if (root == nullptr) root = node;
    else root->insert(node);
}

Student *StudentTree::findByName(const char *name) {
    if (root == nullptr) {
        printf("EMPTY TREE!\n");
        return nullptr;
    }
    return root->findByName(name);
}