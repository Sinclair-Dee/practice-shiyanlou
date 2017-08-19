//status: pass the challenge！！ compiled
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define FILE_PATH "./maze.data"

int maze[1004][1004];
int m, n;
//基本思想：深度遍历
//向左向下深度遍历
int maze_dfs(int x, int y){
    if(x==m-1 && y==n-1){
        return 1;
    }
    if(x==m-1){
        if(maze[x][y+1] == 0) return maze_dfs(x, y+1);
    }
    else if(y==n-1){
        if(maze[x+1][y] == 0) return maze_dfs(x+1, y);
    }
    else{
        if(maze[x][y+1] == 0) return maze_dfs(x, y+1);
        if(maze[x+1][y] == 0) return maze_dfs(x+1, y);
    }
    return 0;
}

int haveExit() {
    return maze_dfs(0,0);
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
