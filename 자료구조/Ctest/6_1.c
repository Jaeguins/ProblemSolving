#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_POLYS 100
#define BUFFER_LENGTH 100


struct term
{
    int coef;
    int expo;
    struct term *next;
};
typedef struct term Term;

typedef struct polynomial
{
    char name;
    Term *first;
    int size;
}
Polynomial;
Polynomial *polys[MAX_POLYS];
int n = 0;

int read_line(char buffer[], int bufferLen) {
    int i = 0;
    for (; i < bufferLen; i++) {
        scanf_s("%c", &buffer[i]);
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            break;
        }
    }
    return i;
}

Term *create_term_instance() {
    Term *t = (Term *)malloc(sizeof(Term));
    t->coef = 0;
    t->expo = 0;
    t->next = NULL;
    return t;
}

Polynomial *create_polynomial_instance(char name) {
    Polynomial *ptr_poly = (Polynomial *)malloc(sizeof(Polynomial));
    ptr_poly->name = name;
    ptr_poly->size = 0;
    ptr_poly->first = NULL;
    return ptr_poly;
}

void add_term(int c, int e, Polynomial *poly) {
    if (c == 0)return;
    Term *p = poly->first, *q = NULL;
    while (p != NULL && p->expo > e) {
        q = p;
        p = p->next;
    }
    if (p != NULL && p->expo == e) {
        p->coef += c;
        if (p->coef == 0) {
            if (q == NULL)poly->first = p->next;
            else q->next = p->next;
            poly->size--;
            free(p);
        }
        return;
    }
    Term *term = create_term_instance();
    term->coef = c;
    term->expo = e;
    if (q == NULL) {
        term->next = poly->first;
        poly->first = term;
    }
    else
    {
        term->next = p;
        q->next = term;
    }
    poly->size++;
}

int eval(Polynomial *poly, int x) {
    int result = 0;
    Term *t = poly->first;
    while (t != NULL) {
        result += eval_term(t, x);
        t = t->next;
    }
    return result;
}

int eval_term(Term *term, int x) {
    int result = term->coef;
    for (int i = 0; i < term->expo; i++) {
        result *= x;
    }
    return result;
}

void print_term(Term *pTerm) {//TODO printing term
    if (pTerm->coef == 0 && pTerm->expo == 0) {
        printf("0");
        return;
    }
    if (pTerm->coef == -1)printf(" - ");
    else if (pTerm->coef == 1 && pTerm->expo == 0)printf(" 1");
    else if (pTerm->coef < 0) printf(" - %d", pTerm->coef*-1);
    else if (pTerm->coef != 1) printf(" %d", pTerm->coef);
    if (pTerm->expo == 1)printf("x");
    else if (pTerm->expo != 0)printf("x^%d", pTerm->expo);
}

void print_poly(Polynomial *p) {
    printf("%c(x) =", p->name);
    Term *t = p->first;
    while (t != NULL) {
        print_term(t);
        t = t->next;
        if(t!=NULL&&t->coef>0)printf(" +");
    }
    printf("\n");
}

void handle_print(char name) {
    for (int i = 0; i < n; i++) {
        if (polys[i]->name == name) print_poly(polys[i]);
    }
    
}

void print_all() {
    for (int i = 0; i < n; i++) {
        print_poly(polys[i]);
    }
}

void handle_calc(char name, char *x_str) {
    Polynomial* p = NULL;
    for (int i = 0; i < n; i++) {
        if (polys[i]->name == name)p = polys[i];
    }
    if (p == NULL) {
        printf("invalid polynomial\n");
        return;
    }
    int ret = 0, inserted = atoi(x_str);
    Term* pointer = p->first;
    while (1) {
        if (pointer == NULL)break;
        int pow = 1;
        for (int i = 0; i < pointer->expo; i++) {
            pow *= inserted;
        }
        ret += (pointer->coef*pow);
        pointer = pointer->next;
    }
    printf("%d\n", ret);
}

void erase_blanks(char *expression) {//TODO erase_blanks
    int length = strlen(expression);
    for (int i = 0; i < length; i++) {
        if (expression[i] == ' ') {
            for (int j = i--; j < length; j++) {
                expression[j] = expression[j + 1];
            }
            continue;
        }
    }
}

void destroy_polynomial(Polynomial *ptr_poly) {
    if (ptr_poly == NULL)
        return;
    Term *t = ptr_poly->first, *tmp;
    while (t != NULL) {
        tmp = t;
        t = t->next;
        free(tmp);
    }
    free(ptr_poly);
}

void insert_polynomial(Polynomial *ptr_poly) {
    for (int i = 0; i < n; i++) {
        if (polys[i]->name == ptr_poly->name) {
            destroy_polynomial(polys[i]);
            polys[i] = ptr_poly;
            return;
        }
    }
    polys[n++] = ptr_poly;
}

void handle_definition(char *expression) {
    erase_blanks(expression);
    char *f_name = strtok(expression, "=");
    if (f_name == NULL || strlen(f_name) != 1) {
        printf("Unsupported command.");
        return;
    }
    char *exp_body = strtok(NULL, "=");
    if (exp_body == NULL || strlen(exp_body) <= 0) {
        printf("Invalid expression format.--");
        return;
    }
    if (exp_body[0] >= 'a' && exp_body[0] <= 'z' && exp_body[0] != 'x') {
        char opt[2] = { exp_body[1],'\0' };
        char *former = strtok(exp_body,opt);
        if (former == NULL || strlen(former) != 1) {
            printf("Invalid expression format.");
            return;
        }
        char *later = strtok(NULL,opt);
        if (later == NULL || strlen(later) != 1) {
            printf("Invalid expression format.");
            return;
        }
        Polynomial *pol;
        if(strcmp(opt,"+")==0)pol = create_by_add_two_polynomials(f_name[0], former[0], later[0]);
        else if (strcmp(opt, "*") == 0)pol = create_by_mult_two_polynomials(f_name[0], former[0], later[0]);
        else pol = NULL;
        if (pol == NULL) {
            printf("Invalid expression format.");
            return;
        }
        insert_polynomial(pol);
    }
    else
    {
        Polynomial *pol = create_by_parse_polynomial(f_name[0], exp_body);
        if (pol == NULL) {
            printf("Invalid expression format."
            );
            return;
        }
        insert_polynomial(pol);
    }
}


int create_by_parse_polynomial(char name, char *body) {
    Polynomial* ptr_poly = create_polynomial_instance(name);
    int i = 0, begin_term = 0;
    while (i < strlen(body)) {
        if (body[i] == '+' || body[i] == '-')
            i++;
        while (i < strlen(body) && body[i] != '+' &&body[i] != '-')
            i++;
        int result = parse_and_add_term(body, begin_term, i, ptr_poly);
        if (result == 0)
        {
            destroy_polynomial(ptr_poly);
            return NULL;
        }
        begin_term = i;
    }
    return ptr_poly;
}

int parse_and_add_term(char *expr, int begin, int end, Polynomial *p_poly) {
    int i = begin;
    int sign_coef = 1, coef = 0, expo = 1;
    if (expr[i] == '+')
        i++;
    else if (expr[i] == '-') {
        sign_coef = -1;
        i++;
    }
    while (i < end && expr[i] >= '0' && expr[i] <= '9') {
        coef = coef * 10 + (int)(expr[i] - '0');
        i++;
    }
    if (coef == 0)coef = sign_coef;
    else coef *= sign_coef;
    if (i >= end) {
        add_term(coef, 0, p_poly);
        return 1;
    }
    if (expr[i] != 'x')return 0;
    i++;
    if (i >= end) {
        add_term(coef, 1, p_poly);
        return 1;
    }
    if (expr[i] != '^')return 0;
    i++;
    expo = 0;
    while (i < end && expr[i] >= '0' && expr[i] <= '9') {
        expo = expo * 10 + (int)(expr[i] - '0');
        i++;
    }
    add_term(coef, expo, p_poly);
    return 1;
}

int create_by_add_two_polynomials(char name, char f, char g) {//TODO adding
    Term *former = NULL, *later = NULL;
    Polynomial* ret = create_polynomial_instance(name);

    for (int i = 0; i < n; i++) {
        if (polys[i]->name == f) former = polys[i]->first;
        else if (polys[i]->name == g) later = polys[i]->first;
    }
    while (1) {
        if (former == NULL && later == NULL) return (Polynomial*) ret;
        if (former == NULL || former->expo < later->expo) {
            add_term(later->coef, later->expo, ret);
            later = later->next;
        }
        else if (later==NULL||former->expo>later->expo) {
            add_term(former->coef, former->expo, ret);
            former = former->next;
        }
        else if (later->expo == former->expo) {
            add_term(later->coef+former->coef, later->expo, ret);
            later = later->next;
            former= former->next;
        }
    }
}

int create_by_mult_two_polynomials(char name, char f, char g) {
    Polynomial *former = NULL, *later = NULL;
    Polynomial* ret = create_polynomial_instance(name);

    for (int i = 0; i < n; i++) {
        if (polys[i]->name == f) former = polys[i];
        else if (polys[i]->name == g) later = polys[i];
    }
    Term *formerPointer = former->first, *laterPointer=later->first;
    while (1) {
        int tCoef = formerPointer->coef*laterPointer->coef;
        int tExpo = formerPointer->expo+laterPointer->expo;
        add_term(tCoef, tExpo, ret);
        laterPointer = laterPointer->next;
        if (laterPointer == NULL) {
            formerPointer = formerPointer->next;
            laterPointer = later->first;
        }
        if (formerPointer == NULL)break;
    }
    return ret;
}

void process_command() {
    char command_line[BUFFER_LENGTH];
    char copied[BUFFER_LENGTH];
    char *command, *arg1, *arg2;
    while (1) {
        printf("$ ");
        if (read_line(command_line, BUFFER_LENGTH) <= 0)
            continue;
        strcpy(copied, command_line);
        command = strtok(command_line, " ");
        if (strcmp(command, "print") == 0) {
            arg1 = strtok(NULL, " ");
            if (arg1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            handle_print(arg1[0]);
        }
        else if (strcmp(command, "printall") == 0) {
            print_all();
        }
        else if (strcmp(command, "calc") == 0) {
            arg1 = strtok(NULL, " ");
            if (arg1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            arg2 = strtok(NULL, " ");
            if (arg2 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            handle_calc(arg1[0], arg2);
        }
        else if (strcmp(command, "exit") == 0)
            break;
        else {
            handle_definition(copied);
        }
    }
}

int main() {
    while (1) {
        process_command();
    }
}