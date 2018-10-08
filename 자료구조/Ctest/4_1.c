#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_TERMS 100
#define MAX 100
#define MAX_BUFFER_LENGTH 100

typedef struct term {
    int coef;
    int expo;
} Term;
typedef struct polynomial {
    char name[MAX_BUFFER_LENGTH];
    int nbr_terms;
    Term terms[MAX_TERMS];
} Polynomial;

Polynomial polys[MAX];
int n = 0;

void createPoly(char* name);
void addTerm(char* name, int coef, int expo);
void multPoly(char* name, int val);
void printPoly(char* name);
void printAll();
void printInternal(int input);
void diffPoly(char* name, char* result);
void calcPoly(char* name, int val);
int findPoly(char* name);
void swapPoly(Polynomial* ind1, Polynomial* ind2);
void swapTerm(Term* ind1, Term* ind2);
void sortPolys();
void sortTerms(int index);
int main() {
    while (1) {
        char buffer[MAX_BUFFER_LENGTH];
        printf("$ ");
        scanf_s("%s", &buffer, MAX_BUFFER_LENGTH);
        if (strcmp(buffer, "create") == 0) {
            scanf_s(" %s", &buffer, MAX_BUFFER_LENGTH);
            createPoly(buffer);
            sortPolys();
        }
        else if (strcmp(buffer, "add") == 0) {
            int coef, expo;
            scanf_s(" %s %d %d", &buffer,MAX_BUFFER_LENGTH, &coef, &expo);
            addTerm(buffer, coef, expo);
            
        }
        else if (strcmp(buffer, "mult") == 0) {
            int val;
            scanf_s( "%s %d", &buffer, MAX_BUFFER_LENGTH, &val);
            multPoly(buffer, val);
        }
        else if (strcmp(buffer, "calc") == 0) {
            int val;
            scanf_s(" %s %d", &buffer, MAX_BUFFER_LENGTH, &val);
            calcPoly(buffer, val);
        }
        else if (strcmp(buffer, "diff") == 0) {
            char resultDiff[MAX_BUFFER_LENGTH];
            scanf_s(" %s as %s", &buffer, MAX_BUFFER_LENGTH, &resultDiff, MAX_BUFFER_LENGTH);//dangerous part
            diffPoly(buffer, resultDiff);
        }
        else if (strcmp(buffer, "print") == 0) {
            scanf_s(" %s", &buffer, MAX_BUFFER_LENGTH);
            if (strcmp(buffer, "all") == 0)
                printAll();
            else
                printPoly(buffer);
        }
        else if (strcmp(buffer, "exit") == 0) {
            exit(0);
        }
    }
    getchar();
    getchar();
}

void createPoly(char* name) {
    strcpy_s(polys[n].name,MAX_BUFFER_LENGTH,name);
    polys[n++].nbr_terms = 0;
}

int findPoly(char*name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(polys[i].name, name) == 0)return i;
    }
    return -1;
}

void addTerm(char* name, int coef, int expo) {
    int index = findPoly(name);
    char isDup = 0;
    for (int i = 0; i < polys[index].nbr_terms; i++) {
        if (polys[index].terms[i].expo == expo) {
            polys[index].terms[i].coef += coef;
            isDup = 1;
            break;
        }
    }
    if (!isDup) {
        polys[index].terms[polys[index].nbr_terms].coef = coef;
        polys[index].terms[polys[index].nbr_terms++].expo = expo;
    }
    sortTerms(index);
}

void multPoly(char* name, int val) {
    int index = findPoly(name);
    for (int i = 0; i < polys[index].nbr_terms; i++) {
        polys[index].terms[i].coef *= val;
    }
}

void printInternal(int index) {
    for (int i = 0; i < polys[index].nbr_terms; i++) {
        if (polys[index].terms[i].coef == -1 && polys[index].terms[i].expo != 0)//coef
            printf("-");
        else if (i == 0)
            printf("%d", polys[index].terms[i].coef);
        else if (polys[index].terms[i].coef == 1&&i!=0)
            printf("+");
        else
            printf("%+d", polys[index].terms[i].coef);

        if (polys[index].terms[i].expo != 0)//expo
            printf("x^%d", polys[index].terms[i].expo);
    }
    printf("\n");
}
//sorting
void sortPolys()
{
    for (int i = n-1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (strcmp(polys[j].name,polys[j+1].name) > 0)
            {
                swapPoly(&polys[j], &polys[j + 1]);
            }
        }
    }
}

void sortTerms(int index)
{
    for (int i = polys[index].nbr_terms-1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (polys[index].terms[j].expo<polys[index].terms[j+1].expo)
            {
                swapTerm(&(polys[index].terms[j]), &(polys[index].terms[j + 1]));
            }
        }
    }
}
void printPoly(char* name) {
    printInternal(findPoly(name));
}

void printAll() {
    for (int i = 0; i < n; i++) {
        printf("%s(x) = ", polys[i].name);
        printInternal(i);
    }
}

void swapPoly(Polynomial* ind1, Polynomial* ind2) {
    Polynomial tmp = *ind1;
    *ind1 = *ind2;
    *ind2 = tmp;
}
void swapTerm(Term* ind1, Term* ind2) {
    Term tmp = *ind1;
    *ind1 = *ind2;
    *ind2 = tmp;
}

void diffPoly(char* name, char* result) {
    createPoly(result);
    int index = findPoly(name),outIndex=findPoly(result);
    int count = 0;
    for (int i = 0; i < polys[index].nbr_terms; i++) {
        polys[outIndex].terms[count].coef = (polys[index].terms[i].expo*polys[index].terms[i].coef);
        polys[outIndex].terms[count].expo = (polys[index].terms[i].expo - 1);
        if (polys[outIndex].terms[count].expo < 0) {
            polys[outIndex].terms[count].coef = 0;
            polys[outIndex].terms[count].expo = 0;
            count -= 1;
        }
        count += 1;
    }
    polys[outIndex].nbr_terms = count;
}

void calcPoly(char* name, int val) {
    int index = findPoly(name);
    int output=0;
    for (int i = 0; i < polys[index].nbr_terms; i++) {
        output += (polys[index].terms[i].coef*pow(val,polys[index].terms[i].expo));
    }
    printf("%d\n",output);
}
