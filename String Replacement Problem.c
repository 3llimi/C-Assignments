#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fi;
    FILE *fo;
    int N;
    // Opening the input file
    fi = fopen("input.txt", "r");
    // Creating the output file
    fo = fopen("output.txt", "w");
    if (fi == NULL)
    {
        fputs("Invalid inputs\n", fo);
        fclose(fo);
        return 0;
    }
    // Getting the first input N from the input file and checking if it satisfies the conditions
    if (fscanf(fi, "%d", &N) != 1)
    {
        fputs("Invalid inputs\n", fo);
        fclose(fo);
        fclose(fi);
        return 0;
    }
    if (N < 2 || N > 50)
    {
        fputs("Invalid inputs\n", fo);
        fclose(fi);
        fclose(fo);
    }
 
    char S[N + 1];
    int M;
    int H;
    // Getting the second input S and checking if it satisfies the conditons
    if (fscanf(fi, "%s", S) != 1)
    {
        fputs("Invalid inputs\n", fo);
        fclose(fi);
        fclose(fo);
    }
    // Checking The length of the string S if it is equal to N
    int L = strlen(S);
    if (L != N)
    {
        fputs("Invalid inputs\n", fo);
        fclose(fi);
        fclose(fo);
    }
    
 
    // Getting the 3rd input M from the input file and checking if it satisfies the conditons
    if (fscanf(fi, "%d", &M) != 1)
    {
        fputs("Invalid inputs\n", fo);
        fclose(fi);
        fclose(fo);
    }
    // Checking if M is out of bounds
    if (M < 1 || M > N)
    {
        fputs("Invalid inputs\n", fo);
        fclose(fi);
        fclose(fo);
    }
    // Getting the M inputs from the input file and checking if it is out of bounds
    for (int i = 0; i < M; i++)
    {
        if (fscanf(fi, "%d", &H) != 1)
        {
            fputs("Invalid inputs\n", fo);
            fclose(fi);
            fclose(fo);
        }
        if (H >= N || H < 1)
        {
            fputs("Invalid inputs\n", fo);
            fclose(fi);
            fclose(fo);
        }
        else
        {
            // Replacing the Hth character in S with its Hth equivalent in the English Alphabet
            if (H <= 26)
            {
                S[H] = (char)(H + 96);
            }
            else
            {
                S[H] = (char)((H - 26) + 96);
            };
        }
    }
    // Writing the output in the output file
    fputs(S, fo);
    fputs("\n", fo);
    // Closing the input and the output files
    fclose(fi);
    fclose(fo);
    return 0;
}