//
// Created by xiodine on 4/15/15.
//

#ifndef POO_2_CONTROLLER_H
#define POO_2_CONTROLLER_H


#include "../models/Stoc.h"

class Controller {
public:
    Controller();
    virtual ~Controller();

    virtual void run(Stoc &stoc);
};


#endif //POO_2_CONTROLLER_H
