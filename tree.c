#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#define path "/home/patilkam/ipc/practice"

main(int argc, char *argv[]){

int i;

if(argc < 2){
    printf("\nError. Use: %s directory\n", argv[0]);
    system("exit");
}
for(i=1;i<argc;i++)
    //if(argv[i][0] != '-')
        tree(argv[i]);
}

tree(char *ruta){

DIR *dirp;
struct dirent *dp;
static nivel = 0;
struct stat buf;
char fichero[256];
int i;

if((dirp = opendir(path)) == NULL){
    perror(path);
    return;
}

while((dp = readdir(dirp)) != NULL){
    printf(fichero, "%s/%s", path, dp->d_name);
    if((buf.st_mode & S_IFMT) == S_IFDIR){
        for(i=0;i<nivel;i++)
            printf("\t");
        printf("%s\n", dp->d_name);
        ++nivel;
        tree(fichero);
        --nivel;
    }

}
}
