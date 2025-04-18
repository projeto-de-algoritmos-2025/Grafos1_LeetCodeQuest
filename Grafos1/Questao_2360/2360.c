int longestCycle(int* edges, int edgesSize) {
    int* visitTime = (int*)malloc(sizeof(int) * edgesSize);
    for (int i = 0; i < edgesSize; i++) {
        visitTime[i] = -1;
    }

    int time = 0;
    int result = -1;

    for (int i = 0; i < edgesSize; i++) {
        if (visitTime[i] != -1) continue;

        int startTime = time;
        int current = i;

        while (current != -1 && visitTime[current] == -1) {
            visitTime[current] = time++;
            current = edges[current];
        }

        if (current != -1 && visitTime[current] >= startTime) {
            int cycleLength = time - visitTime[current];
            if (cycleLength > result) {
                result = cycleLength;
            }
        }
    }

    return result;
}
