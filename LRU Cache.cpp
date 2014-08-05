#include <iostream>
#include <map>
#include <list>

using namespace std;


class LRUCache{
public:
	struct Entry {
		int key;
		int value;
	};


    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
    	if (cacheMap.find(key) != cacheMap.end()) {
    		set(key, cacheMap.find(key)->second->value);
    		return cache.begin()->value;
    	} else {
    		return -1;
    	}
    }
    
    void set(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
        	cache.erase(cacheMap.find(key)->second);
        } else if (cache.size() >= this->capacity) {
        	cacheMap.erase(cache.back().key);
        	cache.pop_back();
        }
        Entry entry;
        entry.key = key;
        entry.value = value;
        cache.push_front(entry);
        cacheMap[key] = cache.begin();
    }

private:
	int capacity;
	list<Entry> cache;
	map<int, list<Entry>::iterator> cacheMap;
};

int main(void) {
	LRUCache cache(3);
	cache.set(1, 1);
	cout << cache.get(1) << endl;
	cache.set(2, 2);
	cout << cache.get(2) << endl;
	cache.set(3, 3);
	cout << cache.get(3) << endl;
	cache.set(4, 4);
	cout << cache.get(4) << "~~~~" << cache.get(1) << endl;
	cache.set(2, 5);
	cache.set(6, 6);
	cout << cache.get(2) << "~~~~" << cache.get(3) << "~~~~" << cache.get(6) << endl;
}

