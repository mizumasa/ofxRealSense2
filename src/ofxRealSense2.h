#pragma once

#include "ofMain.h"
#include "ofxRealSense2.h"
#include <librealsense2/rs.hpp>

#define COLOR_WIDTH 640
#define COLOR_HEIGHT 480
#define DEPTH_WIDTH 1280
#define DEPTH_HEIGHT 720


class ofxRealSense2{
    public:
        ~ofxRealSense2();
        ofxRealSense2();
        bool setup();
        void update();
    
    
    ofPixels & getPixels();
    ofPixels & getDepthPixels();
    
    /// draw the color video
    void draw(float x, float y, float w, float h) const;
    void draw(float x, float y) const;
    void draw(const ofPoint& point) const;
    void draw(const ofRectangle& rect) const;
    
    /// draw the color depth map
    void drawDepth(float x, float y, float w, float h) const;
    void drawDepth(float x, float y) const;
    void drawDepth(const ofPoint& point) const;
    void drawDepth(const ofRectangle& rect) const;

    
    private:
        rs2::colorizer color_map;
        rs2::pipeline pipe;
    
        ofImage colorImage;
        ofImage depthImage;
};
