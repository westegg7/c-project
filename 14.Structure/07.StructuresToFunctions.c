#include <stdio.h>
#include <string.h>
#define FUNDLEN 50

struct fortune {
    char bank_name[FUNDLEN];
    double bank_saving;
    char fund_name[FUNDLEN];
    double fund_invest;
};

double sum(const struct fortune*);  // const 의 여부에 신경쓸 것.

int main() {
    struct fortune my_fortune = {
        .bank_name = "Wells Fargo",
        .bank_saving = 4032.27,
        .fund_name = "JPMorgan Chase",
        .fund_invest = 8543.94
    };

    struct fortune* p1 = &my_fortune;

    printf("Total : $%.2f\n", sum(&my_fortune));


    return 0;
}

double sum(const struct fortune* a) {
    return a->bank_saving + a->fund_invest;
}