#include "../cvn.hpp"
class Router {
public:
    struct Packet {
        int source;
        int dest;
        int ts;
        Packet(int src_, int dest_, int ts_): source {src_}, dest {dest_}, ts{ts_}{}
    };

    Router(int memoryLimit): m_limit { memoryLimit } {
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        Packet packet(source, destination, timestamp);
        if (m_table.contains(packet))
            return false;
        if (m_que.size() == m_limit)
            m_que.pop();
        m_table.insert(packet);
        m_dest[destination].insert(packet);
        m_que.push(packet);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (m_que.empty())
            return {};
        vector<int> result(3);
        auto& packet = m_que.front();
        m_que.pop();
        result[0] = packet.source;
        result[1] = packet.dest;
        result[2] = packet.ts;
        m_table.erase(packet);
        m_dest[packet.dest].erase(packet);

        return result;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto& set = m_dest[destination];
        int counter = 0;
        for (auto& packet : set)
            if (startTime <= packet.ts && packet.ts <= endTime)
                ++counter;
        return counter;
    }

private:
    struct HashEqual {
        bool operator()(const Packet& lhs, const Packet& rhs) {
            return lhs.source == rhs.source && lhs.dest == rhs.dest && lhs.ts == rhs.ts;
        }
        std::size_t operator()(const Packet& rhs) {
            return (rhs.source << 30) ^ (rhs.dest << 13 ) ^ rhs.ts;
        }
    };
    unordered_set<Packet, HashEqual, HashEqual> m_table;
    unordered_map<int, unordered_set<Packet, HashEqual, HashEqual>> m_dest;
    queue<Packet> m_que;
    const int m_limit;
};

int main()
{
	Router r(4);
}
