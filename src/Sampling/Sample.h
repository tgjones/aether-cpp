#ifndef Aether_Sample_h
#define Aether_Sample_h

struct Sample {
public:
	// Attribute accessors
	float getImageX() const;
	void setImageX(int imageX);
	float getImageY() const;
	void setImageY(int imageY);
	
private:
	int _imageX, _imageY;
};

#endif
