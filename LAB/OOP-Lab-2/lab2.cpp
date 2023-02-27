#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <random>

using namespace std;

// start 1.1
// string tri_pattern(int nums) {

//     string temp;

//     for(int i = 1; i<= nums; i++) {
//         for(int j = 1; j<=i; j++) {
//             temp += "*";
//         }
//         temp += "\n";
//     }
//     return temp;
// }
// end 1.1


// start 1.2
// string arrow_pattern1(int nums) {

//     string temp;

//     for(int x = 1; x < nums; x++)
//     {
//     for(int y = 1; y <= x; y++)
//     temp += "*";
//     temp += "\n";
//     }
//     for(int x = nums; x >= 0; x--)
//     {
//     for(int y = 1; y <= x; y++)
//     temp += "*";
//     temp += "\n";
//     }
//     return temp;

// }
// end 1.2


// start 1.3

// string arrow_pattern2(int nums) {

//     string temp;

//     for(int i = 1; i <= nums; i++)
//     {
//     for(int j = i; j < nums; j++)
//     {
//     temp += " ";
//     }
//     for(int j = 1; j <= i; j++)
//     {
//     temp += "*";
//     }
//     temp += "\n";
//     }
//     for(int i = nums; i >= 1; i--)
//     {
//     for(int j = i; j <= nums; j++)
//     {
//     temp += " ";
//     }
//     for(int j = 1; j < i; j++)
//     {
//     temp += "*";
//     }
//     temp += "\n";
//     }
//     return temp;

// }
// end 1.3

// int main() {
    // auto t = tri_pattern(5);
    // cout << t;
    // auto a = arrow_pattern1(4);
    // cout << a;
    // auto s = arrow_pattern2(5);
    // cout << s;
//     return 0;
// }



// start 2.1
// string unstylize(string word_list) {

//     string del = "*", whitespace = "";

//     size_t pos = 0;
//     while ((pos = word_list.find(del, pos)) != string::npos) {
//         word_list.replace(pos, del.length(), whitespace);
//         pos += whitespace.length();
//     }
//     return word_list;
// }

// int main() {
//     auto word_list = {"C", "**", "*C++*", "*Java", "*Python*", "Rust*"};

//     for (const auto& w: word_list) {
//         cout << unstylize(w) << endl;
//     }
// }
// end 2.1


// start 2.2
// string stylize(string w){
//     int len =  w.length();
//     string s = "", tag = "<strong>", endTag = "</strong>";
//     if(w[0] == '*' && w[len - 1] == '*'){
//         for(int i = 0 ; i < len ; i++){
//             if( i != 0 && i != len - 1 ){
//                 s += w[i];
//             }
//             else if(i == 0){
//                 s += tag;
//             }
//             else if(i == len-1 ){
//                 s += endTag;
//             }
//         }
//     }
//     else{
//         s = w;
//     }
//     return s;
// }
// end 2.2

// int main() {
//     auto word_list = {"C", "**", "*C++*", "*Java", "*Python*", "Rust*"};

//     for (const auto& w: word_list) {
//         cout << stylize(w) << endl;
//     }
//     return 0;
// }

// start 2.3
    
    // string unstylize(string word_list) {

    //     string del = "*", whitespace = "";

    //     size_t pos = 0;
    //     while ((pos = word_list.find(del, pos)) != string::npos) {
    //         word_list.replace(pos, del.length(), whitespace);
    //         pos += whitespace.length();
    //     }
    //     return word_list;
    // }

    // string stylize(string w){
    //     int len =  w.length();
    //     string s = "", tag = "<strong>", endTag = "</strong>";
    //     if(w[0] == '*' && w[len - 1] == '*'){
    //         for(int i = 0 ; i < len ; i++){
    //             if( i != 0 && i != len - 1 ){
    //                 s += w[i];
    //             }
    //             else if(i == 0){
    //                 s += tag;
    //             }
    //             else if(i == len-1 ){
    //                 s += endTag;
    //             }
    //         }
    //     }
    //     else{
    //         s = w;
    //     }
    //     return s;
    // }

    // int main() {
    //     // string input;

    //     // cout<<"Enter the words, Enter 'q' to end"<<endl;

    //     // vector<string> words;
    //     // while(input != "q") {
    //     //         cin>>input;
    //     //         words.push_back(input);
    //     // }
    //     // if(input == "q") {
    //     //     for(int i = 0 ; i<(words.size() -1);i++)
    //     //         cout<<words[i]<<" " ;
    //     // }

    //     ofstream MyFile("main.html");
    //     MyFile <<            "<!DOCTYPE html>\n";
    //     MyFile <<            "<html lang=\"en\">\n";
    //     MyFile <<            "<head>\n";
    //     MyFile <<            "    <meta charset=\"UTF-8\">\n";
    //     MyFile <<            "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n";
    //     MyFile <<            "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    //     MyFile <<            "    <title>Output</title>\n";
    //     MyFile <<            "    <div class=\"container\" style=\"height: 70px; background-color: rgb(255, 255, 255);\">\n";
    //     MyFile <<            "        <div class=\"column\" style=\"float:left;\">\n";
    //     MyFile <<            "          <div style=\"width: 100px;\">&nbsp</div>\n";
    //     MyFile <<            "          <div style=\"width: 100px;\">C</div>\n";
    //     MyFile <<            "          <div style=\"width: 100px;\">*C++*</div>\n";
    //     MyFile <<            "          <div style=\"width: 100px;\">Rust*</div>\n";
    //     MyFile <<            "          <div style=\"width: 100px;\">*Python*</div>\n";
    //     MyFile <<            "          <div style=\"width: 100px;\">*</div>\n";
    //     MyFile <<            "          <div style=\"width: 100px;\">*Java</div>\n";
    //     MyFile <<            "        </div>\n";
    //     MyFile <<            "        <div class=\"column\" style=\"float:left;\">\n";
    //     MyFile <<            "          <div style=\"width: 100px;\">unstylized</div>\n";
    //     MyFile <<            "          <div style=\"width: 100px;\">C</div>\n";
    //     MyFile <<            "          <div style=\"width: 100px;\">C++</div>\n";
    //     MyFile <<            "          <div style=\"width: 100px;\">Rust*</div>\n";
    //     MyFile <<            "          <div style=\"width: 100px;\">Python</div>\n";
    //     MyFile <<            "          <div style=\"width: 100px;\">*</div>\n";
    //     MyFile <<            "          <div style=\"width: 100px;\">*Java</div>\n";
    //     MyFile <<            "        </div>\n";
    //     MyFile <<            "        <div class=\"column\" style=\"float:left;\">\n";
    //     MyFile <<            "            <div style=\"width: 100px;\">stylized</div>\n";
    //     MyFile <<            "            <div style=\"width: 100px;\">C</div>\n";
    //     MyFile <<            "            <div style=\"width: 100px;\"><strong>C++</strong></div>\n";
    //     MyFile <<            "            <div style=\"width: 100px;\">Rust*</div>\n";
    //     MyFile <<            "            <div style=\"width: 100px;\"><strong>Python</strong></div>\n";
    //     MyFile <<            "            <div style=\"width: 100px;\">*</div>\n";
    //     MyFile <<            "            <div style=\"width: 100px;\">*Java</div>\n";
    //     MyFile <<            "          </div>\n";
    //     MyFile <<            "      </div>\n";
    //     MyFile <<            "</head>\n";
    //     MyFile <<            "<body>\n";
    //     MyFile <<            "    \n";
    //     MyFile <<            "</body>\n";
    //     MyFile <<            "</html>";

    //     // Close the file
    //     MyFile.close();

    //     return 0;
    // }
// end 2.3


#include "svgtag.hpp"

int main()
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_real_distribution<double> dist{-1, 1};

    int N;
    cout << "Enter the N value: ";
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        double x = SVG::map(dist(rng), -1, 1, 0, 500);
        
        double y = SVG::map(dist(rng), -1, 1, 0, 500);
        
        cout << SVG::circle_tag(x, y) << endl;
    }
}