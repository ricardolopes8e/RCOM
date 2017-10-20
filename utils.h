#ifndef __UTILS_H
#define __UTILS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <math.h>

#define MODEMDEVICE "/dev/ttyS1"
#define BAUDRATE B9600
#define _POSIX_SOURCE 1 /* POSIX compliant source */
#define FALSE 0
#define TRUE 1
#define ERR 0x36
#define ERR2 0x35
#define PACKET_SIZE 2048
#define FLAG 0x7E

int status = TRUE;
volatile int STOP=FALSE;
volatile int readFile=FALSE;
volatile int readStart = FALSE;
volatile int packetValidated=FALSE;

typedef struct{
	char arr[5];
} ResponseArray;

typedef struct{
	char* arr;
	int size;
} DataPack;

typedef struct{
	char* arr;
	int namelength;
	int fileSize;
} FileData;


FileData file;
FILE *fp;

void printArray(char* arr,size_t length){

	int index;
	for( index = 0; index < length; index++){
			printf( "0x%X\n", (unsigned char)arr[index] );
	}
}

#endif
