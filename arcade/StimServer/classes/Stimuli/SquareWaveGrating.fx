
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------


cbuffer PS_ANIMATION : register (b1)
{
    float phase : packoffset(c0.x); // pixels per frame -> nFrames * pixelsPerFrame
};

cbuffer PS_CONSTANT_BUFFER : register (b0)
{
    // position
    float2 center       : packoffset(c0.x); // (x,y) [pixels]
    float  width         : packoffset(c0.z);
    float  height        : packoffset(c0.w);   

    // mask parameters 
    float  radius     : packoffset(c1.x); // param 1  radius (circle), width (ellipse) [pixels]
    float  param2     : packoffset(c1.y); // param 2, height (ellipse)                 [pixels]         
    float  mskAngle     : packoffset(c1.z); // param 3, angle  (ellipse)                 [degrees]

    // grating parameters
    float  spatialPeriod: packoffset(c1.w); // param 4  pixels per cycle
    float  direction    : packoffset(c2.x); // param 5  direction                        [degrees] 
    float  smoothR      : packoffset(c2.y); // param 6  smoothing parameter (squarewave) [r > 2] 
    float  phaseOffset  : packoffset(c2.z); // param 7  phase offset                     [degrees]
    
    // empty
    float dummy        : packoffset(c2.w); 
 
};

cbuffer PS_COLOR_BUFFER : register (b2)
{
    float4 color0	: packoffset(c0.x); // color 1
    float4 color1	: packoffset(c1.x); // color 2
    float4 color2	: packoffset(c2.x); // color 3 
    float4 color3	: packoffset(c3.x); // color 4
};


float4 PSmain( float4 Pos : SV_POSITION ) : SV_Target
{
    // float radius     = radix;

    // discard pixel
    if (distance(center, Pos.xy) > radius) discard;
    
    // grating direction 
    float2 p;
    sincos(radians(-1.0f*direction), p.y, p.x);

    float pixelsPerCycle = (spatialPeriod ? spatialPeriod: 100.0f);


    // calculate sw grating 
    int squareWave = (int) floor(( 
        phaseOffset + 
        phase + 
        dot(Pos.xy-center, p)+width/2.0f) 
        / (pixelsPerCycle/2.0f)) & 1;

    // anti aliasing via linear interpolation
    float pixelPhase = (phaseOffset + phase + dot(Pos.xy-center, p) + width/2.0f) % pixelsPerCycle;
    float bright = (float) squareWave;
    float aaWidth = (smoothR ? smoothR : 1.0f);
    if (( pixelPhase >= (pixelsPerCycle/2.0f) ) & 
        (pixelPhase < pixelsPerCycle/2.0f + aaWidth)) {
        bright = (pixelPhase - pixelsPerCycle/2.0f)/aaWidth;        
    };
    if ( pixelPhase <= aaWidth ) {
        bright = 1-(pixelPhase/aaWidth);        
    }
   ;
     return color0*(float4)(bright) + color1*(float4)(1.0f-bright);
}
