#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

#include "student.cpp"

void Q1();
void Q2();
void Q3();
void Q4();
void Q5();

StudentTree *tree;

int main() {
    tree = new StudentTree();
    tree->readFile("list.txt");
    // tree->print();

    Q1();
    Q2();
    Q3();
    Q4();
    Q5();

    delete tree;
    return 0;
}

void Q1() {
    printf("Q1. 김문희가 사는 곳은 어디인가?\n\n");
    const char *name = "김문희";
    Student *student = tree->findByName(name);
    if (student == nullptr) {
        printf("[warning] %s 학생을 찾을 수 없습니다.\n\n", name);
        return;
    }
    printf("[info] %s 학생이 사는 곳은 \"%s\"입니다.\n\n", name, student->address);
}

void Q2() {
    printf("Q2. 천하은보다 성적이 더 좋은 사람은 몇 명인가?\n\n");
    const char *name = "천하은";
    Student *student = tree->findByName(name);
    if (student == nullptr) {
        printf("[warning] %s 학생을 찾을 수 없습니다.\n\n", name);
        return;
    }
    printf("[info] %s보다 성적이 더 좋은 사람은 %d명입니다.\n\n", name, tree->countStudentsBetterThan(student));
}

void Q3() {
    printf("Q3. 가장 학생이 많은 학과는 무슨 과인가?\n\n");
    if (tree->isEmpty()) {
        printf("[warning] 등록된 학생이 없습니다.\n\n");
        return;
    }
    printf("[info] 가장 학생이 많은 학과는 \"%s\" 입니다.\n\n", tree->findMostPopulatedDepartment().c_str());
}

void Q4() {
    printf("Q4. 학생들이 거주하는 지역을 가장 많은 학생들이 거주하는 지역 순으로 출력하라\n\n");
    tree->printAddressesByPopulationInAscendingOrder();
    printf("\n");
}

void Q5() {
    printf("Q5. 학생들의 이름을 ID로 사용하는 것이 가능한가?\n\n");
    if (tree->hasNameRedundancy()) {
        printf("[info] 불가능합니다. 중복된 이름이 있습니다.\n\n");
    } else {
        printf("[info] 가능합니다. 중복된 이름이 없습니다.\n\n");
    }
    printf("\n");
}