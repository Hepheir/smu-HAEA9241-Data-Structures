#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

typedef class node *nptr;

class node {
    int val;
    nptr lchild, rchild;

public:
    void init();
    int insert(int cval, int lval, int rval);
    void inorder_print();
    int height();
    int width();
    int serach(int sval);
    int valid(int cval, int lval, int rval);
    int is_leaf_node(int cval);
};

int main(void) {

    return 0;
}

void node::init() {
    val = -1;
    lchild = nullptr;
    rchild = nullptr;
}