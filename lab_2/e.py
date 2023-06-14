n = int(input().strip())
students = []
last_student = None

for _ in range(n):
    student = input().strip()
    if student != last_student:
        students.append(student)
    last_student = student

students.reverse()
print(f"All in all: {len(students)}")
print("Students:")
for student in students:
    print(student)