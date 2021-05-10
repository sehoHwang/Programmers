#include <iostream>

using namespace std;

#define MAX_TERMS 100

typedef struct {
    float coef;
    int expon;
}pol;

pol terms[MAX_TERMS];
int avail = 0;

void padd(int sa, int ea, int sb, int eb, int *sd, int *ed){
    float coefficient;
    *sd = avail;

    while(sa <= ea && sb <= eb){
        if(terms[sa].expon < terms[sb].expon){
            terms[avail].coef = terms[sb].coef;
            terms[avail].expon = terms[sb].expon;
            avail++;
            sb++;
        }
        else if(terms[sa].expon == terms[sb].expon){
            terms[avail].coef = terms[sa].coef + terms[sb].coef;
            terms[avail].expon = terms[sa].expon;
            sa++;
            sb++;
            avail++;
        }
        else{
            terms[avail].coef = terms[sa].coef;
            terms[avail].expon = terms[sa].expon;
            sa++;
            avail++;
        }
    }

    for(; sa<=ea; sa++){
        terms[avail].coef = terms[sa].coef;
        terms[avail].expon = terms[sa].expon;
        avail++;
        sa++;
    }
    for(; sb<=eb; sb++){
        terms[avail].coef = terms[sb].coef;
        terms[avail].expon = terms[sb].expon;
        avail++;
        sb++;
    }

    *ed = avail-1;
}

int main() {
    int d, e;
    int ea, eb;
    int sd, ed;
    printf("<<< Setting for polynomial A >>>\n");
    printf("Put the degree : ");
    scanf("%d", &d);
    printf("Put each coefficient : \n");
    for(int i=0; i<=d; i++){
        scanf("%d", &e);
        terms[avail].expon = d-i;
        terms[avail].coef = e;
        avail++;
    }

    ea = avail-1;

    printf("<<< Setting for polynomial B >>>\n");
    printf("Put the degree : ");
    scanf("%d", &d);
    printf("Put each coefficient : \n");
    for(int i=0; i<=d; i++){
        scanf("%d", &e);
        terms[avail].expon = d-i;
        terms[avail].coef = e;
        avail++;
    }

    printf("A(X) = ");
    for(int i=0; i<=ea; i++){
        cout<<terms[i].coef<<"x^"<<terms[i].expon<<" ";
    }
    printf("\n");

    printf("B(X) = ");
    for(int i=ea+1; i<=avail-1; i++){
        cout<<terms[i].coef<<"x^"<<terms[i].expon<<" ";
    }
    printf("\n");

    eb = avail-1;
    printf("avail = %d", avail);
    
    padd(0, ea, ea+1, eb, &sd, &ed);    
    
    printf("<<< Result of A + B >>>\n");
    printf("Result = ");
    for(int i=sd; i<=ed; i++){
        cout<<terms[i].coef<<"x^"<<terms[i].expon<<" ";
        if(i!=ed){
            cout<<"+ ";
        }
    }

    return 0;
}