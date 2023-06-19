#include<bits/stdc++.h>
using namespace std;

map<string, double> GPA = {
    {"A+", 4.00},
    {"A", 3.75},
    {"B+", 3.50},
    {"B", 3.00},
    {"C+", 2.50},
    {"C", 2.00},
    {"D+", 1.50},
    {"D", 1.00},
    {"F", 0}
};

int main() {
    int n;
    cin >> n;

    vector<pair<string, pair<string, double>>> students(n);
    for(int i = 0; i < n; i++) {
        cin >> students[i].first >> students[i].second.first;
        int m;
        cin >> m;
        double total_marks = 0, total_credits = 0;
        for(int j = 0; j < m; j++) {
            string grade;
            double credit;
            cin >> grade >> credit;
            total_credits += credit;
            total_marks += credit * GPA[grade];
        }
        students[i].second.second = total_marks / total_credits;
    }

    sort(students.begin(), students.end(), [](pair<string, pair<string, double>>& left, pair<string, pair<string, double>>& right) {
        if(abs(left.second.second - right.second.second) > 1e-9) {
            return left.second.second < right.second.second;
        }
        if(left.first != right.first) {
            return left.first < right.first;
        }
        return left.second.first < right.second.first;
    });

    for(auto& student : students) {
        cout << fixed << setprecision(3) << student.first << " " << student.second.first << " " << student.second.second << "\n";
    }

    return 0;
}