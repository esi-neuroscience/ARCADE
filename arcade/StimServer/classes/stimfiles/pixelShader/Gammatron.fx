//--------------------------------------------------------------------------------------
// File: Grating.fx
// Pixel Shader
//--------------------------------------------------------------------------------------

cbuffer PS_ANIMATION : register (b1)
{
    float  frame : packoffset(c0.x);
};

cbuffer PS_CONSTANT_BUFFER : register (b0)
{
    float2 center        : packoffset(c0.x);
    float  width         : packoffset(c0.z);
    float  height        : packoffset(c0.w);    
    float  spatialPeriod : packoffset(c1.x); // pixels per cycle
    float  temporalPeriod: packoffset(c1.y); // frames per cycle
    float  direction     : packoffset(c1.z); // 1: outward, -1:inward
    float  amplitude     : packoffset(c1.w); // 
};

cbuffer PS_COLOR_BUFFER : register (b2)
{
    float4 color0   : packoffset(c0.x); // color 1
    float4 color1   : packoffset(c1.x); // color 2
    float4 color2   : packoffset(c2.x); // color 3 
    float4 color3   : packoffset(c3.x); // color 4
};


float4 PSmain( float4 Pos : SV_POSITION ) : SV_Target
{
        
    if (distance(center, Pos.xy) > width) discard;
    
    static const float pi = 3.141592654;    

    float r = sqrt((center.y-Pos.y)*(center.y-Pos.y) + (Pos.x-center.x)*(Pos.x-center.x));

    float phase = frame/temporalPeriod*direction*-1.0f;
    float bright = amplitude*(sin( 2.0f*pi/spatialPeriod * r + phase) + 1.0f)/2.0f;
    return float4( bright, bright, bright, 1.0f );
    // return color0*(float4)(1.0f-bright) + color1*(float4)bright;
}
