include <stdio.h>
include <stdlib.h>
include <time.h>
include <string.h>

int newfile(FILE *fp)
{
  char fname[20];
  printf("\nEnter the name of the file...  ");
  scanf("%19s",fname);//File name cannot have spaces
  strcat(fname, ".txt");
  fp=fopen(fname, "w");
  int i, N = 600, newfile[N];
  for(i=0;i<N;i++)
  {
     newfile[i]= ((rand() % 6)+1);
     fprintf(fp,"%d\n",newfile[i]);
  }
}

int main() 
{
  int i = 0;
  FILE *fp;
  do
  {
    newfile(fp);
    i++;
  }
  while (i<1);
    FILE* fpointer;
    char filename[20];
    int value = 0, result = 0, num[600] = { 0 };
    float sum, mean;

    printf("\nEnter the name of the file...  ");
    scanf("%19s",filename);
    fpointer = fopen(filename, "r");

    if (fpointer == NULL) {
        printf("ERROR: CANNOT OPEN FILE!\n");
        return -1;
    }

    result = fscanf(fpointer, "%d", &value);
    while (result == 1)
    {
        {
            num[value] = num[value] + 1;  // num[value]++
        }
        result = fscanf(fpointer, "%d", &value);
    }

    for (int i = 0; i <= 6; i++) {
        if (num[i] > 0) {
            printf("Number %i has appeared %d times\n", i, num[i]);
        }
    }
    
    sum = (1*(num[1])+2*(num[2])+3*(num[3])+4*(num[4])+5*(num[5])+6*(num[6]));

    mean = sum / 600;
    printf("\nThe mean is %f",mean);


    fclose(fpointer);
    return 0;
}