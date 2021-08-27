#include "Title.h"


int UnitTestSolution(void){
    int ind = 1;
    TEST test[6];
    for (int i = 0; i < 6; i++){
        test[i].Ans = {ZERO, {NAN,NAN}};
        test[i].Coef = {1};
    }
    input_s(&test);
    for (int i = 0; i < 6; i++){
        struct Answers ans1 = {ZERO, {NAN, NAN}};
        if (!compair(&(test[i]), &ans1)){
            printf("Something wrong i = %d \n", i);
            ind = 0;
            printf("Coefficients: a = %lg, b = %lg, c = %lg \n", test[i].Coef.a, test[i].Coef.b, test[i].Coef.c);
            printf("Roots: ");
            if (test[i].Ans.amount != INFINIT){
                for (int j = 0; j < i; j++){
                    printf("x%d = %lg ", i, test[i].Ans.roots[j]);
                }
            }
            printf("\n The received response: ");
            for (int j = 0; j < ans1.amount; j++){
                printf("x%d = %lg ", j, ans1.roots[j]);
            }
            printf("\n");
        }
        else{
            printf("All right :) \n");
        }
    }
    return ind;   
}

void input_s(TEST (*test)[6]){
    assert(test);
    (*test)[0].Coef = {0};
    (*test)[0].Ans.amount = INFINIT;
    
    (*test)[1].Coef.a = 0;
    (*test)[1].Coef.b = 0;
    (*test)[1].Coef.c = 1;
    (*test)[1].Ans.amount = ZERO;

    (*test)[2].Coef.a = 0;
    (*test)[2].Coef.b = 8;
    (*test)[2].Coef.c = 4;
    (*test)[2].Ans.amount = ONE;
    (*test)[2].Ans.roots[0] = -0.5;

    (*test)[3].Coef.a = 25;
    (*test)[3].Coef.b = 0;
    (*test)[3].Coef.c = 1;
    (*test)[3].Ans.amount = ZERO;

    (*test)[4].Coef.a = 25;
    (*test)[4].Coef.b = 0;
    (*test)[4].Coef.c = -1;
    (*test)[4].Ans.amount = TWO;
    (*test)[4].Ans.roots[0] = -0.2;
    (*test)[4].Ans.roots[1] = 0.2;

    (*test)[5].Coef.a = 25;
    (*test)[5].Coef.b = 5;
    (*test)[5].Coef.c = 0;
    (*test)[5].Ans.amount = TWO;
    (*test)[5].Ans.roots[0] = -0.2;
    (*test)[5].Ans.roots[1] = 0;

}

bool compair (TEST * test, struct Answers * ans1){
    assert(test);
    assert(ans1);
    solve_equation(ans1, &(test->Coef));
    if (ans1->amount == test->Ans.amount){
        if (test->Ans.amount == ZERO || test->Ans.amount == INFINIT){
            return true;
        }
        else{
            if (fabs(ans1->roots[0] - test->Ans.roots[0]) < zero){
                if (ans1->amount == TWO && fabs(ans1->roots[1] - test->Ans.roots[1]) < zero){
                    return true;
                }
                else if (ans1->amount == ONE){
                    return true;
                }
            }
        }
    }
    return false;
}