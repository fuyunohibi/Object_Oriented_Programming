#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// Leo 5000 
// Leo 1200 
// Leo 2000 
// Leo 4500
// Mike 3800 
// Mike 2400 
// Mike 3200
// Raph 1500 
// Raph 2200 
// Raph 1200 
// Raph 4000 
// Raph 4800
// Don 5000 
// Don 1600 
// Don 3200 
// Don 4600
// May 4400 
// May 3300 
// May 5800

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

  // Compute the maximum score for each player
  map<string, int> max_scores;
  for (auto const& [name, score_list] : scores) {
    int max_score = *max_element(score_list.begin(), score_list.end());
    max_scores[name] = max_score;
  }

  // Sort players by descending score and ascending name
  vector<pair<string, int>> sorted_scores(max_scores.begin(), max_scores.end());
  sort(sorted_scores.begin(), sorted_scores.end(),
       [](pair<string, int> const& a, pair<string, int> const& b) {
         if (a.second == b.second) {
           return a.first < b.first;
         } else {
           return a.second > b.second;
         }
       });

  // Print out the rankings and max scores
  int rank = 1;
  for (auto const& [name, score] : sorted_scores) {
    cout << rank << ": " << name << " (" << score << ")" << endl;
    rank++;
  }

  return 0;
}