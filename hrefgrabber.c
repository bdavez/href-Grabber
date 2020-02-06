#include <stdio.h>
#include <stdlib.h>
#include <string.h> 



int main(void)
{
    char buffer; 
    char name[50];
    printf("Please enter a file name\n");
    scanf("%s", name);

    FILE *input = fopen(name, "r"); 
    if (input == NULL)
    {
        fprintf(stderr, "There was a problem opening the file");
        exit(-33);
    }
    FILE *output = fopen("links.txt", "w");
        if (output != NULL)
    {
        fprintf(stderr, "File Exists, will now overwrite\n");
    }

    while(fscanf(input, "%c", &buffer) != EOF)
    {

        if(buffer =='h' || buffer == 'H')
        {   
            fscanf(input, "%c", &buffer);

            if(buffer =='r' || buffer == 'R')
            {
                fscanf(input, "%c", &buffer);
                if(buffer =='e' || buffer == 'E')
                {
                    fscanf(input, "%c", &buffer);
                    if(buffer =='f' || buffer == 'F')
                    {
                        fscanf(input, "%c", &buffer);
                        if(buffer =='='){
                            fscanf(input, "%c", &buffer);
                            if(buffer =='"')
                            {
                                do 
                                {
                                    fscanf(input, "%c", &buffer);
                                    if(buffer != '"')
                                    {
                                    fprintf(output,"%c", buffer);
                                    printf("%c", buffer);
                                    }
                                } while (buffer != '"');
                                fprintf(output, "\n");
                                printf("\n");
                            }
                        }
                    }
                }
            }
        }     
    }
     
    
    printf("All Done, written to links.txt\n", name);
    return 0;
}