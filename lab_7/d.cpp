#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <map>

struct Student {
    std::string lastname;
    std::string firstname;
    double gpa;
};

double convertMarkToGPA(const std::string& mark) {
    if (mark == "A+") return 4.00;
    if (mark == "A") return 3.75;
    if (mark == "B+") return 3.50;
    if (mark == "B") return 3.00;
    if (mark == "C+") return 2.50;
    if (mark == "C") return 2.00;
    if (mark == "D+") return 1.50;
    if (mark == "D") return 1.00;
    return 0;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        std::cin >> students[i].lastname >> students[i].firstname;
        
        int m;
        std::cin >> m;

        double total = 0;
        double credits = 0;
        for (int j = 0; j < m; j++) {
            std::string mark;
            double credit;
            std::cin >> mark >> credit;
            
            total += convertMarkToGPA(mark) * credit;
            credits += credit;
        }

        students[i].gpa = total / credits;
    }

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.gpa != b.gpa) return a.gpa < b.gpa;
        if (a.lastname != b.lastname) return a.lastname < b.lastname;
        return a.firstname < b.firstname;
    });

    std::cout << std::fixed << std::setprecision(3);
    for (const auto& student : students) {
        std::cout << student.lastname << " " << student.firstname << " " << student.gpa << std::endl;
    }

    return 0;
}