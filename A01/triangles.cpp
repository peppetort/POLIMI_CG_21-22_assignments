/**************
 Function Triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)

 draws a triangle connecting points (x1,y1)  (x2, y2) and (x3, y3), colored with the (r,g,b) specified color.
 vertex are expressed in Normalized screen coordinates, (i.e. in range [-1,+1]), following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 
 Using function Triangle(...) try to draw a children house, similar to the one below.
 
 First remove the two function below (given only as an example), and replace them with your own.
 Since it is a C program, you can use for loops if you think it can be helpful in your drawing.
 The for() command below that draws a sun like shape in exact center of the screen near the top,
 is an example on how you can use it: please remove it, and replace it with your own code.
 It is not necessery to use a for loop if you do not really need it: it has been put here only as
 an example to help students not familiar with C++.
***************/

//roof
Triangle(0.35,-0.45, -0.01,0.18, 0.71,0.18,   1,0,0);


//house
double x = 0.08;
double y = 0.18;
Triangle(x,y, x+0.55,y, x,y+0.62,   0,0,1);
Triangle(x+0.55,y+0.62, x+0.55,y, x,y+0.62,   0,0,1);	



//left window
x = 0.18;
y = 0.29;
Triangle(x,y, x+0.1,y, x,y+0.1,   255,255,0);
Triangle(x+0.1,y+0.1, x+0.1,y, x,y+0.1,   255,255,0);	

//rigth window
x = 0.45;
y = 0.29;
Triangle(x,y, x+0.1,y, x,y+0.1,   255,255,0);
Triangle(x+0.1,y+0.1, x+0.1,y, x,y+0.1,   255,255,0);

//door
x = 0.31;
y = 0.5;
Triangle(x,y, x+0.1,y, x,y+0.3,   255,255,0);
Triangle(x+0.1,y+0.3, x+0.1,y, x,y+0.3,   255,255,0);

//weed
x = -1;
y = 0.8;
Triangle(x,y, x+2,y, x,y+0.2,   0,1,0);
Triangle(x+2,y+0.2, x+2,y, x,y+0.2,   0,1,0);



/*Triangle(1,-1, 0,0, 1,1,   0,1,0);	*/ // Draws a green triangle pointing left


for(int i = 0; i < 32; i++) {
	Triangle( 0.00 + 0.05 * cos(6.28/32*(i-0.5)), -0.80 + 0.05 * sin(6.28/32*(i-0.5)),
			  0.00 + 0.10 * cos(6.28/32*i), -0.80 + 0.10 * sin(6.28/32*i),
			  0.00 + 0.05 * cos(6.28/32*(i+0.5)), -0.80 + 0.05 * sin(6.28/32*(i+0.5)),
			  1,1,0);
}
