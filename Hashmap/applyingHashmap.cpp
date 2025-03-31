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
    int mapSize=0;

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
        for (auto &[k, v] : hashtable[idx])
        {
            // since modifying u gotta do it
            if (k == key)
            {
                v = value;
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
        for (auto &[k, v] : hashtable[idx])
        {
            if (k == key)
                return v;
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

    bool contains(int key){
        int idx=hash(key);
        for(auto [k,v]:hashtable[idx]){
            if(k==key)
                return true;
        }
        return false;
    }

    int sizeOf(){
        if(mapSize<1)
            return -1;
        return mapSize;

    }
    void printMap(){
        for(auto bucket:hashtable){
            
        }
        for(auto [k,v]:hashtable){

        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    MyHashMap map;
    map.put(2,21);
    map.put(6,73);
    map.put(24,12);
    return 0;
}