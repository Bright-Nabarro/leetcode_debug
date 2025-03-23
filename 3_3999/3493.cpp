#include "../cvn.hpp"

class Solution {
public:
    int m_k;
    vector<set<int>> trees;
    
    
    bool intersect(int i, int j)
    {
        auto& tree1 = trees[i];
        auto& tree2 = trees[j];
        auto itr1 = tree1.begin();
        auto itr2 = tree2.begin();
        int counter = 0;
        while(itr1 != tree1.end() && itr2 != tree2.end()) {
            if (*itr1 == *itr2) {
                ++counter;
                ++itr1;
                ++itr2;
            } else if (*itr1 < *itr2) {
                ++itr1;
            } else {
                ++itr2;
            }
        }
        return counter >= m_k;
    }

    int find(auto& parent, int x) {
        if (parent[x] != x)
            parent.at(x) = find(parent, parent.at(x));
        return parent.at(x);
    }

    void unite(auto& parent, int x, int y) {
		if (find(parent, x) == find(parent, y))
			return;
        parent[find(parent, y)] = x;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int size = properties.size();
        m_k = k;
        trees.clear();
        for (auto& list : properties) {
            set<int> s;
            for (int x : list) {
                s.insert(x);
            }
            trees.push_back(std::move(s));
        }
        
        vector<int> parents(size);
        for (int i = 0; i < parents.size(); ++i) {
            parents[i] = i;
        }

        for (int i = 0; i < size; ++i) {
            for (int j = i+1; j < size; ++j) {
                if (intersect(i, j))
                {
                    unite(parents, i, j);
                }
            }
			print_1d(parents, "p");
        }

        unordered_set<int> set;
        for (int n : parents)
            set.insert(find(parents, n));
        
        return set.size();
    }
};

int main()
{
	Solution s{};
	vector<vector<int>> list {{1},{1},{1}};
	std::println("{}", s.numberOfComponents(list, 1));
}
