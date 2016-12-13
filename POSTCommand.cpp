/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   POSTCommand.cpp
 * Author: cefothe
 * 
 * Created on November 18, 2016, 5:18 PM
 */

#include "POSTCommand.h"

    
using namespace std;

void POSTCommand::execute(int sock) {
    char response[2000];
  
    std::string firstLine= HelperFunction::split(request,0,'\n');
    char* result = strcpy((char*)malloc(firstLine.length()+1), firstLine.c_str());
   
    string parametars = HelperFunction::lastRow(request,'\n');
    const char* fileInformationChar = parametars.c_str();
    
 sprintf(response, "HTTP/1.1 202\r\n"
                          "Content-Type: text/html; charset=UTF-8\r\n"
                          "Content-Length: %d\r\n"
                          "\r\n"
                          "%s\r\n",
            strlen(fileInformationChar), fileInformationChar);
 send(sock, response, strlen(response), 0);
}

