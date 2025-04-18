int** result;
int resultSize;
int* columnSizes;

void dfs(int** graph, int* graphColSize, int node, int* path, int pathLen, int target) {
    path[pathLen++] = node;

    if (node == target) {
        int* validPath = (int*)malloc(sizeof(int) * pathLen);
        for (int i = 0; i < pathLen; i++) {
            validPath[i] = path[i];
        }

        result[resultSize] = validPath;
        columnSizes[resultSize] = pathLen;
        resultSize++;
        return;
    }

    for (int i = 0; i < graphColSize[node]; i++) {
        dfs(graph, graphColSize, graph[node][i], path, pathLen, target);
    }
}

int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes) {
    result = (int**)malloc(sizeof(int*) * 1000);
    columnSizes = (int*)malloc(sizeof(int) * 1000);
    resultSize = 0;
    int* path = (int*)malloc(sizeof(int) * 100);

    dfs(graph, graphColSize, 0, path, 0, graphSize - 1);

    *returnSize = resultSize;
    *returnColumnSizes = columnSizes;
    return result;
}