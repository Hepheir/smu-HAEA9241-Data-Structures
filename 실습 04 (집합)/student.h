#include <cstdio>
#include <cstring>
#include <map>
#include <string>

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
    void countByDepartment(std::map<std::string, int> *counter);
    void countByAddress(std::map<std::string, int> *counter);
};

class StudentTree {
private:
    StudentNode *root;

public:
    StudentTree();
    ~StudentTree();

    void insert(Student *student);
    void print();
    bool isEmpty();

    void readFile(const char *filename);

    Student *findByName(const char *name);
    int countStudentsBetterThan(const Student *student);
    bool hasNameRedundancy();
    std::string findMostPopulatedDepartment();
    void printAddressesByPopulationInAscendingOrder();
};

class AddressNode {
private:
    const char *address;
    int count;
    AddressNode *left;
    AddressNode *right;

public:
    AddressNode(const char *address, int count);
    ~AddressNode();

    void insert(AddressNode *node);
    void print();
};

class AddressTree {
private:
    AddressNode *root;

public:
    AddressTree();
    ~AddressTree();

    void insert(const char *address, int count);
    void print();
};
