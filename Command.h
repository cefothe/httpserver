/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Command.h
 * Author: cefothe
 *
 * Created on November 18, 2016, 4:18 PM
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sstream>
#include <fstream>
#include "HelperFunction.h"

class Command {

protected:
    char* request;
public:
    Command(char* request);
    virtual void execute(int sock) =0 ;	
};


#endif /* COMMAND_H */

