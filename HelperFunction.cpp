/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HelperFunction.cpp
 * Author: cefothe
 * 
 * Created on November 23, 2016, 4:34 PM
 */

#include "HelperFunction.h"

HelperFunction::HelperFunction() {
}
string HelperFunction::split(char *request, int number, char separater){
    
  std::stringstream ss(request);
  std::string to;
  int current = 0;
    while(std::getline(ss,to,separater)){
        if(current==number) break;
        current++;
    }
  return to;
}

string HelperFunction::getHTTPMethod(char* requests){
      std::string firstLine= split(requests,0,'\n');
      char* result = strcpy((char*)malloc(firstLine.length()+1), firstLine.c_str());
      std::string command = split(result,0,' ');
      return command;
}

string HelperFunction::lastRow(char* request, char separater){
      std::stringstream ss(request);
      std::string to;
    while(std::getline(ss,to,separater));
  return to;

}