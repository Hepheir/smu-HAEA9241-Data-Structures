/**
 * @file solution.c
 * @author 김동주 (hepheir@gmail.com)
 * @brief 자료 구조 실습 #1 "C언어를 이용한 파일 입출력" 소스 코드
 * @version 0.1
 * @date 2023-03-15
 */

#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "list.txt"
#define STRING_MAX_LEN 16 // 가장 긴 문자열의 길이가 한글 6자 이므로 최대 13 bytes 필요.

// 1. 학생 정보를 저장할 구조체 선언하기

typedef struct {
    char name[STRING_MAX_LEN]; // 이름
    char gender; // 성별
    char address[STRING_MAX_LEN]; // 사는 곳
    char department[STRING_MAX_LEN]; // 학과
    float gpa; // 평점
    int height; // 키
    int weight; // 체중
} Student;

int main(int argc, char *argv[]) {
    FILE *pFile;
    size_t lineCount;
    Student *studentRepository;
    size_t studentCount;
    int i;

    // 2. 파일의 줄 수 세기

    pFile = fopen(FILE_PATH, "r");
    if (pFile == NULL) {
        return -1; // 파일 읽기에 실패 함.
    }
    lineCount = 1;
    for (char c = fgetc(pFile); c != EOF; c = fgetc(pFile)) {
        if (c == '\n') {
            lineCount++;
        }
    }
    fclose(pFile);
    studentCount = lineCount;

    // 3. 동적 메모리 할당하기

    studentRepository = (Student *) malloc(sizeof(Student) * studentCount);

    // 4. 입력받기

    pFile = fopen(FILE_PATH, "r");
    if (pFile == NULL) {
        return -1; // 파일 읽기에 실패 함.
    }
    for (i = 0; i < studentCount; i++) {
        fscanf(pFile, "%s %c %s %s %f %d %d",
            studentRepository[i].name,
            &studentRepository[i].gender,
            studentRepository[i].address,
            studentRepository[i].department,
            &studentRepository[i].gpa,
            &studentRepository[i].height,
            &studentRepository[i].weight);
    }
    fclose(pFile);

    // 5. 출력하기

    for (i = 0; i < studentCount; i++) {
        printf("%s %c %s %s %.2f %d %d\n",
            studentRepository[i].name,
            studentRepository[i].gender,
            studentRepository[i].address,
            studentRepository[i].department,
            studentRepository[i].gpa,
            studentRepository[i].height,
            studentRepository[i].weight);
    }

    // 프로그램 종료

    free(studentRepository);
    return 0;
}