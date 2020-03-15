#include <stdio.h>
#include <stdlib.h>


void reploop(void);

char* readLine(void);
char** parseLine(char*);
int executeLine(char**);

int main(int argc, char** argv)
{
    //Load a configuration file

    //Run a read-evaluate-print loop

    reploop();

    //Shutdown cleanup; release memory




    return 0;
}


void reploop(void){
    char * cmdLine;
    char ** args;
    int cmdStatus;

    //Read user command
    //Parse command
    //Execute command

    do{
        printf("Shell line >: ");

        cmdLine = readLine();   //A function that takes the user input from the shell console

        args = parseLine(cmdLine);     //A function that parses the cmdLine, to extract the command and associated arguments

        status = executeLine(args);     //A function that finds the relevant command to execute and executes it, using the arguments from the parse function
                                        //The return value of this function will tell the loop if it executed successfully or not

        free(cmdLine);          //Free the memory used in this loop
        free(args);
    }while(cmdStatus);
}

char* readLine(void){
//Fill me
}
char** parseLine(char*){
//Fill me
}
int executeLine(char**){
//Fill me
}

//Will need to implement a list of acceptable commands-here, or in sep. file?
