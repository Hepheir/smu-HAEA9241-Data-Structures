#include <cstdio>

#include "student.h"

void Q1();
void Q2();
void Q3();
void Q4();
void Q5();

StudentTree *tree;

int main() {
    tree = new StudentTree();
    tree->readFile("list.txt");

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
    printf("\n");
}

void Q2() {
    printf("Q2. 천하은보다 성적이 더 좋은 사람은 몇 명인가?\n\n");
    printf("\n");
}

void Q3() {
    printf("Q3. 가장 학생이 많은 학과는 무슨 과인가?\n\n");
    printf("\n");
}

void Q4() {
    printf("Q4. 학생들이 거주하는 지역을 가장 많은 학생들이 거주하는 지역 순으로 출력하라\n\n");
    printf("\n");
}

void Q5() {
    printf("Q5. 학생들의 이름을 ID로 사용하는 것이 가능한가?\n\n");
    printf("\n");
}