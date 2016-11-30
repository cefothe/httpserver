/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   POSTCommand.h
 * Author: cefothe
 *
 * Created on November 18, 2016, 5:18 PM
 */

#ifndef POSTCOMMAND_H
#define POSTCOMMAND_H

#include "Command.h"

class POSTCommand : public Command
{
	public: 
		POSTCommand(char* request):Command(request){
		}
		virtual void execute(int sock);
};

#endif /* POSTCOMMAND_H */

