void instructionR(char *instruction, char *function, char *result){
    int i, rs = 2, rd = 1;
    char *partsOfInstruction[4], temporary[17];
    
    partsOfInstruction[2] = (char *)malloc(sizeof(char) * 6);
    partsOfInstruction[3] = (char *)malloc(sizeof(char) * 6);

    strcpy(partsOfInstruction[2], "dipper");

    removeTokens(instruction);
    separateTokens(instruction, partsOfInstruction);

    strcpy(result, "000000");

    if(!strcmp(partsOfInstruction[2], "dipper")) {
      rs = 1;
      rd = 2;
      strcpy(partsOfInstruction[2], "$zero");
      strcpy(partsOfInstruction[3], "$zero");
    }

    for(i = 0; strcmp(partsOfInstruction[rs], registers[i]); i++);
    strcpy(temporary, convertDecimalToBinary(i, 5));
    strcat(result, temporary);

    for(i = 0; strcmp(partsOfInstruction[3], registers[i]); i++);
    strcpy(temporary, convertDecimalToBinary(i, 5));
    strcat(result, temporary);

    for(i = 0; strcmp(partsOfInstruction[rd], registers[i]); i++);
    strcpy(temporary, convertDecimalToBinary(i, 5));
    strcat(result, temporary);

    strcat(result, "00000");

    strcat(result, function);
}

void instructionI(char *instruction, char *opcode, char *result, int lineNumber){
    int i, j, k, isLabel;
    char *partsOfInstruction[4], temporary[16];
    char *aux = strpbrk(instruction, "()");

    if(aux){
      switchPosition(instruction);
    }

    removeTokens(instruction);
    separateTokens(instruction, partsOfInstruction);

    strcpy(result, opcode);

    for(i = 0; strcmp(partsOfInstruction[1], registers[i]); i++);
    for(j = 0; strcmp(partsOfInstruction[2], registers[j]); j++);

    for(k = 0, isLabel = 0; k < numbOfLabels; k++){
      if(!strcmp(labels[k], partsOfInstruction[3])){
        isLabel = 1;
        break;
      }
    }

    if(isLabel){
      if(!aux){
        strcpy(temporary, convertDecimalToBinary(i, 5));
        strcat(result, temporary);

        strcpy(temporary, convertDecimalToBinary(j, 5));
        strcat(result, temporary);
      } else {
        strcpy(temporary, convertDecimalToBinary(j, 5));
        strcat(result, temporary);

        strcpy(temporary, convertDecimalToBinary(i, 5));
        strcat(result, temporary);

      }
      strcpy(temporary, convertDecimalToBinary(labelsPositions[k] - (lineNumber + 1), 16));
    } else {
      strcpy(temporary, convertDecimalToBinary(j, 5));
      strcat(result, temporary);

      strcpy(temporary, convertDecimalToBinary(i, 5));
      strcat(result, temporary);

      strcpy(temporary, convertDecimalToBinary(atoi(partsOfInstruction[3]), 16));
    }

    strcat(result, temporary);
}

void instructionJ(char *instruction, char *opcode, char *result){
  int i;
  char targetAddress[27];
  char label[33];
  
  // Leitura e procura do 'for' no labels, identificar a posição e procurar valor correspondente em linhaDosLabels
  sscanf(instruction, "%*s %s", label);

  for(i = 0; i < 32; i++){
    if(!strcmp(labels[i], label)){
      break;
    }
  }

  // Manipular o valor da linhaDosLabels para formar o target address
  strcpy(targetAddress, convertDecimalToBinary(labelsPositions[i] - 1, 26));
  
  strcpy(result, opcode);
  strcat(result, targetAddress);
}