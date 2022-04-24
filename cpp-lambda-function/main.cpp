#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>

struct Employee {
	std::string Name;
	int Age;
	float Salary;

	friend std::ostream& operator<< (std::ostream& stream, const Employee& employee) {
		stream << "{ ";
		stream << "\"Name\": \"" << employee.Name << "\", ";
		stream << "\"Age\": " << employee.Age << ", ";
		stream << "\"Salary\": " << employee.Salary;
		stream << " }";

		return stream;
	}

};

int main()
{
	std::vector<Employee> data = {
		{"Andris", 25, 1105.72f},
		{"Elze", 35, 805.27f},
		{"Vitaults", 19, 1305.22f},
		{"Liene", 61, 5005.21f},
		{"Talivalds", 81, 705.23f},
		{"Mariss", 43, 905.22f},
		{"Rainers", 33, 1105.42f},
		{"Judite", 17, 1205.29f},
	};



	auto max_sal_emp = std::max_element(
		data.begin(), data.end(),
		[](Employee const& d1, Employee const& d2)
		{
			return d1.Salary < d2.Salary;
		}
	);
	std::cout << "Employee with highest salary: " << std::endl << "    " << *max_sal_emp << std::endl << std::endl;



	auto min_sal_emp = std::max_element(
		data.begin(), data.end(),
		[](Employee const& d1, Employee const& d2)
		{
			return d1.Salary > d2.Salary;
		}
	);
	std::cout << "Employee with smallest salary: " << std::endl << "    " << *min_sal_emp << std::endl << std::endl;

	

	std::cout << "Employees who are older than 50: " << std::endl;
	std::for_each(
		data.begin(), data.end(),
		[](Employee const& emp) {
			if (emp.Age > 50)
				std::cout << "    " << emp << std::endl;
		}
	);
	std::cout << std::endl;



	std::cout << "Employees who are younger than 25: " << std::endl;
	std::for_each(
		data.begin(), data.end(),
		[](Employee const& emp) {
			if (emp.Age < 25)
				std::cout << "    " << emp << std::endl;
		}
	);
	std::cout << std::endl;



	std::cout << "Employees who's salagy is bigger than 1000 Eur: " << std::endl;
	std::for_each(
		data.begin(), data.end(),
		[](Employee const& emp) {
			if (emp.Salary > 1000)
				std::cout << "    " << emp << std::endl;
		}
	);
	std::cout << std::endl;



	std::cout << "Employees who's salagy is bigger than 500 Eur: " << std::endl;
	std::for_each(
		data.begin(), data.end(),
		[](Employee const& emp) {
			if (emp.Salary > 500)
				std::cout << "    " << emp << std::endl;
		}
	);
	std::cout << std::endl;



	auto emp_age_15 = std::find_if(
		data.begin(), data.end(),
		[](Employee const& emp) { return emp.Age < 15; }
	);
	std::cout << "Is there employee younger than 15 years?: " << std::endl << "    " << std::boolalpha << (emp_age_15 != data.end()) << std::endl << std::endl;



	std::cout << "All employees: " << std::endl;
	std::for_each(
		data.begin(), data.end(),
		[](Employee const& emp) {
			std::cout << "    " << emp << std::endl;
		}
	);

	return 0;
}