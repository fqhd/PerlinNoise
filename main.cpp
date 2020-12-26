#include <iostream>
#include <vector>


void graph(const std::vector<float>& heights, unsigned int maxHeight);



int main(){

     std::vector<float> noise;
     std::vector<float> perlin;

     //Seeding the noise vector
     srand(time(0));
     for(unsigned int i = 0; i < 256; i++){
          noise.push_back((rand() % 100) / 100.0f);
     }



     //input values
     float scaleBias = 1.5f;
     int numOctaves = 8;

     for(int x = 0; x < noise.size(); x++){
          float noiseValue = 0.0f;
          float scaleFactor = 1.0f;
          float scaleAccumulation = 0.0f;

          for(int o = 0; o < numOctaves; o++){
               int currentPitch = noise.size() >> o;

               int sample1 = (x / currentPitch) * currentPitch;
               int sample2 = (sample1 + currentPitch) % noise.size();

               float blendFactor = (float)(x - sample1) / (float)currentPitch;
               float interpolatedValue = (1.0f - blendFactor) * noise[sample1] + blendFactor * noise[sample2];

               noiseValue += interpolatedValue * scaleFactor;
               scaleAccumulation += scaleFactor;
               scaleFactor = scaleFactor / scaleBias;


          }

          perlin.push_back(noiseValue / scaleAccumulation);

     }




     //Graphing perlin noise vector
     graph(perlin, 128);

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
