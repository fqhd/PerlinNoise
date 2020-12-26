#include <iostream>
#include <vector>


void graph(const std::vector<float>& heights, unsigned int maxHeight);

int main(){

     std::vector<float> heights;
     

     return 0;
}

void graph(const std::vector<float>& heights, unsigned int maxHeight){

     for(unsigned int i = 0; i < heights.size(); i++){
          unsigned int currentHeight = heights[i] * maxHeight;
          for(unsigned int j = 0; j < currentHeight; j++){
               std::cout << "#";
          }
          std::cout << std::endl;
     }

}
