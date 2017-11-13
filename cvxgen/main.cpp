//
// Created by keisuke on 17/11/14.
//

extern "C"{
#include "solver.h"
}


int main(int argc, char **argv){
    Vars result = start_calc(argc, argv);

    printf("y1=%f",*result.y[1] );

}