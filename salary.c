#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double rate_gjj = 0.1200;
double rate_ylbx1 = 0.0800;
double rate_ylbx2 = 0.0204;
double rate_sybx = 0.0020;
double rate_base = 3500;

double result[12] = {0};

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

void getBonusPersonalIncomeTax(double bonus)
{
    double bonus_taxable_income;
    double bonus_rate_level;
    double bonus_tax_rate;
    double bonus_rate_deduction;
    double bonus_personal_income_tax;

    bonus_taxable_income = bonus / 12;
    if(0 <= bonus_taxable_income && bonus_taxable_income <= 500)
    {
        bonus_rate_level = 1;
        bonus_tax_rate = 0.0500;
        bonus_rate_deduction = 0;
    }
    else if(500 < bonus_taxable_income && bonus_taxable_income <= 2000)
    {
        bonus_rate_level = 2;
        bonus_tax_rate = 0.1000;
        bonus_rate_deduction = 25;
    }
    else if(2000 < bonus_taxable_income && bonus_taxable_income <= 5000)
    {
        bonus_rate_level = 3;
        bonus_tax_rate = 0.1500;
        bonus_rate_deduction = 125;
    }
    else if(5000 < bonus_taxable_income && bonus_taxable_income <= 20000)
    {
        bonus_rate_level = 4;
        bonus_tax_rate = 0.2000;
        bonus_rate_deduction = 375;
    }
    else if(20000 < bonus_taxable_income && bonus_taxable_income <= 40000)
    {
        bonus_rate_level = 5;
        bonus_tax_rate = 0.2500;
        bonus_rate_deduction = 1375;
    }
    else if(40000 < bonus_taxable_income && bonus_taxable_income <= 60000)
    {
        bonus_rate_level = 6;
        bonus_tax_rate = 0.3000;
        bonus_rate_deduction = 3375;
    }
    else if(60000 < bonus_taxable_income && bonus_taxable_income <= 80000)
    {
        bonus_rate_level = 7;
        bonus_tax_rate = 0.3500;
        bonus_rate_deduction = 6375;
    }
    else if(80000 < bonus_taxable_income && bonus_taxable_income <= 100000)
    {
        bonus_rate_level = 8;
        bonus_tax_rate = 0.4000;
        bonus_rate_deduction = 10375;
    }
    else
    {
        bonus_rate_level = 9;
        bonus_tax_rate = 0.4500;
        bonus_rate_deduction = 15375;
    }

    bonus_personal_income_tax = bonus * bonus_tax_rate - bonus_rate_deduction;

    result[7] = bonus_taxable_income;
    result[8] = bonus_rate_level;
    result[9] = bonus_tax_rate;
    result[10] = bonus_rate_deduction;
    result[11] = bonus_personal_income_tax;
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

    double bonus_taxable_income;
    double bonus_rate_level;
    double bonus_tax_rate;
    double bonus_rate_deduction;
    double bonus_personal_income_tax;

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
    subsidy = allowance + performance;
    
    getPersonalIncomeTax(salary, subsidy);
    getBonusPersonalIncomeTax(bonus);

    taxable_income            = result[0];
    rate_level                = result[1];
    tax_rate                  = result[2];
    rate_deduction            = result[3];
    personal_income_tax       = result[4];
    rate_wxyj                 = result[5];
    wxyj                      = result[6];
    
    bonus_taxable_income      = result[7];
    bonus_rate_level          = result[8];
    bonus_tax_rate            = result[9];
    bonus_rate_deduction      = result[10];
    bonus_personal_income_tax = result[11];

    post_tax = pre_tax - wxyj - personal_income_tax - bonus_personal_income_tax;

    printf("01.salary: %.2lf\n", salary);
    printf("02.allowance: %.2lf\n", allowance);
    printf("03.performance: %.2lf\n", performance);
    printf("04.bonus: %.2lf\n", bonus);
    printf("\n");
    printf("05.wxyj: %f, rate_wxyj: %.2f%\n", wxyj, rate_wxyj * 100);

    printf("\n");

    printf("06.taxable_income: %.2lf\n", taxable_income);
    printf("07.rate_level: %d\n", (int)rate_level);
    printf("08.tax_rate: %0.lf%\n", tax_rate * 100);
    printf("09.rate_deduction: %d\n", (int)rate_deduction);
    printf("10.personal_income_tax: %.2lf\n", personal_income_tax);

    printf("\n");

    printf("11.bonus_taxable_income: %.2lf\n", bonus_taxable_income);
    printf("12.bonus_rate_level: %d\n", (int)bonus_rate_level);
    printf("13.bonus_tax_rate: %0.lf%\n", bonus_tax_rate * 100);
    printf("14.bonus_rate_deduction: %d\n", (int)bonus_rate_deduction);
    printf("15.bonus_personal_income_tax: %.2lf\n", bonus_personal_income_tax);
    printf("16.post_bonus: %.2lf\n", bonus - bonus_personal_income_tax);

    printf("\n");

    printf("17.pre_tax: %.2lf\n", pre_tax);
    printf("18.deduction: %.2lf\n", wxyj + personal_income_tax + bonus_personal_income_tax);
    printf("19.total_tax: %.2lf\n", personal_income_tax + bonus_personal_income_tax);
    printf("20.post_tax: %.2lf\n", post_tax);

    return 0;
}


