//
//  RPiVideoGrabber.cpp
//  JVCRPI2_LOCAL
//
//  Created by jason van cleave on 12/20/15.
//  Copyright © 2015 jason van cleave. All rights reserved.
//

#include "RPiVideoGrabber.h"


RPiVideoGrabber::RPiVideoGrabber()
{
    cameraWidth = 0;
    cameraHeight = 0;
    didInit = false;
    hasNewFrame = true;
}


bool RPiVideoGrabber::setup(int w, int h)
{
    return initGrabber(w, h);
}

bool RPiVideoGrabber::initGrabber(int w, int h)
{
    
    
    settings.sensorWidth = w; 
    settings.sensorHeight = h;
    settings.enablePixels = true;
    cameraWidth = w;
    cameraHeight = h;
    
    settings.enableTexture = true; //default true
    videoGrabber.setup(settings);
    videoGrabber.enablePixels();

    didInit = true;
    return didInit;
}

bool RPiVideoGrabber::isFrameNew() const
{
    return hasNewFrame;
}

void RPiVideoGrabber::setDesiredFrameRate(int framerate)
{
    settings.framerate = framerate;
}

int RPiVideoGrabber::getFrameRate()
{
    return settings.framerate;
}

void RPiVideoGrabber::update()
{
    hasNewFrame = videoGrabber.isFrameNew();
}

float RPiVideoGrabber::getHeight() const
{
    return cameraHeight;
}

float RPiVideoGrabber::getWidth() const
{
    return cameraWidth;
}

void RPiVideoGrabber::draw(int x, int y)
{
    videoGrabber.draw(x, y);
}

void RPiVideoGrabber::draw(int x, int y, int width, int height)
{
    videoGrabber.draw(x, y, width, height);
}

ofTexture* RPiVideoGrabber::getTexturePtr()
{
    return &videoGrabber.displayController.fbo.getTexture(); 
}

bool RPiVideoGrabber::isInitialized() const
{
    return didInit;
}

bool RPiVideoGrabber::setPixelFormat(ofPixelFormat pixelFormat)
{
    if (pixelFormat == OF_PIXELS_RGBA) 
    {
        return true;
    }
    return false;
}

ofPixelFormat RPiVideoGrabber::getPixelFormat() const
{
    return OF_PIXELS_RGBA;
    
}

const ofPixels& RPiVideoGrabber::getPixels() const
{
    return videoGrabber.displayController.of_pixels;
}

ofPixels& RPiVideoGrabber::getPixels()
{
    return videoGrabber.displayController.of_pixels;
}

void RPiVideoGrabber::close()
{
    videoGrabber.close();
}

vector<ofVideoDevice> RPiVideoGrabber::listDevices() const
{
    ofLogError(__func__) << "you don't need to call this";
    return unused;
}

void RPiVideoGrabber::videoSettings()
{
    ofLogError(__func__) << "not used";
}

