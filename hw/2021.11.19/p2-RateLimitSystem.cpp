#include "../../utils.cpp"

class Rule {
    public:
      Rule(int ruleId, int time, int interval, int number): ruleId(ruleId), time(time), interval(interval), number(number){}
      ~Rule();

      int ruleId;
      int time;
      int interval;
      int number;
      // default values
      int genCnt = 0;
      int endTime = INT_MAX;
}; 

class RateLimitSystem {
    public:
      RateLimitSystem(int tokenLimit) {
        cacheSize = tokenLimit;  
        curSize = 0; 
      }
      ~RateLimitSystem();

      int computeGenCnts(Rule* rule) {
        int increCnt = curTime < rule->time? 0 : ((min(curTime, rule->endTime) - rule->time) / rule->interval + 1 - rule->genCnt);
        rule->genCnt += increCnt; 
        return increCnt;
      }

      void addRateforRule(Rule* rule) {
        if(curSize == cacheSize) return;
        curSize += computeGenCnts(rule) * rule->number;
        if(curSize > cacheSize) curSize = cacheSize;
      }

      void applyRules() {
        vector<int> delete_ids;
        for(unordered_map<int, Rule*>::iterator iter = cache.begin(); iter != cache.end(); ++iter) {
          addRateforRule(iter->second);
          if(iter->second->endTime <= curTime){
            delete_ids.emplace_back(iter->first);
          }
        }
        for(int& id: delete_ids) {
          cache.erase(id);
        }
      }

      void updateToken(int time) {
        if(time == curTime) return;
        curTime = time; // update time
        applyRules(); // apply Rules to generate Tokens  
      }
      
      bool addRule(int ruleId, int time, int interval, int number) {
      updateToken(time);
      if(cache.count(ruleId)) {
        return false;
      }
      else {
        cache.insert(make_pair(ruleId, new Rule(ruleId, time, interval, number)));
        return true;
      }
      }

      bool removeRule(int ruleId, int time) {
      updateToken(time);
      if(!cache.count(ruleId)) {
        return false;
      }
      else {
        cache[ruleId]->endTime = time;
        return true;
      } 
      } 
      
      int queryToken(int time) {
        updateToken(time);
        return curSize; 
      }

      bool transferData(int time, int size) {
        if(queryToken(time) >= size) {
          curSize -= size;
          return true;
        } else {
          return false;
        }
    }

    // private:
    unordered_map<int, Rule*> cache; 
    int cacheSize;
    int curSize;
    int curTime;
};

void RateLimitSystemCall(RateLimitSystem* rS, const string& call, vector<int>& contents) {
  if(call == "addRule") {
    cout << (rS->addRule(contents[0], contents[1], contents[2], contents[3]) ? "true" : "false");
  }
  else if(call == "transferData") {
    cout << (rS->transferData(contents[0], contents[1])? "true" : "false");
  }
  else if(call == "removeRule") {
    cout << (rS->removeRule(contents[0], contents[1])? "true" : "false");
  }
  else if(call == "queryToken") {
    cout << rS->queryToken(contents[0]);
  }
}

int main() { 

  list<pair<string, vector<int>>> contentList;
  contentList.emplace_back(make_pair("addRule", vector<int> {0, 0, 1, 3}));
  contentList.emplace_back(make_pair("transferData", vector<int> {1, 5}));
  contentList.emplace_back(make_pair("queryToken", vector<int> {1}));
  contentList.emplace_back(make_pair("removeRule", vector<int> {0, 2}));
  contentList.emplace_back(make_pair("queryToken", vector<int> {2}));
  contentList.emplace_back(make_pair("queryToken", vector<int> {4}));
  
  RateLimitSystem* rateLimitSystem = new RateLimitSystem(10);
  cout << "Output:" << endl << "--------------------" << endl << "[null, ";
  for(auto iter = contentList.begin(); iter != contentList.end();) {
    RateLimitSystemCall(rateLimitSystem, iter->first, iter->second);
    if(++iter != contentList.end()) cout << ", ";
  }
  cout << "]" << endl;
}