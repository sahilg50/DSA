#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

long packetsRemaining(int totalPackets, int time, int rate)
{
    long maxTransferPossible = time * rate;
    if (totalPackets <= maxTransferPossible)
    {
        return 0;
    }
    return totalPackets - maxTransferPossible;
}
long getNumberOfDroppedPackets(vector<vector<int>> requests, int max_packets, int rate)
{
    sort(requests.begin(), requests.end());
    long packetsDropped = 0, packetsPending = 0;
    int i;
    for (i = 0; i < requests.size() - 1; i++)
    {
        long time = requests[i + 1][0] - requests[i][0];
        long totalPackets = packetsPending + requests[i][1];
        if (totalPackets > max_packets)
        {
            packetsDropped += totalPackets - max_packets;
            packetsPending = packetsRemaining(max_packets, time, rate);
        }
        else
        {
            packetsPending = totalPackets - (time * rate);
        }
    }
    long totalPackets = packetsPending + requests[i][1];
    if (totalPackets > max_packets)
    {
        packetsDropped += totalPackets - max_packets;
    }
    return packetsDropped;
}
int main()
{
    return 0;
}