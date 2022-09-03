void cleanLineOfFile(FILE *file, FILE *out){
    char *aux;
    char aux1, string[101];
    int numberOfLabels = 0, linePosition = 0, changeNumberOfLabels = 0;
    char **instructions;

    instructions = (char **)malloc(sizeof(char *));
    labels = (char **)malloc(sizeof(char *));
    labelsPositions = (int *)malloc(sizeof(int));

    do{
        if(!fgets(string, 101, file)){
            break;
        }
        
        //remove comentario da linha
        while((aux = strchr(string, '#'))){
            strcpy(aux, "\0");
        }

        //remove \n
        while((aux = strchr(string, '\n'))){
            strcpy(aux, "\0");
        }
        
        //substitui tab por espaço
        int i = 0;
        while((aux1 = string[i], aux1 == '\t')) {
            aux = strchr(string, '\t');
            strcpy(aux, aux + 1);
            i++;
        }
        
        while((aux = strchr(string, '\t'))) {
            aux[0] = ' ';
        }

        //se for linha válida
        if(strcmp(string, "\0") && strcmp(string, " ")){
            aux = splitLabel(string);
            if(aux){
                numberOfLabels++;
                changeNumberOfLabels = 1;

                labels = (char **)realloc(labels, sizeof(char *) * numberOfLabels);
                labels[numberOfLabels - 1] = (char *)malloc(sizeof(char) * strlen(aux));
                strcpy(labels[numberOfLabels - 1], aux);

                //remove espaços do label
                while((aux = strchr(labels[numberOfLabels - 1], ' '))){
                    strcpy(aux, aux + 1);
                }
            }

            //remove labels da string
            while((aux = strchr(string, ':'))){
                strcpy(string, aux + 1);
            }
            //se após remover o label sobrou alguma instrução válida
            
            if(strcmp(string, "\0") && strcmp(string, " ")){
                linePosition++;
                
                if(changeNumberOfLabels) {
                    labelsPositions = (int *)realloc(labelsPositions, sizeof(int) * numberOfLabels);
                    labelsPositions[numberOfLabels - 1] = linePosition;

                    changeNumberOfLabels = 0;
                }
                
                instructions = (char **)realloc(instructions, sizeof(char *) * linePosition);
                instructions[linePosition - 1] = (char *)malloc(sizeof(char) * (strlen(string) + 1));
                strcpy(instructions[linePosition - 1], string);
            }
        }
    } while(!feof(file));

    numbOfLabels = numberOfLabels;
    
    identifyInstruction(instructions, out, linePosition);
}

char *splitLabel(char *string){
    char *result;
    result = (char *)malloc(sizeof(char));

    for(unsigned int i = 0; i < 
    
    strlen(string); i++){
        if(string[i] != ':'){
            result = (char *)realloc(result, sizeof(char) * (i + 1));
            result[i] = string[i];
        } else {
            result[i] = '\0';
            return result;
        }
    }
    return NULL;
}

void identifyInstruction(char **instructions, FILE *out, int amount){
    int line;
    char *aux, string[101], part[101], opcodeOrFunction[10], backup[101], result[101];
    FILE *funcoes = NULL;
    
    funcoes = fopen("funcoes.txt", "r");
    
    for(int i = 0; i < amount; i++){
        line = 0;

        strcpy(backup, instructions[i]);

        strcpy(part, strtok(instructions[i], " ,"));
        strcat(part, ":");

        while(!feof(funcoes)){
            if(!fgets(string, 101, funcoes)){
                break;
            }

            while((aux = strchr(string, '\n'))){
                aux[0] = '\0';
            }

            line++;
            if((aux = strstr(string, part))){
                strncpy(opcodeOrFunction, strchr(aux, ':') + 1, 6);

                switch(line){
                    case 1 :
                        instructionR(backup, opcodeOrFunction, result);
                        break;
                    case 2 :
                        instructionI(backup, opcodeOrFunction, result, i + 1);
                        break;
                    case 3 :
                        instructionJ(backup, opcodeOrFunction, result);
                        break;
                    default :
                        puts("ERRO 42!");
                        exit(42);
                        break;
                }
            }
        }
        rewind(funcoes);
        writeInFile(result, out);
    }
}

void writeInFile(char *string, FILE *output){
    char part[10];
    int j, i;

    for(i = 3; i >= 0; i--){
        for(j = 0; j < 8; j++) {
            part[j] = string[(i * 8) + j];
        }
        part[j] = '\0';
        strcat(part, "\n");
        fputs(part, output);
    }
}