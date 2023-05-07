#include "student.h"

void Student::fread(FILE *fp) {
    fscanf(fp, "%s %c %s %s %f %d %d", name, &gender, address, department, &gpa, &height, &weight);
}

StudentNode::StudentNode(Student *student) {
    this->student = student;
    left = nullptr;
    right = nullptr;
}

StudentNode::~StudentNode() {
    delete student;
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
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

int StudentNode::countStudentsBetterThan(const Student *student) {
    int count = 0;
    if (left != nullptr) count += left->countStudentsBetterThan(student);
    if (right != nullptr) count += right->countStudentsBetterThan(student);
    if (this->student->gpa > student->gpa) count += 1;
    return count;
}

bool StudentNode::hasNameRedundancy() {
    if (left != nullptr) {
        if (left->findByName(student->name) != nullptr) return true;
        if (left->hasNameRedundancy()) return true;
    }
    if (right != nullptr) {
        if (right->findByName(student->name) != nullptr) return true;
        if (right->hasNameRedundancy()) return true;
    }
    return false;
}

void StudentNode::print() {
    if (left != nullptr) left->print();
    printf("%s ", student->name);
    if (right != nullptr) right->print();
}

void StudentNode::countByDepartment(std::map<std::string, int> *counter) {
    std::map<std::string, int>::iterator it = counter->find(student->department);
    if (it == counter->end()) {
        counter->insert(std::make_pair(student->department, 1));
    }
    else {
        it->second++;
    }
    if (left != nullptr) left->countByDepartment(counter);
    if (right != nullptr) right->countByDepartment(counter);
}

void StudentNode::countByAddress(std::map<std::string, int> *counter) {
    std::map<std::string, int>::iterator it = counter->find(student->address);
    if (it == counter->end()) {
        counter->insert(std::make_pair(student->address, 1));
    }
    else {
        it->second++;
    }
    if (left != nullptr) left->countByAddress(counter);
    if (right != nullptr) right->countByAddress(counter);
}

StudentTree::StudentTree() {
    root = nullptr;
}

StudentTree::~StudentTree() {
    if (root != nullptr) delete root;
}

bool StudentTree::isEmpty() {
    return root == nullptr;
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
    StudentNode *node = new StudentNode(student);

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

int StudentTree::countStudentsBetterThan(const Student *student) {
    if (root == nullptr) return 0;
    return root->countStudentsBetterThan(student);
}

bool StudentTree::hasNameRedundancy() {
    if (root != nullptr) {
        return root->hasNameRedundancy();
    }
    return false;
}

void StudentTree::print() {
    if (root != nullptr) {
        root->print();
        printf("\n");
    }
}

std::string StudentTree::findMostPopulatedDepartment() {
    if (root == nullptr) {
        return nullptr;
    }
    std::map<std::string, int> m;
    std::map<std::string, int>::iterator it;
    std::string department;
    int population = -1;
    root->countByDepartment(&m);
    for (it = m.begin(); it != m.end(); it++) {
        if (it->second > population) {
            department = it->first;
            population = it->second;
        }
    }
    return department;
}

void StudentTree::printAddressesByPopulationInAscendingOrder() {
    if (root == nullptr) {
        return;
    }
    std::map<std::string, int> m;
    std::map<std::string, int>::iterator it;
    AddressTree *tree = new AddressTree();
    root->countByAddress(&m);
    for (it = m.begin(); it != m.end(); it++) {
        tree->insert(it->first.c_str(), it->second);
    }
    tree->print();
    delete tree;
}

AddressNode::AddressNode(const char *address, int count) {
    this->address = address;
    this->count = count;
    left = nullptr;
    right = nullptr;
}

AddressNode::~AddressNode() {
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
}

void AddressNode::insert(AddressNode *node) {
    if ((node->count > count) || (node->count == count) && strcmp(node->address, address) < 0) {
        if (left == nullptr) left = node;
        else left->insert(node);
    }
    else {
        if (right == nullptr) right = node;
        else right->insert(node);
    }
}

void AddressNode::print() {
    // in-order 순으로 순회하면 정렬된 순서로 출력하게 됨.
    if (left != nullptr) left->print();
    printf("%s(%d명) ", address, count);
    if (right != nullptr) right->print();
}

AddressTree::AddressTree() {
    root = nullptr;
}

AddressTree::~AddressTree() {
    if (root != nullptr) delete root;
}

void AddressTree::insert(const char *address, int count) {
    AddressNode *nnode = new AddressNode(address, count);
    if (root == nullptr) {
        root = nnode;
        return;
    }
    root->insert(nnode);
}

void AddressTree::print() {
    if (root != nullptr) {
        root->print();
        printf("\n");
    }
}