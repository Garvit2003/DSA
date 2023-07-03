#include <iostream>
#include <vector>
#include <algorithm>

int calculateDroppedPackets(std::vector<std::vector<int>> &requests, int maxPackets, int rate)
{
    int currentTime = 0;
    int pipeline = 0;
    int droppedPackets = 0;

    for (const std::vector<int> &request : requests)
    {
        int requestTime = request[0];
        int packetsToSend = request[1];

        while (packetsToSend > 0)
        {
            int timeDiff = currentTime - requestTime;
            int packetsToDeliver = std::min(packetsToSend, rate * timeDiff);
            pipeline = std::max(pipeline - rate * timeDiff, 0);
            int pipelineCapacity = maxPackets - pipeline;
            int packetsToSendNow = std::min(packetsToDeliver, pipelineCapacity);
            pipeline += packetsToSendNow;
            packetsToSend -= packetsToSendNow;
            if (packetsToSendNow < packetsToDeliver)
            {
                droppedPackets += (packetsToDeliver - packetsToSendNow);
            }
        }

        currentTime = requestTime;
    }

    return droppedPackets;
}

int main()
{
    // Example usage:
    std::vector<std::vector<int>> requests = {{1, 8}, {4, 9}, {6, 7}};
    int maxPackets = 10;
    int rate = 2;

    int totalDroppedPackets = calculateDroppedPackets(requests, maxPackets, rate);
    std::cout << "Total dropped packets: " << totalDroppedPackets << std::endl;

    return 0;
}
