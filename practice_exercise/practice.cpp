#include"std_lib_facilities.h"
#include<map>
#include<stack>
#include<vector>
#include <algorithm>


struct CmpByValue {
	bool operator()(pair<string,int> left, pair<string,int> right) {
		return left.second > right.second;
	}
};

int main()
{
	string file_name = "C:\\Users\\Air\\Desktop\\practice_exercise\\practice_exercise\\dictionary.txt";
	ifstream dictionary(file_name);
	string word;
	vector<string> stack_of_word;
	while (getline(dictionary, word))
	{
		stack_of_word.push_back(word);
	}
	map<string,int> map_of_suffix;

	int n_letter;
	cout << "Enter a number :";
	cin >> n_letter;

	for (int i = 0; i < stack_of_word.size(); i++)
	{
		string temp_word = stack_of_word[i];
		if (temp_word.size() < n_letter)
			continue;
		else
		{
			string suffix;
			for (int j = temp_word.size() - n_letter; j < temp_word.size(); j++)
			{
				suffix += temp_word[j];
			}
			map_of_suffix[suffix]++;
		}
	}

	vector<pair<string,int>> sorted_suffix(map_of_suffix.begin(), map_of_suffix.end());
	sort(sorted_suffix.begin(), sorted_suffix.end(), CmpByValue());
	for (int i = 0; i < 12; i++)
	{
		cout << "No." << i + 1 << ": " << sorted_suffix[i].first<<" number of words:" <<sorted_suffix[i].second<< endl;
	}

	string user_suffix;
	cout << "enter the suffix: ";
	cin >> user_suffix;

	int suffix_long=user_suffix.size();
	cout <<"the suffix has words:"<< map_of_suffix[user_suffix]<<endl;

	for (int i = stack_of_word.size()-1; i >0; i--)
	{
		string temp_suffix;
		string temp_word1 = stack_of_word[i];
		if (temp_word1.size() <suffix_long)
			continue;
		else
		{
			for (int j = temp_word1.size() - suffix_long; j < temp_word1.size(); j++)
			{
				temp_suffix += temp_word1[j];
			}
			if (temp_suffix == user_suffix)
				cout << temp_word1 << endl;
		}
	}

	keep_window_open();
}