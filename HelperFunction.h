/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HelperFunction.h
 * Author: cefothe
 *
 * Created on November 23, 2016, 4:34 PM
 */

#ifndef HELPERFUNCTION_H
#define HELPERFUNCTION_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>

using namespace std;

class HelperFunction {
public:
    HelperFunction();
    static string split(char *request, int number, char separater);
    static string getHTTPMethod(char* requests);
    static string lastRow(char *request, char separater);
    static string splitExtension(string fileName);
};

#endif /* HELPERFUNCTION_H */

