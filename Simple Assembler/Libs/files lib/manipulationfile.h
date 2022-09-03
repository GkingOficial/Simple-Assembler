void cleanLineOfFile(FILE *file, FILE *out);
char *splitLabel(char *string);
void identifyInstruction(char **instructions, FILE *out, int amount);
void writeInFile(char *string, FILE *file);