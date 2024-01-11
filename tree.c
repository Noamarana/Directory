#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void listFiles(const char* dirname, int counter) {
    //This going to be our directory with it's realative path
    DIR* dir;
    char path[100] = "";
    //Pointing this data type to iterate all the elements on the directory
    struct dirent* entity;
    struct stat stats;

    dir = opendir(dirname);
    if (dir == NULL) 
    {
        perror("Error, unable to read the directory");
        return; //do not return a value
    }
    if(counter == 1){
        printf("%*s%s\n", counter*4, "",  ".");
    } else {
    printf("%*s%s\n", counter*2, "",  dirname);
           }
    //strcat(dirname, "/");
    
    entity = readdir(dir);

    while (entity != NULL) {

        strcpy(path, dirname); 
        strcat(path, entity->d_name);
        stat(path, &stats); // get the file attributes pointed by path and store them in temp2
            while (entity != NULL  && (!(S_ISDIR(stats.st_mode)) || (!strcmp(entity->d_name, ".") || !strcmp(entity->d_name, ".."))))
            {
                if ((strcmp(entity->d_name, ".") && strcmp(entity->d_name, "..")))
                {
                    printf(" %*s %s\n", counter*2+2, "-", entity->d_name);
                    
                }
                entity = readdir(dir);
                if (entity != NULL) 
                {
                    strcpy(path, "                              ");
                    strcpy(path, dirname); 
                    strcat(path, entity->d_name);
                    stat(path, &stats); 
                }
                
            } 
        if (entity != NULL  && S_ISDIR(stats.st_mode))
        {
            strcat(path, "/");
             listFiles(path, counter+2); 
        }
        
        if (entity != NULL)
            entity = readdir(dir);
    }
    closedir(dir);
    return;
}

int main(int argc, char* argv[]) {
    listFiles("./", 1); //prints the current directory
    return 0;
}