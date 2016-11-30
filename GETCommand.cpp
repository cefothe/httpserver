/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GETCommand.cpp
 * Author: cefothe
 * 
 * Created on November 18, 2016, 5:20 PM
 */

#include "GETCommand.h"

using namespace std;

void GETCommand::execute(int sock) {
    char response[2000];
  
    std::string firstLine= HelperFunction::split(request,0,'\n');
    char* result = strcpy((char*)malloc(firstLine.length()+1), firstLine.c_str());
        std::string fileName = HelperFunction::split(result,1,' ');
    
    int statusCode = 404;
    
    std::ostringstream sstream;
    std::ifstream fs(("/home/cefothe/NetBeansProjects/httpServer/files"+fileName).c_str());
    if(fs){
       statusCode=200;
       sstream << fs.rdbuf();
    }
    const std::string fileInformation = sstream.str();
    const char* fileInformationChar = fileInformation.c_str();
 sprintf(response, "HTTP/1.1 %d\r\n"
                          "Content-Type: text/html; charset=UTF-8\r\n"
                          "Content-Length: %d\r\n"
                          "\r\n"
                          "%s\r\n",
            statusCode,strlen(fileInformationChar), fileInformationChar);
 send(sock, response, strlen(response), 0);
}
