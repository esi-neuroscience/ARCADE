
//-------------------------------------------------------------------------
// File: Grating.fx
// -- Pixel Shader --
// grating -> sine or squarewave
// mask    -> circle or ellipse
// color   -> bw or full rgb
//-------------------------------------------------------------------------


cbuffer PS_ANIMATION : register (b1)
{
    float  frame : packoffset(c0.x); // pixels per frame -> nFrames * pixelsPerFrame
};

cbuffer PS_CONSTANT_BUFFER : register (b0)
{
    // position
    float2 center       : packoffset(c0.x); // (x,y) [pixels]
    float  width         : packoffset(c0.z);
    float  height        : packoffset(c0.w);   

    // mask parameters 
    float  mskWidth     : packoffset(c1.x); // param 1  radius (circle), width (ellipse) [pixels]
    float  mskHight     : packoffset(c1.y); // param 2, height (ellipse)                 [pixels]         
    float  mskAngle     : packoffset(c1.z); // param 3, angle  (ellipse)                 [degrees]

    // grating parameters
    float  spatialPeriod   : packoffset(c1.w); // param 4  [pixels per degree]
    float  direction       : packoffset(c2.x); // param 5  [degrees] 
    float  temporalFrequency  : packoffset(c2.y); // param 6  [cycles per frame]
    float  initialPhase    : packoffset(c2.z); // param 7  [degrees]
        
    float  radialSlope     : packoffset(c2.w); // param 8 [degrees per pixel]
 
};

cbuffer PS_COLOR_BUFFER : register (b2)
{
    float4 color0	: packoffset(c0.x); // color 1
    float4 color1	: packoffset(c1.x); // color 2
};


float4 PSmain( float4 Pos : SV_POSITION ) : SV_Target
{
    // define values 
    static const float pi = 3.141592654;

    float radix      = (mskWidth ? mskWidth: 500.0f);
    float radiy      = (mskHight ? mskHight: radix);
    float radius     = radix;

    // discard pixel
    if (distance(center, Pos.xy) > radius) discard;
    
    // grating direction 
    float2 pDrift;
    float2 pOrthogonalToDrift;
    sincos(radians(-1.0f*direction), pDrift.y, pDrift.x);
    sincos(radians(-1.0f*direction), pOrthogonalToDrift.x, pOrthogonalToDrift.y);

    float R = 2;

    float driftDir = dot(center-Pos.xy, pDrift) / spatialPeriod;
    float orthoDriftDir = dot(center-Pos.xy, pOrthogonalToDrift)*(2.0f*pi)/spatialPeriod;
    // calculate sinewave components
    float phi_0 = radians(initialPhase);
    float phi_t = 2.0f * pi * frame * temporalFrequency;
    float phi_s = 2.0f*  pi * driftDir;
    float phi_delta = -1.0f * radians(radialSlope) * orthoDriftDir * orthoDriftDir;
    float sineWave = sin( phi_0 + phi_t + phi_s + phi_delta );
    float bright   = (width*height*0.0f)+(pow(abs(sineWave), 2.0f/R) * sign(sineWave) + 1.0f) / 2.0f;

    // if colored, implement color via alpha blending  
    return color0*(float4)(1.0f-bright) + color1*(float4)bright;
}
