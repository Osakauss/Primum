#include <efilibs.h>
#include <stdlib.h>


static char list[100][2][100];
char *lookup(char *name){
    for (int o = 0; o <= 100; o++){
        if (list[o][0][0] == 0){
            continue;
        }
        else if (strcmp(name, list[o][0]) == 0){
            return (char*)&list[o][1];
        }
        else{
            continue;
        }
    }
    return NULL;
};
void scan(char *l){
    
    char name[128], value[128];
    int i = 0;
    int v = 0;
    int n =0;
    int ln = 0;
    u16 c[32];
    for (int x = 0; x < strlen(l); x++){
        if (n >= 100 || v >= 100){
            Print(L"variable name or value is too long [");
            itoa_(x+1, c,10);
            Print(c);
            Print(L":");
            itoa_(ln+1,c,10);
            Print(c);
            Print(L"]\n");

            break;
        }
        if (l[x] == ' '){
            continue;
        }
        if ((l[x] >= 'a' && l[x] <= 'z') || (l[x] >= 'A' && l[x] <= 'Z')){
            if (i){
                value[v] = l[x];
                v++;
            }
            else{
                name[n] = l[x];
                n++;
            }
        }
        else if( l[x] == '='){
            if (!i){
                i = 1;                
            }
            else{
                Print(L"variable name or value is too long [");
                itoa_(x+1, c,10);
                Print(c);
                Print(L":");
                itoa_(ln+1,c,10);
                Print(c);
                Print(L"]\n");
            }
        }
        else if (l[x] == '\n'){
            if (n != 0){
                memcpy(list[ln][0],name, strlen(name)+1);
                memcpy(list[ln][1], value, strlen(value)+1);
                ln++;
                i=0;
                v=0;
                n=0;
                memset(&name, 0, 128);
                memset(&value, 0, 128);
            }
            else{
                Print(L"error");
            }
        }
        else{
            if (i){
                value[v] = l[x];
                v++;
            }
            else{
                Print(L"variable name or value is too long [");
                itoa_(x+1, c,10);
                Print(c);
                Print(L":");
                itoa_(ln+1,c,10);
                Print(c);
                Print(L"]\n");
            }
        }
    }
    if (n!=0){
        memcpy(list[ln][0],name, strlen(name)+1);
        memcpy(list[ln][1], value, strlen(value)+1);
    }
}
