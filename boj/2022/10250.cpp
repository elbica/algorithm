//
// Created by Kim So Hee on 2022/06/29.
//

#include <bits/stdc++.h>

using namespace std;

string ACM(int floor, int room, int people) {
    string roomNumber = to_string((int)ceil(people / (double) floor));
    string floorNumber = to_string(people % floor);

    if (roomNumber.size() == 1) roomNumber = "0" + roomNumber;
    if (floorNumber == "0") floorNumber = to_string(floor);
    return floorNumber + roomNumber;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int x, y, z;
        cin >> x >> y >> z;
        cout << ACM(x, y, z) << '\n';
    }
}