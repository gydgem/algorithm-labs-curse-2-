//
// Created by gydgem on 9/16/2024.
//

#ifndef GRAPHLAB1_PROGRAM_H
#define GRAPHLAB1_PROGRAM_H

#include "Task1Handler.h"
#include "Task2Handler.h"
#include "Task3Handler.h"

namespace hgem {

    class Program {
    private:
        Task1Handler task1 = Task1Handler();
        Task2Handler task2 = Task2Handler();
        Task3Handler task3 = Task3Handler();

    public:

        void task(){
            task1.task1();
            task2.task2();
            task3.task3();

        }
    };

} // hgem

#endif //GRAPHLAB1_PROGRAM_H
