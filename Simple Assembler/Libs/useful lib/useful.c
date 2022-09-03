char *convertDecimalToBinary(int decimal, int amount){
  int i, restoDaDivisaoInt, originalDecimal = decimal;
  char restoDaDivisaoChar;
  char *binaryNumber = (char *) malloc(sizeof(char) * 33);

  if(decimal < 0) {
    decimal *= -1;
  }

  for(i = 0; decimal >= 1; i++) {
    restoDaDivisaoInt = decimal % 2;
    decimal = decimal / 2;

    restoDaDivisaoChar = convertIntegerToCaracter(restoDaDivisaoInt);
    binaryNumber[i] = restoDaDivisaoChar;
  }
  binaryNumber[i] = '\0';
  reverseString(binaryNumber);

  fillWithZeros(binaryNumber, amount);

  if(originalDecimal < 0) {
    complementOfTwo(binaryNumber, amount);
  }

  return binaryNumber;
}

char convertIntegerToCaracter(int number) {
  char aux = number + '0';
  return aux;
}

void reverseString(char *string) {
  int i, length = strlen(string);
  char aux;
  
  for(i = 0; i < (length / 2); i++) {
    aux = string[i];
    string[i] = string[(length - i - 1)];
    string[(length - i - 1)] = aux;
  }
}

void complementOfTwo(char binaryNumber[], int amount) {
  int i, length;
  sprintf(binaryNumber, "%0*d", amount, atoi(binaryNumber));

  length = strlen(binaryNumber);

  for(i = (length - 1); binaryNumber[i] == '0'; i--);
  
  for(i--; i >= 0; i--) {
    if(binaryNumber[i] == '0') {
      *(binaryNumber + i) = '1';
    } else {
      *(binaryNumber + i) = '0';
    }
  }
}

void fillWithZeros(char string[], int amount) {
  sprintf(string, "%0*d", amount, atoi(string));
  for(unsigned int i = 0; i < strlen(string); i++) {
    if(string[i] == ' ') {
      string[i] = '0';
    }
  }
}