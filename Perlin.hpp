#ifndef PERLIN_H
#define PERLIN_H

class Perlin {
public:

     void init(unsigned int width, unsigned int octaves, float bias);
     void noise2D(unsigned int x, unsigned int y);
     void destroy();

private:

     void createRandomNoise(float* randomNoiseArray, unsigned int size);
     void createPerlinNoise(int width, int octaves, float bias, float* seed, float *output);

     float* m_noise = nullptr;
     unsigend int m_width = 0;

};

#endif
