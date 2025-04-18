void dfs(int** graph, int* graphColSize, int node, int* path, int pathLen,
    int*** paths, int* returnSize, int** returnColumnSizes, int target) {
path[pathLen++] = node;

if (node == target) {
   (*paths)[*returnSize] = (int*)malloc(sizeof(int) * pathLen);
   for (int i = 0; i < pathLen; i++) {
       (*paths)[*returnSize][i] = path[i];
   }

   (*returnColumnSizes)[*returnSize] = pathLen;
   (*returnSize)++;
   return;
}

for (int i = 0; i < graphColSize[node]; i++) {
   dfs(graph, graphColSize, graph[node][i], path, pathLen, paths, returnSize, returnColumnSizes, target);
}
}

int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes) {
*returnSize = 0;
int maxPaths = 10000;
int** paths = (int**)malloc(sizeof(int*) * maxPaths);
*returnColumnSizes = (int*)malloc(sizeof(int) * maxPaths);
int* path = (int*)malloc(sizeof(int) * graphSize);

dfs(graph, graphColSize, 0, path, 0, &paths, returnSize, returnColumnSizes, graphSize - 1);

free(path);
return paths;
}
