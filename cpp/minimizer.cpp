#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm> //for str.erase
#include <set>
#include <iterator>

int w;
int k;
int l;

//minimizer() function
std::string minimizer(std::string subString){
  std::set<std::string> sortedItems;
  for(int i=0; i<(int)subString.size()-k+1; i++){
    sortedItems.insert(subString.substr(i,k));
    //std::cout << subString.substr(i,k) << std::endl;
  }
  //std::cout << *sortedItems.begin() << std::endl;

  return *sortedItems.begin();
}

//left_end() function
std::vector<std::string> left_end(std::string subString){
  std::vector<std::string> leftEndSeeds;
  for(int i=k; i<l; i++){
    leftEndSeeds.push_back(minimizer(subString.substr(0,i)));
    //std::cout << subString.substr(0,i) << std::endl;
  }
  return leftEndSeeds;
}

//right_end() function
std::vector<std::string> right_end(std::string subString){
  std::vector<std::string> rightEndSeeds;
  for(int i=0; i<l-k; i++){
    rightEndSeeds.push_back(minimizer(subString.substr(i,l-1)));
    //std::cout << subString.substr(i,l-1) << std::endl;
  }
  //for(auto i=rightEndSeeds.begin(); i!=rightEndSeeds.end(); ++i){
  //  std::cout << *i << std::endl;
  //}
  return rightEndSeeds;
}

//main() function
int main(int argc, char *argv[])
{
  //Init
  char* inputFile = argv[1];
  std::vector<std::string> minimizers;
  std::vector<std::string> leftEndMin;
  std::vector<std::string> rightEndMin;
  w = (int)(argv[2][0] - '0');
  k = (int)(argv[3][0] - '0');
  l = w+k-1;

  std::cout << "w=" << w << ", k=" << k << ", l=" << l << std::endl;

  //Loading input file to string and removing \n and \r
  std::ifstream ifs(inputFile);
  std::string genome( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );  
  genome.erase(std::remove(genome.begin(), genome.end(), '\n'), genome.end());
  genome.erase(std::remove(genome.begin(), genome.end(), '\r'), genome.end());
  
  std::cout << "Loaded " << genome.size() << " chars from string!" << std::endl;
  //std::cout << genome << std::endl;

  //Find left end minimizers
  leftEndMin = left_end(genome.substr(0,l-1));
  //std::cout << "leftEndMin: " << leftEndMin.size() << std::endl;
  for(int i=0; i<(int)leftEndMin.size(); i++){
    minimizers.push_back(leftEndMin[i]);
  }

  //Find interior minimizers
  for(int i=0; i<(int)genome.size()-l+1; i++){
    //std::cout << minimizer(genom.substr(i,k+w-1)) << std::endl;
    minimizers.push_back(minimizer(genome.substr(i,l)));
  }

  //Find right end minimizers
  rightEndMin = right_end(genome.substr(genome.size()-l+1,l-1));
  //std::cout << "rightEndMin: " << rightEndMin.size() << std::endl;
  for(int i=0; i<(int)rightEndMin.size(); i++){
    minimizers.push_back(rightEndMin[i]);
  }

  //Delete duplicates and print to stdout
  minimizers.erase(unique(minimizers.begin(), minimizers.end()), minimizers.end());
  //for(auto i=minimizers.begin(); i!=minimizers.end(); ++i){
  //  std::cout << *i << std::endl;
  //}

  //Write the results to a text file
  std::ofstream output_file("./output.txt");
  std::ostream_iterator<std::string> output_iterator(output_file, "\n");
  std::copy(minimizers.begin(), minimizers.end(), output_iterator);
  std::cout << "Stored " << minimizers.size() << " minimizers to output.txt" << std::endl;
  
  return 0;
}
