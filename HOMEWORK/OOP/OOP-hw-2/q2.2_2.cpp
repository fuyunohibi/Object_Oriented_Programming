#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;



// Ranking by minimum score:



int main() {
  // Create an empty map to store player scores
  map<string, vector<int>> scores;

  // Read in player names and scores
  string name;
  int score;
  cout << "Please input the score for each player, press CTRL-D to show the output: " << endl;
  while (cin >> name >> score) {
    scores[name].push_back(score);
  }

  // Compute the minimum score for each player
  map<string, int> min_scores;
  for (auto const& [name, score_list] : scores) {
    int min_score = *min_element(score_list.begin(), score_list.end());
    min_scores[name] = min_score;
  }

  // Sort players by ascending minimum score and ascending name
  vector<pair<string, int>> sorted_scores(min_scores.begin(), min_scores.end());
  sort(sorted_scores.begin(), sorted_scores.end(),
       [](pair<string, int> const& a, pair<string, int> const& b) {
         if (a.second == b.second) {
           return a.first < b.first;
         } else {
           return a.second < b.second;
         }
       });

  // Print out the rankings and minimum scores
  int rank = 1;
  for (auto const& [name, score] : sorted_scores) {
    cout << rank << ": " << name << " (" << score << ")" << endl;
    rank++;
  }

  return 0;
}

