//
// Created by gydgem on 9/16/2024.
//

#ifndef GRAPHLAB1_PROGRAM_H
#define GRAPHLAB1_PROGRAM_H

#include "Task1Handler.h"
#include "Task2Handler.h"

namespace hgem {

    class Program {
    private:
        Task1Handler task1 = Task1Handler();
        Task2Handler task2 = Task2Handler();

    public:

        void task(){
            task1.task1();
            task2.task2();
        }
    };

} // hgem

#endif //GRAPHLAB1_PROGRAM_H
