#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include "config.h"

#define EXPECTED_ARGS 2

//DEFAULT VALUES
bool answerKey = false;
bool inputFileMode = false;
bool outputFileMode = false;
bool hasTitle = false;
char *outputAnswerFile = NULL, *inputFileName = NULL, *outputFileName = NULL, *title = NULL;

void printOutput(){
	printf("\\documentclass[twocolumn]{report}\n\\usepackage{amsmath}\n\\begin{document}");
	if (hasTitle == true)
		printf("\\title{%s}", title);
}

int main(int argc, char *argv[])
{
	if (argc != EXPECTED_ARGS - 1){
		fprintf(stderr, "INVALID NUMBER OF ARGS: Expected %d, got %d\n", EXPECTED_ARGS, argc);
		puts(usageMessage);
		exit(1);
	}
	
	char opt;

	while ((opt = getopt(argc, argv, "i:a:t:")) != -1) {
		switch(opt){
			case 'a':
				answerKey = true;
				outputAnswerFile = optarg;
				break;
			case 'i':
				inputFileMode = true;
				inputFileName = optarg;
				break;
			case 'o':
				outputFileMode = true;
				outputFileName = optarg;
				break;
			case 't':
				hasTitle = true;
				title = optarg;
				break;
			default:
				break;
		}
	}

	if (inputFileMode == true){
		FILE *inputFile = fopen(inputFileName, "r");
		parseInput(inputFile);
		fclose(inputFile);
	}

	else{

				
				

	return 0;
}
