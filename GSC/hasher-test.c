#include <stdio.h>
int hasher(int);
char line[256];

int main(){
    printf("Enter the word to be hashed: ");
    scanf("%s", line);
    char newChar;
    int cmdLen = 0;

    do{     //This loops through until the first space is found, to find the length of the first command
        newChar = line[cmdLen];
        cmdLen++;
    }while(newChar != '\0');
    int hashVal = hasher(cmdLen);
    printf("Hash value = %d", hashVal);
    return 0;
}

int hasher(cmdLen){
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
