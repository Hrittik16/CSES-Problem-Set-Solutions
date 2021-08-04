#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	std::set<int> unique_nums;
	for(int i = 0; i < n; i++) {
		int item;
		std::cin >> item;
		unique_nums.insert(item);
	}
	std::cout << unique_nums.size() << "\n";
}