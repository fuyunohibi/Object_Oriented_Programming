#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// ============= Example Input =============

//       [1, 2, 3; 4, 5; 6, 7, 8, 9]

class Array
{
private:
   vector<vector<int>> data_;

public:
   Array(vector<vector<int>> data) : data_(data) {}

   string repr() const
   {
      stringstream ss;
      ss << "Array(";

      for (size_t i = 0; i < data_.size(); ++i)
      {
         if (data_[i].empty()) // skip empty rows
            continue;

         ss << "[";
         for (size_t j = 0; j < data_[i].size(); ++j)
         {
            ss << data_[i][j];
            if (j != data_[i].size() - 1)
            {
               ss << ",";
            }
         }
         ss << "]";
         if (i != data_.size() - 1)
         {
            ss << ",";
         }
      }
      ss << ")";
      return ss.str();
   }
};

int main()
{
   string input;

   cout << "Please Enter the data: ";

   getline(cin, input);

   vector<vector<int>> data;

   stringstream ss(input);
   string row_str;

   cout << "\nformatting data...\n";
   while (getline(ss, row_str, ';'))
   {
      stringstream row_ss(row_str);
      vector<int> row_data;
      char c;
      while (row_ss >> c)
      {
         if (isdigit(c))
         {
            row_ss.putback(c);
            int val;
            row_ss >> val;
            row_data.push_back(val);
         }
      }
      if (!row_data.empty())
      {
         data.push_back(row_data);
      }
   }

   for (int i = 0; i < data.size(); i++)
   {
      for (int j = 0; j < data[i].size(); j++)
      {
         cout << data[i][j] << " ";
      }
      cout << endl;
   }
   cout << "Completed\n\n";

   Array arr(data);
   cout << "Output: " << arr.repr() << endl;

   return 0;
}
