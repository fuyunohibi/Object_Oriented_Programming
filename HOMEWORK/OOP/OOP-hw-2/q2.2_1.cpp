#include <iostream>
#include <map>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Ranking by average score:

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

  // Compute the average score for each player
  map<string, double> avg_scores;
  for (auto const& [name, score_list] : scores) {
    double avg_score = accumulate(score_list.begin(), score_list.end(), 0.0) / score_list.size();
    avg_scores[name] = avg_score;
  }

  // Sort players by descending average score and ascending name
  vector<pair<string, double>> sorted_scores(avg_scores.begin(), avg_scores.end());
  sort(sorted_scores.begin(), sorted_scores.end(),
       [](pair<string, double> const& a, pair<string, double> const& b) {
         if (a.second == b.second) {
           return a.first < b.first;
         } else {
           return a.second > b.second;
         }
       });

  // Print out the rankings and average scores
  int rank = 1;
  for (auto const& [name, score] : sorted_scores) {
    cout << rank << ": " << name << " (" << score << ")" << endl;
    rank++;
  }

  return 0;
}