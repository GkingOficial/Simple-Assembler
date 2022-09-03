void removeTokens(char *string){
    char *character;

    character = strpbrk(string, ",()");

    while(character){
        strncpy(character, " ", 1);
        character = strpbrk(character + 1, ",()");
    }
}

void separateTokens(char *string, char *array[]){
    int i = 0;
    char *character = strtok(string, ",() ");

    while (character){
        array[i] = (char *)malloc(strlen(character));

        strcpy(array[i], character);
        character = strtok(NULL, ",() ");
        i++;
    }
}

void switchPosition(char *instruction){
  char *first, *aux;
  int lenght;

  first = strchr(instruction, '(');
  for(int i = 0; !(aux = strpbrk(instruction + strlen(instruction) - i, ", ")); i++);
  lenght = strlen(aux) - strlen(first);
  strncat(instruction, aux + 1, lenght - 1);
  memset(aux, ' ', lenght);
}