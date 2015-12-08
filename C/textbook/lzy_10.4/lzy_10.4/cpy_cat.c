//
//  main.c
//  lzy_10.4
//
//  Created by 赖志懿 on 15/6/15.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    FILE *file,*newFile;
    char ch;
    int i;
    
    newFile = fopen(argv[argc-1], "w");
    
    for (i=1; i<argc-1; i++) {
        file = fopen(argv[i], "r");
        
        while ((ch = fgetc(file)) != EOF)
            fputc(ch, newFile);
        
        fclose(file);
    }
    
    fclose(newFile);
    
    return 0;
}
