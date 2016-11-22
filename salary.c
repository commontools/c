#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double rate_gjj = 0.1200;
double rate_ylbx1 = 0.0800;
double rate_ylbx2 = 0.0204;
double rate_sybx = 0.0020;
double rate_base = 3500;

double result[7] = {0};

void usage()
{
    printf("Usage: ./salary salary allowance performance bonus\n\
                salary      -- salary on the contract\n\
                allowance   -- such as phone, food\n\
                performance -- merit pay, usually 0\n\
                bonus       -- year-end bonus, usually 0\n");
}

void getPersonalIncomeTax(double salary, double subsidy)
{
    double wxyj, rate_wxyj;
    double rate_level, tax_rate, rate_deduction;
    double taxable_income;
    double personal_income_tax;

    rate_wxyj = rate_gjj + rate_ylbx1 + rate_ylbx2 + rate_sybx; 
    wxyj = salary * rate_wxyj;
    taxable_income = (salary + subsidy) - wxyj - rate_base;
    if(0 <= taxable_income && taxable_income <= 1500)
    {
        rate_level = 1;
        rate_deduction = 0;
        tax_rate = 0.0300;
    }
    else if(1500 < taxable_income && taxable_income <= 4500)
    {
        rate_level = 2;
        rate_deduction = 105;
        tax_rate = 0.1000;
    }
    else if(4500 < taxable_income && taxable_income <= 9000)
    {
        rate_level = 3;
        rate_deduction = 555;
        tax_rate = 0.2000;
    }
    else if(9000 < taxable_income && taxable_income <= 35000)
    {
        rate_level = 4;
        rate_deduction = 1005;
        tax_rate = 0.2500;
    }
    else if(35000 < taxable_income && taxable_income <= 55000)
    {
        rate_level = 5;
        rate_deduction = 2755;
        tax_rate = 0.3000;
    }
    else if(55000 < taxable_income && taxable_income <= 80000)
    {
        rate_level = 6;
        rate_deduction = 5505;
        tax_rate = 0.3500;
    }
    else
    {
        rate_level = 7;
        rate_deduction = 13505;
        tax_rate = 0.4500;
    }

    personal_income_tax = taxable_income * tax_rate - rate_deduction;

    result[0] = taxable_income;
    result[1] = rate_level;
    result[2] = tax_rate;
    result[3] = rate_deduction;
    result[4] = personal_income_tax;
    result[5] = rate_wxyj;
    result[6] = wxyj;
}

int main(int argc, char * argv[])
{
    double salary = 0;
    double allowance = 0;
    double performance = 0;
    double bonus = 0;

    double pre_tax = 0;
    double post_tax = 0;
    double subsidy = 0;
    
    double wxyj = 0;
    double rate_wxyj = 0;

    double taxable_income = 0;
    double rate_level = 0;
    double tax_rate = 0;
    double rate_deduction = 0;
    double personal_income_tax = 0; 

    if(argc == 1)
    {
        usage();
        exit(2);
    }

    switch(argc)
    {
        case 2:
            salary = (double)atof(argv[1]);
            break;

        case 3:
            salary = (double)atof(argv[1]);
            allowance = (double)atof(argv[2]);
            break;

        case 4:
            salary = (double)atof(argv[1]);
            allowance = (double)atof(argv[2]);
            performance = (double)atof(argv[3]);
            break;

        case 5:
            salary = (double)atof(argv[1]);
            allowance = (double)atof(argv[2]);
            performance = (double)atof(argv[3]);
            bonus = (double)atof(argv[4]);
            break;

        default:
            usage();
            exit(2);
    }

    pre_tax = salary + allowance + performance + bonus;    
    subsidy = allowance + performance + bonus;
    
    getPersonalIncomeTax(salary, subsidy);

    taxable_income      = result[0];
    rate_level          = result[1];
    tax_rate            = result[2];
    rate_deduction      = result[3];
    personal_income_tax = result[4];
    rate_wxyj           = result[5];
    wxyj                = result[6];

    post_tax = pre_tax - wxyj - personal_income_tax;

    printf("01.salary: %lf\n", salary);
    printf("02.allowance: %lf\n", allowance);
    printf("03.performance: %lf\n", performance);
    printf("04.bonus: %lf\n", bonus);
    printf("\n");
    printf("05.wxyj: %f, rate_wxyj: %.2f%\n", wxyj, rate_wxyj * 100);
    printf("\n");
    printf("06.taxable_income: %lf\n", taxable_income);
    printf("07.rate_level: %d\n", (int)rate_level);
    printf("08.tax_rate: %0.f%\n", tax_rate * 100);
    printf("09.rate_deduction: %d\n", (int)rate_deduction);
    printf("10.personal_income_tax: %lf\n", personal_income_tax);
    printf("\n");
    printf("11.pre_tax: %lf\n", pre_tax);
    printf("12.subsidy: %lf\n", subsidy);
    printf("13.deduction: %lf\n", wxyj + personal_income_tax);
    printf("14.post_tax: %lf\n", post_tax);

    return 0;
}


