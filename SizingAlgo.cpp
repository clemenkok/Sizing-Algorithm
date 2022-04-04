// An Implementation of 3 Row Parade Sizing in C++.

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

std::vector<double> SatuInsertion(
	int i,
	int n,
	int t,
	std::vector<double> v_even,
	std::vector<double> v_sized) {
	auto itPos = v_sized.begin() + ((t / 3) * 3 + n - 1);
	
	if (n == 1 && i != -1) {
		v_sized.erase(itPos);
		v_sized.insert(itPos, v_even[i]);
		n = 3;
		t = t + 1;
		i = i - 1;
		return SatuInsertion(i, n, t, v_even, v_sized);
	}
	
	else if (n == 3 && i != -1) {
		v_sized.erase(itPos);
		v_sized.insert(itPos, v_even[i]);
		n = 2;
		t = t + 1;
		i = i - 1;
		return SatuInsertion(i, n, t, v_even, v_sized);
	}
	
	else if (n == 2 && i != -1) {
		v_sized.erase(itPos);
		v_sized.insert(itPos, v_even[i]);
		n = 1;
		t = t + 1;
		i = i - 1;
		return SatuInsertion(i, n, t, v_even, v_sized);
	}
	return v_sized;
}

std::vector<double> DuaInsertion(
	int i,
	int n,
	int t,
	int k,
	std::vector<double> v_odd,
	std::vector<double> v_sized) {
	int pos = v_sized.size() - (t / 3) * 3 - n + k;
	auto itPos = v_sized.begin() + v_sized.size() - (t / 3) * 3 - n + k;
	
	// For Dua, we will be inserting from the back instead.
	if (n == 2 && i > -1 && v_sized[pos] == 0) {
		v_sized.erase(itPos);
		v_sized.insert(itPos, v_odd[i]);
		n = 3;
		t = t + 1;
		i = i - 1;
		return DuaInsertion(i, n, t, k, v_odd, v_sized);
	}

	else if (n == 3 && i > -1 && v_sized[pos] == 0) {
		v_sized.erase(itPos);
		v_sized.insert(itPos, v_odd[i]);
		n = 1;
		t = t + 1;
		i = i - 1;
		return DuaInsertion(i, n, t, k, v_odd, v_sized);
	}

	else if (n == 1 && i > -1 && v_sized[pos] == 0) {
		v_sized.erase(itPos);
		v_sized.insert(itPos, v_odd[i]);
		n = 2;
		t = t + 1;
		i = i - 1;
		return DuaInsertion(i, n, t, k, v_odd, v_sized);
	}

	else if (v_sized[pos] != 0 && i > -1) {
		return DuaInsertion(i, n, t, k + 1, v_odd, v_sized);
	}

	return v_sized;
}

int main() {
	std::vector<double> v_even, v_odd, v_sized;
	std::ifstream infile;
	std::ofstream outfile;
	int total_size;

	// File I/O.
	infile.open("input.txt");
	if (!infile.is_open()) {
		std::cout << "error opening file" << std::endl;
		return EXIT_FAILURE;
	}
	int tmp;
	while (infile >> tmp) {
		v_even.push_back(tmp);
	};
	infile.close();

	// Getting initial size of v_even, i.e. number of people in formation.
	total_size = v_even.size();

	// C++ Standard Library Sort.
	std::sort(v_even.begin(), v_even.end());

	// Separating Odd Elements into new Vector ('Dua').
	for (int i = 0; i < total_size; i++) {
		if (i % 2 == 1) {
			v_odd.push_back(v_even[i]);
		}
	}

	// Removing Separated Elements, keeping Even Elements ('Satu').
	for (int i = total_size; i != 0; i--) {
		if (i % 2 == 0) {
			v_even.erase(v_even.begin() + i - 1);
		}
	}

	// Create Array of 0s.
	for (int i = 0; i < total_size; i++) {
		v_sized.push_back(0);
	}

	// Ordered Insertion Function for Even Row - 1, 3, 2. Recurse from the
	// Front.
	v_sized = SatuInsertion(v_even.size() - 1, 1, 0, v_even, v_sized);

	// Ordered Insertion Function for Odd Row - 2, 3, 1. Recurse from the Back.
	v_sized = DuaInsertion(v_odd.size() - 1, 3, 0, 0, v_odd, v_sized);

	// File I/O
	outfile.open("output.txt");

	for (int i = 2; i > -1; i = i - 1) {
		outfile << v_sized[i + 6] << v_sized[i + 3] << v_sized[i] << std::endl;
	}

	outfile.close();
}
