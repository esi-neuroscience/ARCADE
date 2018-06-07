
//-------------------------------------------------------------------------
// File: Gabor.fx
// Pixel Shader
//-------------------------------------------------------------------------


cbuffer PS_ANIMATION : register (b1)
{
    float  frame : packoffset(c0.x);
};

cbuffer PS_CONSTANT_BUFFER : register (b0)
{
    float2 center        : packoffset(c0.x);
    float  width         : packoffset(c0.z);
    float  height        : packoffset(c0.w);    

    // gaussian mask parameters
    float  sx : packoffset(c1.x); // standard deviation in px
    float  sy : packoffset(c1.y); // standard deviation in px
    float  maskAngle : packoffset(c1.z); // rotation in degrees

    // grating parameters
    float  cycle        : packoffset(c1.w); // param 4  pixels per cycle                       [pixels per cycle]
    float  direction    : packoffset(c2.x); // param 5  direction                        [degrees] 
    float  smoothR      : packoffset(c2.y); // param 6  smoothing parameter (squarewave) [r > 2] 
    float  phaseOffset  : packoffset(c2.z); // param 7  phase offset     

};

cbuffer PS_COLOR_BUFFER : register (b2)
{
    float4 color0   : packoffset(c0.x); 
    float4 color1   : packoffset(c1.x);
    float4 color2   : packoffset(c2.x); // dummy color 3 
    float4 color3   : packoffset(c3.x); // dummy color 4 

};


float4 PSmain( float4 Pos : SV_POSITION ) : SV_Target
{   
    // gaussian mask 
    float theta = radians(maskAngle);
    float rx = (center.x-Pos.x);
    float ry = (center.y-Pos.y);
    float sxx = pow(sx,2.0f);
    float syy = pow(sy,2.0f);
    float a = pow(cos(theta),2.0f)/(2.0f*sxx) + pow(sin(theta),2.0f)/(2.0f*syy);
    float b = -sin(2.0f*theta)/(4.0f*sxx) + sin(2.0f*theta)/(4.0f*syy);
    float c = pow(sin(theta),2.0f)/(2.0f*sxx) + pow(cos(theta),2.0f)/(2.0f*syy);

    float mask = exp(-( a*pow(rx,2.0f) - 2.0f*b*rx*ry + c*pow(ry,2.0f) ));

    // grating direction 
    float2 p;
    sincos(radians(-1.0f*direction), p.y, p.x);

    // calculate sinewave 
    float R = (smoothR ? smoothR: 2.0f);
    float pixelsPerCycle = (cycle ? cycle : 20.0f);
    static const float pi = 3.141592654;
    float sineWave = sin( radians(phaseOffset) + frame*2.0f*pi + dot(center-Pos.xy, p)*(2.0f*pi)/pixelsPerCycle );
    float bright   = (pow(abs(sineWave), 2.0f/R) * sign(sineWave) + 1.0f) / 2.0f;

    float4 gabor = color0*(float4)(1.0f-bright) + color1*(float4)bright;
    gabor[3] = mask*gabor[3];
      
    return gabor;
}
