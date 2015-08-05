//
//  Stack.cpp
//  MathParser
//
//  Created by Vedant Mathur on 7/28/15.
//  Copyright (c) 2015 Vedant Mathur. All rights reserved.
//

#include "Stack.h"

Stack::Stack()
{
    stackIndex = 0;
    
    stackArray = (char**)malloc(sizeof(char*) * stackIndex);

}

Stack::~Stack()
{
    
}

void Stack::push(Token token)
{
    char* chrToken = new char[token.value().size() + 1];
    strcpy(chrToken, token.value().c_str());
    
    stackArray[stackIndex] = (char*)chrToken;
    
    stackIndex++;
    //realloc
    stackArray = (char **)realloc(stackArray, sizeof(char *) * (stackIndex + 1));
    
//check eprfromance time iteratino countn in 10 secz 1 sec too unrelaibalee
}
//try vecotr class
void Stack::pop(Queue& queue)
{
    queue.push(Token(stackArray[stackIndex - 1]));

    stackArray = (char **)realloc(stackArray, sizeof(char *) * stackIndex - 1);

    --stackIndex;
}

void Stack::freeStack()
{
    free(stackArray);
}

void Stack::print()
{
    //stakcpeepk
}

string Stack::pop()
{
    string tempData = stackArray[stackIndex - 1];
    
    stackArray = (char **)realloc(stackArray, sizeof(char *) * stackIndex - 1);
    
    --stackIndex;
    
    return tempData;
}

string Stack::popStr()
{
    return stackArray[stackIndex - 1];
   // return "";
}

bool Stack::isEmpty()
{
    return stackIndex == 0? true: false;
}