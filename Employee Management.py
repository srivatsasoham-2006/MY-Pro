employees = {}

def add_employee():
    emp_id = input("Enter Employee ID: ")

    if emp_id in employees:
        print("Employee already exists!\n")
        return

    name = input("Enter Employee Name: ")

    try:
        age = int(input("Enter Employee Age: "))
        salary = float(input("Enter Salary: "))
    except ValueError:
        print("Invalid input! Age must be integer and salary must be number.\n")
        return

    department = input("Enter Department: ")

    employees[emp_id] = {
        "name": name,
        "age": age,
        "department": department,
        "salary": salary
    }

    print("Employee added successfully!\n")


def display_employees():
    if not employees:
        print("No employees found.\n")
        return

    print("\nEmployee List:")
    for emp_id, details in employees.items():
        print("------------------------")
        print(f"ID: {emp_id}")
        print(f"Name: {details['name']}")
        print(f"Age: {details['age']}")
        print(f"Department: {details['department']}")
        print(f"Salary: {details['salary']}")
    print("------------------------\n")


def search_employee():
    emp_id = input("Enter Employee ID to search: ")

    if emp_id in employees:
        details = employees[emp_id]
        print("\nEmployee Found")
        print(details, "\n")
    else:
        print("Employee not found!\n")


def update_employee():
    emp_id = input("Enter Employee ID to update: ")

    if emp_id in employees:
        print("Leave blank to keep old values")

        name = input("Enter new name: ")
        age = input("Enter new age: ")
        department = input("Enter new department: ")
        salary = input("Enter new salary: ")

        if name:
            employees[emp_id]["name"] = name
        if age:
            employees[emp_id]["age"] = int(age)
        if department:
            employees[emp_id]["department"] = department
        if salary:
            employees[emp_id]["salary"] = float(salary)

        print("Employee updated successfully!\n")
    else:
        print("Employee not found!\n")


def delete_employee():
    emp_id = input("Enter Employee ID to delete: ")

    if emp_id in employees:
        confirm = input("Are you sure? (y/n): ")
        if confirm.lower() == 'y':
            del employees[emp_id]
            print("Employee deleted successfully!\n")
    else:
        print("Employee not found!\n")


while True:
    print("***** Employee Management System *****")
    print("1. Add Employee")
    print("2. Display Employees")
    print("3. Search Employee")
    print("4. Update Employee")
    print("5. Delete Employee")
    print("6. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        add_employee()
    elif choice == "2":
        display_employees()
    elif choice == "3":
        search_employee()
    elif choice == "4":
        update_employee()
    elif choice == "5":
        delete_employee()
    elif choice == "6":
        print("Exiting program...")
        break
    else:
        print("Invalid choice! Please try again.\n")
