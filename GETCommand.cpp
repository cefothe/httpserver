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
    char* response;
    char* contentType;
    char * data ='\0';
    int size=0;
     
  
    std::string firstLine= HelperFunction::split(request,0,'\n');
    char* result = strcpy((char*)malloc(firstLine.length()+1), firstLine.c_str());
        std::string fileName = HelperFunction::split(result,1,' ');
    
    int statusCode = 404;
    
    std::ostringstream sstream;
    std::ifstream fs(("/home/cefothe/NetBeansProjects/httpServer/files"+fileName).c_str(),std::ios::in | std::ios::binary | std::ios::ate);
    if(fs){
       statusCode=200;
       sstream << fs.rdbuf();
       cout<< HelperFunction::splitExtension(fileName);
       if(HelperFunction::splitExtension(fileName).compare("png") == 0){
           contentType = "image/png";
       }else 
       if(HelperFunction::splitExtension(fileName).compare("html") == 0){
           contentType = "text/html";
       }else{
       statusCode=405;
       
       }
       
    }
    
    if(statusCode !=405 && statusCode != 404){
       fs.seekg( 0, std::ios::end );
       size = fs.tellg();
       fs.seekg( 0, std::ios::beg );

       data= new char[ size + 1 ];
       fs.read( data, size );
       data[ size ] = '\0';
    }
   
    response = (char *) malloc(400);
 sprintf(response, "HTTP/1.1 %d\r\n"
                          "Content-Type: %s\r\n"
                          "Content-Length: %d\r\n"
                          "\r\n",
            statusCode,contentType,size);
 
 send(sock, response, strlen(response), 0);
 send(sock, data, size, 0);
}
