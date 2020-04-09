const byte maxChars = 32;
char receivedCmd[maxChars];   // an array to store the received line

void setup(){
  Serial.begin(9600);
  Serial.println("<Board live>");
  //Add a test for connection to sensors here, and print the result
}

void loop(){
  int cmdLen;
  Serial.println("Shell line >: ");
  readLine(); //This reads the serial monitor to the endstop \n and writes the data to a char array
  cmdLen = parseCmd(); //The line is parsed to find the first space, and the characters before that are the command
  executeLine(cmdLen);  //The command is hashed, and this hash compared to the known command hashes. The relevent command is then called
}


void readLine(){
    static byte nb = 0;
    char endStop = '\n';
    char readChar;

    while (Serial.available() > 0 && newCmd == false){
      readChar = Serial.read(); //Read available char

      if (readChar != endStop)){  //If not end marker, add char to char array
        recievedCmd[nb] = readChar;
        nb++l
        if (nb >= maxChars){  //Prevents memory leak
          nb = maxChars - 1;
        }
      }
      else {
        recievedCmd[nb] = '\0'; //If end marker, end the string in the char array
        nb = 0;
      }
    }
}

int parseCmd(){ //Parses the line, to identify the first command issued. No args functionality, will be added later if necessary

    char newChar;
    cmdLen = 0;

    do{     //This loops through until the first space is found, to find the length of the first command
        newChar = recievedCmd[cmdLen];
        cmdLen++;
    }while(newChar != ' ');
    return(cmdLen);
}

void executeLine(cmdLen){

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
    Serial.println("The available commands are: \nhelp\nlaunch\n");
}
void launchCommand(){
    Serial.println("Launching...\n");
}


//Will need a "get weather" command, and maybe commands for individual sensors?

//Will need to log events that occur in the console as well-either record each command, or just the command line in general (inputs and output)
