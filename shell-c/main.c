#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char line[256];

//Shell structure
void reploop(void);
void readLine(void);
int parseLine(void);
int executeLine(int);

//Command Functions
long hasher(int);
void helpCommand(void);
void launchCommand(void);

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
    int hashedEntry = hasher(cmdLen);




    //To avoid recomputing, the hashes using the function below have been pre-calculated, and the array populated

        #define helpHash 1167652161
        #define launchHash 1636433284


    //Create a hash function, make an array containing the hashes of the commands, then use a switch to identify if a command has been used.
    //To avoid collisions, ignore any entries that fall outside the possible lengths of commands. Use a robust hash function
    //Create functions for each command, and have the switch point to the functions, rather than store them here
    long lineHash = hasher(cmdLen);
    switch (lineHash){
        case helpHash:
            helpCommand();
            break;
        case launchHash:
            launchCommand();
            break;
        default:
            printf("Command not recognised. Use help to get a list of available commands.\n");
    }

    return(0);
}

long hasher(cmdLen){
    //Thank you, stack overflow
    //https://stackoverflow.com/questions/7666509/hash-function-for-string
    int hash, i;
    for (hash = i = 0; i < cmdLen; i++){
        hash += line[i];
        hash += (hash << 10);
        hash += (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

void helpCommand(){
    printf("The available commands are: \nhelp\nlaunch\n");
}
void launchCommand(){
    printf("Launching...\n");
}


//Will need a "get weather" command, and maybe commands for individual sensors?

//Will need to log events that occur in the console as well-either record each command, or just the command line in general (inputs and output)


