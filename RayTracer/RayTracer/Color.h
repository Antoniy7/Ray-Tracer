#ifndef _COLOR_H
#define _COLOR_H


class Color{
	double red;
	double green;
	double blue;
	double special;

public:
	Color();
	Color(double, double, double,double);
	double getColorRed() { return red; }
	double getColorGreen() { return green; }
	double getColorBlue(){ return blue; }
	double getColorSpecial(){ return special;}
	 
	void setColorRed(double redValue){red = redValue;}
	void setColorGreen(double greenValue){ green = greenValue; }
	void setColorBlue(double blueValue){ blue = blueValue; }
	void setColorSpecial(double specialValue){ special = specialValue;}

	double brightness(){
		return (red + green + blue) / 3;
	}

	Color colorScalar(double scalar){                       //reflective shininess
		return Color(red*scalar, green*scalar, blue*scalar, special);
	}

	Color colorAdd(Color color){
		return Color(red + color.getColorRed(), green + color.getColorGreen(), blue + color.getColorBlue(), special);
	}
	Color colorMultiply(Color color){
		return Color(red*color.getColorRed(), green*color.getColorGreen(), blue*color.getColorBlue(), special);
	}
	
	Color clip(){
		double allight = red + green + blue;
		double excesslight = allight - 3;
		if (excesslight>0){
			red = red + excesslight*(red / allight);
			green = green + excesslight*(green / allight);
			blue = blue + excesslight*(blue / allight);
		}
		if (red > 1 || red<0){ red = 1; }
		if (green > 1 || green <0){green = 1; }
		if (blue > 1 || blue<0){ blue = 1; }

		return Color(red, green, blue, special);
	}

	Color colorAverage(Color color){
		return Color((red + color.getColorRed()) / 2, (green + color.getColorGreen()) / 2, (blue + color.getColorBlue()) / 2, special);
	}
};

Color::Color()
{
	//defaul color be gray
	red = 0.5;
	green = 0.5;
	blue = 0.5;
}

Color::Color(double i, double j, double k,double s)
{
	red = i;
	green = j;
	blue = k;
	special = s;
}

#endif
