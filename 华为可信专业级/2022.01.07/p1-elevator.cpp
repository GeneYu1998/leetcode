#include "../../utils.cpp"

int numFloorTravelled(const vector<vector<int>>& passengers, const int& initialFloor) {
    int n = passengers.size();
    if(!n) return 0;   

    bool curDirec, lastDirec = (passengers[0][1] - passengers[0][0]) <= 0;
    int travelledFloor = 0, lastEnd = initialFloor, lastBegin = 0, curTri;

    for(const vector<int>& passenger: passengers){
       curTri = passenger[1] - passenger[0];
       curDirec = (curTri > 0)? true: false;

       if(curDirec == lastDirec && (static_cast<bool>(passenger[1] - lastEnd > 0) ^ static_cast<bool>(passenger[0] - lastBegin > 0))) {
          continue;
       }
       else if(curDirec == lastDirec && !(static_cast<bool>(passenger[0] - lastEnd > 0) ^ curDirec)) {
          travelledFloor += abs(passenger[0] - lastEnd) + abs(curTri);
       }
       else if(curDirec == lastDirec) {
           travelledFloor += abs(curTri) - abs(passenger[0] - lastEnd);
       }
       else travelledFloor += abs(curTri) + abs(passenger[0] - lastEnd);

       lastDirec = curDirec;
       lastEnd = passenger[1];
       lastBegin = passenger[0];
    }

    return travelledFloor;
}

int main(){
    vector<vector<int>> passengers = {{12, 66}, {25, 27}, {26, 83}};
    cout << "The elevator travelled " << numFloorTravelled(passengers, 50) << " floor in total. " << endl;
}
