/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cefothe
 *
 * Created on November 18, 2016, 4:03 PM
 */



#include "GETCommand.h"
#include "POSTCommand.h"

using namespace std;

void doprocessing (int sock);

int main(int argc, char* argv)
{
    int socket_desc, client_sock, pid;
    struct sockaddr_in server, client;

   
    //create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create ");
    }

    //Configuration server to localhost and port 8888
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // bind adreess
    bind(socket_desc, (struct sockaddr*)&server, sizeof(server));
    // Listen
    listen(socket_desc, 1);

    // get size of connection
    int c = sizeof(struct sockaddr_in);

    // Forever loop 
    while (1) {
        //accept connection from comming server
        client_sock = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c);

        /* Create child process */
        pid = fork();

        if (pid < 0) {
            perror("ERROR on fork");
            exit(1);
        }

        if (pid == 0) {
            /* This is the client process */
            close(socket_desc);
            doprocessing(client_sock);
            exit(0);
        }
        else {
            // Close client sock
            close(client_sock);
        }
        //printf("%s", response);
    }
}

void doprocessing(int sock)
{
    // This value represent 
    char requests[2000];
    int read_size=0;
  
    // Fill request with '\0'
    memset(requests,'\0',2000);
    
    //Read information from request
    while ((read_size = recv(sock, requests, 2000, 0)) > 0) {
       //printf("%s \n\r",requests);
       
       // Parse http method 
        if(HelperFunction::getHTTPMethod(requests)=="GET"){
            GETCommand getCommand(requests);
            getCommand.execute(sock);
        }
        if(HelperFunction::getHTTPMethod(requests)=="POST"){
            POSTCommand postCommand(requests);
            postCommand.execute(sock);
        }
        
        //printf("\r\n");
      
    }
}

