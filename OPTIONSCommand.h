/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OPTIONSCommand.h
 * Author: cefothe
 *
 * Created on November 18, 2016, 4:20 PM
 */

#ifndef OPTIONSCOMMAND_H
#define OPTIONSCOMMAND_H

#include "Command.h"


class OPTIONSCommand : public Command {

    public: 
        OPTIONSCommand(char* request):Command(request){
        }
	virtual void execute(); 

};

#endif /* OPTIONSCOMMAND_H */

