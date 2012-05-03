#ifndef Aether_Sample_h
#define Aether_Sample_h

struct Sample {
public:
	float getImageX() const;
	float getImageY() const;
	
private:
	int _imageX, _imageY;
};

#endif
