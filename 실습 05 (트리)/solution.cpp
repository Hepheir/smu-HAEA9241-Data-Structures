#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

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
    int search(int sval);
    int valid(int cval, int lval, int rval);
    int is_leaf_node(int cval);
};

int main(int argc, char *argv[]) {
    int i;
    int cval, lval, rval;
    char str[128];
    FILE *fp = fopen("tree.txt", "r+t");

    node *root = (node *) malloc(sizeof(node));

    root->init();

    while (fgets(str, 128, fp) != NULL)  {
        sscanf(str, "%d %d %d", &cval, &lval, &rval);
        if (!root->valid(cval, lval, rval)) {
            printf("Invalid: %d, %d, %d\n", cval, lval, rval);
            continue;
        }
        root->insert(cval, lval, rval);
    }
    fclose(fp);

    root->inorder_print();
    printf("\n");

    printf("Height: %d\n", root->height());
    printf("Width: %d\n", root->width());

    system("Pause");
    return 0;
}

void node::init() {
    val = -1;
    lchild = nullptr;
    rchild = nullptr;
}

int node::is_leaf_node(int cval) {
    if (val == cval) {
        return lchild == nullptr && rchild == nullptr;
    }
    if (lchild != nullptr && lchild->is_leaf_node(cval)) {
        return true;
    }
    if (rchild != nullptr && rchild->is_leaf_node(cval)) {
        return true;
    }
    return false;
}