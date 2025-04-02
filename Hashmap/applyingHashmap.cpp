#include <bits/stdc++.h>
using namespace std;

/**
 * it has =>=>
 * put(key,val)
 * get(key):val
 * remove(key)
 * contains(key)
 * sizeOf()
 * printMap()
 */
class MyHashMap
{
private:
    static const int Size = 100;
    vector<list<pair<int, int>>> hashtable;
    int mapSize = 0;

    int hash(int key)
    {
        return key % Size;
        // lessens
    }

public:
    MyHashMap() : hashtable(Size) {}

    void put(int key, int value)
    {
        int idx = hash(key);
        // structured binding only with pair and tuple works
        for (auto &p : hashtable[idx])
        {
            // since modifying u gotta do it
            if (p.first == key)
            {
                p.second = value;
                mapSize++;
                return;
            }
        }
        hashtable[idx].emplace_back(key, value);
        mapSize++;
        // adding on last of list
    }

    int get(int key)
    {
        int idx = hash(key);
        for (auto &p : hashtable[idx])
        {
            if (p.first == key)
                return p.second;
        }
        return -1;
    }

    void remove(int key)
    {
        int idx = hash(key);
        auto &bucket = hashtable[idx];

        for (auto it = bucket.begin(); it != bucket.end(); it++)
        {
            if (it->first == key)
            {
                bucket.erase(it);
                mapSize--;
                return;
                // yea erase the location forget about next shiis!
            }
        }
    }

    bool contains(int key)
    {
        int idx = hash(key);
        for (auto p : hashtable[idx])
        {
            if (p.first == key)
                return true;
        }
        return false;
    }

    void sizeOf()
    {
        if (this->mapSize < 1)
        {
            cout << "The map is empty" << endl;
            return;
        }
        cout << "The size of the map is :(total entries) " << this->mapSize << endl;
    }
    void printMap()
    {
        if (this->mapSize < 1)
        {
            cout << " Bro its fricking empty " << endl;
            return;
        }
        cout << "The map shown below : " << endl;
        for (auto bucket : hashtable)
        {
            for (auto p : bucket)
            {
                cout << "{ Key : " << p.first << ", Value : " << p.second << " }" << endl;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    MyHashMap map;
    map.put(2, 21);
    map.put(6, 73);
    map.put(24, 12);
    map.remove(6);
    map.put(1215, 24);
    map.printMap();
    cout << "The key 24 exists :" << map.contains(24) << endl;
    map.sizeOf();
    return 0;
}