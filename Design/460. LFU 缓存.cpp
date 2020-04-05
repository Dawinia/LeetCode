class LFUCache {
private:
    map<int, pair<int, int> > cache;
    map<int, list<int>::iterator> cacheIter;
    map<int, list<int> > fcache;
    int capacity;
    int minFreq;
    int size;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        if(cache.count(key)) {
            fcache[cache[key].second].erase(cacheIter[key]);
            ++cache[key].second;
            fcache[cache[key].second].push_back(key);
            cacheIter[key] = --fcache[cache[key].second].end();
        
            if(fcache[minFreq].size()==0 ) 
                minFreq++;
        
            return cache[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity <= 0)
            return;
        
        int storedValue = get(key);
        if(storedValue != -1) {
            cache[key].first = value;
            return;
        }

        if(size >= capacity) {
            cache.erase(fcache[minFreq].front());
            cacheIter.erase(fcache[minFreq].front());
            fcache[minFreq].pop_front();
            --size;
        }

        cache[key] = {value, 1};
        fcache[1].push_back(key);
        cacheIter[key] = --fcache[1].end();
        minFreq = 1;
        ++size;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
