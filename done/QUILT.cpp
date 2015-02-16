#include <iostream>
#include <cstdio>
#include <cstdlib>

/*
S -> A
  |  B
  |  turn(S)
  |  sew(S, S)
*/

typedef struct {
    char** info;
    int rows, cols;
} thing;

thing *newA() {
    // char **a = (char**) malloc(sizeof(char*) * 2);
    char **a = (char**) malloc(sizeof(char*) * 2);
    a[0] = (char*) malloc(sizeof(char) * 2);
    a[1] = (char*) malloc(sizeof(char) * 2);
    a[0][0] = '/';
    a[0][1] = '/';
    a[1][0] = '/';
    a[1][1] = '+';

    thing* result = (thing*) malloc(sizeof(thing));
    result->info = a;
    result->rows = 2; 
    result->cols = 2; 
    return result;
}

thing *newB() {
    char **b = (char**) malloc(sizeof(char*) * 2);
    b[0] = (char*) malloc(sizeof(char) * 2);
    b[1] = (char*) malloc(sizeof(char) * 2);
    b[0][0] = '-';
    b[0][1] = '-';
    b[1][0] = '-';
    b[1][1] = '-';

    thing* result = (thing*) malloc(sizeof(thing));
    result->info = b;
    result->rows = 2; 
    result->cols = 2; 
    return result;
}

char transform(char c) {
    switch (c) {
        case '/' : return '\\';
        case '\\': return '/';
        case '-' : return '|';
        case '|' : return '-';
    }
    return c;
}

thing *turn(thing* t) {
    std::cout << std::flush;

    int cols = t->cols, rows = t->rows;
    char **result = (char**) malloc(sizeof(char*) * cols);
    char **before = t->info;

    for (int i = 0; i < cols; ++i) {
        result[i] = (char*) malloc(sizeof(char) * rows);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][rows - i - 1] = transform(before[i][j]);
        }
        free(before[i]);
    }
    free(before);

    t->info = result;
    t->rows = cols;
    t->cols = rows;

    return t;
}

thing *sew(thing* l, thing *r) {
    if (l->rows != r->rows) return NULL;

    int cols = l->cols + r->cols, rows = l->rows;
    char** result = l->info;

    for (int i = 0; i < rows; ++i) {
        result[i] = (char*) realloc(result[i], sizeof(char) * cols);
        for (int j = 0; j < r->cols; ++j) {
            result[i][j + l->cols] = r->info[i][j];
        }
        free(r->info[i]);
    }
    free(r->info);
    free(r);

    l->info = result;
    l->rows = rows;
    l->cols = cols;
    return l;
}

thing* parser() {

    char c;
    c = getchar();

    switch (c) {
        case 'A': return newA();
        case 'B': return newB();

        case 't':
            if ((c = getchar()) == 'u' && 
                (c = getchar()) == 'r' && 
                (c = getchar()) == 'n') {
                thing *to_turn = parser();
                return turn(to_turn);
            }

        case 's':
            if ((c = getchar()) == 'e' && 
                (c = getchar()) == 'w') {
                thing *left = parser();
                thing *right = parser();
                return sew(left, right);
            }

        case ',':
        case '(':
        case ')':
        case  ';':
        case  ' ': 
        case '\n':
            return parser();
    }

    return NULL;
}

int main() {
    
    thing *program;
    int quilt = 0;

    for (program = parser(); !feof(stdin); program = parser()) {
        ++quilt;

        std::cout << "Quilt " << quilt << ":" << std::endl;

        if (program == NULL) {
            std::cout << "error" << std::endl;
            continue;
        }

        for (int i = 0; i < program->rows; ++i) {
            for (int j = 0; j < program->cols; ++j) {
                std::cout << program->info[i][j];
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
