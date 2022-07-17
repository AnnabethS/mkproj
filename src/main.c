#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 64

/*
project name
project type
*/

int mk_cstd(char* name);

int main(int argc, char** argv)
{
    char proj_name[BUFFER_LENGTH] = {0};
    char proj_type[BUFFER_LENGTH] = {0};
    if (argc < 3)
    { // manual entry
        printf("Enter project name..\n");
        scanf("%63s", proj_name);
        if (proj_name[63] != 0)
        {
            printf("ERROR: project name longer than maximum length (63)\n");
            return 1;
        }
        printf("Enter project type..\n");
        scanf("%63s", proj_type);
        if (proj_type[63] != 0)
        {
            printf("ERROR: project type longer than maximum length (63)\n");
            return 1;
        }
    }
    else if (argc == 3)
    { // project name and type specified
        printf("%s %s\n", *(argv + 1), *(argv + 2));
        strcpy(proj_name, *(argv + 1));
        strcpy(proj_type, *(argv + 2));
    }
    else
    {
        printf("incorrect number of arguments, should be 0 or 2\n");
    }

    if (!strcmp(proj_type, "c"))
    {
        return mk_cstd(proj_name);
    }
    return 0;
}

int mk_cstd(char* name)
{
    int ret = 0;
    char cmd[BUFFER_LENGTH + 6 + 3];
    strcpy(cmd, "mkdir ");
    strcat(cmd, name);
    ret = system(cmd);
    if (ret != 0)
        return ret;
    strcat(cmd, "/src");
    ret = system(cmd);
    if (ret != 0)
        return ret;
    char cmd2[BUFFER_LENGTH + 4 + 6];
    strcpy(cmd2, "touch ");
    strcat(cmd2, name);
    strcat(cmd2, "/src/main.c");
    system(cmd2);
    char file_path[BUFFER_LENGTH + 6 + 3];
    strcpy(file_path, name);
    strcat(file_path, "/src/main.c");
    FILE* fp = fopen(file_path, "w");
    fprintf(fp, "#include <stdio.h>\n"
            "\n"
            "int main(int argc, char**argv)\n"
            "{\n"
            "    printf(\"hello world!\\n\");\n"
            "    return 0;\n"
            "}\n");
    fclose(fp);
    return 0;
}

int mk_csdl(char* name)
{
    return 0;
}
