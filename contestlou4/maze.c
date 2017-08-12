//status: fall!!!
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define FILE_PATH "./maze.data"
#define M 1004*1004

int maze[1004][1004];
int m, n;
int pre[30];

int haveExit() {
    //建并查集
    for(int i=0;i<30;i++){
        pre[i] = i;
    }
    //连通可以通过的路
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            if(maze[i][j])
                continue;
            if(i > 0 && !maze[i-1][j]){
                int temp = (i-1)*n+j;
                while(pre[temp] != temp){
					temp = pre[temp];
                }
                pre[i*j] = temp;
            }
            if(j > 0 && !maze[i][j-1]){
                int temp = i*n+j-1;
                while(pre[temp] != temp){
					temp = pre[temp];
                }
                int temp2 = pre[i*n+j];
                if(temp2 != temp){
                    for(int k = 0;k< m*n;k++)
                        if(pre[k] == temp2)
                            pre[k] = temp;
                 }
                
            }
        }
    if(pre[0] == pre[m*n-1])
        return 1;
    else
        return 0;
}

// 以下代码不允许修改
void read() {
    FILE *fp;
    memset(maze, -1, sizeof(maze));
    if ((fp = fopen(FILE_PATH, "r")) == NULL) {
        perror(FILE_PATH);
        exit(1);
    }
    fscanf(fp, "%d %d", &m, &n);
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            fscanf(fp, "%d", &maze[i][j]);
        }
    }
    fclose(fp);
}

int main() {
    read();
    if (haveExit()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
