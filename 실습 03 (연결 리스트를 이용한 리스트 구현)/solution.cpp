#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#define MAX_STR_LEN 36
#define MAX_CMD_LEN 512

#define CMD_STR_CREATE "CREATE"
#define CMD_STR_LOAD "LOAD"
#define CMD_STR_PRINT "PRINT"
#define CMD_STR_INSERT "INSERT"
#define CMD_STR_DELETE "DELETE"
#define CMD_STR_SEARCH "SEARCH"

#define CMD_CREATE 0
#define CMD_LOAD 1
#define CMD_PRINT 2
#define CMD_INSERT 3
#define CMD_DELETE 4
#define CMD_SEARCH 5

class data_type
{
public:
    char name[MAX_STR_LEN];
    char gender;
    char location[MAX_STR_LEN];
    char department[MAX_STR_LEN];
    float gpa;
    int height;
    int weight;

    data_type(char *name, char gender, char *location, char *department, float gpa, int height, int weight)
    {
        strcpy(this->name, name);
        this->gender = gender;
        strcpy(this->location, location);
        strcpy(this->department, department);
        this->gpa = gpa;
        this->height = height;
        this->weight = weight;
    }

    data_type(char args[7][MAX_STR_LEN])
    {
        strcpy(this->name, args[0]);
        this->gender = args[1][0];
        strcpy(this->location, args[2]);
        strcpy(this->department, args[3]);
        this->gpa = atof(args[4]);
        this->height = atoi(args[5]);
        this->weight = atoi(args[6]);
    }

    void print()
    {
        printf("%s %c %s %s %.2f %d %d\n", name, gender, location, department, gpa, height, weight);
    }
};

class node
{
public:
    data_type *item;
    node *link; // 다음 학생을 가리키는 포인터

    ~node()
    {
        free(item);
    }

    void insert(data_type *item)
    {
        node *curr = this;
        while (curr->link != nullptr)
        {
            if (strcmp(curr->link->item->name, item->name) > 0)
            {
                break;
            }
            curr = curr->link;
        }
        node *nnode = new node;
        nnode->item = item;
        nnode->link = curr->link;
        curr->link = nnode;
    }

    void remove(char *name)
    {
        node *curr = this;
        while (curr->link != nullptr)
        {
            if (strcmp(curr->link->item->name, name) == 0)
            {
                break;
            }
            curr = curr->link;
        }
        if (curr->link == nullptr)
        {
            return;
        }
        node *dnode = curr->link;
        curr->link = dnode->link;
        free(dnode);
    }

    node *search(char *name)
    {
        node *curr = this;
        while (curr != nullptr)
        {
            if (strcmp(curr->item->name, name) == 0)
            {
                return curr;
            }
            curr = curr->link;
        }
        return nullptr;
    }

    void print()
    {
        item->print();
    }
};

class head_node
{
public:
    node *head;

    void insert(data_type *item)
    {
        // 텅 빈 리스트에 처음 추가
        if (head == nullptr)
        {
            node *nnode = new node;
            nnode->item = item;
            nnode->link = nullptr;
            head = nnode;
            return;
        }
        // 첫 번째 노드 앞에 추가
        else if (strcmp(head->item->name, item->name) > 0)
        {
            node *nnode = new node;
            nnode->item = item;
            nnode->link = head;
            head = nnode;
            return;
        }
        else
        {
            head->insert(item);
        }
    }

    void remove(char *name)
    {
        // 텅 빈 리스트
        if (head == nullptr)
        {
            printf("[warn] empty list!\n");
            return;
        }
        // 첫 번째 노드를 삭제
        else if (strcmp(head->item->name, name) == 0)
        {
            node *dnode = head;
            head = dnode->link;
            free(dnode);
            return;
        }
        else
        {
            head->remove(name);
        }
    }

    void search(char *name)
    {
        // 텅 빈 리스트
        if (head == nullptr)
        {
            printf("[warn] empty list!\n");
            return;
        }
        node *curr = head->search(name);
        if (curr == nullptr)
        {
            printf("[warn] student %s was not found!\n", name);
            return;
        }
        curr->print();
    }

    void print()
    {
        if (head == nullptr)
        {
            printf("empty list!\n");
            return;
        }
        node *curr = head;
        while (curr != nullptr)
        {
            curr->item->print();
            curr = curr->link;
        }
    }
};

/**
 * @brief 한 줄의 문자열을 공백문자를 기준으로 토큰화 한다.
 *
 * @param src 입력 문자열
 * @param dst 파싱한 토큰들을 담을 문자 배열 (char[8][])
 */
void tokenize(const char *src, char dst[8][MAX_STR_LEN]);

/**
 * @brief 명령어 문자열을 읽어와, 해당 명령어의 숫자 코드를 반환한다.
 *
 * @param src 명령어 문자열
 * @return CMD_CREATE=0, CMD_LOAD=1, CMD_PRINT=2, CMD_INSERT=3, CMD_DELETE=4, CMD_SEARCH=5, -1 if command not found.
 */
int parse_command(const char *src);

int main()
{
    char raw[MAX_CMD_LEN];
    char args[8][MAX_STR_LEN];
    char params[7][MAX_STR_LEN];
    FILE *input_file = fopen("input.txt", "r");
    FILE *list_file;
    data_type *item;
    node *curr;
    head_node *head = nullptr;
    while (fgets(raw, MAX_CMD_LEN, input_file) != NULL)
    {
        tokenize(raw, args);
        switch (parse_command(args[0]))
        {
        case CMD_CREATE:
            head = new head_node;
            head->head = nullptr;
            break;
        case CMD_LOAD:
            list_file = fopen(args[1], "r");
            while (fgets(raw, MAX_CMD_LEN, list_file) != NULL)
            {
                tokenize(raw, params);
                item = new data_type(params);
                head->insert(item);
            }
            fclose(list_file);
            break;
        case CMD_PRINT:
            head->print();
            break;
        case CMD_INSERT:
            item = new data_type(&args[1]);
            head->insert(item);
            break;
        case CMD_DELETE:
            head->remove(args[1]);
            break;
        case CMD_SEARCH:
            head->search(args[1]);
            break;
        default:
            printf("%s is not a keyword.\n", args[0]);
            break;
        }
        printf("\n%s done ========================================\n\n", args[0]);
    }
    fclose(input_file);
    return 0;
}

/**
 * ================================================================
 * 구현 부
 * ================================================================
 */

void tokenize(const char *src, char dst[8][MAX_STR_LEN])
{
    sscanf(src, "%s%s%s%s%s%s%s%s", dst[0], dst[1], dst[2], dst[3], dst[4], dst[5], dst[6], dst[7]);
}

int parse_command(const char *src)
{
    if (strcmp(src, CMD_STR_CREATE) == 0)
    {
        return CMD_CREATE;
    }
    if (strcmp(src, CMD_STR_LOAD) == 0)
    {
        return CMD_LOAD;
    }
    if (strcmp(src, CMD_STR_PRINT) == 0)
    {
        return CMD_PRINT;
    }
    if (strcmp(src, CMD_STR_INSERT) == 0)
    {
        return CMD_INSERT;
    }
    if (strcmp(src, CMD_STR_DELETE) == 0)
    {
        return CMD_DELETE;
    }
    if (strcmp(src, CMD_STR_SEARCH) == 0)
    {
        return CMD_SEARCH;
    }
    return -1;
}
