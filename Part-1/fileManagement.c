#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
  int pid = getpid();
  printf("%d\n", pid);
  char dirName[100];
  sprintf(dirName, "folder_%d", pid);
  printf("%s\n", dirName);
  int created = mkdir(dirName, 0755);
  if (created == 0) {
    printf("Folder created successfully\n");
  } else {
    printf("Error Creating the Folder\n");
  }
  char contentPath[200];
  sprintf(contentPath, "%s/content.txt", dirName);
  FILE *file = fopen(contentPath, "w+");
  if (file == NULL) {
    printf("Error Opening the File\n");
    return 1;
  } else {
    printf("File opened successfully\n");
  }
  char logsPath[200];
  sprintf(logsPath, "%s/logs.txt", dirName);
  FILE *file1 = fopen(logsPath, "w+");
  if (file1 == NULL) {
    printf("Error Opening the File\n");
    return 1;
  } else {
    printf("File opened successfully\n");
  }
  char command[100];
  char input[1024];
  while (1) {
    printf("Enter Command: ");
    scanf("%s", command);
    if (strcmp(command, "INPUT") == 0) {
      printf("INPUT -> ");
      scanf(" %[^\n]", input);
      for (int i = 0; input[i] != '\0'; i++) {
        fputc(input[i], file);
      }
      fputc('\n', file);
      fflush(file);
      char logText[] = "INPUT";
      for (int i = 0; logText[i] != '\0'; i++) {
        fputc(logText[i], file1);
      }
      fputc('\n', file1);
      fflush(file1);
    } else if (strcmp(command, "PRINT") == 0) {
      rewind(file);
      int ch;
      while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
      }
      char logText[] = "PRINT";
      for (int i = 0; logText[i] != '\0'; i++) {
        fputc(logText[i], file1);
      }
      fputc('\n', file1);
      fflush(file1);
    } else if (strcmp(command, "FIRST") == 0) {
      int n;
      scanf("%d", &n);
      rewind(file);
      int ch;
      int count = 0;
      while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n'){
          count++;
        }
        if (count == n){
          printf("%c", ch);
          break;
        } 
        printf("%c", ch); 
      }
      char logText[] = "FIRST";
      for (int i = 0; logText[i] != '\0'; i++) {
        fputc(logText[i], file1);
      }
      fputc('\n', file1);
    } else if (strcmp(command, "LAST") == 0) {

    } else if (strcmp(command, "STOP") == 0) {

    } else if (strcmp(command, "LOG") == 0) {
      int n;
      scanf("%d", &n);
      rewind(file1);
      int ch;
      int count = 0;
      while ((ch = fgetc(file1)) != EOF) {
        if (ch == '\n'){
          count++;
        }
        if (count == n){
          printf("%c", ch);
          break;
        } 
        printf("%c", ch); 
      }
      char logText[] = "LOG";
      for (int i = 0; logText[i] != '\0'; i++) {
        fputc(logText[i], file1);
      }
      fputc('\n', file1);
    } else {
      printf("Unknown command\n");
    }
  }
  return 0;
}