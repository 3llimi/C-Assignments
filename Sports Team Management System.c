#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
//Intialization of an enum type for position
typedef enum position
{
    Goalkeeper,
    Defender,
    Midfielder,
    Forward
} Position;
//Intialization of a struct for player
struct Player
{
    int ID;
    char name[15];
    Position position;
    int age;
    int ng;
};
//Intiazation of an array of player structures
struct Player player[22];
//Function to check the conditon for the name
bool namecheck(const char *name)
{
    int len = strlen(name);
    if (len < 2 || len > 16)
    {
        return false;
    }
    if (!isupper(name[0]))
    {
        return false;
    }
    for (int i = 1; i < len; i++)
    {
        if (!isalpha(name[i]))
        {
            return false;
        }
    }
    return true;
}
//Function to check the conditon for the ID
bool IDcheck(int id, int M)
{
    if (id < 0)
    {
        return false;
    }
    for (int i = 0; i < M; i++)
    {
        if (player[i].ID == id)
        {
            return false;
        }
    }
    return true;
}
//Function to check the conditions for the age
bool agecheck(int age)
{
    return (age >= 18 && age <= 100);
}
//Function to check the conditions for the number of goals
bool goalcheck(int goals)
{
    return (goals >= 0 && goals <= 1000);
}
//Function to convert the enum of position to a string
const char *strpos(Position position)
{
    switch (position)
    {
    case Goalkeeper:
        return "Goalkeeper";
    case Defender:
        return "Defender";
    case Midfielder:
        return "Midfielder";
    case Forward:
        return "Forward";
    default:
        return "";
    }
}
//Function to add a player to the players array
void add(int M, FILE *fi, FILE *fo)
{
    int ID;
    fscanf(fi, "%d", &ID);
    if (!IDcheck(ID, M))
    {
        fputs("Invalid inputs\n", fo);
        printf("%d", ID);
        fclose(fi);
        fclose(fo);
    }
    player[M].ID = ID;
    char name[16];
    fscanf(fi, "%s", name);
    if (!namecheck(name))
    {
        fputs("Invalid inputs\n", fo);
        fclose(fi);
        fclose(fo);
    }
    strcpy(player[M].name, name);
    char pos[30];
    fscanf(fi, "%s", pos);
    if (strcmp(pos, "Goalkeeper") == 0)
    {
        player[M].position = Goalkeeper;
    }
    else if (strcmp(pos, "Defender") == 0)
    {
        player[M].position = Defender;
    }
    else if (strcmp(pos, "Midfielder") == 0)
    {
        player[M].position = Midfielder;
    }
    else if (strcmp(pos, "Forward") == 0)
    {
        player[M].position = Forward;
    }
    else
    {
        fputs("Invalid inputs\n", fo);
        fclose(fi);
        fclose(fo);
    }
    int age;
    fscanf(fi, "%d", &age);
    if (!agecheck(age))
    {
        fputs("Invalid inputs\n", fo);
        fclose(fi);
        fclose(fo);
    }
    player[M].age = age;
    int gl;
    fscanf(fi, "%d", &gl);
    if (!goalcheck(gl))
    {
        fputs("Invalid inputs\n", fo);
        fclose(fi);
        fclose(fo);
    }
 
    player[M].ng = gl;
};
//Function to update the information of a player in the player array
void update(int D, FILE *fi, FILE *fo)
{
    for (int i = 0; i < 22; i++)
    {
        if (player[i].ID == D)
        {
            char name[16];
            fscanf(fi, "%s", name);
            if (!namecheck(name))
            {
                fputs("Invalid inputs\n", fo);
                fclose(fi);
                fclose(fo);
                break;
            }
            strcpy(player[i].name, name);
            char pos[30];
 
            fscanf(fi, "%s", pos);
            if (strcmp(pos, "Goalkeeper") == 0)
            {
                player[i].position = Goalkeeper;
            }
            else if (strcmp(pos, "Defender") == 0)
            {
                player[i].position = Defender;
            }
            else if (strcmp(pos, "Midfielder") == 0)
            {
                player[i].position = Midfielder;
            }
            else if (strcmp(pos, "Forward") == 0)
            {
                player[i].position = Forward;
            }
            else
            {
                fputs("Invalid inputs\n", fo);
                fclose(fi);
                fclose(fo);
                break;
            }
            int age;
            fscanf(fi, "%d", &age);
            if (!agecheck(age))
            {
                fputs("Invalid inputs\n", fo);
                fclose(fi);
                fclose(fo);
                break;
            }
            player[i].age = age;
            int gl;
            fscanf(fi, "%d", &gl);
            if (!goalcheck(gl))
            {
                fputs("Invalid inputs\n", fo);
                fclose(fi);
                fclose(fo);
                break;
            }
 
            player[i].ng = gl;
        }
    }
};
//Function to search for a player in the player array
void search(int D, FILE *fo)
{
    bool A = false;
    for (int i = 0; i < 22; i++)
    {
        if (player[i].ID == D)
        {
            A = true;
            fputs("Found\n", fo);
        }
    }
    if (A == false)
    {
        fputs("Not found\n", fo);
    }
};
//Function that displays all the players in the player array in the output file
void display(FILE *fo)
{
    for (int i = 0; i < 22; i++)
    {
        if (player[i].ID != -1)
        {
 
            fprintf(fo, "ID: %d, Name: %s, Position: %s, Age: %d, Goals: %d\n",
                    player[i].ID, player[i].name, strpos(player[i].position), player[i].age, player[i].ng);
        }
    }
};
//Function the deletes a specific player from the player array
void delete(int D, FILE *fo)
{
    bool delete = false;
    for (int i = 0; i < 22; i++)
    {
        if (player[i].ID == D)
        {
            delete = true;
            player[i].ID = -1;
        }
    }
    if (delete == false)
    {
        fputs("Impossible to delete\n", fo);
    }
};
int main()
{
    FILE *fo;
    FILE *fi;
    // Opening the input file
    fo = fopen("output.txt", "w");
    // Opening the output file
    fi = fopen("input.txt", "r");
    // Initializing the empty elements of the player array with an ID equal to -1
    for (int i = 0; i < 22; i++)
    {
        player[i].ID = -1;
    }
    char op[10];
    int M = 0;
    //Reading the instruction from the input file
    while (fscanf(fi, "%s", op) != EOF)
    {
        if (strcmp(op, "Add") == 0)
        {
            add(M, fi, fo);
            M = M + 1;
        }
        else if (strcmp(op, "Update") == 0)
        {
            int pu;
            fscanf(fi, "%d", &pu);
            update(pu, fi, fo);
        }
        else if (strcmp(op, "Delete") == 0)
        {
            int pd;
            fscanf(fi, "%d", &pd);
            delete (pd, fo);
        }
        else if (strcmp(op, "Search") == 0)
        {
            int ps;
            fscanf(fi, "%d", &ps);
            search(ps, fo);
        }
        else if (strcmp(op, "Display") == 0)
        {
            display(fo);
        }
        else{
            fputs("Invalid inputs\n", fo);
            fclose(fi);
            fclose(fo);
        }
    }
    // Closing the input and the output files
    fclose(fi);
    fclose(fo);
}