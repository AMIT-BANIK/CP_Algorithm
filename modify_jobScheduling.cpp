#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Job {
    char id; 
    int dead;
    int profit;
};

struct jobProfit {
    bool operator()(const Job &a, const Job &b) const {
        return a.profit < b.profit;
    }
};

void printJobScheduling(Job arr[], int n) {
    vector<Job> result;
    sort(arr, arr + n, [](Job a, Job b) { return a.dead < b.dead; });

    priority_queue<Job, vector<Job>, jobProfit> pq;

    for (int i = n - 1; i >= 0; i--) {
        int slot_available = (i == 0) ? arr[i].dead : arr[i].dead - arr[i - 1].dead;

        pq.push(arr[i]);

        while (slot_available > 0 && !pq.empty()) {
            Job job = pq.top();
            pq.pop();

            result.push_back(job);
            slot_available--;
        }
    }

    sort(result.begin(), result.end(), [](Job a, Job b) { return a.dead < b.dead; });

    int maxProfit = 0;
    cout << "Scheduled Jobs: ";
    for (auto &job : result) {
        cout << job.id << ' ';
        maxProfit += job.profit;
    }
    cout << endl;

    cout << "Maximum Profit: " << maxProfit << endl;
}

int main() {
    int n;
    cin >> n;

    vector<char> id(n);
    vector<int> deadline(n);
    vector<int> profit(n);

    for (int i = 0; i < n; i++) cin >> id[i];
    for (int i = 0; i < n; i++) cin >> deadline[i];
    for (int i = 0; i < n; i++) cin >> profit[i];

    Job* arr = new Job[n];
    for (int i = 0; i < n; i++) {
        arr[i].id = id[i];
        arr[i].dead = deadline[i];
        arr[i].profit = profit[i];
    }

    printJobScheduling(arr, n);

    delete[] arr;
    return 0;
}

/*
7
a b c d e f g
2 1 2 1 7 7 7
100 19 27 25 20 15 5


Scheduled Jobs: a c e f g 
Maximum Profit: 167
*/