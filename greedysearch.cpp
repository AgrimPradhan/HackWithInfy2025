#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Activity {
public:
    int start, end;
    Activity(int s, int e) {
        start = s;
        end = e;
    }
};

int main() {
    int n;
    cout << "Enter no. of activities: ";
    cin >> n;

    vector<Activity> activities;
    cout << "Enter start & end time for each activity:\n";

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        activities.push_back(Activity(s, e));
    }

    
    sort(activities.begin(), activities.end(), [](Activity a, Activity b) {
        return a.end < b.end;
    });

    int count = 1;
    int lastEnd = activities[0].end;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }

    cout << "Maximum no. of non-overlapping activities: " << count << endl;

    return 0;
}
