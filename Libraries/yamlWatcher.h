#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkBool(const char *str) {
    FILE *yml = fopen("config.yml", "r");
    if (!yml) {
        printf("Errore nell'apertura del file.");
        return false;
    }

    char key[100];
    char value[100];
    bool result = false;

    char line[256];
    while (fgets(line, sizeof(line), yml) != NULL) {
        char configKey[100];
        char value[100];
        if (sscanf(line, "%s = %s", configKey, value) == 2) {
            if (strcmp(value, "true") == 0) {
                fclose(yml);
                return true;
            }else if(strcmp(value, "false")){
                    return false;
                }else if(strcmp(value, "false") != 0 && strcmp(value, "true") != 0){
                    printf("\nValore nel file yaml non valido: %s, %s", key, value);
            }
        }
    }


    fclose(yml);
    return false;
}

int checkInt(char *str) {
    FILE *yml = fopen("config.yml", "r");
    char line[256];
    while (fgets(line, sizeof(line), yml) != NULL) {
        char configKey[100];
        int value;
        if (sscanf(line, "%99s = %d", configKey, &value) == 2) {
            if(strcmp(configKey, str) == 0){
            fclose(yml);
            return value;
            }
        }
    }
    fclose(yml);
    return 0;
}