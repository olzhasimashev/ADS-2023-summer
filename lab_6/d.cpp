#include <bits/stdc++.h>
using namespace std;

struct Date {
    int day, month, year;
    string original_format;
};

bool compareDates(Date &a, Date &b) {
    if (a.year != b.year)
        return a.year < b.year;
    if (a.month != b.month)
        return a.month < b.month;
    return a.day < b.day;
}

int main() {
    int n;
    cin >> n;
    vector<Date> dates(n);
    for (int i = 0; i < n; i++) {
        string date_str;
        cin >> date_str;
        dates[i].day = stoi(date_str.substr(0, 2));
        dates[i].month = stoi(date_str.substr(3, 2));
        dates[i].year = stoi(date_str.substr(6, 4));
        dates[i].original_format = date_str;
    }

    sort(dates.begin(), dates.end(), compareDates);

    for (Date &date : dates) {
        cout << date.original_format << endl;
    }

    return 0;
}