//--------------------------------------------------------------------------------------
// File: Gammatron.fx
// Pixel Shader
//--------------------------------------------------------------------------------------

cbuffer PS_ANIMATION : register (b1)
{
    float  frame : packoffset(c0.x);
};

cbuffer PS_CONSTANT_BUFFER : register (b0)
{
    // position and size
    float2 center        : packoffset(c0.x);
    float  width         : packoffset(c0.z);
    float  height        : packoffset(c0.w);    

    // parameters
    float  spatialPeriod : packoffset(c1.x); // 1: pixels per cycle
    float  temporalFrequency : packoffset(c1.y); // 2: cycles per frame
    float  aaWidth       : packoffset(c1.z); // 3: pixels
    float  phaseOffset   : packoffset(c1.w); // 4: degrees
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
    
    float r = distance(center, Pos.xy); 
    float radius = width/2.0f;
    if ( r > radius ) discard;    
    float alpha = 1.0;
    static const float pi = 3.141592654;    

    float phase = 2.0f*pi * frame * temporalFrequency * -1.0f + radians(phaseOffset);
    float bright = (sin( 2.0f*pi/spatialPeriod * r + phase) + 1.0f)/2.0f;    

    if ( aaWidth > 0 ) {
         if (r >= (radius-aaWidth)) {
            alpha = 1.0f - (r-(radius-aaWidth))/aaWidth;
        }
    }
    float4 color = color0*(float4)(1.0f-bright) + color1*(float4)(bright);
    color[3] = alpha;

    return color;

}
