#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char line[256];

void reploop(void);
void readLine(void);
int parseLine(void);
int executeLine(int);

int main()
{
    //Load a configuration file

    //Run a read-evaluate-print loop

    reploop();

    //Shutdown cleanup; release memory



    return 0;
}


void reploop(void){
    int cmdLen;
    int cmdStatus;
    //Read user command
    //Parse command
    //Execute command
    do{
        printf("Shell line >: ");
        readLine();   //A function that takes the user input from the shell console
        cmdLen = parseLine();     //A function that parses the cmdLine, to extract the command and associated arguments
        cmdStatus = executeLine(cmdLen);     //A function that finds the relevant command to execute and executes it, using the arguments from the parse function
                                        //The return value of this function will tell the loop if it executed successfully or not
    }while(cmdStatus ==0);
}

void readLine(void){
    scanf("%s", line);  //Scans the whole line in as a string, to be parsed by a different function
}

int parseLine(void){    //In this version, only the first word of a command can be parsed. Arguments will be handled in subsequent versions

    char newChar;
    int cmdLen = 0;

    do{     //This loops through until the first space is found, to find the length of the first command
        newChar = line[cmdLen];
        cmdLen++;
    }while(newChar != '\0');
    return(cmdLen);
}

int executeLine(cmdLen){

    char command[cmdLen];
    for(int i = 0; i <= cmdLen; i++){
        command[i] = line[i];
    }
    if(strcmp(command, "launch") == 0) {
        printf("Launching\n");                //Inefficient way of doing it. To improve, have a hash table of commands so a switch can be used for
    }
    else if(strcmp(command, "exit") == 0){
        printf("Exiting...");
        return(1);
    }                                    //comparison to known commands. Also, commands should have own functions to be called in later versions
    else {
        printf("Command not recognised\n");
    }
    return(0);
}

//Will need to implement a list of acceptable commands-here, or in sep. file?
