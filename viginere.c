#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int parse(char input);
char num2char(int input);

int main(int argc, char *argv[])
{
    FILE *fp, *kp, *ep;
    char cipher[512] = "", ch;
    int pText[512], key[512], c, q, i=0, z=0;


    // **************************************************************KEY ************************************************************************

    kp = fopen(argv[1], "r");

    if(kp == NULL){
        printf("error opening file!");
        return 0;
    }

    printf("Viginere Key:\n\n");
    //read key file & parse to int array
    while((ch = fgetc(kp)) != EOF){
        if(z<512){
            if(isalpha(ch)){

                key[z] = parse(ch);
                z++;
		printf("%c", num2char(parse(ch)));
            }
        }
    }

    printf("\n\n");
	fclose(kp);

    //******** Read plaintext; parse to integers; put into array ********************

    fp = fopen(argv[2], "r");

    if(fp == NULL){
        printf("error opening file!");
        return 0;
    }

    //read file & parse to int array
	printf("Plaintext:\n\n");

	while((ch = fgetc(fp)) != EOF){
		if(i<512){
			if(isalpha(ch)){
		       		pText[i] = parse(ch);
				printf("%c", num2char(parse(ch)));
		        	i++;
		    	}
		}
    }
    //pad with x
    for(i=i;i<512;i++){
       pText[i] = 23;
	}


    fclose(fp);

    // ***********modular arithmetic -- Viginere Equation****************************
   	int keyLen = z;
   	for(z=keyLen; z<512; z++){
     		key[z] = key[z%keyLen];
    	}

		printf("\n\nCiphertext:\n\n");
	for(i=0;i<512;i++){
        cipher[i] = num2char((pText[i] + key[i]) % 26);
	printf("%c", cipher[i]);
	}

    return 0;
}

int parse(char input){
    switch(input){
        case ' ':
            break;
        case 'A':
        case 'a':
            return 0;
            break;
        case 'B':
        case 'b':
            return 1;
            break;
        case 'C':
        case 'c':
            return 2;
            break;
        case 'D':
        case 'd':
            return 3;
            break;
        case 'E':
        case 'e':
            return 4;
            break;
        case 'F':
        case 'f':
            return 5;
            break;
        case 'G':
        case 'g':
            return 6;
            break;
        case 'H':
        case 'h':
            return 7;
            break;
        case 'I':
        case 'i':
            return 8;
            break;
        case 'J':
        case 'j':
            return 9;
            break;
        case 'K':
        case 'k':
            return 10;
            break;
        case 'L':
        case 'l':
            return 11;
            break;
        case 'M':
        case 'm':
            return 12;
            break;
        case 'N':
        case 'n':
            return 13;
            break;
        case 'O':
        case 'o':
            return 14;
            break;
        case 'P':
        case 'p':
            return 15;
            break;
        case 'Q':
        case 'q':
            return 16;
            break;
        case 'R':
        case 'r':
            return 17;
            break;
        case 'S':
        case 's':
            return 18;
            break;
        case 'T':
        case 't':
            return 19;
            break;
        case 'U':
        case 'u':
            return 20;
            break;
        case 'V':
        case 'v':
            return 21;
            break;
        case 'W':
        case 'w':
            return 22;
            break;
        case 'X':
        case 'x':
            return 23;
            break;
        case 'Y':
        case 'y':
            return 24;
            break;
        case 'Z':
        case 'z':
            return 25;
            break;
    }
}

char num2char(int input){
    if(input<0 || input>25){
        printf("invalid");
        exit(0);
    }else{
        switch(input){
            case 0:
                return 'a';
                break;
            case 1:
                return 'b';
                break;
            case 2:
                return 'c';
                break;
            case 3:
                return 'd';
                break;
            case 4:
                return 'e';
                break;
            case 5:
                return 'f';
                break;
            case 6:
                return 'g';
                break;
            case 7:
                return 'h';
                break;
            case 8:
                return 'i';
                break;
            case 9:
                return 'j';
                break;
            case 10:
                return 'k';
                break;
            case 11:
                return 'l';
                break;
            case 12:
                return 'm';
                break;
            case 13:
                return 'n';
                break;
            case 14:
                return 'o';
                break;
            case 15:
                return 'p';
                break;
            case 16:
                return 'q';
                break;
            case 17:
                return 'r';
                break;
            case 18:
                return 's';
                break;
            case 19:
                return 't';
                break;
            case 20:
                return 'u';
                break;
            case 21:
                return 'v';
                break;
            case 22:
                return 'w';
                break;
            case 23:
                return 'x';
                break;
            case 24:
                return 'y';
                break;
            case 25:
                return 'z';
                break;

        }
    }
}
