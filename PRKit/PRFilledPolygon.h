/*
 PRFilledPolygon.h
 
 PRKit:  Precognitive Research additions to Cocos2D.  http://cocos2d-iphone.org
 Contact us if you like it:  http://precognitiveresearch.com
 
 Created by Andy Sinesio on 6/25/10.
 Copyright 2011 Precognitive Research, LLC. All rights reserved.
 
 This class fills a polygon as described by an array of NSValue-encapsulated points with a texture.
 
 Translated in C++ for Cocos2d-X by Damiano Mazzella on 19/03/2012
 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#ifndef PRFILLEDPOLYGON_H
#define PRFILLEDPOLYGON_H

#include "cocos2d.h"
#include "PRTriangulator.h"

class PRFilledPolygon : public cocos2d::Node {
private:
	int areaTrianglePointCount;
    
	cocos2d::Texture2D* texture;
	cocos2d::BlendFunc blendFunc;
    
	cocos2d::Point* areaTrianglePoints;
	cocos2d::Point* textureCoordinates;
    
    PRTriangulator* triangulator;
    void calculateTextureCoordinates();
    
public:
    
    PRFilledPolygon() {
        areaTrianglePointCount = 0;
        texture = NULL;
        areaTrianglePoints = NULL;
        textureCoordinates = NULL;
        triangulator = NULL;
    }
    
    /**
     Returns an autoreleased polygon.  Default triangulator is used (Ratcliff's).
     */
    static PRFilledPolygon* create(Vector2dVector& polygonPoints, cocos2d::Texture2D* fillTexture);
    
    /**
     Returns an autoreleased filled poly with a supplied triangulator.
     */
    static PRFilledPolygon* create(Vector2dVector& polygonPoints, cocos2d::Texture2D* fillTexture, PRTriangulator* polygonTriangulator);
    
    /**
     Initialize the polygon.  polygonPoints will be triangulated.  Default triangulator is used (Ratcliff).
     */
    bool init(Vector2dVector& polygonPoints, cocos2d::Texture2D* fillTexture);
    
    /**
     Initialize the polygon.  polygonPoints will be triangulated using the supplied triangulator.
     */
    bool init(Vector2dVector& polygonPoints, cocos2d::Texture2D* fillTexture, PRTriangulator* polygonTriangulator);
    
    void setPoints(Vector2dVector& points);
    
    void setTexture(cocos2d::Texture2D* texture2D);
	cocos2d::Texture2D* getTexture() const;
    void updateBlendFunc();
    void setBlendFunc(cocos2d::BlendFunc blendFuncIn);
    virtual void cleanup() override;
	virtual void draw() override;
};

#endif
