#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW05App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void HW05App::setup()
{
	
}

void HW05App::mouseDown( MouseEvent event )
{
}

void HW05App::update()
{
}

void HW05App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

//CINDER_APP_BASIC( HW05App, RendererGl )
