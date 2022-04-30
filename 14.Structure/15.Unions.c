/*
--------------------------------
Car Model : Hustler
Personal owner : 900405-1860432
--------------------------------
--------------------------------
Car Model : Sonata
Company owner : 111-22-33333
--------------------------------
*/
//  Anonymous.

#include <stdio.h>

struct personal_owner {
    char rrn1[7];
    char rrn2[8];
};

struct company_owner {
    char crn1[4];
    char crn2[3];
    char crn3[6];
};

struct car_data {
    char model[15];
    int status;     // 0 : personal_owner, 1 : company_owner
    union {
        struct personal_owner po;
        struct company_owner co;
    };
};

void print_car(struct car_data car) {
    printf("--------------------------------\n");

    printf("Car Model : %s\n", car.model);
    if (car.status == 0) {
        printf("Personal Owner : %s-%s\n", car.po.rrn1, car.po.rrn2);
    }
    else {
        printf("Company Owner : %s-%s-%s\n", car.co.crn1, car.co.crn2, car.co.crn3);
    }

    printf("--------------------------------\n");
}

int main() {
    struct car_data car1 = { .model = "Avante", .status = 0, .po = {"900405", "1183994"} };
    struct car_data car2 = { .model = "Sonata", .status = 1, .co = {"333", "22", "55344"} };

    print_car(car1);
    print_car(car2);


    return 0;
}