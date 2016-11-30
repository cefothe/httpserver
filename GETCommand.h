/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GETCommand.h
 * Author: cefothe
 *
 * Created on November 18, 2016, 5:20 PM
 */

#ifndef GETCOMMAND_H
#define GETCOMMAND_H

#include "Command.h"

class GETCommand : public Command
{
    public: 
	GETCommand(char* request):Command(request){
		};
	void execute(int sock);
};

#endif /* GETCOMMAND_H */

