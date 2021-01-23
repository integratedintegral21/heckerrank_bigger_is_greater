#include <iostream>
#include <algorithm>

using namespace std;

string biggerIsGreater(string w) {

	// the biggest possible option
	string test_w = w;
	sort(test_w.begin(), test_w.end(), [](char a, char b) { return a > b; });
	if (test_w == w) return "no answer";

	int str_len = w.size();
	//begin from the second last element
	for (int i = str_len - 2; i >= 0; i--) {

		int min_dist = 26;
		int min_dist_index = -1;
		for (int j = i; j < str_len; j++) { //find the closest biggest character to swap
			if ((w[j] > w[i]) && (w[j] - w[i] < min_dist)) {
				min_dist = w[j] - w[i];
				min_dist_index = j;
			}
		}
		//if a character is found 
		if (min_dist_index > -1) {
			//swap characters
			swap(w[i], w[min_dist_index]);
			string sort_substr = w.substr(i + 1);
			string untouched_substr = w.substr(0, i + 1);

			//sort w[i+1:] so the result is the minimum one
			sort(sort_substr.begin(), sort_substr.end(), [](char a, char b) { return a < b; });

			w = untouched_substr + sort_substr;
			break;
		}
	}

	return w;
}

int main() {
	cout << biggerIsGreater("dhck");

	return 0;
}